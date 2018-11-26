#include<stdio.h>
#include<stdlib.h>
#include<string.h>;
int Allman(int argc, char *argv[])
{
	FILE *fp,*fq;
	char ch;
	int i=0;
	if( (fp=fopen("h_ing.c","r")) == NULL || (fq=fopen(argv[3],"w")) == NULL )
	{
		printf("Can not open h_ing.c file\n");
		exit(1);
		
	}
	int flag=0;
	while((ch=getc(fp)) != EOF)
	{
		if(ch=='{')
		{
			flag++;
			if(flag>0)
			{
				fputs("\n",fq);
				for(i=0;i<flag-1;i++)
				{
					fputs("	",fq);
					
				}
				
			}
			fputc(ch,fq);
			fputs("\n",fq);
			for(i=0;i<flag;i++)
			{
				fputs("	",fq);
				
			}
			continue;
			
		}
		else if(ch=='}' && jd_flag==0)
		{
			flag--;
			fputs("\n",fq);
			for(i=0;i<flag;i++)
			{
				fputs("	",fq);
				
			}
			fputc(ch,fq);
			fputs("\n",fq);
			for(i=0;i<flag;i++)
			{
				fputs("	",fq);
				
			}
			continue;
			
		}
		else if(ch==';')
		{
			fputc(';',fq);
			fputs("\n",fq);
			for(i=0;i<flag;i++)
			{
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
