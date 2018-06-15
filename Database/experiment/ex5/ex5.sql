--1
select customer_name
from customer;

--2
select *
from branch;

--3
select customer_name
from depositor;

--4
select *
from account
where balance > 1200;

--5
select account_number, branch_name, customer_name
from depositor natural join account natural join account
where balance > 1200;

--6
select *
from customer
where customer_name like 'M%';

--7
select *
from customer
where customer_street like '_a%';

--8
select *
from loan
where amount >= 1000 and amount <= 2000;

--9
select customer_name, customer_street, customer_city,
       branch_name, branch_city, loan_number, amount
from borrower natural join customer natural join branch natural join loan;

--10
select customer_name, customer_street, customer_city,
       branch_name, branch_city, account_number, balance
from depositor natural join customer natural join branch natural join account;

--11
(select customer_name
from depositor)
union
(select customer_name
from borrower);

--12
select customer_name
from depositor
where customer_name not in (select customer_name
                       from borrower);

--13
select customer_name
from depositor
where customer_name in (select customer_name
                        from borrower);

--14
create view borrow(customer_name, customer_street, customer_city,
                   branch_name, branch_city, loan_number, amount) as
select customer_name, customer_street, customer_city,
       branch_name, branch_city, loan_number, amount
from borrower natural join customer natural join branch natural join loan;


--15
create view deposit(customer_name, customer_street, customer_city,
                    branch_name, branch_city, account_number, balance) as
select customer_name, customer_street, customer_city,
       branch_name, branch_city,account_number, balance
from depositor natural join customer natural join branch natural join account;

--16
create view borrow_and_deposit(borrower_or_depositor, customer_name, customer_street,
                               customer_city, branch_name, branch_city, sum_of_money) as
(select 'borrower', customer_name, customer_street,
        customer_city,branch_name, branch_city, amount
from borrower natural join customer natural join branch natural join loan)
union
(select 'depositor', customer_name, customer_street,
        customer_city,branch_name, branch_city, balance
from depositor natural join customer natural join branch natural join account);

--17
select customer_name, branch_name, account_number, balance
from depositor natural join account
where balance = (select max(balance)
                 from account);

--18
select customer_name, account_number
from customer natural left outer join depositor;

--19
select *
from depositor natural join account
order by account_number, balance desc;

--20
select loan_number, customer_name, amount
from borrower natural join loan natural join branch
where branch_name = 'Downtown'
order by amount desc;

--21
create table t_branch as(
    select *
    from branch
    where 1 = 0
);

--22
insert into t_branch
    select *
    from branch;
