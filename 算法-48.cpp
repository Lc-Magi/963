#include <iostream>
#include <string.h>

using namespace std;

int main(){
	int n,m;
	cin>>n>>m;
	int a[n][m];
	memset(a,0,sizeof(a));
	int p,q;
	for(int i=0;i<m;i++){
		cin>>p>>q;
		a[p-1][i]=1;
		a[q-1][i]=-1;
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
} 
