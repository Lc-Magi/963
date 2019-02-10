#include <iostream>
#include <algorithm>
#include <string.h>

using namespace std;

int dp[19][19];

int Digui(int m,int n){
	if(m<n) return 0;
    else if(n==0) return 1;
    	else {
    		dp[m-1][n]=Digui(m-1,n);
    		dp[m][n-1]=Digui(m,n-1);
    		return dp[m-1][n]+dp[m][n-1];
		}
}

int main(){
	memset(dp,0,sizeof(dp));
	int m,n;
	cin>>m>>n;
	int s=0;
	s=Digui(m,n);
	cout<<s<<endl;
	return 0;
}
