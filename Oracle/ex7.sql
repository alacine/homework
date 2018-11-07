set serveroutput on;
-- 1. 在A_DB模式中有一个名为tan1(a)的表，表中有若干个整数（不要管是否有重复）。
-- 请编写一个名为obj7_1 的存储函数（无参数），统计该表中有多少个数是素数，并作为函数返回值返回。
create or replace function obj7_1 return int as
    cnt int;
    k int;
    i int;
begin
    cnt := 0;
    for c_tan in (select * from a_db.tan1) loop
        if c_tan.a = 2 then cnt := cnt + 1;
        elsif c_tan.a < 2 or mod(c_tan.a, 2) = 0 then cnt := cnt;
        else
            k := sqrt(c_tan.a);
            i := 3;
            while mod(c_tan.a, i) != 0 loop
                if i > k then exit;
                end if;
                i := i + 1;
            end loop;
            if i > k then cnt := cnt + 1;
            end if;
        end if;
    end loop;
    return cnt;
end;
select obj7_1() from dual;

-- 2. 在A_DB模式中有一个名为tan3(a)的表，表中有若干个整数（不要管是否有重复）,假设这些数表示年份。
-- 请编写一个名为obj7_2的存储函数（无参数），统计该表中有多少个年份是闰年，并作为函数返回值返回。
-- 说明：闰年的计算方法：被400整除，或被4整除而不能被100整除的年份为闰年。
create or replace function obj7_2 return int as
    cnt int;
begin
    cnt := 0;
    for x in (select a from a_db.tan3) loop
        if mod(x.a, 400) = 0 then cnt := cnt + 1;
        elsif mod(x.a, 100) = 0 then cnt := cnt;
        elsif mod(x.a, 4) = 0 then cnt := cnt + 1;
        else cnt := cnt;
        end if;
    end loop;
    return cnt;
end;

select obj7_2() from dual;

-- 3. 在A_DB模式中有一个名为tanbn1(a,b)的表。
-- 请编写一个名为obj7_3的存储函数（无参数），对于表中所有三位数abc,将个位与百位数字交换，得到cba，求这些cba的和，并作为函数返回值返回。
create or replace function obj7_3 return int as
    sum_cba int;
    digit_a int;
    digit_b int;
    digit_c int;
begin
    sum_cba := 0;
    for x in (select * from a_db.tanbn1) loop
        if x.a/100 > 1 and x.a/100 <10 then
            digit_c := mod(x.a, 10);
            digit_b := mod((x.a - digit_c)/10, 10);
            digit_a := floor(x.a/100);
            sum_cba := sum_cba + digit_a + digit_b*10 + digit_c*100;
            -- dbms_output.put_line(x.a||' '||digit_c||' '||digit_b||' '||digit_a);
        end if;
        if x.b/100 > 1 and x.b/100 <10 then
            digit_c := mod(x.b, 10);
            digit_b := mod((x.b - digit_c)/10, 10);
            digit_a := floor(x.b/100);
            sum_cba := sum_cba + digit_a + digit_b*10 + digit_c*100;
            -- dbms_output.put_line(x.b||' '||digit_c||' '||digit_b||' '||digit_a);
        end if;
    end loop;
    return sum_cba;
end;
select obj7_3() from dual;

-- 4. 对称字符串。
-- 在A_DB模式中有一个名为tac1(a)的表，表中有若干个字符串（不要管是否有重复）。
-- 请编写一个名为obj7_4的存储函数（无参数），统计该表中有多少对称字符串，并作为函数返回值返回。
-- 说明：对称字符串是正读倒读一样的字符串。如：“abcdcba”、“6”和"123321"等前后对称，是对称字符串；而“12332”不是。
create or replace function obj7_4 return int as
    ans int;
    i int;
    j int;
begin
    ans := 0;
    for x in (select a from a_db.tac1) loop
        i := 1;
        j := length(x.a);
        while i < j and substr(x.a, i, 1) = substr(x.a, j, 1) loop
            -- dbms_output.put_line(x.a);
            -- dbms_output.put_line(substr(x.a, i, 1)||substr(x.a, j, 1));
            i := i + 1;
            j := j - 1;
        end loop;
        if i < j then ans := ans;
        else ans := ans + 1;
        end if;
    end loop;
    return ans;
end;
select obj7_4() from dual;

