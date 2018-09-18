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
select trim(' ab cd e ') from dual;
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

select months_between('01-1月-03', '14-3月-03') from dual;
select months_between('14-3月-03', '01-1月-03') from dual;
select months_between('03-1月-03', '14-1月-03') from dual;

select next_day('01-8月-03', '星期二') from dual;
select next_day('06-8月-03', '星期三') from dual;
select next_day('06-8月-03', '星期日') from dual;
--日期四舍五入
select round(sysdate, 'year') from dual;
select round(sysdate, 'month') from dual;
select round(sysdate, 'day') from dual;

select sysdate from dual;
select next_day(sysdate, '星期三') from dual;
select months_between(sysdate, '14-1月-03') from dual;
--日期截取
select trunc(sysdate, 'YYYY') from dual;
select trunc(sysdate, 'MM') from dual;
select trunc(sysdate, 'D') from dual;
--General Comparison Functions
select greatest() from dual;
select least() from dual;
--Conversion Functions
select to_char() from dual;
select to_char() from dual;
select to_date() from dual;
select to_number() from dual;
--Encoding and Decoding Functions
select decode(sign(sal-1500), 1, sal+500, -1, sal+100, sal) from scott.emp;
select decode(mod(sal,1000), 0, 'level_0', 1, 'level_1', 2, 'level_2', 'level_3') from scott.emp;
select decode(sign(lpad(ename,1)-'z'), 1, sal+500, -1, sal+100, sal) from scott.emp;
--NULL-Related Functions
select coalesce() from dual;
select nullif() from dual;
select nvl() from dual;
select nvl2() from dual;
--Environment and Identifier Functions
select uid() from dual;
select user() from dual;
--Aggregate Functions
select avg() from dual;
select count() from dual;
select dense_rank() from dual;
select max() from dual;
select min() from dual;
select rank() from dual;
select sum() from dual;
--Analytic Funcions
select avg() from dual;
select count() from dual;
select dense_rank() from dual;
select max() from dual;
select min() from dual;
select rank() from dual;
select sum() from dual;
select row_number() from dual;


--2

select "注册日期", count("姓名")
from "学生"
group by "注册日期";

--3

--4
select "姓名", sum(case when "科目" = "语文" then "成绩" else 0 end) "语文",
               sum(case when "科目" = "数学" then "成绩" else 0 end) "数学",
               sum(case when "科目" = "英语" then "成绩" else 0 end) "英语",
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
create view obj2_2("学号", "名次") as
    select "学号", rank() over(order by nvl("分数", 0) desc) as srank
    from "成绩"
    where "课程号" = 'C13'
    order by srank, "学号";

--按平均分数对课程连续排名(可以并列)，显示名次、课程号与平均分数(保留2位小数)，按名次、课程号升序排列
drop view obj2_3;
create view obj2_3("名次", "课程号", "平均分数") as
    select rank() over(order by avg("分数")) as srank, "课程号", round(avg("分数"), 2)
    from "成绩"
    group by "课程号"
    order by srank, "课程号";

-- 查询每门课程的课程号，以及每门课程考试成绩第一名（可以并列）的学生的姓名，按课程号与姓名升序排列
drop view obj2_4;
create view obj2_4("课程", "姓名") as
    select "课程号", "姓名"
    from "成绩" natural join "学生" a
    where "分数" = (select max("分数")
                    from "成绩" b
                    where a."课程号" = b."课程号")
    order by "课程号", "姓名";


--列出emp表中工资在3500到5000之间的员工的姓名，但只取姓名的前5个字符，不足5个则以*补足，按姓名升序排列
