#include <iostream>
#include <string.h>
#include <algorithm>

using namespace std;

int main(){
	int T,n,t;
	cin>>T;t=T;
	int s[T]={0};
	while(T--){
		cin>>n;
		int a[n],b[n],c[n]={0};
		for(int i=0;i<n;i++) cin>>a[i];
		for(int i=0;i<n;i++) cin>>b[i];
		sort(a,a+n);
		sort(b,b+n);
		for(int i=0;i<n;i++){
			c[i]=a[i]*b[n-i-1];
		}
		for(int i=0;i<n;i++) s[T]+=c[i];		
	}
	for(int i=t-1;i>=0;i--) cout<<s[i]<<endl;
	return 0;
}
