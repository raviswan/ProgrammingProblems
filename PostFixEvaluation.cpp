#include <iostream>
#include <vector>
#include <stack>
#include <sstream>
using namespace std;

bool isOperator(char* c){
	switch(*c){
		case '+':
		case '-':
		case '*':
		case '/':
			return true;
		default:
			return false;
	}
}

int operation(char* c, int op1, int op2){
	switch(*c){
		case '+':
			return op1 + op2;
		case '-':
			return op1 - op2;
		case '*':
			return op1*op2;
		case '/':
			return op1/op2;
		default:
			break;
	}
	return 0;
}

int main(int argc, char** argv){
	char c[256], ch;
	int val;
	stack<int> s;
	int op1,op2;
	string str = "1024";
	string ss("abc");
	cout<<str<<" "<<ss<<endl;
	cout<<"enter input on postfix form\n";
	getline(cin,str);
	strcpy(c,str.c_str());
	printf("string=%s\n",c);
	char *a = c;

	while(*a !='\0'){
		if(!isOperator(a)){
			op1 = *a - '0';
			cout<<"op1= "<<op1<<endl;
			s.push(op1);
		}
		/*saw an operaator, pop out last two elements*/
		else{
			op2 = s.top();
			s.pop();
			op1 = s.top();
			s.pop();
			val = operation(a,op1,op2);
			cout<<"val= "<<val<<endl;
			s.push(val);
		}
		a++;
	}
	cout<<"value is :"<<val<<endl;


}