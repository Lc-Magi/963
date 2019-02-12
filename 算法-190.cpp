#include <iostream>
#include <algorithm>

using namespace std;

int main(){
	long long int n;
	cin>>n;
	long long int a[100];
	long long int s=1;
    int num=0;
    for (int i=2;i*i<=n;i++)
        {
            if (n%i==0) a[num++]=i;
            while(n%i==0) n=n/i;
        }
    if (n>1) a[num++]=n;
    for (int i=0;i<num;i++)
        s*=a[i];
    cout<<s<<endl;
    return 0;
}
