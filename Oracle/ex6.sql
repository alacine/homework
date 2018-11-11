set serveroutput on;
-- 有针对性地给“实验四”上机内容中的过程与函数增加异常处理部分，保留原来的过程与函数，修改后的过程与函数另外保存，如obj4_1另存为obj6_1，以此类推。
--1、输出名为SMITH的雇员的薪水和职位。(存储过程)
create or replace procedure obj6_1 as
  vsal emp.sal%type;
  vjob emp.job%type;
begin
  select sal, job into vsal, vjob
    from emp
    where ename = 'SMITH';
  dbms_output.put_line('薪水: '||vsal||', 职位: '||vjob);
  exception
      when no_data_found then dbms_output.put_line('没有SMITH这个雇员');
      when too_many_rows then dbms_output.put_line('超过一人名字叫SMITH');
end;
execute obj6_1;

--2、接收部门编号，输出部门名和地理位置。(存储过程)
create or replace procedure obj6_2(vdeptno dept.deptno%type) as
    vdname dept.dname%type;
    vloc dept.loc%type;
begin
    select dname, loc
        into vdname, vloc
        from dept
        where deptno= vdeptno;
    dbms_output.put_line('部门名: '||vdname||', 地理位置: '||vloc);
    exception
      when no_data_found then dbms_output.put_line('没有这个部门，请检查你的输入');
end;
execute obj6_2(90);

--3、接收雇员号，输出该雇员的工资和提成，没有提成的用0替代。（用%type实现）。(存储过程)
create or replace procedure obj6_3(vempno emp.empno%type) as
    vsal emp.sal%type;
    vcomm emp.comm%type;
begin
    select sal, nvl(comm, 0)
        into vsal, vcomm
        from emp
        where vempno=empno;
    dbms_output.put_line('工资: '||vsal||', 提成: '||vcomm);
    exception
        when no_data_found then dbms_output.put_line('没有这个雇员，请检查你的输入');
end;
execute obj6_3(9999);

--4、传送参数雇员号，输出该雇员的所有信息，没有提成的用0替代。（用%rowtype实现）。(存储过程)
create or replace procedure obj6_4(vempno emp.empno%type) as
    vemp emp%rowtype;
begin
    select * into vemp
        from emp
        where vempno=emp.empno;
    dbms_output.put_line('empno: '||vemp.empno||' ename: '||vemp.ename||' job: '||vemp.job||' mgr: '||vemp.mgr||
                         ' hiredate: '||vemp.hiredate||' sal: '||vemp.sal||' comm: '||nvl(vemp.comm, 0)||' deptno: '||vemp.deptno);
    exception
        when no_data_found then dbms_output.put_line('没有这个雇员，请检查你的输入');
end;
execute obj6_4(9999);

--5、传送参数雇员号，返回该雇员的工资。(存储函数)
create or replace function obj6_5(vempno emp.empno%type) return number as
    vsal emp.sal%type;
begin
    select sal into vsal
        from emp
        where vempno = emp.empno;
    exception
        when no_data_found then vsal := -1;
    return vsal;
end;
select obj6_5(9999) from dual;

--6、传送参数雇员名或雇员编号，判断他的job，根据job不同，为他增加相应的sal（用if-elsif实现，不要改动到基本表emp，创建一个与emp表一模一样的表emp1）。(存储过程)
/*
    Job       raise
    clerk     +500
    salesman    +1000
    analyst    +1500
    otherwise   +3000
*/
drop table emp1;
create table emp1 as select * from emp;
create or replace procedure obj6_6(foo varchar2) as
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
    exception
        when no_data_found then dbms_output.put_line('雇员不存在');
        when too_many_rows then dbms_output.put_line('多人同名，请尝试输入雇员号');
end;

--7、传送参数部门编号，按照下列加工资比例给该部门的雇员加工资(用CASE实现，修改emp1表的数据) (存储过程)
/*
    deptno  raise(%)
    10      8%
    20      10%
    30      20%
    40      20%
    加薪比例以现有的sal为标准。
*/
create or replace procedure obj6_7(vdeptno emp1.deptno%type) as
    vename emp1.ename%type;
    vempno emp1.empno%type;
    vsal emp1.sal%type;
    no_such_dept exception;
begin
    case vdeptno
        when 10 then update emp1 set sal = sal * 1.08 where deptno = vdeptno;
        when 20 then update emp1 set sal = sal * 1.1 where deptno = vdeptno;
        when 30 then update emp1 set sal = sal * 1.2 where deptno = vdeptno;
        when 40 then update emp1 set sal = sal * 1.2 where deptno = vdeptno;
        else raise no_such_dept;
    end case;
    dbms_output.put_line('更新'||vdeptno||'号部门的薪水');
    exception
        when no_such_dept then dbms_output.put_line('没有这个部门，请检查你的输入');
end;
execute obj6_7(99);

--8、在学生表中增加一列，用来记录学生的密码，写一个PL/SQL程序，模拟登录的过程。输入学号和密码，判断是否正确，对于登录成功和失败分别给出提示信息。(存储过程)
alter table "学生" drop column "密码";
alter table "学生" add "密码" varchar2(16) default '123456';
create or replace procedure obj6_8(input_number "学生"."学号"%type, input_passwd "学生"."密码"%type) as
    vnumber "学生"."学号"%type;
    vpasswd "学生"."密码"%type;
    vname "学生"."姓名"%type;
    vstatus "学生"."状态"%type;
    not_register exception;
