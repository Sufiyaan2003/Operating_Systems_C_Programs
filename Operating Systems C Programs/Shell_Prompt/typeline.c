//Typeline (shell)

#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<stdlib.h>

void typeline(char *op,char *fname)
{
	char ch,n1,n2,str[20];
	FILE *fp;
	int lc=0,skip,count=0;
	fp=fopen(fname,"r");
	if(fp==NULL)
		printf("file does not exist\n");
	
	else
		printf("file exist\n");

	if(strcmp(op,"a")==0)
	{
		while(!feof(fp))
		{
			ch=fgetc(fp);
			printf("%c",ch);
		}
	}

	else
	{
		int n=atoi(op);
		if(n>0)
		{
			while(lc<n)
			{
				ch=fgetc(fp);
				if(ch=='\n')
				lc++;
				printf("%c",ch);
			}
		}

		if(n<0)
		{
			while(!feof(fp))
			{
				ch=fgetc(fp);
				if(ch=='\n')
				lc++;
			}
			skip=lc+n;
			fseek(fp,0,SEEK_SET);
			while(fgets(str,80,fp)!=NULL)
			{
				count++;
				if(count<=skip){}
				else
				printf("%s",str);
		 
			}
		}
	}
}

int main(int argc,char *argv[])
{
	char tok1[20],tok2[20],tok3[20],tok4[20],fname[30];
	int choice,f;
	char cmd[40] ;
	while(1)
	{
		printf("\nMyshell $:") ;
		gets(cmd);
		if(strcmp(cmd,"exit")==0)
		exit(0);
		int choice=sscanf(cmd,"%s%s%s%s",&tok1,&tok2,&tok3,&tok4);
		if (choice==3)
		{
			if(strcmp(tok1,"typeline")==0)
			typeline(tok2,tok3);
			continue;
		}
		if(fork()==0)  
		{
			switch(choice)
			{
					  case 1:
						  execlp(tok1,NULL);
						  break; 
					  case 2:
						  execlp(tok1,tok2,NULL) ;
						  break; 
					  case 3:
						  execlp(tok1,tok2,tok3,NULL) ;
						  break; 
					  case 4:
						  execlp(tok1,tok2,tok3,tok4,NULL) ;
						  break; 
			}//switch
			exit(0);
		}//if
	}//while   
}//main