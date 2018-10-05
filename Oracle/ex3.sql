--1索引
--创建索引
--创建student1表，并为student1表建立主键。(“student1”的结构与“a_db.学生”表一样)
drop table student1;
create table "A2016551103".student1 as select * from "A_DB"."学生" where '1' = '1';
alter table student1 add constraint student1_pk primary key ("学号");

--按student1表的“姓名”创建索引，索引名为“obj3_1”
drop index obj3_1;
create index obj3_1 on student1("姓名");

--按student1表的“注册日期”创建索引，并以降序排列，索引名为“obj3_2”
drop index obj3_2;
create index obj3_2 on student1("注册日期" desc);

--按student1表的“性别”创建位图索引，索引名为“student_gender_index”
drop index student_gender_index;
create bitmap index student_gender_index on student1("性别");

--按student1表的“性别”和“姓名”创建组合索引，索引名为“obj3_3”
drop index obj3_3;
create index obj3_3 on student1("性别", "姓名");

--查看索引
--利用数据字典视图USER_INDEXES、USER_IND_COLUMNS查看索引信息
select * from user_indexes;
select * from user_ind_columns;

--删除索引
--删除索引“student_ gender _index”
drop index student_gender_index;

--2同义词
--创建同义词
--创建student1表的同义词，名为“obj3_4”
drop synonym obj3_4;
create synonym obj3_4 for student1;

--创建同义词obj3_4的同义词，名为“st1”
drop synonym st1;
create synonym st1 for obj3_4;

--创建视图obj2_1的同义词，名为“obj3_5”
drop synonym obj3_5;
create synonym obj3_5 for obj2_1;

--创建视图obj2_5的公共同义词，公共同义词的命名规则：字符串“obj3_”后面跟上你的学号
drop public synonym obj3_2016551103;
create public synonym obj3_2016551103 for obj2_5;

--3序列
--创建序列
--创建序列，该序列起始值50，步长为10，不缓冲，序列名为“obj3_6”
drop sequence obj3_6;
create sequence obj3_6
  increment by 10
  start with 50
  nocache;
  
--创建序列，该序列最大值无限制，最小值为1，步长为1，序列名为“obj3_7”
drop sequence obj3_7;
create sequence obj3_7
  nomaxvalue
  increment by 1
  minvalue 1;

--创建序列，该序列起始值为1000，步长为2，最大值为10000，不可循环，序列名为“obj3_8”
drop sequence obj3_8;
create sequence obj3_8
    start with 1000
    increment by 2
    nocycle;

--查看序列
--利用数据字典视图user_SEQUENCES、all_SEQUENCES查看序列信息
select * from user_SEQUENCES;
select * from all_SEQUENCES;

--引用序列
--向DEPT表中插入三条记录，利用序列obj3_6生成部门编号
insert into dept values(obj3_6.nextval, 'newdept1', 'xtu1');
insert into dept values(obj3_6.nextval, 'newdept2', 'xtu2');
insert into dept values(obj3_6.nextval, 'newdept3', 'xtu3');

--修改序列
--修改序列“obj3_6”，将该序列最大值设为“82000”，最小值设为“100”，步长设为“5”
select obj3_6.currval from dual;
select obj3_6.nextval from dual;
--多次使用序列，使得currval大于等于100，才能进行以下修改
alter sequence obj3_6
  maxvalue 82000
  minvalue 100
  increment by 5;

--修改序列“obj3_7”，将该序列最大值设为“1000”
alter sequence obj3_7
  maxvalue 1000;

commit;
rollback;
--4用户（用自己的数据库）
--创建用户
--创建一个用户，用户名为你自己姓名的汉语拼音，密码是你的学号
create user c##ruian identified by 2016551103;

--该用户授予一定的权限
grant connect to c##ruian;

--授予用户权限
--新开一个会话，以新创建的用户身份连接并对scott中的emp表进行查询、删除操作。如果权限不够，则授予相应权限。最后，回滚事务
select * from emp;
grant select on c##scott.emp to c##ruian;
delete from emp where job = 'CLERK';
grant delect on c##scott.emp to c##ruian;
rollback;

--修改用户信息
--修改该用户的口令，然后用新口令重新连接
alter user c##ruian identified by password;
sqlplus c##ruian/password

--封锁该用户的账号，然后解锁
alter user c##ruian account lock;
alter user c##ruian account unlock;

--查询用户与权限信息
--利用数据字典视图dba_user、user_sys_privs、user_tab_privs、user_role_privs、session_privs查询用户与权限信息
select * from dba_users where username = 'C##RUIAN';
select * from user_sys_privs;
select * from user_tab_privs;
select * from user_role_privs;
select * from session_privs;

--删除用户
drop user c##ruian;
