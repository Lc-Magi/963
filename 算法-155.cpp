/*
#include <iostream>

using namespace std;

int gongyin(int a,int b){
	if(b%a==0) return a;
	else gongyin(b%a,a);
}

int main(){
	int a,b,c,d,e,f;
	e=f=0;
	cin>>a>>b>>c>>d;
	while(a>b){
		a=a-b;
		e++;
	}
	while(c>d){
		c=c-d;
		f++;
	}
	int m=gongyin(a,b);a/=m;b/=m;
	int n=gongyin(c,d);c/=n;d/=n;
	if(e==f && a==c && b==d) m=1;else m=0;
	if(e<f ||(e==f && (float(a)/float(b))<(float(c)/float(d)))) n=1;else n=0;
	cout<<"zrf is:"<<a+e*b<<"/"<<b<<"; ";
	cout<<"ssh is:"<<c+f*d<<"/"<<d<<endl;
	cout<<"(zrf==ssh) is:"<<m<<"; ";
	cout<<"(zrf<ssh) is:"<<n<<endl;
	return 0;
}
*/
std::ostream &operator<<(std::ostream &stream,const zrf_Ratio& op)
{
 stream<<op.num<<"/"<<op.den;
 return stream;
}
std::istream& operator>>(std::istream &stream, zrf_Ratio& op)
{
 stream>>op.num>>op.den;
 return stream; 
}
bool operator==(const zrf_Ratio&op1, const zrf_Ratio&op2)
{
 return ((op1.num==op2.num)&&(op1.den==op2.den));
}
bool operator<(const zrf_Ratio&op1, const zrf_Ratio&op2)
{
 return ((op1.num*op2.den)<(op2.num*op1.den));
}

