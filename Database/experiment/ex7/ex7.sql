--1
update loan
set amount = 1200
where loan_number = 'L-11';
commit;

--2
update loan
set branch_name = 'Perryridge', amount = 1400
where loan_number = 'L-20';
commit;

--3
update account
set balance = balance * 1.06
where account_number in (select account_number
                        from depositor
                        where customer_name = 'Smith');
commit;

--4
update account
set balance = case when balance > 2000 then balance * 1.06
                   else balance * 1.05
              end;
commit;

--5
update customer
set customer_city = (select customer_city
                     from customer
                     where customer_name = 'Jones')
where customer_name = 'Smith';
commit;

--6
update customer
set customer_city = (select customer_city
                     from customer
                     where customer_name = 'Turner'),
    customer_street = (select customer_street
                       from customer
                       where customer_name = 'Turner')
where customer_name = 'Smith';
commit;

--7
delete from customer
where customer_name = 'Brooks';
commit;

--8
delete from customer
where customer_name not in ((select customer_name
                             from borrower)
                            union
                            (select customer_name
                             from depositor));
commit;

--9
select *
from loan;

select *
from account;

select *
from customer;

--10
rollback;