#include <iostream>
#include <vector>

using namespace std;

int Sum(int n){
	if(n==0) return 0;
	int i;
	cin>>i;
	return i+Sum(n-1);
}

int Pjun(int m,int n){
	return m/n;
}

int main(){
	int n;
	cin>>n;
	int m;
	m=Sum(n);
	cout<<m<<" "<<Pjun(m,n)<<endl;
	return 0;
}
	
