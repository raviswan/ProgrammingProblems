/*
The first 12 digits of pi are 314159265358. We can make these digits into an expression evaluating to 27182 (first 5 digits of e) as follows:

3141 * 5 / 9 * 26 / 5 * 3 - 5 * 8 = 27182   
or 
3 + 1 - 415 * 92 + 65358 = 27182

Notice that the order of the input digits is not changed. Operators (+,-,/, or *) are simply inserted to create the expression.  

Write a function to take a list of numbers and a target, and return all the ways that those numbers can be formed into expressions evaluating to the target. Do not use the eval function in Python, Ruby or JavaScript

For example: 
f("314159265358", 27182) should print:      

3 + 1 - 415 * 92 + 65358 = 27182 
3 * 1 + 4 * 159 + 26535 + 8 = 27182 
3 / 1 + 4 * 159 + 26535 + 8 = 27182 
3 * 14 * 15 + 9 + 26535 + 8 = 27182 
3141 * 5 / 9 * 26 / 5 * 3 - 5 * 8 = 27182
 */

#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<char> operand = {'+','-','*','/'};

long compute(long& op1, long& op2, char& operand){
	int result;
	switch(operand){
		case '+':
			result = (op1+op2);
			break;
		case '-':
			result = op1 - op2;
			break;
		case '*':
			result = op1*op2;
			break;
		case '/':
			result = op1/op2;
			break;
		default:
			break;

	}
	return result;
}

void evalExpression(string& input, long& output, long& result){
	size_t len = 0;
	size_t i=0;
	size_t j =0;
	long op1;
	long op2;
	while(i<operand.size()){
			op1 = stol(input[i]);
			op2 = stol(str.substr(i+1:string::npos));
			result += compute(op1,op2,operand[i]);
			if(result==output)
				cout<<op1<<operand[i]<<op2;
			else
				op2=stol(str.substr(i+1:))


		}


	}
}
int main(){
	long result;
	string input("314159265358");
	long output = 27182;
	
	evalExpression(input, output,result);

}



}