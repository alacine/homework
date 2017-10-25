//函数del,将源程序格式化为单行文件，并且去掉所有缩进
#include<stdio.h>
#include<stdlib.h>
int del(int argc, char *argv[]){
	char ch;
	FILE *fp,*fq;
	
	if((fp=fopen(argv[1],"r")) == NULL || (fq=fopen("ing.c","w")) == NULL){
		printf("Can not find open %s\n",argv[2]);
		exit(1);
	}
	
	int flag=0;
	int jd_flag=0;
	while((ch=getc(fp)) != EOF){ 
		if(ch=='(')
			jd_flag=1;
		else if(ch==')' && jd_flag==1)
			jd_flag=0;
		
		if( ( (ch=='	') || (ch=='\n') || (ch=='\r') )  && jd_flag==0 ){
			flag=0;
			continue;
		}
		
		else if(ch==' ' && jd_flag==0){
			flag++;
			if(flag>1){
				continue;
			}
		}
		
		else
			flag=0;
		
		fputc(ch,fq);
	}
	
	fclose(fp);
	fclose(fq);
	
}
