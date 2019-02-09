#include <iostream>
#include <iomanip>

using namespace std;

int main(){
	char a;
	int b,c;
	cin>>a>>b>>c;
	if(a=='+') cout<<c+b<<endl;
	else if(a=='-') cout<<b-c<<endl;
	else if(a=='*') cout<<c*b<<endl;
	else if(a=='/') cout<<b/c<<endl;
	return 0;
}
