//Search (shell)

#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<stdlib.h>

void search(char *tok2,char *tok3,char *tok4)//tok2:command tok3:pattern tok4:filename
{
	FILE *fp;
	int lineno=0,count=0;
	char str[50];
	fp=fopen(tok4,"r");
	if(fp==NULL)
	{
		printf("File does not exist");
		exit(0);
	}
	else
	{
		
		if(strcmp(tok2,"f")==0)//First occurance of pattern
		{
			while(!feof(fp))
			{
				fgets(str,50,fp);
				lineno++;
				if(strstr(str,tok3))
				{
				printf("First occurance of '%s' is on line%d\n",tok3,lineno);
				break;
				}
			}
		}

			
		if(strcmp(tok2,"c")==0)//Total number of occurances of pattern
		{
			while(!feof(fp))
			{
				fgets(str,50,fp);
				if(strstr(str,tok3))
				{
					count++;
				}
			}
			printf("Total number occurance of pattern(%s) is %d\n",tok3,count);
		}

		if(strcmp(tok2,"a")==0)//Total occurances of pattern
		{
			while(!feof(fp))
			{
				fgets(str,50,fp);
				lineno++;
				if(strstr(str,tok3))
				{
					printf("%d %s\n",lineno,str);
				}	
			}
			
		}
		
	}
}

void main(int argc,char *argv[])
{
	char cmd[20],tok1[20],tok2[20],tok3[20],tok4[20];
	while(1)
	{
		printf("\nMyShell$:");
		gets(cmd);
		int ch=sscanf(cmd,"%s%s%s%s",tok1,tok2,tok3,tok4);
		if(ch==4)
		{
			if(strcmp(tok1,"exit")==0)
			exit(0);
			
			if(strcmp(tok1,"search")==0)
			{
			search(tok2,tok3,tok4);
			continue;
			}
		}
		if(fork()==0)
		{
			switch(ch)
			{
				case 1:
					execlp(tok1,NULL);
					break;
				case 2:
					execlp(tok1,tok2,NULL);
					break;
				case 3:
					execlp(tok1,tok2,tok3,NULL);
					break;
				case 4:
					execlp(tok1,tok2,tok3,tok4,NULL);
					break;
			}
		}
	}
}