#include <iostream>

using namespace std;

int zuhe(int k,int n){
	if(k==0 ||k==n){
		return 1;
	}
	else if(k>0 && k<n){
		return zuhe(k,n-1)+zuhe(k-1,n-1);
	}
}

int main(){
	int k,n;
	cin>>k>>n;
	int m;
	m=zuhe(k,n);
	cout<<m<<endl;
	return 0;
}
