## 第五章习题

### 5.9  
说明如何使用 **rollup** 来表达 **group by cube**(a, b, c, d)；答案只允许含有一个 **group by** 子句。  
```sql
group by rollup(a), rollup(b), rollup(c), rollup(d);
```
### 5.10  
对于给定的一个关系 *S(student, subject, marks)*，写一个查询，利用排名操作找出总分数在前 n 位的学生。
```sql
select student, sum_marks, marks_rank
from (select student, sum(marks) as sum_marks, rank() over (order by sum(marks)  desc) as marks_rank
      from S
      group by student)
where marks_rank <= n;
```

### 5.11  
考虑 5.6 节中的关系 *sales*，写一个 SQL 查询，计算该关系上的立方体（cube）操作，给出图 5-21 中的关系。**不要使用 cube** 结构。
```sql
(select item_name, color, 'all', sum(quantity)
from sales
group by item_name, color)
union
(select item_name, 'all', 'all', sum(quantity)
from sales
group by item_name)
union
(select 'all', color, 'all', sum(quantity)
from sales
group by color)
```

### 5.25  
在 5.5.1 节中，我们使用习题 4.5 中的视图 *student_grades* 来写基于绩点平均值对学生排名次的查询。修改这个查询，只显示前十名的学生（也就是说，从第一名到第十名的那些学生）。
```sql
select ID, GPA, gpa_rank
from (select ID, GPA, rank() over (order by GPA desc) as gpa_rank
      from student_grades)
where gpa_rank <= 10;
```

### 5.27  
对于给定的一个关系 *r(a, b, c)*，说明如何使用扩展 SQL 特性产生一个 c 对 a 的直方图。将 a 分成 20 个等分的区（即每个区含有 r 中 5% 的元组，并按 a 排序）。
```sql
select new_a, sum(c)
from (select c, ntile(20) over (order by a) as new_a
      from r)
group by new_a;
```

### 5.28  
考虑图 5-25 中的银行数据库，以及关系 *account* 的 *balance* 属性。写一个 SQL 查询，计算 *balance* 值的直方图，从 0 到目前最大账户余额的范围分成三个相等的区域。
> branch(**branch_name**, branch_city, assets)  
> customer(**customer_name**, customer_street, customer_city)  
> loan(**loan_number**, breach_name, amount)  
> borrower(**customer_name**, **loan_number**)  
> account(**account_number**, branch_name, balance)  
> depositor(**customer_name**, **account_number**)  
> 图5-25

```sql
--将余额分成三个区间，而不是按照人数分
--即0~1/3*max(balance),1/3*max(balance)~2/3*max(balance),2/3*max(balance)~max(balance)
(select 1, count(account_number)
from account
where balance < (select max(balance)/3
                 from account))
union
(select 2, count(account_number)
from account
where balance < (select max(balance)/3*2
                 from account)
  and balance > (select max(balance)/3
                 from account))
union
(select 3, count(account_number)
from account
where balance < (select max(balance)
                 from account)
  and balance > (select max(balance)/3*2
                 from account))
```