#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Del.c"
#include "headfile_indent.c"
#include "Clean.c"

#include "KR.c"
#include "Allman.c"
#include "GNU.c"
#include "Whitesmiths.c"
#include "Horstmann.c"
#include "Pico.c"
#include "Ratliff.c"
#include "Lisp.c"


char ch;
FILE *fp,*fq;

int main(int argc, char *argv[]){
	printf("Please make sure that there is no such file named as 'ing.c' or 'h_ing.c'\n");
	printf("Press Enter to continue or Ctrl+C to quit\n");
	getchar();

	if(argv[2][0] != '-'){
		printf("ERROE: Please add a '-' before option\n");
		exit(1);
	}

	//打开源程序文件，创建目标文件
	else if( (fp=fopen(argv[1],"r"))==NULL || (fq=fopen(argv[3],"w"))==NULL){
		printf("ERROR: Can not find open %s\n",argv[1]);
		exit(1);
	}

	else{
		del(argc,argv);//去掉源代码中的缩进和换行
		head();
		if(argv[2][1]=='k'){
			printf("Style: K&R and variants\n");
			KR(argc,argv);
			clean();
		}
			
		else if(argv[2][1]=='a'){
			printf("Style: Allman\n");
			Allman(argc,argv);
			clean();
		}

		else if(argv[2][1]=='g'){
			printf("Style: GNU\n");
			GNU(argc,argv);
			clean();
		}
		
		else if(argv[2][1]=='w'){
			printf("Style: Whitesmiths\n");
			Whitesmiths(argc,argv);
			clean();
		}
			
		else if(argv[2][1]=='h'){
			printf("Style: Horstmann\n");
			Horstmann(argc,argv);
			clean();
		}
			
		else if(argv[2][1]=='p'){
			printf("Style: Pico\n");
			Pico(argc,argv);
			clean();
		}
		
		else if(argv[2][1]=='r'){
			printf("Style: Ratliff\n");
			Ratliff(argc,argv);
			clean();
		}
			
		else if(argv[2][1]=='l'){
			printf("Style: Lisp\n");
			Lisp(argc,argv);
			clean();
		}
		else{
			printf("ERROR: No such option\n");
			printf("Please read 'BEFORE_USE'\n");
			clean();
			exit(1);
		}
	}

	fclose(fp);
	fclose(fq);

	return 0;

}