-- 5. 编写一个名为obj7_5的存储过程，判断正整数n是否是若干个连续的正整数之和。如是，则输出这些连续的正整数；如果有多串连续的正整数，则输出最长的那串连续的正整数。n是过程的参数。如：15=1+2+3+4+5，15=7+8，则输出1,2,3,4,5。
create or replace procedure obj7_5(n int) as
    delta number;
    flag int;
    head int;
    tail int;
begin
    flag := 0;
    for i in 1..floor(n/2) loop
        delta := sqrt((2*i-1)*(2*i-1)+8*n);
        if delta - trunc(delta) = 0 then flag := 1;
            head := i;
            tail := head + (-2*i + 1 + delta) / 2 - 1;
            exit;
        end if;
    end loop;
    if flag = 1 then 
        dbms_output.put(head);
        for i in head+1..tail loop
            dbms_output.put(', '||i);
        end loop;
        dbms_output.new_line();
    else dbms_output.put_line('无法分解');
    end if;
end;
execute obj7_5(15);
execute obj7_5(100);

-- 6. 编写一个名为obj7_6的存储函数，判断正整数n是否是若干个连续的正整数之和。如是，则返回1，否则返回0。n是函数的参数。
create or replace function obj7_6(n int) return int as
    delta number;
    flag int;
begin
    flag := 0;
    for i in 1..floor(n/2) loop
        delta := sqrt((2*i-1)*(2*i-1)+8*n);
        if delta - trunc(delta) = 0 then flag := 1;
            exit;
        end if;
    end loop;
    return flag;
end;
select obj7_6(15) from dual;
select obj7_6(8) from dual;
 
-- 7. 在A_DB模式中有一个名为tan2(a)的表，表中有若干个整数（不要管是否有重复）。
-- 请编写一个名为obj7_7的存储函数（无参数），统计该表中有多少个数是若干个连续的正整数之和，并作为函数返回值返回。要求调用第6题编写的存储函数f6(n)。
create or replace function obj7_7 return int as
    cnt int;
begin
    cnt := 0;
    for x in (select a from a_db.tan2) loop
        cnt := cnt + obj7_6(x.a);
    end loop;
    return cnt;
end;
select obj7_7() from dual;

-- 8. 对于emp表，编写一个名为obj7_8的程序包，包中重载两个过程，一个以员工号为参数，输出该员工信息；另一个以员工名为参数，输出员工信息。包中另一个过程利用两个重载过程分别查询员工号为7902、7934、以及员工名为SMITH、FORD的员工信息。
create or replace package obj7_8 as
    procedure act(vempno emp.empno%type);
    procedure act(vename emp.ename%type);
    procedure act2;
end;

create or replace package body obj7_8 as
    procedure act(vempno emp.empno%type) as
        vemp emp%rowtype;
    begin
        select * into vemp
            from emp
            where vempno=emp.empno;
            dbms_output.put_line('empno: '||vemp.empno||' ename: '||vemp.ename||' job: '||vemp.job||' mgr: '||vemp.mgr||
                                 ' hiredate: '||vemp.hiredate||' sal: '||vemp.sal||' comm: '||nvl(vemp.comm, 0)||' deptno: '||vemp.deptno);
    end act;
    procedure act(vename emp.ename%type) as
        vemp emp%rowtype;
    begin
        select * into vemp
            from emp
            where vename=emp.ename;
            dbms_output.put_line('empno: '||vemp.empno||' ename: '||vemp.ename||' job: '||vemp.job||' mgr: '||vemp.mgr||
                                 ' hiredate: '||vemp.hiredate||' sal: '||vemp.sal||' comm: '||nvl(vemp.comm, 0)||' deptno: '||vemp.deptno);
    end act;
    procedure act2 as
    begin
        act(7902);
        act(7934);
        act('SMITH');
        act('FORD');
    end act2;
end;
execute obj7_8.act(7902);
execute obj7_8.act('SMITH');
execute obj7_8.act2;

-- 9.  在示例“5. 二进制转换为十进制”的bit_to_number函数中特意用到了动态SQL与BIN_TO_NUM函数。请换一种方式实现相同的功能，该存储函数命名为obj7_9。
create or replace function obj7_9(bit varchar2) return int as
    ans int;
    len int;
begin
    ans := 0;
    len := length(bit);
    for i in 1..len loop
        ans := ans + power(2, len - i) * to_number(substr(bit, i, 1));
    end loop;
    return ans;
end;
select obj7_9('1001001') from dual;
select obj7_9('1000001') from dual;

commit;
