#include <iostream>
#include <iomanip>
#include <string.h>

using namespace std;

int main(){
	int n,m,s;
	cin>>n>>m>>s;
	int a[n][m],b[m][s],c[n][s];
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++)
		cin>>a[i][j];
	}
	for(int i=0;i<m;i++){
		for(int j=0;j<s;j++)
		cin>>b[i][j];
	}
	memset(c,0,sizeof(c));
	for(int i=0;i<n;i++){
		for(int j=0;j<s;j++){
			for(int k=0;k<m;k++)
			   c[i][j]+=a[i][k]*b[k][j];
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<s;j++){
			cout<<c[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}
