#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(){
	string a,b;
	cin>>a>>b;
	if(a.length() ==b.length() ){
		for(int i=0;i<a.length() ;i++)
		if(a[i]<='Z' && a[i]>='A')
		a[i]=char(a[i]-'A'+'a');
		for(int i=0;i<b.length() ;i++)
		if(b[i]<='Z' && b[i]>='A')
		b[i]=char(b[i]-'A'+'a');
        sort(a.begin() ,a.end() );
        sort(b.begin() ,b.end() );
        if(a==b) cout<<"Y"<<endl;
        else cout<<"N"<<endl;
	}
	else cout<<"N"<<endl;
	return 0;
}
	
	
