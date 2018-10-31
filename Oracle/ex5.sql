set serveroutput on;
-- 1．用显式游标输出emp表的所有信息。
create or replace procedure obj5_1 as
    cursor c_emp is
        select * from emp;
        c_row c_emp%rowtype;
begin
    dbms_output.put_line('empno; ename; job; mgr; hiredate; sal; comm; deptno');
    open c_emp;
    loop
        fetch c_emp into c_row;
        exit when c_emp%notfound;
        dbms_output.put_line(c_row.empno||'; '||c_row.ename||'; '||c_row.job||'; '||c_row.mgr||'; '
                             ||c_row.hiredate||'; '||c_row.sal||'; '||c_row.comm||'; '||c_row.deptno);
    end loop;
    close c_emp;
end;
execute obj5_1;

-- 2．用隐式游标输出dept表的所有信息。
create or replace procedure obj5_2 as
begin
    dbms_output.put_line('deptno; dname; loc');
    for c_dept in (select * from dept) loop
        dbms_output.put_line(c_dept.deptno||'; '||c_dept.dname||'; '||c_dept.loc);
    end loop;
end;
execute obj5_2;

-- 3．  利用游标，修改员工工资。根据job不同，为员工增加相应的sal：
/*
    Job         raise
    clerk      +500
    salesman   +1000
    analyst    +1500
    otherwise  +2000
*/
create or replace procedure obj5_3 as
    cursor c_emp is
        select * from emp for update of sal;
    c_row c_emp%rowtype;
    csal emp.sal%type;
begin
    for c_row in c_emp loop
        dbms_output.put_line('更新工资');
        if c_row.job = 'CLERK' then csal := c_row.sal + 500;
        elsif c_row.job = 'SALESMAN' then csal := c_row.sal + 1000;
        elsif c_row.job = 'ANALYST' then csal := c_row.sal + 1500;
        else csal := c_row.sal + 2000;
        end if;
        update emp set sal = csal where current of c_emp;
    end loop;
end;
execute obj5_3;

-- 4．用显式游标输出指定学年欠费的学生名单（含姓名、专业、欠费金额）。
create or replace procedure obj5_4(input_year "收费表"."学年"%type) as
    cursor c_list is
        select * from "收费表" where "学年" = input_year and "应交学费" > "已交学费";
    c_row c_list%rowtype;
    vname "学生"."姓名"%type;
    vmajor "学生"."专业"%type;
begin
    for c_row in c_list loop
        select "姓名", "专业" into vname, vmajor
            from "学生"
            where "学号" = c_row."学号";
        dbms_output.put_line(vname||'; '||vmajor||'; '||'欠费'||(c_row."应交学费"-c_row."已交学费")||'元');
    end loop;
end;
execute obj5_4(2018);
execute obj5_4(2017);

commit;
