--1
update loan
set amount = 1200
where loan_number = 'L-11';

--2
update loan
set branch_name = 'Perryridge', amount = 1400
where loan_number = 'L-20';

--3
update account
set balance = balance * 1.06
where account_number = (select account_number
                        from depositor
                        where customer_name = 'Smith');

--4
update account
set balance = case when balance > 2000 then balance * 1.06
                   else balance * 1.05
              end

--5
update customer
set customer_city = (select customer_city
                     from customer
                     where customer_name = 'Jones')
where customer_name = 'Smith';

--6
with temp(customer_city, customer_street) as
    (select customer_city, customer_street
     from customer
     where customer_name = Turner)
update customer
set customer_city = temp.customer_city, customer_street = temp.customer_street
where customer_name = 'Smith';

--7
delete from customer
where customer_name = 'Brooks';

--8
delete from customer
where customer_name not in ((select customer_name
                             from borrower)
                            union
                            (select customer_name
                             from depositor));