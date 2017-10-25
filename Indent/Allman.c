//函数Allman，格式化代码为Allman风格
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int Allman(int argc, char *argv[]){
	
	FILE *fp,*fq;
	char ch;
	int i=0;
	
	//读取头文件被格式化过的文件
	if( (fp=fopen("h_ing.c","r")) == NULL || (fq=fopen(argv[3],"w")) == NULL ){
		printf("Can not open h_ing.c file\n");
		exit(1);
	}
	
	//以"{","}"字符为标记
	int flag=0;                    //用flag作为计数器来确定缩进的个数
	int jd_flag=0;                    //用于判断 '{' , '}' , ';' 是否在括号内
	while((ch=getc(fp)) != EOF){   //从文件中读入字符
		if(ch=='(')
			jd_flag=1;
		else if(ch==')' && jd_flag==1)
			jd_flag=0;
		
		if(ch=='{' && jd_flag==0){
			flag++;
			if(flag>0){
				fputs("\n",fq);
				for(i=0;i<flag-1;i++){
					fputs("	",fq);
				}
			}
			fputc(ch,fq);
			fputs("\n",fq);
			for(i=0;i<flag;i++){
				fputs("	",fq);
			}
			continue;
		}
		
		else if(ch=='}' && jd_flag==0){
			flag--;
			fputs("\n",fq);
			for(i=0;i<flag;i++){
				fputs("	",fq);
			}
			fputc(ch,fq);
			fputs("\n",fq);
			for(i=0;i<flag;i++){
				fputs("	",fq);
			}
			continue;
		}
		
		else if(ch==';' && jd_flag==0){
			fputc(';',fq);
			fputs("\n",fq);
			for(i=0;i<flag;i++){
				fputs("	",fq);
			}
			continue;
		}
		
		fputc(ch,fq);
	}

	fclose(fp);
	fclose(fq);

	return 0;
}
