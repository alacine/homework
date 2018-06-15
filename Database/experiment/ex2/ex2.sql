-- 建表
create table branch (
    -- 分行表
    branch_name varchar2(20) not null,
    branch_city varchar2(30) not null,
    assets integer
);

create table loan (
    -- 借款表
    loan_number varchar2(10) not null,
    branch_name varchar2(20) not null,
    amount integer not null
);

create table account (
    -- 存款表
    account_number varchar2(10) not null,
    branch_name varchar2(20) not null,
    balance integer not null
);

create table customer (
    -- 客户表
    customer_name varchar2(20) not null,
    customer_city varchar2(20),
    customer_street varchar2(30)
);

create table borrower (
    -- 借款人表
    customer_name varchar2(20) not null,
    loan_number varchar2(10) not null
);

create table depositor (
    -- 存款人表
    customer_name varchar2(20) not null,
    account_number varchar2(10) not null
);


-- 删除掉实验一中建立的表taba
drop table taba;

-- 将customer表中的customer_street列的类型改成varchar2(20)
alter table customer modify customer_street varchar2(20);

-- 将customer表中加入列gender,类型varchar2(1)
alter table customer add (gender varchar2(1));

-- 将customer表中的列gender删除
alter table customer drop column gender;