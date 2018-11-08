-- 准备：
create table emp1  as select * from emp;
create table emp2  as select * from emp;
create table emp3  as select * from emp;
create table emp4  as select * from emp;
create table dept1  as select * from dept;

-- 将下面创建的触发器依次命名为obj8_1、obj8_2、…、obj8_6

-- 1. 创建一个emp1表的插入或修改触发器，功能是：员工的工资不能超过自己的经理的工资，超过则报错误。
create or replace trigger obj8_1
    before insert or update of sal on emp1 for each row
    declare pragma autonomous_transaction;
    mgr_sal emp1.sal%type := 0;
    cnt int := 0;
begin
    select sal into mgr_sal
        from emp1
        where empno = :new.mgr;
    if :new.sal > mgr_sal then
        raise_application_error(-20001, ' 别扯了，给你经理留个面子');
    end if;
end;

update emp1 set sal = 9999 where empno = 7369;

-- 2. 创建一个名为dept_summary(deptno,emp_count,sal_sum)的表，保存每一个部门的人数与工资总额。创建一个触发器，当对emp2表执行INSERT, UPDATE, DELETE 操作时，自动更新dept_summary 表中的数据。

-- 3. 创建一个dept1表的触发器，当删除一个部门时，同时也在emp1表中删除该部门所有的员工记录。

-- 4. 有如下视图：

create view empdept as select empno,ename,salary,deptno,dname  from emp2 natural join dept 1;

-- 创建一个empdept 视图的instead of触发器。当向该视图插入一条记录时，先判断该部门是否存在，若存在，则向emp2表插入一条相应的员工记录；若不存在该部门，则先向dept1表插入一条相应的部门记录，再向emp2表插入一条相应的员工记录。当从该视图删除记录时，则从emp2表中删除相应的员工记录。

-- 5. 创建一个emp3表的触发器，功能是：当插入记录时，若dept表不存在相应的部门，则拒绝插入；当修改记录中部门号deptno时，若dept1表不存在相应的部门，则拒绝修改。也就是不定义外键，用触发器完成相应的约束。

-- 6. 创建一个emp4表的触发器，功能是：当插入或修改记录时，将员工的姓名转换成大写字母。
