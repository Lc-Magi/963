#include <iostream>
#include <string.h>
#include <math.h>

using namespace std;

int main(){
	int n,m,s;
	cin>>n;
	int flag=0;
	if(n>2){
	s=6;m=2;
	for(int i=5;m<n;i++){
		flag=1;
		for(int j=2;j<=sqrt(i);j++){
		   if(i%j ==0) flag=0;
		}
		if(flag==1)  {
			m++;
			s=(s*i)%50000;
		}
	}
	}
	if(n==2) cout<<6<<endl;
	if(n==1) cout<<2<<endl;
	if(n<1) cout<<0<<endl;
	if(n>2) cout<<s<<endl;
	return 0;
}
