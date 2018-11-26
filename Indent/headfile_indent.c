/*函数head,先格式化头文件、宏定义
 *存在问题：最后一个不会被格式化，需要手动在最后一个头文件或宏定义行末加上分号';'
 */
#include<stdlib.h>
#include<stdio.h>
int head(){
	FILE *fp,*fq;
	char ch;

	//读入已被格式化为单行的文件，生成头文件和宏定义被格式化好的新文件
	if( (fp=fopen("ing.c","r")) == NULL || (fq=fopen("h_ing.c","w")) == NULL ){
		printf("Can not open ing.c file\n");
		exit(1);
	}
	
	int flag=0;
	while((ch=getc(fp)) != EOF){
		if(ch=='#'){
			flag++;
			if(flag>1){
				fputs("\n",fq);
			}
		}
		fputc(ch,fq);
	}
	
	fclose(fp);
	fclose(fq);
}
