#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int Com(string a,string b){
	int n=0;
	for(int i=0;i<=a.length() -b.length();i++ )
	if(a.find(b,i) !=string::npos) {
		i=a.find(b,i);
		n++;
	}
	return n;
}

int main(){
	int l;
	cin>>l;
	string a,b,c[60];
	cin>>a;
	int m[60]={0};
	for(int i=0;i<=a.length() -l;i++){
		b=string(a,i,l);
		c[i]=b;
        m[i]=Com(a,b);
	}
	l=0;
	for(int i=0,n=0;i<60;i++)
	if(n<m[i]){
		n=m[i];
		l=i;
	}
	cout<<c[l]<<endl;
	return 0;
}
