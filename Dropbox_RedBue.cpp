#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

void getSubPattern(string& input,size_t& pos,string& subPattern){
	size_t i = pos;
	size_t found = input.find(input[i],pos+1);
	vector<char> v;
	while(found != string::npos){
		v.push_back(input[i]);
		i++;
		found = input.find(input[i],found+1);
	}
	std::string str(v.begin(),v.end());
	cout<<"found substring"<<str<<endl;
	subPattern = str;

}

bool wordPattern(string& pattern,string& input,map<char,string>& mMap){
	size_t i = 0;
	size_t pos = 0;
	size_t pIndex = 0;
	string subPattern;
	while(pIndex < pattern.size()){
		auto it = mMap.find(pattern[pIndex]);
		if 	(it != mMap.end()){
			
			if(it->second != subPattern)
				cout<<"false"<<endl;
				return false;
		}
		else{
			getSubPattern(input,pos,subPattern);
			mMap[pattern[pIndex]] = subPattern;
			pIndex++;
			pos += subPattern.size();
			cout<<"pos= "<<pos<<endl;
		}
	}
	cout<<"true"<<endl;
	return true;
}

int main(){
	string pattern("abba");
	string input("redbluebluered");
	map<char,string> mMap;
	for (auto i: mMap)
		cout<<i.first<<" "<<i.second<<endl;

	cout<<wordPattern(pattern,input,mMap)<<endl;
}