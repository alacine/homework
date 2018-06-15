--1
select max(balance)
from account;

--2
select branch_name, max(balance)
from account
group by branch_name;

--3
select branch_name, sum(amount), count(loan_number), avg(amount)
from loan
group by branch_name
order by sum(amount) desc;

--4
select branch_name, sum(amount), count(loan_number), avg(amount)
from loan
where amount > 750
group by branch_name
order by sum(amount);

--5
select branch_name, avg(balance)
from account
group by branch_name;

--6
select branch_name, avg(balance)
from account
group by branch_name
having avg(balance) > (select avg(balance)
                       from account);

--7
--in
select customer_name
from borrower
where customer_name not in (select customer_name
                            from depositor);
--exists
select customer_name
from borrower b
where not exists (select customer_name
                  from depositor d
                  where b.customer_name = d.customer_name);
--8
select account_number, branch_name, balance, customer_name
from account natural join depositor
where branch_name = 'Perryridge' or
      branch_name = 'Brighton' or
      branch_name = 'Downtown';

--9
select distinct customer_name
from account natural join depositor
where branch_name in (select branch_name
                     from account natural join depositor
                     where customer_name = 'Hayes');

--10
select branch_name
from (select branch_name, rank() over(order by sum(balance) desc) as balance_rank
      from account
      group by branch_name)
where balance_rank <= 3;

--11
select customer_name, sum(case when branch_name = 'Perryridge' then balance else 0 end) Perryridge,
                      sum(case when branch_name = 'Brighton' then balance else 0 end) Brighton,
                      sum(case when branch_name = 'Downtown' then balance else 0 end) Downtown
from account natural join depositor
group by customer_name;