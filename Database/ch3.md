## 第三章习题

### 3.1
**使用大学模式，用 SQL 写出如下查询数据。**

a. 找出 Comp.Sci. 系开设的具有3个学分的课程名称。
```sql
select title
from course
where dept_name = 'Comp. Sci.' and credits = 3;
```

b. 找出名叫 Einstein 的教师所教的学生的标识，保证结果中没有重复。
```sql
select distinct student.ID, student.name
from instructor, teaches, takes, student
where instructor.name = 'Einstein'
    and instructor.ID = teaches.ID
    and teaches.course_id = takes.course_id;
```

c. 找出教师的最高工资。
```sql
select max(salary)
from instructor;
```

d. 找出工资最高的所有教师（可能有不止一位教师具有相同工资）。
```sql
select ID, name
from instructor
--利用上一题的搜索结果
where salary = (select max(salary)
                from instructor);
```
e. 找出2009年秋季开设的每个课程段的选课人数。
```sql
select course_id, count(ID)
from takes
where semester = 'Fall' and year = 2009
group by course_id;
```
f. 从2009年秋季开设的所有课程中，找出最多的选课人数。
```sql
select max(a)
--利用e题结果
from (select course_id, count(ID) a
      from takes
      where semester = 'Fall' and year = 2009
      group by course_id);
```
g. 找出在2009年秋季拥有最多选课人数的课程段。
```sql
select course_id, a
--在e题结果的表中查找
from (select course_id, count(ID) a
      from takes
      where semester = 'Fall' and year = 2009
      group by course_id)
where a = (select max(a)
           from (select course_id, count(ID) a
           from takes
           where semester = 'Fall' and year = 2009
           group by course_id));
```
### 3.2 
**假设给你一个关系 grade_points(grad_e, points)，它提供从 takes 关系中用字母的成绩等级到数字表示的得分之间的转换。例如，“A”等级可指定为对应于4分，“A-”对应于3.7分，“B+”对应于3.3分，“B”对应于3分，等等。学生在某门课程（课程段）上所获得的等级分值被定义为该课程段的学分乘以该生得到的成绩等级所对应的数字表示的得分。**

给定上述关系和我们的大学模式，用 SQL 写出下面的每个查询。为简单起见，可以假设没有任何 takes 元组在 grade 上取 null 值。

a. 根据 ID 为12345的学生所选修的所有课程，找出该生所获得的等级分值的总和。
```sql
select sum(credits * points)
from takes natural join course natural join grade_points
where ID = 12345;
```
b. 找出上述学生等级分值的平均值（GPA），即用等级分值的总和除以相关课程学分的总和。
```sql
select sum(credits * points)/sum(credits) as GPA
from takes natural join course natural join grade_points
where ID = 12345;
```
c. 找出每个学生的 ID 和等级分值的平均值。
```sql
select ID, sum(credits * points)/sum(credits) as GPA
from takes natural join course natural join grade_points
group by ID;
```

### 3.3
**使用大学模式，用 SQL 写出如下插入、删除和更新语句**

a. 给 Comp. Sci. 系的每位教师涨10%工资。
```sql
update instructor
set salary = salary * 1.1
where dept_name = 'Comp. Sci';
```
b. 删除所有未开设过（即没有出现在 section 关系中）的课程。
```sql
delete from course
where course_id not in (select course_id
                        from section);
```
c. 把每个在 tot_cred 属性上取值找过100的学生作为同系的教师插入，工资为10000美元。
```sql
insert into instructor(ID, name, dept_name, salary)
      select ID, name, dept_name, 10000
      from student
      where tot_cred > 100;
```
### 3.4
**考虑图3-18中的保险公司数据库，其中加入下划线的是主码。为这个关系数据库构造出如下 SQL 查询：**

> person (**driver_id**, name, address)\
> car (**license, model**, year)\
> accident (**report_number**, date, location)\
> owns (**driver_id**, license)\
> participated (**report_number**, license, driver_id, damage_amount)\
> 图3-18  保险公司数据库(使用加粗代替下划线)

a. 找出2009年其中车辆出过交通事故的人员总数。
```sql
select count(distinct driver_id)
from accident natural join owns natural join participated
where date between date'2009-1-1' and date'2009-12-31';
```
b. 向数据库中增加一个新的事故，对每个必须的属性可以设定任意值。
```sql
insert into accident
      values(1234, '2018-5-1', 'xtu');
insert into participated
      values(1234, 'xt8888', 2016551103, 10000);
```
c. 删除“John Smith”拥有的马自达车（Mazda）。
```sql
delete from owns
where driver_id in (select driver_id
                    from person
                    where name = 'John Smith')
      and license in (select license
                      from car
                      where model = 'Mazda');
```

