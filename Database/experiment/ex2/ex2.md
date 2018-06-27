## 实验二（DDL中的表操作）报告  

### 实验目的  
1. 熟悉和掌握 SQL的 Create Table, Drop Table, Alter Table语句语法；  
2. 熟悉和掌握 SQL Plus或 TOAD等开发工具；  

### 预备知识  
1. 掌握登陆远程数据库方法；  
2. 掌握至少一种 Oracle PL/SQL开发工具的使用；  
3. PL/SQL中 Create Table, Drop Table, Alter Table语句语法。  

### 实验内容  
1. 按照要求建表  
```sql
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
```
2. 删除掉实验一中建立的表taba；
```sql
drop table taba;
```
3. 将customer表中的customer_street列的类型改成varchar2(20)。
```sql
alter table customer modify customer_street varchar2(20);
```
4. 将customer表中加入列gender,类型varchar2(1)。
```sql
alter table customer add (gender varchar2(1));
```
5. 将customer表中的列gender删除。
```sql
alter table customer drop column gender;
```