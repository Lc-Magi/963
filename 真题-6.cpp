#include <iostream>
#include <string>

using namespace std;

int main()
{
	string a,b;
	cin>>a>>b;
	int count=0;
	for(int i=0;i<a.length();i++){
		if(a[i]!=b[i]){
			if(a[i+1]=='*') a[i+1]='o';
			else a[i+1]='*';
			count++;
		}
	}
	cout << count<<endl;
	return 0;
}
