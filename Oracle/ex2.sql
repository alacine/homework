--1
--Numeric Functions
--绝对值
select abs(-9) from dual;
select abs(9) from dual;
select abs(-9.5) from dual;
--向上取整
select ceil(9.5) from dual;
select ceil(-9.5) from dual;
select ceil(10.1) from dual;
--自然对数
select exp(0) from dual;
select exp(1) from dual;
select exp(10) from dual;
--向下取整
select floor(9.5) from dual;
select floor(-9.5) from dual;
select floor(9.1) from dual;
--对数函数
select log(2, 8) from dual;
select log(10, 1000) from dual;
select log(3, 27777777) from dual;
--取模
select mod(12, 5) from dual;
select mod(-12, 5) from dual;
select mod(12, -5) from dual;
--幂运算
select power(2, 10) from dual;
select power(4, 10) from dual;
select power(10, -4) from dual;
--四舍五入
select round(123.456, 0) from dual;
select round(123.456, 1) from dual;
select round(-123.456, 2) from dual;
--判断符号函数
select sign(10) from dual;
select sign(-10) from dual;
select sign(0) from dual;
--开方函数
select sqrt(4) from dual;
select sqrt(100) from dual;
select sqrt(37.32) from dual;
--截取小数后位数
select trunc(123.98) from dual;
select trunc(123.98, 2) from dual;
select trunc(123.98, -1) from dual;

