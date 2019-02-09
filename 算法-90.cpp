#include <iostream>
#include <iomanip>

using namespace std;

int main(){
	int n=0;
	cin>>n;
	if(n<=0) return 0;
	long long int a[n]={0};
	int b[n]={0};
	for(int i=0;i<n;i++){
		cin>>a[i];
		for(int j=0;j<=i;j++){
			if(a[i]==a[j])
			b[i]++;
		}
	}
	int m,k;
	m=k=0;
	for(int i=0;i<n;i++){
		if(m<b[i]) {
			k=i;
			m=b[i];
		}
		else if(m==b[i]) {
		   if(a[i]<a[k]) {
		      k=i;
		      m=b[i];
		   }
		}
	}

	if(n>0)
	cout<<a[k]<<endl;
	return 0;
}
