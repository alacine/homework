--编写存储过程或存储函数完成以下各题，存储过程或函数依次命名为obj4_1、obj4_2、…
--以下1-7题与EMP、DEPT表有关。
--select * from emp;
set serveroutput on;
--1、输出名为SMITH的雇员的薪水和职位。(存储过程)
create or replace procedure obj4_1 as
  vsal number;
  vjob varchar2(100);
begin
  select sal, job into vsal, vjob
    from emp
    where ename = 'SMITH';
  dbms_output.put_line('薪水: '||vsal||', 职位: '||vjob);
end;
select object_name, authid from user_procedures;
select line, text from user_source where name='OBJ4_1';
execute obj4_1;

--2、接收部门编号，输出部门名和地理位置。(存储过程)
create or replace procedure obj4_2(vdeptno dept.deptno%type) as
  vdname dept.dname%type;
  vloc dept.loc%type;
begin
  select dname, loc
    into vdname, vloc
    from dept
    where deptno= vdeptno;
  dbms_output.put_line('部门名: '||vdname||', 地理位置: '||vloc);
end;
execute obj4_2(10);

--3、接收雇员号，输出该雇员的工资和提成，没有提成的用0替代。（用%type实现）。(存储过程)
create or replace procedure obj4_3(vempno emp.empno%type) as
  vsal emp.sal%type;
  vcomm emp.comm%type;
begin
  select sal, nvl(comm, 0)
    into vsal, vcomm
    from emp
    where vempno=empno;
  dbms_output.put_line('工资: '||vsal||', 提成: '||vcomm);
end;
execute obj4_3(7369);

--4、接收雇员号，输出该雇员的所有信息，没有提成的用0替代。（用%rowtype实现）。(存储过程)
create or replace procedure obj4_4(vempno emp.empno%type) as
  vemp emp%rowtype;
begin
  select * into vemp
    from emp
    where vempno=emp.empno;
  dbms_output.put_line('empno: '||vemp.empno||' ename: '||vemp.ename||' job: '||vemp.job||' mgr: '||vemp.mgr||
                       ' hiredate: '||vemp.hiredate||' sal: '||vemp.sal||' comm: '||nvl(vemp.comm, 0)||' deptno: '||vemp.deptno);
end;
execute obj4_4(7369);

--5、接收雇员号，输出该雇员的工资。(存储函数)
create or replace function obj4_5(vempno emp.empno%type) return number as
  vsal emp.sal%type;
begin
  select sal into vsal
    from emp
    where vempno = emp.empno;
  return vsal;
end;
select obj4_5(7369) from dual;

--6、接收一个雇员名或雇员编号，判断他的job，根据job不同，为他增加相应的sal（用if-elsif实现，不要改动到基本表emp，创建一个与emp表一模一样的表emp1）。(存储过程)
/*
    Job       raise
    clerk     +500
    salesman    +1000
    analyst    +1500
    otherwise   +3000
*/
drop table emp1;
create table emp1 as select * from emp;
create or replace procedure obj4_6(foo varchar2) as
  vename emp1.ename%type;
  vempno emp1.empno%type;
  vjob emp1.job%type;
  vsal emp1.sal%type;
  vcomm emp1.comm%type;
  vdeptno emp1.deptno%type;
begin
    select job, sal into vjob, vsal from emp1 where to_char(empno) = foo or ename = foo;
    if vjob = 'CLERK' then vsal := vsal + 500;
    elsif vjob = 'SALESMAN' then vsal := vsal + 1000;
    elsif vjob = 'ANALYST' then vsal := vsal + 1500;
    else vsal := vsal + 3000;
    end if;
    update emp1 set sal = vsal where to_char(empno) = foo or ename = foo;
    dbms_output.put_line('职位: '||vjob||' 薪水增加到: '||vsal);
end;
execute obj4_6(7369);
execute obj4_6('SMITH');

--7、输入部门编号，按照下列加薪比例执行给该部门的雇员加薪(用CASE实现，修改emp1表的数据) (存储过程)
/*
    deptno  raise(%)
    10      8%
    20      10%
    30      20%
    40      20%
    加薪比例以现有的sal为标准。
*/
create or replace procedure obj4_7(vdeptno emp1.deptno%type) as
    vename emp1.ename%type;
    vempno emp1.empno%type;
    vsal emp1.sal%type;
begin
    case vdeptno
        when 10 then update emp1 set sal = sal * 1.08 where deptno = vdeptno;
        when 20 then update emp1 set sal = sal * 1.1 where deptno = vdeptno;
        when 30 then update emp1 set sal = sal * 1.2 where deptno = vdeptno;
        when 40 then update emp1 set sal = sal * 1.2 where deptno = vdeptno;
    end case;
    dbms_output.put_line('更新'||vdeptno||'号部门的薪水');
end;
execute obj4_7(10);

--以下8-12题与以下表有关：学生、学费标准表、收费表、收费明细表。先从a_db模式中将这些表等复制到自己的模式中。
create table "学生" as select * from a_db."学生";
create table "学费标准表" as select * from a_db."学费标准表";
create table "收费表" as select * from a_db."收费表";
create table "收费明细表" as select * from a_db."收费明细表";

--学生每学年开学前必须注册。注册前要初始化学生表，所有学生（状态为“毕业”、“开除”、“休学”的除外）的状态设置为空值。注册时将状态设置为“注册”，并在收费表生成相应记录。学生每学年按专业收取学费，交学费时产生收费明细记录，并修改收费表中相应记录。

--8、在学生表中增加一列，用来记录学生的密码，写一个PL/SQL程序，模拟登录的过程。输入学号和密码，判断是否正确，对于登录成功和失败分别给出提示信息。(存储过程)
alter table "学生" drop column "密码";
alter table "学生" add "密码" varchar2(16) default '123456';
create or replace procedure obj4_8(input_number "学生"."学号"%type, input_passwd "学生"."密码"%type) as
    vnumber "学生"."学号"%type;
    vpasswd "学生"."密码"%type;
    vname "学生"."姓名"%type;
begin
    select "密码", "姓名" into vpasswd, vname from "学生" where "学号" = input_number;
    if vpasswd = input_passwd then dbms_output.put_line('登录成功，'||vname);
    else dbms_output.put_line('登录失败，请重试');
    end if;
    exception
        when no_data_found then dbms_output.put_line('登录失败，请重试');
end;
execute obj4_8('S101', '123456');

--9、编写一个向学费标准表添加记录的过程。

--10、编写一个学生注册的过程，注册日期默认为当天，以学号为参数。

--11、编写一个收学费的过程，收费日期默认为当天，以学年、 学号、学费为参数。

--12、编写一个过程，输出指定学年的欠费情况（含欠费人数、欠费总金额）。

--13、输出如下九九乘法表。(存储过程)
