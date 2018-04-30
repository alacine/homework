## 第三章习题

### 3.1 使用大学模式，用 SQL 写出如下查询数据。

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
           group by course_id))
```
### 3.2 假设给你一个关系 grade_points(grad_e, points)，它提供从 takes 关系中用字母的成绩等级到数字表示的得分之间的转换。例如，“A”等级可指定为对应于4分，“A-”对应于3.7分，“B+”对应于3.3分，“B”对应于3分，等等。学生在某门课程（课程段）上所获得的等级分值被定义为该课程段的学分乘以该生得到的成绩等级所对应的数字表示的得分。
给定上述关系和我们的大学模式，用 SQL 写出下面的每个查询。为简单起见，可以假设没有任何 takes 元组在 grade 上取 null 值。

a. 根据 ID 为12345的学生所选修的所有课程，找出该生所获得的等级分值的总和
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
c. 找出每个学生的 ID 和等级分值的平均值
```sql
select ID, sum(credits * points)/sum(credits) as GPA
from takes natural join course natural join grade_points
group by ID;
```

### 3.3 使用大学模式，用 SQL 写出如下插入、删除和更新语句

a. 给 Comp. Sci. 系的每位教师涨10%工资。
```sql
update instructor
set salary = salary * 1.1
where dept_name = 'Comp. Sci';
```
b. 删除所有未开设过（即没有出现在 section 关系中）的课程
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
### 3.4 考虑图3-18中的保险公司数据库，其中加入下划线的是主码。为这个关系数据库构造出如下 SQL 查询：

a. 找出2009年其中车辆出过交通事故的人员总数。
```sql
select count(distinct driver_id)
from accident natural join owns natural join participated
where date between date'2009-1-1' and date'2009-12-31'
```
b. 向数据库中增加一个新的事故，对每个必须的属性可以设定任意值。
```sql
insert into accident
      value(1234, '2018-5-1', 'xtu');
insert into participated
      value(1234, 'xt8888', 2016551103);
```
c. 删除“John Smith”拥有的马自达车（Mazda）
```sql
delete from owns
where driver_id in (select driver_id
                    from person
                    where name = 'John Smith')
      and license in (select license
                      from car
                      where model = 'Mazda');
```

> person (**driver_id, name**, address)\
> car (**license, model**, year)\
> accident (**report_number**, date, location)\
> owns (**driver_id**, license)\
> participated (**report_number**, license, driver_id, damage_amount)\
> 图3-18  习题3.4和习题3.14的保险公司数据库(使用加粗代替下划线)

### 3.5 假设有关系 marks(ID, score)，我们希望基于如下标准为学生评定等级：如果 score < 40 得 F；如果 40 <= scare < 60 得 C；如果 60 <= score < 80 得 B；如果 80 <= score 得 A。写出 SQL 查询完成下列操作；

a. 基于 marks 关系显示每个学生得等级。
```sql

```
b. 找出各等级得学生数。
```sql
```