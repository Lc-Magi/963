#include <iostream>
#include <string.h>

using namespace std;

int main(){
	int n,s,k=0;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++) cin>>a[i];
	s=a[0];
	for(int i=0;i<n;i++){
		if(s<a[i]) {
			s=a[i];
			k=i;
		}
	}
	cout<<s<<" "<<k<<endl;
	return 0;
}
