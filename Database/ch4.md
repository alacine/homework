## 第四章习题

### 4.1
**用 SQL 写出下面的查询**

a. 显示所有教师的列表，列出他们的 ID、姓名以及所讲授课程段的编号。对于没有讲授任何课程段的教师，确保将课程段编号显示为0。在你的查询中应该使用外连接，不能使用标量子查询。
```sql
select ID, name, nvl(sec_id, 0)
from instructor natural left outer join teaches;
```

b. 使用标量子查询，不适用外连接写出上述查询。
```sql
(select ID, name, sec_id
from instructor natural join teaches)
union
(select ID, name, null
from instructor
where ID not in (select ID
                 from teaches));
```

c. 显示2010年春季开设的所有课程的列表，包括讲授课程段的教师的姓名。如果一个课程段有不止一位教师讲授，那么有多少位教师，此课程段在结果中就出现多少次。如果一个课程没有任何教师，它也要出现在结果中，相应的教师名置为“——”。
```sql
select course_id, title, nvl(instructor.name, '-')
from (course natural join section) natural left outer join teaches natural left outer join instructor
where year = 2010 and
      semester = 'Spring';
```

d. 显示所有系的列表，包括每个系中教师的总数，不能使用标量子查询。确保正确处理没有教师的系。
```sql
select dept_name, count(ID)
from department natural left outer join instructor
group by dept_name;
```

### 4.2
**不使用 SQL 外连接运算也可以在 SQL 中计算连接表达式。为了阐明这个事实，不使用外连接表达式重写下面每个 SQL 查询：**

a. ```select * from student natural left outer join takes```
```sql
(select *
from student natural join takes)
union
(select ID, name, dept_name, tot_cred, null, null, null, null, null
from student
where ID not in (select ID
                 from takes));
```

b. ```select * from student natural full outer join takes```
```sql
(select *
from student natural join takes)
union
(select ID, name, dept_name, tot_cred, null, null, null, null, null
from student
where ID not in (select ID
                 from takes))
union
(select ID, null, null, null, course_id, sec_id, semester, year, grade
from takes
where ID not in (select ID
                 from student));
```

### 4.3
**假设有三个关系r(A, B)、s(B, C)和t(B, D)，其中所有属性声明为非空。考虑表达式：**

* ```r natural left outer join (s natural left outer join t)```
* ```(r natural left outer join s) natural left outer join t```

a. 给出关系r、s和t的实例，使得在第二个表达式的结果中，属性C有一个空值但属性D有非空值。  
```sql
r = (a1, b1)
s = (b2, c2)
t = (b1, d1)
```

b. 在第一个表达式的结果中，上述模式中的C为空且D非空有可能吗? 解释原因。  
> 不可能，因为表达式```(s natural left outer join t)```的结果C必不为空，r再左外连接上这个结果只有可能C和D均为空或C不空D空。

### 4.5
**基于习题3.2中的查询，指出如何定义视图 *student_grades(ID, GPA)*，他给出了每个学生的等级分值的平均值；回忆一下，我们用关系 *grade_points(grade, points)* 来把用字母表示的成绩等级转换为用数字表示的得分。你的视图定义要确保能够正确处理在 *takes* 关系的 *grade* 属性上取 *null* 值得情况。**
```sql
create view student_grades(ID, GPA) as
select ID, sum(credits * points)/sum(credits)
from takes natural join course natural left outer join grade_points
group by ID;
```

### 4.8
**正如在4.4.7节所讨论的，我们希望能够满足约束“每位教师不能再同一个学期的同一个时间段在两个不同的教师授课”。**  
a. 写出一个 SQL 查询，它返回违反此约束的所有 *(instructor, section)* 组合。
```sql
select ID, name, sec_id
from instructor natural join teaches natural join section
group by ID, name, sec_id, year, time_slot_id
having count(building) > 1 or
       count(room_no) > 1;
```

### 4.9
**SQL 允许外码依赖指向同一个关系，如下面的例子所示：**
```sql
create table manager
  (employee_name var char(20) not null
  manager_name var char (20) not null,
  primary key employee_name,
  foreign key (manager_name) references manager
  on delete cascade)
```
**这里 *employee_name* 是 *manager* 表的码，意味着每个雇员最多只有一个经理。外码子句要求每个经理都是一个雇员。请准确解释当 *manager* 关系中一个元组被删除时会发生什么情况。**
> 该元组的雇员被删除，同时此雇员的经理被删除，和此雇员同一个经理的雇员被删除。

### 4.12
**对于图4-11中的数据库，写出一个查询来找到那些没有经理的雇员。注意一个雇员可能只是没有列出其经理，或者可能有 *null* 经理。使用外连接书写查询，然后不用外连接再重写查询。**
> employee(**employee_name**, street, city)  
> works(**employee_name**, company_name, salary)  
> comopany(**company_name**, city)  
> manages(**employee_name**, manager_name)  
> 图4-11 雇员数据库

```sql
--外连接
select employee_name
from employee natural left outer join manages
where manager_name is null;
--无外连接
select employee_name
from employee
where employee_name in (select employee_name
                        from manages
                        where manager_name is null)
   or employee_name not in (select employee_name
                            from manages)
```

### 4.15
**给出如何用 case 运算表达习题4.10中的 coalesce 运算。**
```sql
select case when A1.name is not null then A1.name
            when A2.name is not null then A2.name
            ...
            when An.name is not null then An.name
            else null
       end
from A;
```