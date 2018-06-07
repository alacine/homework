-- 1.a.建立主键约束
alter table borrower add constraint borrower_pk primary key (costomer_name, loan_number);
alter table loan add constraint loan_pk primary key (loan_number);
alter table branch add constraint branch_pk primary key (branch_name);
alter table customer add constraint customer_pk primary key (customer_name);
alter table depositor add constraint depositor_pk primary key (customer_name, account_number);
alter table account add constraint account_pk primary key (account_name);

-- 1.b 运行下列SQL语句
insert into branch values('Xiangtan University', 'Xiangtan', 4000000);
insert into branch values('Xiangtan University', 'Xiangtan', 5000000);

--2.a 建立外键约束
