#include <stdio.h>




/* 
Your previous Plain Text content is preserved below:

This is just a simple shared plaintext pad, with no execution capabilities.

When you know what language you'd like to use for your interview,
simply choose it from the dropdown in the top bar.

You can also change the default language your pads are created with
in your account settings: https://coderpad.io/settings

Enjoy your interview!
*/

void swap(int *a, int sPos, int ePos){
  int temp = a[sPos];
  a[sPos] = a[ePos];
  a[ePos] = temp;
}

// Return the number of even integers in the array
int rearrange(int *arr, int arraySize) {
  int oddPos = 0;
  int i = 0;
  int evenCnt = 0;
  //int temp = 0;
  while(i < arraySize){
  
    while(arr[i] % 2 == 0 && i < arraySize){
        ++i;
        ++evenCnt;
    }
    if (i == arraySize)
      return evenCnt;
    
    oddPos = i++;
    while(arr[i] % 2  && i < arraySize){
      ++i;
    }
    if(i == arraySize)
      return evenCnt;
    
    ++evenCnt;
   // temp = arr[oddPos];
   // arr[oddPos] = arr[i];
   // arr[i] = temp;
    swap(arr, oddPos, i);
    // swap(arr[oddPos], arr[i]);
    
    i = ++oddPos;
  }
  return evenCnt;
}




void printArray(int* a, int len){
  for (int i=0 ; i< len; ++i){
    printf(" %d ", a[i]);
  }
  printf("\n");
    
}
    // To execute C, please define "int main()"

int main() {
  //int a[]= {10,8,9,5,6,11,12,14};
  int a[]= {1,1,3,5};
  int arraylen = sizeof(a)/sizeof(a[0]);
  int evenCount = 0;
  printf(" Original array \n");
  printArray(a, arraylen);
  evenCount = rearrange(a, arraylen );
   printf(" Final array \n");
  printArray(a, arraylen );
  printf("even count = %d\n",evenCount);
  return 0;
}