#include <iostream>
#include <algorithm>

using namespace std;

int main(){
	int m,n;
	cin>>m>>n;
	// ��������m,n�ǵ�ma+nb=1,�ɵ�iΪ����0����������ʱ
	//ab-a-b+i=ab-a-b+i(ma+nb)=a(b-1+mi)+b(ni-1)
	//so,
	cout<<m*n-m-n<<endl;
	return 0;
}
