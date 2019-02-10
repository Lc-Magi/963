#include <iostream>
#include <algorithm>
#include <string.h>

using namespace std;

long long int dp[16][16];

int main(){
	memset(dp,0,sizeof(dp));
	int n,k;
	cin>>n>>k;
	long long int a[n],sum=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum+=a[i];
		dp[i][0]=sum;
	}
	for(int i=1;i<=n;i++){
	    for(int j=1;j<=i-1;j++){
	    	for(int m=2;m<=i;m++){
	    		dp[i][j]=max(dp[i][j],dp[m-1][j-1]*(dp[i][0]-dp[m-1][0]));
			}
		}
	}
	cout<<dp[n][k]<<endl;
	return 0;
}
