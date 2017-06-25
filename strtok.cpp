#include <iostream>
#include <cstring>
using namespace std;
int main(int argc, char** argv){
	char str[256] = "What, is this world, we are doing. I don't know.";
	char* tok;
	tok = strtok(str," .,");
	while( tok != NULL){
		cout<<tok<<endl;
		tok = strtok(NULL," .,");
	}
}
