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