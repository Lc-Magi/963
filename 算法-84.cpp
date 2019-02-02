#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main(){
	string a;
	cin>>a;
	for(int i=0;i<a.length() ;i++){
		if(a[i]<='Z' && a[i]>='A'){
		a[i]=char(a[i]-'A'+'a');
		continue;	}
		if(a[i]<='z' && a[i]>='a') 
		a[i]=char(a[i]+'A'-'a');
	}
	cout<<a<<endl;
	return 0;
}