### 3.5
**假设有关系 marks(ID, score)，我们希望基于如下标准为学生评定等级：如果 score < 40 得 F；如果 40 <= scare < 60 得 C；如果 60 <= score < 80 得 B；如果 80 <= score 得 A。写出 SQL 查询完成下列操作：**

a. 基于 marks 关系显示每个学生得等级。
```sql
select  ID,
    case
        when score < 40 then 'F'
        when score < 60 then 'C'
        when score < 80 then 'B'
        else 'A'
    end as grade
from marks;
```
b. 找出各等级得学生数。
```sql
select count(ID)
from (select  ID,
      case
          when score < 40 then 'F'
          when score < 60 then 'C'
          when score < 80 then 'B'
          else 'A'
      end as grade
      from marks)
group by grade;
```

### 3.6
**SQL 的 like 运算符是大小写敏感的，但字符串上的 lower() 函数可以用来实现大小写不敏感的匹配。为了说明是怎么用的，写出这样一个查询：找出名称中包含了“sci”子串的系，忽略大小写。**
```sql
select dept_name
from department
where lower(dept_name) like '%sci%';
```

### 3.7
**考虑 SQL 查询**
```sql
select distinct p.a1
from p, r1, r2
where p.a1 = r1.a1 or p.a1 = r2.a1
```
在什么条件下这个查询选择的 p.a1 值要么在 r1 中，要么在 r2 中？仔细考察 r1 或 r2 可能为空的情况。

> 答：
> 1. r1，r2不能同时为空
> 2. p 不能为空
> 3. p.a1 与 r1.a1 或 r2.a1 有交集

### 3.8
**考虑图3-19中的银行数据库，其中加下划线的是主码。为这个关系数据库构造出如下 SQL 查询：**

> branch(**branch_name**, branch_city, assets)\
> customer(**customer_name**, customer_street, customer_city)\
> loan(**loan_number**, breach_name, amount)\
> borrower(**customer_name**, **loan_number**)\
> account(**account_number**, branch_name, balance)\
> depositor(**customer_name**, **account_number**)\
> 图3-19 银行数据库

a. 找出银行中所有有账户但无贷款的客户。
```sql
select customer_name
from customer
where customer_name not in (select customer_name
                            from borrower);
```
b. 找出与“Smith”居住在同一个城市、同一个街道的所有客户的名字。
```sql
select a.customer_name
from customer a, customer b
where b.name = 'Smith'
      and a.custromer_street = b.customer_street
      and a.customer_city = b.customer_city;
```
c. 找出所有支行的名称，在这些支行中都有居住在“Harrison”的客户所开设的账户。
```sql
select distinct branch_name
from customer natural join account natural join depositor
where customer_city = 'Harrison';
``` 

### 3.9
**考虑图3-20的雇员数据库，其中加入下划线的是主码。为下面每个查询写出 SQL 表达式：**

> employee(**employee_name**, street, city)\
> works(**employee_name**, company_name, salary)\
> company(**cpmpany_name**, city)\
> managers(**employee_name**, manager_name)\
> 图3-20 雇员数据库

a. 找出所有为“First Bank Corporation”工作的雇员名字及其居住城市。
```sql
select employee_name, city
from employee natural join works
where company_name = 'First Bank Corporation';
```
b. 找出所有为“First Bank Corporation”工作且薪水超过10000美元的雇员名字、居住街道和城市。
```sql
select employee_name, street, city
from employee natural join works
where company_name = 'First Bank Corporation'
      and salary > 10000;
```
c. 找出数据库中所有不为“First Bank Corporation”工作的雇员。
```sql
select employee_name
from employee natural join works
where company_name != 'First Bank Corporation';
```
d. 找出数据库中工资高于“Small Bank Corporation”的每个雇员的所有雇员。
```sql
select employee_name
from works
where salary > (select max(salary)
                from works
                where company_name = 'Small Bank Corporation');
```
e. 假设一个公司可以在好几个城市有分部。找出位于“Small Bank Cprporation”所有所在城市的所有公司。
```sql
select a.company_name
from company a, company b
where b.company_name = 'Small Bank Corporation'
      and a.city = b.city;
```
f. 找出雇员最多的公司。
```sql
select company_name
from works
group by company_name
having count(employee_name) = (select max(count(empoyee_name))
                               from works
                               group by company_name);
```
g. 找出平均工资高于“First Bank Corporarion”平均工资的那些公司。
```sql
select company_name
from works
group by company_name
having avg(salary) > (select avg(salary)
                      from works
                      where company_name = 'First Bank Corporarion');
```

### 3.10
**考虑3-20的关系数据库，给出下面每个查询的 SQL 表达式：**

