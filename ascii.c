//reads a file netcat that contains ascii code
//converts ascii code to characters

#include <stdio.h>
#include <stdlib.h>

int main()
{
	FILE *fileptr;
	int num;
	fileptr = fopen("../pico_ctf/netcat","r");				//location of netcat file
	
	if(fileptr==NULL)
	{
		printf("Error reading file\n");
		exit(0);
	}
	
	int flag = 1;
	while(flag!=EOF)
	{
		fscanf(fileptr,"%d",&num);
		printf("%c",num);
		flag = getc(fileptr);						//checks if fileptr is at eof
	}

	fclose(fileptr);

	return 0;
}
