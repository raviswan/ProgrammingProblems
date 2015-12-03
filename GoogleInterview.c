#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>

int atoiRecursion(char *c, int len);

int asciiToInteger(const char* str){
 	char *c = (char*)str;
 	int len = strlen(str);
 	int i= 0;
 	int val=0;
 	int minusFlag = 1;
 	int term;
 	if(c[0]=='-'){
 		minusFlag = -1;
 		i=1;
 	}
 	if(c[0]=='+'){
 		minusFlag = 1;
 		i=1;
 	}
 				
 	while(i<len){
 		switch (c[i]){
			case 'a':
			case 'b':
			case 'c':
			case 'd':
			case 'e':
			case 'f':
				term = (10+(c[i]-'a'))*pow(16,len-1-i);
				break;
			case 'A':
			case 'B':
			case 'C':
			case 'D':
			case 'E':
			case 'F':
				term = (10+(c[i]-'A'))*pow(16,len-1-i);
				break;
			case '0':
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			case '8':
			case '9':
				term = (c[i]-'0')*pow(10,len-1-i);
				break;
			default:
				printf ("invalid entry\n");
				exit(0);
		}
 		val += term;
 		i++;
 	}
 	return minusFlag*val;
 }


 int ascToInt(char *c){
 	int len = strlen(c)-1;
 	int sign=1;
 	if(c[0]=='-'){
 		sign= -1;
 		c = c+1;
 		len = len-1;
 	}
 	int val = atoiRecursion(c,len);
 	printf("val=%d\n",val);
 	return sign*val;
}

int atoiRecursion(char* c, int len){
	int term;
	if (*c=='\0'){
		return 0;
	}
	term = (*c - '0')*pow(10,len) + atoiRecursion(c+1,len-1);
	printf("term=%d\n",term);
	return term;
}

// Recursive function to compute atoi() Not mine
int myAtoiRecursive(char *str, int n)
{
    // Base case (Only one digit)
    if (n == 1)
        return *str - '0';
 
    // If more than 1 digits, recur for (n-1), multiplu result with 10
    // and add last digit
    return (10 * myAtoiRecursive(str, n - 1) + str[n-1] - '0');
}

 int main(){

 	char str[]="985";
 	//printf("Value of %s is %d\n",str,asciiToInteger(str));

 	printf("Recursion: Value of %s is %d func=%d\n",str,ascToInt(str), myAtoiRecursive(str,strlen(str)));

 	return 0;
 }

 