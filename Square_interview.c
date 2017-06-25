#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <stdlib.h>

// https://en.wikipedia.org/wiki/Stdarg.h
// http://www.cplusplus.com/reference/cstdarg/

/*Implementing itoa*/
char* sq_itoa(int a){
  char* c = malloc(sizeof(char)*256);
  char temp;
  size_t i =0;
  size_t j;
  size_t len = 0;
  while(a!=0){
    c[i] = a%10+'0';
    a = a/10;
    i++;
    len++;
  }
  j= len-1;
  i=0;
  while(i<=j){
    temp = c[i];
    c[i]=c[j];
    c[j]=temp;
    i++;
    j--;
  }
  c[len] = '\0';
  return c;
}

/*implementing atoi*/
int sq_atoi(char* a){
  int res = 0;
  while(*a != '\0'){
    res = 10*res + *a-'0';
    a++;
  }
  return res;
}


int sq_sprintf(char *buf, char const *fmt, ...)
{
  //char* fmtPtr;
  va_list vl;
  va_start(vl,fmt);
  int param;
  char* str;
  
  if (fmt == NULL) {
    return -1;
  }
  
  while(*fmt != '\0'){
      if(*fmt=='%'){
        fmt++;
        if(*fmt=='d'){
          param = va_arg(vl,int);
          
          str = sq_itoa(param);
          printf("val=%d ,str=%s\n",param,str);
          memcpy(buf,str,strlen(str));
          buf += strlen(str);
          fmt++;
        }
        else if(*fmt=='s'){
          str = va_arg(vl,char*);
          memcpy(buf,str,strlen(str));
          buf += strlen(str);
          fmt++;
        }
      }
      else{
          *buf++ = *fmt++;
      }
        
    }
    *buf = '\0';
    return 0;
      
  
}


int main() {
  int i=13433;
  
  char buf[100];
  char* str = sq_itoa(i);
 
  printf("itoa: %s\n", str);
  free(str);
  
  sq_sprintf(buf, "This is a test case ");
  printf("%s\n", buf);
  
  sq_sprintf(buf, "This is a test case with a %s", "string");
  printf("%s\n", buf);
  
  sq_sprintf(buf, "This is %s %s with %d", "test", "case",i);
  printf("%s\n", buf);
  
  return 0;
}