--Character Functions Returning Character Values
--ascii码转字符
select chr(82) from dual;
select chr(65) from dual;
select chr(100) from dual;
--转换为小写
select lower('A') from dual;
select lower('B') from dual;
select lower('C') from dual;
--截取指定字符串长度，不够左侧填充指定字符，默认为空格
select lpad('oracle', 3) from dual;
select lpad('oracle', 3, 'a') from dual;
select lpad('oracle', 8, 'X') from dual;
--去掉字符串左侧指定的字符集
select ltrim('xxxabcxxx', 'abc') from dual;
select ltrim('abcxxx', 'abc') from dual;
select ltrim('bacxxx', 'abc') from dual;
--替换指定字符串
select replace('accd', 'cd', 'ef') from dual;
select replace('xxxabcxxx', 'abc', 'xx') from dual;
select replace('accd', 'cd', '') from dual;
--截取指定字符串长度，不够右侧填充指定字符，默认为空格
select rpad('oracle', 3) from dual;
select rpad('oracle', 3, 'a') from dual;
select rpad('oracle', 8, 'X') from dual;
--去掉字符串右侧指定的字符集
select rtrim('xxxabcxxx', 'abc') from dual;
select rtrim('xxxabc', 'abc') from dual;
select rtrim('xxxcba', 'abc') from dual;
--截取指定位置的字串
select substr('abcdefg', 3, 4) from dual;
select substr('abcdefg', -5, 4) from dual;
select substr('abcdefg', 5, 4.2) from dual;
--替换指定字符，前后一一对应，不一样长用空补齐
select translate('accd', 'cd', 'ef') from dual;
select translate('accd', 'cd', 'e') from dual;
select translate('accd', 'cd', 'efg') from dual;
--去除指定字符的前后的指定字符，默认为空格
select trim(' ab cd e ') from dual;
select trim(leading 'a' from 'ab cd a') from dual;
select trim(trailing 'a' from 'ab cd a'), trim(both 'a' from 'ab cd a') from dual;
--转换为大写
select upper('a') from dual;
select upper('b') from dual;
select upper('c') from dual;
--Character Functions Returning Number Values
--字符转ascii
select ascii('a') from dual;
select ascii('r') from dual;
select ascii('A') from dual;
--从指定位置开始搜索指定的第几次出现的指定字符串的位置
select instr('123ab6789ab', 'ab', 3, 2) from dual;
select instr('123ab6789ab', 'ab', -3, 2) from dual;
select instr('123ab6789ab', 'ab', 5, 2) from dual;
--字符串长度
select length('candide') from dual;
select length('12345') from dual;
select length('哈哈') from dual;
--Datatime Functions
--月份加
select add_months('01-8月-03', 3) from dual;
select add_months('01-8月-03', -3) from dual;
select add_months('31-8月-03', 6) from dual;
--从指定日期中提取指定的年月日时分秒等
select extract(year from date '2003-08-22') from dual;
select extract(mouth from date '2003-08-22') from dual;
select extract(day from date '2003-08-22') from dual;
--指定日期月份的最后一天
select last_day('15-3月-03') from dual;
select last_day('03-2月-03') from dual;
select last_day('03-2月-04') from dual;
--两个日期之间相差的时间(以月为单位)
select months_between('01-1月-03', '14-3月-03') from dual;
select months_between('14-3月-03', '01-1月-03') from dual;
select months_between('03-1月-03', '14-1月-03') from dual;
--下一个星期几的日期
select next_day('01-8月-03', '星期二') from dual;
select next_day('06-8月-03', '星期三') from dual;
select next_day('06-8月-03', '星期日') from dual;
--日期四舍五入
select round(sysdate, 'year') from dual;
select round(sysdate, 'month') from dual;
select round(sysdate, 'day') from dual;
--返回当前系统日期
select sysdate from dual;
select next_day(sysdate, '星期三') from dual;
select months_between(sysdate, '14-1月-03') from dual;
--日期截取
select trunc(sysdate, 'YYYY') from dual;
select trunc(sysdate, 'MM') from dual;
select trunc(sysdate, 'D') from dual;
--General Comparison Functions
--最大值
select greatest(5, 2, 4, 9) from dual;
select greatest('15', '2', '4', '9') from dual;
select greatest('apples', 'applas', 'applis') from dual;
--最小值
select least(5, 2, 4, 9) from dual;
select least('15', '2', '4', '9') from dual;
select least('apples', 'applas', 'applis') from dual;
--Conversion Functions
--把数字或日期安装某种格式转变成字符串
select to_char(sysdate, 'yyyy-dd-mm') from dual;
select to_char(1210.72, '9999.9') from dual;
select to_char(hiredate, 'yy/dd/mm') from emp;
--把字符串转变成日期
select to_date('2018/9/21', 'yyyy/mm/dd') from dual;
select to_date('070903', 'mmddyy') from dual;
select to_date('20180921', 'yyyymmdd') from dual;
--把字符串转变成数字
select to_number('1210.12') from dual;
select to_number('1210.12', '9999.99') from dual;
select to_number('1210', '9999') from dual;
--Encoding and Decoding Functions
--把表达式的值与后面的值依次比较，当匹配到相等的值时，返回对应的值，类似if-elseif-...-else
select decode(sign(sal-1500), 1, sal+500, -1, sal+100, sal) from emp;
select decode(mod(sal,1000), 0, 'level_0', 1, 'level_1', 2, 'level_2', 'level_3') from emp;
select decode(deptno, 10, 'A', 20, 'R', 30, 'S', 40, 'O', 'none') from dept;
--NULL-Related Functions
--返回第一个非空的表达式，如果全是空值则返回空值(至少有两个表达式)
select coalesce(1) from dual;
select coalesce(1, null) from dual;
select coalesce(null, 1) from dual;
--判断两个表达式是否相等，是返回null，否返回第一个表达式的值
select nullif(12, 12) from dual;
select nullif(12, 13) from dual;
select nullif('apples', 'applas') from dual;
--当查询的某个值为空值时，用指定的值代替，并不会更改表
select ename, nvl(comm, 0) from emp where job = 'CLERK';
select ename, nvl(comm, 0) from emp where comm is null;
select job, nvl(mgr, 1000000) from emp;
--查询的某个值为非空时，用一个值代替，空时也用一个值代替，同样不会更改表
select ename, nvl2(comm, 1, 0) from emp where job = 'CLERK';
select ename, nvl2(comm, 1, 0) from emp where comm is null;
select job, nvl2(mgr, 1, 0) from emp;
--Environment and Identifier Functions
--返回当前登录用户的UID
select uid from dual;
select username from all_users where user_id = uid;
select username from all_users where user_id < uid;
--返回当前登录用户
select user from dual;
select user_id from all_users where username = user;
show user;
--Aggregate Functions
--求平均值默认不计算空值的行
select avg(sal) from emp;
select avg(mgr) from emp;
select avg(nvl(mgr, 0)) from emp;
--返回表达式的数量，不计算空值的行
select count(1) from dual;
select count(ename) from emp;
select count(mgr) from emp;
--连续式排名函数
select dense_rank(800) within group(order by sal) from emp;
select dense_rank(10000) within group(order by mgr) from emp;
select dense_rank(7777, 1200) within group(order by mgr, sal) from emp;
--最大值
select max(sal) from emp;
select max(ename) from emp;
select job, max(sal) from emp group by job;
--最小值
select min(sal) from emp;
select min(ename) from emp;
select job, min(sal) from emp group by job;
--跳跃式排名函数
select rank(800) within group(order by sal) from emp;
select rank(10000) within group(order by mgr) from emp;
select rank(7777, 1200) within group(order by mgr, sal) from emp;
--求和
select sum(sal) from emp;
select sum(mgr) from emp;
select job, sum(sal) from emp group by job;
--Analytic Funcions
select distinct job, avg(sal) over(partition by job) from emp;
select distinct deptno, avg(sal) over(partition by deptno) from emp;
select distinct job, avg(mgr) over(partition by job) from emp;

