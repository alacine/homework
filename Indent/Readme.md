### 代码格式化工具 indent

* 使用说明
	- Linux
	```sh
	./indent 源文件名 参数 新文件名 (若源文件和新文件名相同，则覆盖源文件)
	```
	- Dos
	```sh
	indent-win.exe 源文件名 参数 新文件名
	```
	
	| 参数  |  风格                                                      |
	|------|-------------------------------------------------------------|
	| -k   |    K&R and variants: 1TB, Stroustrup, Linux kernel, BSD KNF |
	| -a   |    Allman                                                   |
	| -g   |    GNU                                                      |
	| -w   |    Whitesmiths                                              |
	| -h   |    Horstmann                                                |
	| -p   |    Pico                                                     |
	| -r   |    Ratliff                                                  |
	| -l   |    Lisp                                                     |


* 注意事项
	- 使用前在最后一个头文件或者宏定义的那一行行末手动加上分号 ';' 并在新文件中手动删除;
	- 视缩进为4个空格长度;
	- 源文件必须由英文字符,符号,数字组成;
	- 不支持注释格式化
	- 不支持'{','}','(',')',';'这些符号作为数组元素



* 程序清单

|文件类型          | 文件名                              |
|------------------|-------------------------------------|
|main 函数所在文件  |idnent.c                             |
|自定义函数所在文件|Allman.c KR.c Ratliff.c Horstmann.c Lisp.c Whitesmiths.c GNU.c Clean.c Pico.c Del.c headfile_indent.c |
|执行文件          |indent                               |
|测试输入文件      |test_input.c                         |
|测试输出文件      |test_output.c                        |
|风格样例文件      |style.c                              |