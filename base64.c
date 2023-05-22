//convert base64 text to ascii text 
//in base64 decoding, check index of each character in base 64 table.
//then convert integer index into binary format
//drop first two zeros from binary string for every character and then concat
//resulting strings
//divide res string into groups of 8 and drop last group if it has <8 char
//convert using ascii table; res char are original text

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//function binary converts given number to binary format
//ptr1 is start of string; ptr2 is end of string
void binary(int n,char *ptr1,char *ptr2)
{
	while(ptr1<=ptr2)
	{
		if(n%2)
			*ptr2='1';
		n /= 2;
		ptr2--;
	}
}

//function to find index of character m corresponding to base64 table
int find(char m,char *ptr,char *end)
{
	int pos=0;
	while(ptr<=end && m!=*ptr)
	{
//		printf("%c",*ptr);
		ptr++;
//		printf("%d ",pos);
		pos++;
	}
	return pos;
}

//function to change string to all zero binary string
void zero(char *ptr1, char *ptr2)
{
	while(ptr1<=ptr2)
	{
		*ptr1 = '0';
		ptr1++;
	}
}

int main()
{
	int n,len,j,pos,len1,i;
	
	char base64[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H',			//stores base64 table
			'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P',
			'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X',
			'Y', 'Z', 'a', 'b', 'c', 'd', 'e', 'f',
			'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n',
			'o', 'p', 'q', 'r', 's', 't', 'u', 'v',
			'w', 'x', 'y', 'z', '0', '1', '2', '3',
			'4', '5', '6', '7', '8', '9', '+', '/'};	
	
	printf("Enter text:");	
	char m[100];								//array that stores input text 
	char bin[9];								//binary string array
	scanf("%s",m);
	len = strlen(m);
	len1 = (len*6);
	char decode[len1+1+len];
	decode[len1]='\0';
//	printf("%d\n",len);
	for(j=0;j<len;j++)
	{
		zero(&bin[0],&bin[7]);
//		printf("Initial bin:%s\n",bin);
		pos = find(m[j],base64,&base64[64]);
//		printf("%d ",pos);
//		binary(n,&bin[0],&bin[7]);
		binary(pos,&bin[0],&bin[7]);		
//		printf("bin: %s\n",bin);
		strncpy(&decode[j*6],bin+2,6);					//add 6bits of corresponding text binary version to decode
//		printf("%.6s\n",&decode[j*6]);
//		printf("%-.6s ",bin+2);
	}
//	printf("decode: %s\n",decode);
	
	if(len1%8)
		len1 -= (len1-1)%8;
//	printf("len1:%d\n",len1);
	
	for(j=0;j<len1;j+=8)
	{
		strncpy(bin,decode+j,8);
		i = strtol(bin,NULL,2);					//strtol converts binary string to long integer based on base
		printf("%c",i);
	}
	printf("\n");
	return 0;
}
