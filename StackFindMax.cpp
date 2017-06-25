#include <iostream>
#include <stack>

using namespace std;
class Stack{
public:
	Stack(){

	}
	Stack(int& a){
		Push(a);
	}
	int Pop(){
		if(s.empty()){
			throw length_error("empty stack");
		}
		int a = s.top().first;
		s.pop();
		return a;
	}

	void Push(int& c){
		if(!s.empty()){
			s.emplace(c,(c > s.top().second)? c : s.top().second) ;
		}
		else{
			s.emplace(c,c) ;
		}
		
	}

	int getMax(){
		if(!s.empty())
			return (s.top().second);
		else
			throw length_error("max():empty stack");
	}


private:
	stack<pair<int,int> > s;

};


int main(){
	int arr[]={1,34,5,2,4,2,344};
	Stack s;
	try{
		for (int i=0;i<sizeof(arr)/sizeof(*arr);i++){
			s.Push(arr[i]);
	}
		catch(exception e){
			cout<<e

		}
	s.Pop();
	cout<<"getMax = "<<s.getMax()<<endl;

	
}