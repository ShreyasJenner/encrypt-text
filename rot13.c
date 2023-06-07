//program to implement rot13 encryption

#include <stdio.h>
#include <string.h>

int main()
{
	char gmail[100];
	scanf("%s",gmail);
	
	for(int i=0;i<strlen(gmail);i++)
	{
		if((int)gmail[i]>109)
			gmail[i] -= 13;
		else
			gmail[i] += 13;
	}

	printf("%s\n",gmail);
	
	return 0;
}
