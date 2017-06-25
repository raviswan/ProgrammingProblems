#include <iostream>
using namespace std;

int longest_flat(int *array, int array_length) {
    int count = 1;
    int maxCount  = 1;
    int i =1;
    while(i<array_length){
        if(array[i]==array[i-1]){
            count++;
        }
        else{
            count=1;
        }
        if(count>maxCount){
            maxCount = count;
        }
        i++; 
    }
    return maxCount;
        
        
}

int main(){
    int a[]={1,1,1,2,2,2,2,2,2,2,2,3,3,4,4,4,4,4};
    int val = longest_flat(a,sizeof(a)/sizeof(*a));
    cout<<val<<endl;

}