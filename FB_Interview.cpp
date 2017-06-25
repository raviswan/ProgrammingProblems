/*oneEditDistanceApart
true
cast
cart

false
cbdt
cast

false
cats
ctds

true
cats
cts

false
car
cast  
*/

#include <iostream>
#include <string>

using namespace std;

bool oneEditCheck(string str1, string str2){
    /*s1 is the shorter of the two strings, if not equal*/
    string s1 = (str1.length() < str2.length())? str1:str2;
    string s2 = (str1.length() < str2.length())? str2:str1;
    cout<<"s1="<<s1<<"s2="<<s2<<endl;
    if(s2.length()-s1.length() > 1)
      return false;
    bool diffCount = false;
    int index1=0;
    int index2=0;

    while(index2<s2.length() && index1<s1.length()){
      cout<<"s1=" <<s1[index1]<<"\ns2="<<s2[index2]<<endl;
      if(s1[index1]!=s2[index2]){
        if(diffCount)
          return false;
        diffCount = true;
        if(s1.length() == s2.length())
          index1++;
      }
      else{
        index1++;
      }
      index2++;
      
    }
    return true;

}


int main(){
  string s1("car");
  string s2 = "HelloRam";
  cout<<"substring:"<<s2.substr(1,4)<<" "<<s2.substr(s2.find("He"),5)
  <<" "<<s2.substr(s2.find_first_of("hle"),5)<<endl;
  cout<<s1<<" "<<s2<<" "<<"\n"<<oneEditCheck(s1,s2)<<endl;
  return 0;
}