a. 修改数据库使“Jones”现在居住在“Newton”市。
```sql
update works
set city = 'Newton'
where employee_name = 'Jones';
```
b. 为“First Bank Corporarion”所有工资不超过100000美元的经理增长10%的工资，对工资超过100000美元的只增长3%。
```sql
update works
set salary = case
                when salary <= 100000 then salary * 1.1
                else salary * 1.03
             end
where employee_name in (select employee_name
                        from managers);
```

### 3.11
**使用大学模式，用 SQL 写出如下查询**

a. 找出所有至少选修了一门 Comp. Sci. 课程的学生姓名，保证结果中没有重复的姓名。
```sql
select distinct student.name
from student, takes, course
where course.dept_name = 'Comp. Sci.'
      and student.ID = takes.ID
      and takes.course_id = course.course_id;
```
b. 找出所有没有选修在2009年春季之前开设的任何课程的学生的ID和姓名。
```sql
select distinct ID, name
from student
where ID not in (select ID
                 from takes
                 where year < 2009);
```
c. 找出每个系教师的最高工资值。可以假设每个系至少有一个教师。
```sql
select dept_name, max(salary)
from instructor
group by dept_name;
```
d. 从前述查询所计算出的每个系最高工资中选出最低值。
```sql
select min(max_salary)
from (select dept_name, max(salary) as max_salary
      from instructor
      group by dept_name);
```

### 3.12
**使用大学模式，用 SQL 写出如下查询。**

a. 创建一门课程“CS - 001”，其名称为“Weekly Seminar”，学分为0。
```sql
insert into course(course_id, title, credits)
    values('CS - 001', 'Weekly Seminar', 0);
```
b. 创建该课程在2009年秋季的一个课程段，sec_id 为1。
```sql
insert into secrion(course_id, sec_id, semester, year)
    values('CS - 001', 1, 'Fall', 2009);
```
c. 让 Comp. Sci. 系的每个学生都选修上述的课程段。
```sql
insert into takes(ID, course_id, sec_id, semester, year)
    select ID, 'CS - 001', 1, 'Fall', 2009
    from student
    where dept_name = 'Comp. Sci.';
```
d. 删除名为 Chavez 的学生选修上述课程段。
```sql
delete from takes
where ID = (select ID
            from student
            where name = 'Chavez')
      and course_id = 'CS - 100'
      and sec_id = 1
      and semester = 'Fall'
      and year =2009;
```
e. 删除课程 CS-001。如果在运行此语句之前，没有先删除这门课程的授课信息（课程段），会发生什么事情?
```sql
delete from course
where course.course_id = 'CS - 001';
```
> 答：
> 会将学生的选课信息一同删除

f. 删除课程名称中包含“database”的任意课程的任意课程段所对应的所有 takes 元组，在课程名的匹配中忽略大小写。
```sql
delete from takes
where course_id in(select course_id
                   from course
                   where course.title = '%database%');
```

### 3.13
**写出对应于图3-18中模式的 SQL DDL。在数据类型上做合理的假设，确保声明主码和外码**

```sql
create table person(
    driver_id numeric(20, 0),
    name varchar(20),
    address varchar(50),
    primary key (driver_id),
    foreign key (name),
    foreign key (address),
);
create table car(
    license varchar(20),
    model varchar(20),
    year numeric(4, 0),
    primary key (license, model),
    foreign key (year),
);
create table accident(
    report_number varchar(20),
    date date,
    location varchar(50),
    primary key (report_number),
    foreign key (date, location),
);
create table owns(
    driver_id numeric(20, 0),
    license varchar(20),
    primary key (driver_id),
    foreign key (license) references car,
);
create table participated(
    report_number varchar(20),
    license varchar(20),
    driver_id numeric(20, 0),
    damage_amount numeric(10, 2),
    primary key (report_number),
    foreign key (license) references car,
    foreign key (driver_id) references person,
    foreign key (damage_amount),
);
```

### 3.14
**考虑图3-18中的保险公司数据库，其中加入下划线的是主码。对这个关系数据库构造出如下 SQL 查询：**

a. 找出和“John Smith”的车有关的交通事故数量。
```sql
select count(report_number)
from accident
where report_number in (select reprot_number
                        from participated natural join person
                        where name = 'John Smith');
```
b. 对事故报告编号为“AR2197”中的车牌是“AABB2000”的车辆损坏保险费用更新到3000美元。
```sql
update participated
set damage_amount = 3000
where report_number = 'AR2197'
    and license = 'AABB2000';
```

### 3.15
**考虑图3-19中的银行数据库，其中加下划线的是主码。为这个关系数据库构造出如下 SQL 查询：**

