oneEditDistanceApart
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

car
cast  
  
  
  
  
  bool oneEditCheck(string s1, string s2){
  
    string s1 = (s1.length() < s2.length())? s1:s2;
    string s2 = (s1.length() < s2.length())? s2:s1;
    bool matchFound = false;

   bool diffCount = false;
   
    for(int i=0;i<s1.length();i++){
      if(s1[i]!=s2[i]){
        if(diffCount)
          return false;
        diffCount = true;
      }
   
    while(*p1 != '\0'){
      while(*p2 != '\0'){
        if (*p1 == *p2){
            matchFound = true;
            /*matchfound*,move on*/
            break;
        else{
          p2++;
        }
      }
        
      if(matchFound==false){
        diffCount++;
        if(diffCount > 1)
          return false;
        p1++;
        p2 = str;
      }
      else{
        p1++;
        p2++;
      }
       
    }
    
    return true;
}
  