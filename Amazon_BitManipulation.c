/*
Amazon interview 
MSB=1
LSB=0
Valid:  111100000000000
Valid:  100000000000000
Valid:  111111111111110
Invalid 110011000000000
 */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv){
	unsigned int a[] = {0x80000000,0xFFF00000,0xFFFE0000};
	for (int i=0;i<sizeof(a)/sizeof(a[0]);i++){
		/*Get twos complement and check for power of 2 as below
		as only one digit should be 1 after 2s complement for a valid
		case*/
		unsigned int c = ~a[i]+1;    
		printf("%x %x\n",a[i],c);
		((c&(c-1))==0) ? printf("yes\n"):printf("no\n");
	}
	return 0;


}