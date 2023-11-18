//List (shell)

#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<stdlib.h>
#include<dirent.h>

/*  dirent.h is the header in the C POSIX library for the C programming language that contains 
    constructs that facilitate directory traversing. The function is not part of the C standard, but
    is considered "pseudo-standard" and is usually portable between platforms. 

    struct dirent 
    {
        ino_t d_ino ;   file serial number
        char d_name[];  name of entry 
    }
*/

void list(char *tok2,char *tok3)
{
	DIR *dp;
	int c=0;
	struct dirent *dir;
	dp=opendir(tok3);
	if(dp==NULL)
	printf("%s directory not exist",tok3);
	else
	{
			if(strcmp(tok2,"n")==0)//No of files in directory
			{
				while((dir=readdir(dp))!=NULL)
				c++;
				printf("No. of files in directory = %d",c);
			}

			if(strcmp(tok2,"f")==0)//filenames in directory
			{
				while((dir=readdir(dp))!=NULL)
				printf("%s\n",dir->d_name);
			}

			if(strcmp(tok2,"i")==0)//Directory name and number
			{
				while((dir=readdir(dp))!=NULL)
				printf("%s\t\t%d\n",dir->d_name,dir->d_ino);
			}
		
	}
}

void main(int argc,char *argv[])
{
	char cmd[20],tok1[20],tok2[20],tok3[20],tok4[20];
	while(1)
	{
		printf("\nMyShell $:");
		gets(cmd);
		if(strcmp(cmd,"exit")==0)
		exit(0);
		int ch=sscanf(cmd,"%s%s%s%s",tok1,tok2,tok3,tok4);
		if(ch==3)
		{
			if(strcmp(tok1,"list")==0)
			list(tok2,tok3);
			continue;
			
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