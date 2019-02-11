#include <iostream>
#include <algorithm>

using namespace std;

int GY(int a,int b){
	if(b%a==0) return a;
	else {
	int s=GY(b%a,a);
	return s ;
	}
}

int main(){
	int a[3];int m[3];
	cin>>a[0]>>a[1]>>a[2];
	sort(a,a+3);
	m[0]=GY(a[0],a[2]);
    m[1]=GY(a[1],a[2]);
    m[2]=GY(a[0],a[1]);
    sort(m,m+3);
	cout<<(a[0]*a[1]*a[2]/(m[1]*m[2]))<<endl;
	return 0;
}
