#include <iostream>

using namespace std;

int gongyin(int a,int b){
	if(b%a==0) return a;
	else gongyin(b%a,a);
}

int main(){
	int a,b;
	cin>>a>>b;
	int c;
	c=gongyin(a,b);
	cout<<(a*b)/c<<endl;
    return 0;	
}
