#include <iostream>
#include <stack>

using namespace std;

void reverseWithStack(char* str){
	stack<char> s;
	for(int i=0;i<strlen(str);i++)
		s.push(str[i]);
	int i=0;
	while(!s.empty()){
		str[i] = s.top();
		s.pop();
		i++;
	}

	str[i]='\0';

	printf("reversed string with Stack=%s\n",str);
}

void palindromeWithStack(char* str){
	stack<char> s;
	for(int i=0;i<=strlen(str)/2;i++){
		s.push(str[i]);
	}

}
void reverseWithPointer(char* str){

	size_t i = 0;
	size_t j = strlen(str)-1;
	char temp;
	while(i<=j){
		temp = str[i];
		str[i]=str[j];
		str[j]=temp;
		i++;
		j--;
	}
	printf("reversed string with Pointer =%s\n",str);


}

int main(){
	char str[]="raman";
	char str1[]="RamanVishy";
	reverseWithStack(str1);
	reverseWithPointer(str1);

	

}