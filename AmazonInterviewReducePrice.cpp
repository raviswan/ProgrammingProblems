#include <iostream>
#include <string>
#include <cmath>
#include <sstream>
//Amazon echo 1 priced at $45  and echo 2 other priced at $34.99.

using namespace std;
static int cnt = 0;


void reducePrice(string& s, int len, int reduce){
	int pos = s.size() -1 ;
	int k = pos;
	float newVal;
	int spacePos = 0;
	string priceStr ; 
	int j = len - 1;
	string newStr;
	int nSize;
	std::ostringstream ss;
	string temp;
	while( j >= 0  && (pos = s.rfind('$', j)) !=  string::npos){
		//If space found after $,extract integer , compute new value and insert
		if ((spacePos = s.find(' ', pos)) != string::npos){
			priceStr = s.substr(pos+1,spacePos - pos);
			//copy all the values up till space starting from end
			while(j >= spacePos){
				s[k--] = s[j--];
			}
			newVal = stof(priceStr) - stof(priceStr)*reduce/100;
			newVal = floor(newVal*100)/ 100;
			ss.str("");
			ss.clear();
			ss << newVal;
			newStr = ss.str();
			nSize = newStr.size() - 1;	
			while(nSize >= 0){
				s[k--]  = newStr[nSize--];
			}
		}
		else{
			priceStr = s.substr(pos+1, len-1- pos);
			newVal = stof(priceStr) - stof(priceStr)*reduce/100;
			newVal = floor(newVal*100)/ 100;
			ss.str("");
			ss.clear();
			ss << newVal;
			newStr = ss.str();
			nSize = newStr.size() - 1;
			while(nSize >= 0){
				s[k--]  = newStr[nSize--];
			}
		}
		s[k--] = s[pos--];
		j = pos;
	}
	//The first part of the string before the very first occurnece of $
	while(j>=0){
		s[k--] = s[j--];
	}
	if(k >= 0)
		s = s.substr(k+1, string::npos);
	cout<<s<<endl;

}

void reducePriceHelper(string& s, int reduce){
	int pos = 0;
	int len = s.size();
	bool flag = false;
	while ((pos = s.find('$',pos)) != string::npos){
			++pos;
			cnt += 4;
	}
	s.resize(s.size() + cnt);
	reducePrice(s, len, reduce);

}

int main(){
	string s("The Amazon echo 1 sells for $40 and Echo2 sells for $100 at AMZN");
	reducePriceHelper(s, 11);
}