a. 找出在“Brooklyn”的所有支行都有账户的所有客户。
```sql
--一个人在一个支行最多有一个账户
select customer_name
from customer natural join depositor
where account_number in (select account
                          from account
                          where branch_name = 'Brooklyn')
group by customer_name
having count(accont_number) = (select count(branch_name)
                               from branch
                               where branch_name = 'Brooklyn');
```
b. 找出银行的所有贷款额的总和。
```sql
select sum(amount)
from loan;
```
c. 找出总资产至少比位于 Brooklyn 的某一家支行要多的所有支行名字。
```sql
select branch_name
from branch
where assets > (select min(assets)
                from branch
                where branch_city = 'Brookly');
```

### 3.16
**考虑图3-20中的关系数据库。给出下面每个查询对应的 SQL 表达式：**

a. 找出所有为“First Bank Corporaion”工作的雇员名字。
```sql
select employee_name
from works
where company_name = 'First Bank Corporaion';
```
b. 找出数据库中所有居住城市和公司所在城市相同的雇员。
```sql
select a.employee_name
from (works natural join employee) as a, company
where a.city = company.city;
```
c. 找出数据库中所有居住的街道和城市与其经理相同的雇员。
```sql
select a.employee_name
from employee natural join works a, employee natural join managers b
where a.city = b.city
    and a.company_name = b.company_name;
```
d. 找出工资高于所在公司雇员平均工资的所有雇员。
```sql
with temp as(select company_name, avg(salary) as avg_salary
             from works
             group by company_name)
select employee_name
from works natural join temp
where salary > temp.avg_salary;
```
e. 找出工资总和最小的公司。
```sql
select distinct company_name
from works
group by company_name
having sum(salary) = (select min(sum(salary))
                      from works
                      group by company_name);
```

### 3.17
**考虑3-20中的关系数据库。给出下面每个查询对应的 SQL 表达式：**

a. 为“First Bank Corporation”的所有雇员增长10%的工资。
```sql
--经理也是雇员
update works
set salary = salary * 1.1
where company_name = 'First Bank Corporation';
```
b. 为“First Bank Corporation”的所有经理增长10%的工资。
```sql
update works
set salary = salary * 1.1
where company_name = 'First Bank Corporation'
    and employee_name in (select employee_name
                          from managers);
```
c. 删除“Small Bank Corporation”的雇员在 works 关系中的所有元组
```sql
delete from works
where company_name = 'Small Bank Corporation';
```

~~3.18~~

~~3.19~~

~~3.20~~

### 3.21
**考虑图3-21中的图书馆数据库。用 SQL 写出如下查询：**

> member(**member_no**, name, age)\
> book(**isbn**, title, authors, publisher)\
> borrowed(**memnb_no**, **isbn**, date)\
> 图3-21

a. 打印借阅了任意由“McGraw-Hill”出版的书的会员的名字。
```sql
select distinct name
from member natural join borrowed natural join book
where publisher = 'McGraw-Hill';
```
b. 打印借阅了所有由“McGraw-Hill”出版的书的会员的名字。
```sql
with count_mc(value) as (
      select count(isbn)
      from book
      where publisher = 'McGraw-Hill')
select name
from member natural join book natural join borrowed
where publisher = 'McGraw-Hill'
group by name
having count(isdn) = count_mc.value;
```
c. 对于每个出版商，打印借阅了多于5本由该出版商出版的书的会员名字。
```sql
select pulisher, name
from member natural join book natural join borrowed
group by name, publisher
having count(isbn) > 5;
```
d. 打印每位会员借阅书籍数量的平均值。考虑这样的情况：如果某会员没有借阅任何书籍那么该会员根本不会出现在 borrowed 关系中。
```sql
select name, avg(count(isbn))
from member natural join borrowed
group by name;
```

~~3.22~~

### 3.23
**考虑查询**
```sql
select course_id, semester, year, sec_id, avg(tot_cred)
from takes natural join student
where year = 2009
group by course_id, semester, year, sec_id
having count(ID) >= 2;
```
**解释为什么在 from 子句中还加上与 section 的连接不会改变查询结果。**

> 答：上述查询需要的所有信息来自关系 takes 和 student，故加上与 section 的连接不会改变查询结果。

### 3.24
**考虑查询**
```sql
with dept_total (dept_name, value) as
    (select dept_name, sum(salary)
     from instructor
     group by dept_name),
dept_total_avg(value) as
    (select avg(value)
     from dept_total)
select dept_name
from dept_total, dept_total_avg
where dept_total.value >= dept_total_avg.value;
```
**不使用 with 结构，重写此查询。**
```sql
select dept_name
from (select dept_name, sum(salary)
      from instructor
      group by dept_name) as a
where a.value >= (select avg(sum(value))
                  from instructor
                  group by dept_name);
```
