set serveroutput on;
-- 有针对性地给“实验四”上机内容中的过程与函数增加异常处理部分，保留原来的过程与函数，修改后的过程与函数另外保存，如obj4_1另存为obj6_1，以此类推。
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

--10、编写一个学生注册的过程，注册日期默认为当天，以学号为参数。
create or replace procedure obj6_10(input_number "学生"."学号"%type,
                                    input_passwd "学生"."密码"%type default '123456') as
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
    exception
        when no_data_found then dbms_output.put_line('没有该学号的学生，请检查你的学号');
end;
execute obj6_10('S101', '654321');
execute obj6_10('S102');
execute obj6_10('S103', '888888');
execute obj6_10('S777', '654321');

