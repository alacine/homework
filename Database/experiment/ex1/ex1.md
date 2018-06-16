## 实验一报告  

### 实验目的  
1. 掌握建立本地Net服务名(TNS)的方法；  
2. 熟悉和掌握使用 SQL Plus工具操作数据库；  
3. 熟悉 TOAD 工具。  

### 实验内容  
1. 使用 Oracle 的 TNS配置程序建立本地服务名；  
a.运行 Oracle的 TNS配置程序；（程序里面的 oracle目录下的 Net Configuration Assistant）  
![p1](1_1.png)  
![p2](1_2.png)  
b.输入远程数据库服务名——orcl；  
![p3](1_3.png)  
c.输入远程数据库 IP地址（172.22.11.8）和端口（1521）；  
![p4](1_4.png)  
![p5](1_5.png)  
d. 使用自己的姓名作为帐户和学号作为密码测试；  
![p6](1_6.png)  
![p7](1_7.png)  
e.输入一个自己容易记住的名字命名 TNS，如 orcl之类的。  
![p8](1_8.png)  
![p9](1_9.png)  
![p10](1_10.png)  
f.完成配置。  
2. 使用 SQL Plus 工具登陆远程数据库；  
a.运行 Oracle的 SQL Plus工具；  
b. 使用自己的学号作为帐户和密码，主机字符串为刚才自己配置的 TNS登陆；  
![p11](2_b.png)
c.记录程序信息；  
![p12](2_c.png)
d.键入“create table taba(cola int,colb int);”，记录 SQL语句运行结果；  
e.键入“insert into taba values(1,1);”，记录 SQL语句运行结果；  
f.键入“commit；”，提交插入操作；  
![p13](2_d_e_f.png)
g.退出应用程序。  
3. 在命令行下使用 SQL Plus登陆远程数据库；  
a.点击运行菜单（或者按 Win+R键）；  
b.输入 cmd；  
c.在命令行窗口下输入 sqlplus 用户名/密码@TNS,如 sqlplus scott/tiger@orcl；  
d.记录程序信息；  
e.键入“select * from taba;”，记录 SQL语句运行结果；  
![p14](3_c_d_e.png)
f.退出程序。  
4. 使用 TOAD工具登陆远程数据库。(实验室的TOAD软件没有激活liscense，实验实际使用Oracle SQL Developer工具，并使用直接连接)  
![p15](4_1.png)
![p16](4_2.png)
![p17](4_3.png)

### 比较三种不同方式使用数据库的不同  
前两种方法类似，都使用了命令的形式，第三种有图形界面。