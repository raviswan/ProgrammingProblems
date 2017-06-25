#include <iostream>
#include <vector>
using namespace std;
bool solution(vector<int>& A, int K){
	int n= A.size();
	cout<<"size="<<n<<" last elem="<<A[n-1]<<endl;
	for(int i= 1; i<=n-1;i++){
		if ((A[i]- A[i-1]) != 0 && (A[i]- A[i-1]) != 1 ){
			cout<<"A["<<i<<"]="<<A[i]<<endl;
			cout<<"A["<<i-1<<"]="<<A[i-1]<<endl;
			return false;
		}
	}
	if(A[0] != 1 ||  A[n-1] != K){
		return false;
	}
	else 
		return true;
}


int main(){
	vector<int> A{1,1,1,1,1,2};
	int K =2;
	cout<< solution(A,K)<<endl;

}