select distinct job, count(empno) over(partition by job) from emp;
select distinct deptno, count(empno) over(partition by deptno) from emp;
select distinct deptno, count(job) over(partition by deptno) from emp;

select ename, dense_rank() over(order by sal) from emp;
select ename, dense_rank() over(order by mgr)from emp;
select ename, dense_rank() over(order by (nvl(mgr, 0)) desc) from emp;

select distinct job, max(sal) over(partition by job) from emp;
select distinct job, max(mgr) over(partition by job) from emp;
select distinct deptno, max(sal) over(partition by deptno) from emp;

select distinct job, min(sal) over(partition by job) from emp;
select distinct job, min(mgr) over(partition by job) from emp;
select distinct deptno, min(sal) over(partition by deptno) from emp;

select ename, rank() over(order by sal) from emp;
select ename, rank() over(order by mgr)from emp;
select ename, rank() over(order by (nvl(mgr, 0)) desc) from emp;

select distinct job, sum(sal) over(partition by job) from emp;
select distinct deptno, sum(sal) over(partition by deptno) from emp;
select distinct job, sum(mgr) over(partition by job) from emp;
--为每一行分配一个唯一的数字
select ename, row_number() over(order by sal) as rn from emp;
select ename, job, row_number() over(partition by job order by sal) as rn from emp;
select ename, comm, row_number() over(partition by comm order by sal) as rn from emp;

--2
--按天统计学生注册人数
select "注册日期", count("姓名")
from "学生"
group by "注册日期";

--3
--将重修成绩表的记录按学校规定合并进成绩表
--学校规定：没有参加该课程期末考试的学生，不能参加该课程的重修考试，即使考了也不登成绩
--创建重修成绩表sc_temp(sno, score) 并输入重修考试成绩
merge into "成绩"
using sc_temp
on ("成绩"."学号"=sc_temp."学号" and "课程号"='C25' and "成绩"."分数" is not null)
when matched then
    update set "成绩"."分数" = sc_temp."分数";

--4
select "姓名", sum(case when "科目" = "语文" then "成绩" else 0 end) "语文",
               sum(case when "科目" = "数学" then "成绩" else 0 end) "数学",
               sum(case when "科目" = "英语" then "成绩" else 0 end) "英语"
from "表格"
group by "姓名";

--5
--创建视图，视图名依次命名为obj2_1、obj2_2、… 、obj2_5
--查询每门课程考试成绩的第一名(可以并列)的学生的学号，按学号升序排列
drop view obj2_1;
create view obj2_1("学号") as
    select "学号"
    from "成绩" a
    where "分数" = (select max("分数")
                    from "成绩" b
                    where a."课程号" = b."课程号")
    order by "学号";

--对选修C13课程的学生，按分数跳跃式排名(可以并列)，显示名次与学号，按名次、学号升序排列
drop view obj2_2;
create view obj2_2("名次", "学号") as
    select rank() over(order by nvl("分数", 0) desc) as srank, "学号"
    from "成绩"
    where "课程号" = 'C13'
    order by srank, "学号";

--按平均分数对课程连续排名(可以并列)，显示名次、课程号与平均分数(保留2位小数)，按名次、课程号升序排列
drop view obj2_3;
create view obj2_3("名次", "课程号", "平均分数") as
    select dense_rank() over(order by avg("分数") desc) as srank, "课程号", round(avg("分数"), 2)
    from "成绩"
    group by "课程号"
    order by srank, "课程号";

-- 查询每门课程的课程号，以及每门课程考试成绩第一名（可以并列）的学生的姓名，按课程号与姓名升序排列
drop view obj2_4;
create view obj2_4("课程号", "姓名") as
    select "课程号", "姓名"
    from "成绩" a natural join "学生" b
    where "分数" = (select max("分数")
                    from "成绩" c
                    where a."课程号" = c."课程号")
    order by "课程号", "姓名";

--列出emp表中工资在3500到5000之间的员工的姓名，但只取姓名的前5个字符，不足5个则以*补足，按姓名升序排列
drop view obj2_5;
create view obj2_5("姓名") as
    select rpad(ename, 5, '*')
    from emp
    where sal >= 3500 and sal <= 5000
    order by ename;

commit;
