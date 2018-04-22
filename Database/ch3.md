## 第三章习题

### 3.1 使用大学模式，用 SQL 写出如下查询数据。

a. 找出 Comp.Sci. 系开设的具有3个学分的课程名称。
```sql
select course_title
from course
where dept_name = 'Comp.Sci.' and credits = 3;
```
![](./1.png)

b. 找出名叫 Einstein 的教师所教的学生的标识，保证结果中没有重复。
```sql

```
