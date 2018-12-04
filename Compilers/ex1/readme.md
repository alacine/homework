## 编译原理实验一

编程实现 DFA 识别字符串的过程。
实验内容:
1. DFA 的输入与 DFA 的存储:确定 DFA 的数据结构以及存储格式
2. DFA 的正确性检查:DFA 的五元组是否正确
3. 输入任意一个整数 N,DFA 的能列表显示其识别的所有长度小于等于 N 的字符串;
4. DFA 的规则字符串判定:输入(或用字符集随机生成)一个字符串,模拟 DFA 识别字符串的过程判定该字符串是否是规则字符串(属于 DFA 的语言集)。

* 运行
```sh
# 一次执行, 终端输入(繁琐, 不建议)
python dfa.py xxx.dot

# 重定向输入
python dfa.py xxx.dot < xxx.txt
# dot 转图片(使用dot命令要安装graphviz)
dot -Tpng xxx.dot -o xxx.png

# 脚本批量执行(推荐Linux)
./run.sh
```

* 脚本说明  
把当前目录下的所有txt文件作为dfa.py的输入, 并生成对应文件名的dot文件和对应文件名的png图片

