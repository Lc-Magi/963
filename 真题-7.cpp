#include <iostream>
#include <string>

using namespace std;

int main()
{
	int n;
	cin>>n;
	int a[n];
	int max=0,min=0;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int count =0;
	for(int i=0;i<n;i++){
		max=min=a[i];
		for(int j=i+1;j<n;j++){
			if(max<a[j]) max=a[j];
			if(min>a[j]) min=a[j];
			if((max-min)==(j-i)) count++;
		}
	}
	cout << count+n <<endl;
	return 0;
}
