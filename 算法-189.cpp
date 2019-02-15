#include <iostream>

using namespace std;

int main(){
	int n;
	cin>>n;
	long long int s=n;
	for(int i=n-1;i>0;i--){
		s*=i;
		s=s % (long long int)1e10;
		while(s%10==0) s=s/10;
	}
	cout<<s % 10<<endl;
	return 0;
}
