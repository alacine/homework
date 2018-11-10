set serveroutput on;
-- 准备：
drop table emp;
drop table emp1;
drop table emp2;
drop table emp3;
drop table emp4;
drop table dept1;
create table emp as select * from scott.emp;
create table emp1 as select * from scott.emp;
create table emp2 as select * from scott.emp;
create table emp3 as select * from scott.emp;
create table emp4 as select * from scott.emp;
create table dept1 as select * from scott.dept;

-- 将下面创建的触发器依次命名为obj8_1、obj8_2、…、obj8_6

-- 1. 创建一个emp1表的插入或修改触发器，功能是：员工的工资不能超过自己的经理的工资，超过则报错误。
create or replace trigger obj8_1 before
    insert or update of sal on emp1 for each row
declare
    pragma autonomous_transaction;
    mgr_sal emp1.sal%type := 0;
begin
    select sal into mgr_sal
        from emp1
        where empno = :new.mgr;
    if :new.sal > mgr_sal then
        raise_application_error(-20001, ' 别扯了，想什么呢');
    end if;
end;

update emp1 set sal = 9999 where empno = 7369;

-- 2. 创建一个名为dept_summary(deptno,emp_count,sal_sum)的表，保存每一个部门的人数与工资总额。创建一个触发器，当对emp2表执行INSERT, UPDATE, DELETE 操作时，自动更新dept_summary 表中的数据。
drop table dept_summary;
create table dept_summary(deptno, emp_count, sal_sum) as
    select deptno, count(empno), sum(sal)
    from emp2
    group by deptno;

create or replace trigger obj8_2 after
    insert or update or delete on emp2
begin
    delete from dept_summary;
    insert into dept_summary
        select deptno, count(empno), sum(sal)
        from emp2
        group by deptno;
    dbms_output.put_line('dept_summary is up to date.');
end;
update emp2 set sal = sal + 10 where deptno = 10;
update emp2 set sal = sal - 10 where deptno = 10;
select * from dept_summary;

-- 3. 创建一个dept1表的触发器，当删除一个部门时，同时也在emp1表中删除该部门所有的员工记录。
create or replace trigger obj8_3 after
    delete on dept1 for each row
begin
    delete from emp1 where deptno = :old.deptno;
    dbms_output.put_line('删除了'||:old.deptno||'号部门的信息');
end;
delete from dept1 where deptno = 10;
commit;
rollback;

-- 4. 有如下视图：

create view empdept as select empno, ename, sal, deptno, dname from emp2 natural join dept1;

-- 创建一个empdept 视图的instead of触发器。当向该视图插入一条记录时，先判断该部门是否存在，若存在，则向emp2表插入一条相应的员工记录；若不存在该部门，则先向dept1表插入一条相应的部门记录，再向emp2表插入一条相应的员工记录。当从该视图删除记录时，则从emp2表中删除相应的员工记录。
create or replace trigger obj8_4 instead of 
    insert or delete on empdept for each row
declare
    cnt int;
begin
    case
        when inserting then
            select count(deptno) into cnt
                from empdept
                where deptno = :new.deptno;
            if cnt = 0 then
                insert into dept1(deptno, dname) values(:new.deptno, :new.dname);
            end if;
            insert into emp2(empno, ename, sal, deptno) values(:new.empno, :new.ename, :new.sal, :new.deptno);
            dbms_output.put_line('已插入新的记录');
        when deleting then
            delete from emp2 where empno = :old.empno;
            dbms_output.put_line('已删除一条记录');
    end case;
end;
insert into empdept values(99, '99', 99, 99, '90');
delete from empdept where empno = 99;
delete from dept1 where deptno = 99;

-- 5. 创建一个emp3表的触发器，功能是：当插入记录时，若dept表不存在相应的部门，则拒绝插入；当修改记录中部门号deptno时，若dept1表不存在相应的部门，则拒绝修改。也就是不定义外键，用触发器完成相应的约束。
create or replace trigger obj8_5 before
    insert or update on emp3 for each row
declare
    cnt int;
begin
    case
        when inserting then
            select count(*) into cnt
                from dept
                where deptno = :new.deptno;
            if cnt = 0 then raise_application_error(-20001, '违反外键约束，dept中没有这个部门');
            end if;
        when updating then
            select count(*) into cnt
                from dept1
                where deptno = :new.deptno;
            if cnt = 0 then raise_application_error(-20002, '违反外键约束，dept1中没有这个部门');
            end if;
    end case;
end;
insert into emp3 values(99, '99', '99', 99, null, 99, 99, 99);
update emp3 set deptno = 99 where deptno = 30;

-- 6. 创建一个emp4表的触发器，功能是：当插入或修改记录时，将员工的姓名转换成大写字母。
create or replace trigger obj8_6 before
    insert or update on emp4 for each row
begin
    :new.ename := upper(:new.ename);
    dbms_output.put_line('帮你改成大写的了，不用谢我');
end;
insert into emp4(ename) values('aaa');
delete from emp4 where ename = 'AAA';

commit;
