
/*The goal is walk the grid of size mxn from top corner to bottom right. 
Moving every box to the right is printed R, and moving every box bottom is D.
You can reverse direction.
For 2x2 matrix, answer is : DR, RD
*/

#include <iostream>
#include <array>
#include <vector>

using namespace std;

array<char, 2> a = {'D', 'R'};


void printVector(vector<char>* v){
	for(auto i:*v){
			cout<<i;
	}
	cout<<endl;
}

void findRouteHelper(array<char,2> a, int sz, int rowCount, int colCount, vector<char>* v){
	if(v->size() == sz){
		printVector(v);
		return;
	}
	for(auto i: a){
		if(rowCount && i == 'D'){
			v->push_back(i);
			--rowCount;
			findRouteHelper(a, sz, rowCount, colCount, v);
			v->pop_back();
			++rowCount;
		}
		if(colCount && i == 'R'){
			v->push_back(i);
			--colCount;
			findRouteHelper(a, sz, rowCount, colCount, v);
			v->pop_back();
			++colCount;
		}
		
	}
	
	
}

void findRoute(int r, int c){
	vector<char> v;
	findRouteHelper(a, (r-1)+(c-1), r-1, c-1, &v);
}


int main(){
	findRoute(3,3);
}