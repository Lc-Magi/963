#include <iostream>
#include <iomanip>

using namespace std;

int main(){
	int n,j=0;
	cin>>n;
	int a[n],b[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(a[i]!=0){
		 b[j]=a[i];
		 j++;
		 }
	}
	cout<<j<<endl;
	for(int i=0;i<j;i++)
	cout<<b[i]<<" ";
	cout<<endl;
	return 0;
}
