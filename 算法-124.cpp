#include <iostream>
#include <algorithm>
#include <string.h>

using namespace std;

int dp[101][101];
int a[101][101];

int main(){
	int n;
	cin>>n;
	memset(a,0,sizeof(a));
	memset(dp,0,sizeof(dp));
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			cin>>a[i][j];
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			dp[i][j]=max(dp[i-1][j-1]+a[i][j],dp[i-1][j]+a[i][j]);
		}
	}
	int s=0;
	for(int i=1;i<=n;i++){
		if(s<dp[n][i]) s=dp[n][i];
	}
	cout<<s<<endl;
	return 0;
}
