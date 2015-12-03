/* The output should be as follows:
f("this is a string") should output (t,h,i,s,i,s,a,s,t,r,i,n,g)
f("thiis iss aa sttringg") should output (i,s,a,t,g)
f("aaabccaaa") should output (a,a)
*/

#include <stdio.h>

size_t findMax(char *str){
  char *p = str;
  size_t max = 1;
  size_t count = 1;
   while(*p != '\0'){
      if(*p == *(p+1))
        count += 1;
      else
        count = 1;
      if(count > max)
        max = count;
      p++;
  }
  return max;
}

int main(){
  char *str = "thiis iss aa sttringg";
  char *p = str;
  size_t count = 1;
  int max = findMax(str);
  //printf("max=%d\n",max);
  while(*p != '\0'){
    if(*p == *(p+1)){
      count += 1;
      //printf("%c count=%ld\n",*p,count);
    }
    else
      count = 1;
    if(count == max)
        printf("%c ",*p);
    p++;
  }
  printf("\n");
  return 0;
}
