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
end;
execute obj4_8('S101', '123456');

--9、编写一个向学费标准表添加记录的过程。
create or replace procedure obj4_9(input_year "学费标准表"."学年"%type,
                                   input_major "学费标准表"."专业"%type,
                                   input_tuition "学费标准表"."学费"%type) as
begin
    insert into "学费标准表" values(input_year, input_major, input_tuition);
end;
execute obj4_9('2018', '计算机科学与技术', 7777);

--10、编写一个学生注册的过程，注册日期默认为当天，以学号为参数。
create or replace procedure obj4_10(input_number "学生"."学号"%type,
                                    input_passwd "学生"."密码"%type) as
    vnumber "学生"."学号"%type;
    vstatus "学生"."状态"%type;
    vmajor "学生"."专业"%type;
    vtuition "收费表"."应交学费"%type;
begin
    select "学号", "状态", "专业" into vnumber, vstatus, vmajor
        from "学生"
        where "学号" = input_number;
    if vstatus is null then
        update "学生"
            set "状态" = '注册', "密码" = input_passwd, "注册日期" = sysdate
            where "学号" = vnumber;
        select "学费" into vtuition
            from "学费标准表"
            where "专业" = vmajor and "学年" = extract(year from sysdate);
        insert into "收费表" values(extract(year from sysdate), input_number, vtuition, 0);
        dbms_output.put_line('注册成功');
    else dbms_output.put_line('该学号已经注册');
    end if;
end;
update "学生" set "状态" = null where "学号" = 'S101' or "学号" = 'S102' or "学号" = 'S103';
execute obj4_10('S101', '654321');
execute obj4_10('S102', '123456');
execute obj4_10('S103', '888888');

--11、编写一个收学费的过程，收费日期默认为当天，以学年、 学号、学费为参数。
create or replace procedure obj4_11(input_number "学生"."学号"%type, paid "收费明细表"."学费"%type) as
    vno "收费明细表"."编号"%type;
begin
    select max("编号")+1 into vno from "收费明细表";
    insert into "收费明细表" values(vno, extract(year from sysdate), input_number, paid, sysdate);
    update "收费表"
        set "已交学费" = "已交学费" + paid
        where "学年" = extract(year from sysdate) and "学号" = input_number;
end;
execute obj4_11('S101', 2000);

--12、编写一个过程，输出指定学年的欠费情况（含欠费人数、欠费总金额）。
create or replace procedure obj4_12(input_year "收费表"."学年"%type) as
    vnumber int;
    vmoney_sum "收费表"."已交学费"%type;
begin
    select count(*), sum("应交学费"-"已交学费") into vnumber, vmoney_sum
        from "收费表"
        where "学年" = input_year and "应交学费" > "已交学费";
    dbms_output.put_line(input_year||'年，欠费人数为：'||vnumber||'欠费总金额为：'||vmoney_sum);
end;
execute obj4_12(2018);

--13、输出如下九九乘法表。(存储过程)
create or replace procedure obj4_13 as
    x int;
begin
    x := 1;
    while x <= 9 loop
        for i in 1..x loop
            dbms_output.put(x||'*'||i||'='||x*i||'  ');
        end loop;
        x := x + 1;
        dbms_output.new_line();
    end loop;
end;
execute obj4_13;
