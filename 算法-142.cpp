#include <iostream>
#include <algorithm>
#include <iomanip>

using namespace std;

struct point{
	float num;
	float flo;
};

int main(){
	point a,b,c;
	char d;
	cin>>d;
	cin>>a.num>>a.flo;
	cin>>b.num>>b.flo;
	if(d=='+'){
		c.num=a.num+b.num;
		c.flo=a.flo+b.flo;
	}
	else if(d=='-'){
		c.num=a.num-b.num;
		c.flo=a.flo-b.flo;
	}
	else if(d=='*'){
		c.num=a.num*b.num-a.flo*b.flo;
		c.flo=a.flo*b.num+a.num*b.flo;
	}
	else if(d=='/'){
		c.num=(a.num*b.num+a.flo*b.flo)/(b.flo*b.flo+b.num*b.num);
		c.flo=(a.flo*b.num-a.num*b.flo)/(b.flo*b.flo+b.num*b.num);
	}
	d=' ';
	cout<<fixed<<setprecision(2)<<c.num<<"+"<<setprecision(2)<<c.flo<<"i"<<endl;
	return 0;
} 
