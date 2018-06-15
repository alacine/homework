-- 1.a.建立主键约束
alter table borrower add constraint borrower_pk primary key (customer_name, loan_number);
alter table loan add constraint loan_pk primary key (loan_number);
alter table branch add constraint branch_pk primary key (branch_name);
alter table customer add constraint customer_pk primary key (customer_name);
alter table depositor add constraint depositor_pk primary key (customer_name, account_number);
alter table account add constraint account_pk primary key (account_number);

-- 1.b 运行下列SQL语句，记录结果
insert into branch values('Xiangtan University', 'Xiangtan', 4000000);
insert into branch values('Xiangtan University', 'Xiangtan', 5000000);

-- 2.a 建立外键约束
alter table borrower add constraint borrower_fk foreign key (customer_name) references customer(customer_name);
alter table borrower add constraint borrower_fk1 foreign key (loan_number) references loan(loan_number);

alter table loan add constraint loan_fk foreign key (branch_name) references branch(branch_name);

alter table account add constraint account_fk foreign key (branch_name) references branch(branch_name);

alter table depositor add constraint depositor_fk foreign key (customer_name) references customer(customer_name);
alter table depositor add constraint depositor_fk1 foreign key (account_number) references account(account_number);

-- 2.b 运行下列SQL语句，记录结果
insert into loan values('L-001', 'Xingtan University', 1000);
insert into loan values('L-002', 'Rain Lake', 2000);

-- 2.c 运行一下SQL语句，记录结果
delete branch;

-- 3.a 在loan表上建立一个unique约束，保证amount是唯一的
alter table loan add constraint loan_unique unique(amount);

-- 3.b 运行以下SQL语句，并记录结果
insert into loan values('L-002','Xiangtan University',1000);

-- 3.c 使得刚才建立的约束无效化，并再次运行上一条SQL语句，记录结果并分析原因
alter table loan disable constraint loan_unique;
insert into loan values('L-002','Xiangtan University',1000);

-- 3.d 删除掉这个约束
alter table loan drop constraint loan_unique;

-- 4.a 在loan表上建立一个check约束，保证amount必须为正数
alter table loan add constraint loan_ckeck check(amount>0);

-- 4.b 运行以下SQL语句，记录结果
insert into loan values('L-003','Xiangtan University',-2000);