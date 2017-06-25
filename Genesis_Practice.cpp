#include <iostream>
#include <vector>

using namespace std;

bool validate(const string & s)
{
    for(int i = 0; i < s.length(); i++)
    {
        if(s[i] < 'a' || s[0] > 'z')
        {
            return false;
        }
    }
    
    return true;
}

void sort(string * s)
{
    for(int i = 1; i < s->length(); i++)
    {
        int j = i;
        char a = (*s)[j-1];
        char b = (*s)[j];
        
        while(j > 0 && (*s)[j-1] > (*s)[j])
        {
            char tmp = (*s)[j - 1];
            (*s)[j - 1] = b;
            (*s)[j] = tmp;
            j--;
        }
    }
}

void uniq(string * s)
{
    char t[26] = {0};
    
    for(int i = 0; i < s->length(); i++)
    {
        char c = (*s)[i];
        t[(c - 'a')] = 1;
    }
    
    *s = "";
    
    for(int i = 0; i < 26; i++)
    {
        if(t[i] != 0)
        {
            *s += (i + 'a');
        }
    }
}

void genperms(
    vector<string> & permutations, 
    const string & p, 
    int nextIndex, 
    const string & s, 
    const string & alphabet)
{
    char next = s[nextIndex];
    
    for(int i = 0; i < alphabet.length(); i++)
    {

        char c = alphabet[i];
        cout<<"i="<<i<<" c="<<c<<endl;
        string px = p + c;
        cout<<"p="<<p<<" "<<"px="<<px<<endl;
        
        if(px.length() < s.length() && permutations.size()<)
        {
            genperms(permutations, px, nextIndex + 1, s, alphabet);
        }
        else
        {
            if(px < s)
            {
                permutations.push_back(px);
            }
            cout<<"permuations.size()="<<permutations.size()<<endl;
            for(const string& c: permutations){
                cout<<c<<endl;
            }
            cout<<endl<<endl;
        }
    }
}

int main()
{
  string s;
  
  getline(cin, s);
    
  if(validate(s) != true)
  {
    cout << s << endl;
    cout << "-1" << endl;
    //return 0;
  }
    
  string alphabet = s;
  vector<string> permutations;
  
  sort(&alphabet);
  cout<<"sorted "<<alphabet<<endl;
  
  uniq(&alphabet);
   cout<<"unique "<<alphabet<<endl;
 
  genperms(permutations, "", 0, s, alphabet);
  
  cout << s << endl;
  cout << permutations.size() << endl;
  
  return 0;
}