begin
    select "状态" into vstatus from "学生" where "学号" = input_number;
    if vstatus is null then raise not_register;
    end if;
    select "密码", "姓名" into vpasswd, vname from "学生" where "学号" = input_number;
    if vpasswd = input_passwd then dbms_output.put_line('登录成功，'||vname);
    else dbms_output.put_line('登录失败，请重试');
    end if;
    exception
        when no_data_found then dbms_output.put_line('学号不存在');
        when not_register then dbms_output.put_line('该学号没有注册，请先注册');
end;
execute obj6_8('S777', '123456');
execute obj6_8('S105', '123456');

--9、编写一个向学费标准表添加记录的过程。
create or replace procedure obj6_9(input_year "学费标准表"."学年"%type,
                                   input_major "学费标准表"."专业"%type,
                                   input_tuition "学费标准表"."学费"%type) as
    vtuition "学费标准表"."学费"%type;
begin
    select "学费" into vtuition
        from "学费标准表"
        where "学年" = input_year and "专业" = input_major;
    if vtuition is not null then
        dbms_output.put_line('已有该学年该专业的记录');
    end if;
    exception
        when no_data_found then
            insert into "学费标准表" values(input_year, input_major, input_tuition);
end;
execute obj6_9('2018', '计算机科学与技术', 7777);

--10、编写一个学生注册的过程，注册日期默认为当天，以学号为参数。
create or replace procedure obj6_10(input_number "学生"."学号"%type,
                                    input_passwd "学生"."密码"%type default null) as
    vnumber "学生"."学号"%type;
    vstatus "学生"."状态"%type;
    vmajor "学生"."专业"%type;
    vtuition "收费表"."应交学费"%type;
    passwd_is_null exception;
begin
    if input_passwd is null then raise passwd_is_null;
    end if;
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
    exception
        when no_data_found then dbms_output.put_line('没有该学号的学生，请检查你的学号');
        when passwd_is_null then dbms_output.put_line('密码不能为空');
end;
execute obj6_10('S101', '654321');
execute obj6_10('S102');
execute obj6_10('S103', '888888');
execute obj6_10('S777', '654321');

--11、编写一个收学费的过程，收费日期默认为当天，以学年、 学号、学费为参数。
create or replace procedure obj6_11(input_number "学生"."学号"%type,
                                    paid "收费明细表"."学费"%type,
                                    input_year "收费表"."学年"%type default extract(year from sysdate)) as
    vno "收费明细表"."编号"%type;
    check_number int;
    check_paid "收费表"."应交学费"%type;
    check_year int;
    input_number_err exception;
    paid_err exception;
    input_year_err exception;
    paid_not_enough exception;
begin
    select count(*) into check_number
        from "收费表" where "学号" = input_number;
    if check_number = 0 then raise input_number_err; end if;
    select count(*) into check_year
        from "收费表" where "学号" = input_number and "学年" = input_year;
    if check_year = 0 then raise input_year_err; end if;
    select ("应交学费"-"已交学费"-paid) into check_paid
        from "收费表" where "学号" = input_number and "学年" = input_year;
    if check_paid < 0 then raise paid_err; end if;
    select max("编号")+1 into vno from "收费明细表";
    insert into "收费明细表" values(vno, input_year, input_number, paid, sysdate);
    update "收费表"
        set "已交学费" = "已交学费" + paid
        where "学年" = input_year and "学号" = input_number;
    dbms_output.put_line('缴费成功');
    select ("应交学费"-"已交学费") into check_paid
        from "收费表" where "学号" = input_number and "学年" = input_year;
    if check_paid > 0 then raise paid_not_enough; end if;
    exception
        when input_number_err then dbms_output.put_line('没有该学号学生的收费信息，请尝试注册学号');
        when input_year_err then dbms_output.put_line('该学生没有'||input_year||'学年的欠费信息，请检查输入学年');
        when paid_err then dbms_output.put_line('缴费金额有误');
        when paid_not_enough then dbms_output.put_line('但该学生'||input_year||'学年的缴费仍然处于欠费状态');
end;
execute obj6_11('S999', 777);
execute obj6_11('S103', 7777);
execute obj6_11('S103', 7777, 2017);
delete from "收费表" where "学号" = 'S103' and "学年" = 2018;

--12、编写一个过程，输出指定学年的欠费情况（含欠费人数、欠费总金额）。
create or replace procedure obj6_12(input_year "收费表"."学年"%type) as
    vnumber int;
    vmoney_sum "收费表"."已交学费"%type;
    vyear "收费表"."学年"%type;
begin
    select "学年" into vyear from "收费表" where "学年" = input_year;
    select count(*), sum("应交学费"-"已交学费") into vnumber, vmoney_sum
        from "收费表"
        where "学年" = input_year and "应交学费" > "已交学费";
    dbms_output.put_line(input_year||'年，欠费人数为：'||vnumber||'欠费总金额为：'||vmoney_sum);
    exception
        when no_data_found then dbms_output.put_line('没有该学年的欠费情况');
end;
execute obj6_12(9999);
