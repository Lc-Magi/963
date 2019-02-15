#include <iostream>
#include <algorithm>

using namespace std;

int main(){
	int m,n;
	cin>>m>>n;
	// 存在整数m,n是的ma+nb=1,可得i为大于0的任意整数时
	//ab-a-b+i=ab-a-b+i(ma+nb)=a(b-1+mi)+b(ni-1)
	//so,
	cout<<m*n-m-n<<endl;
	return 0;
}
