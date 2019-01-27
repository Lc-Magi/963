#include <iostream>
#include <string.h>

using namespace std;

int main(){
	int n,m,k;
	cin>>n>>m;k=(n-1)/100 +1;
	int a[n+1],b[k],c[k];
	memset(b,0,sizeof(b));memset(c,0,sizeof(c));
	for(int i=1;i<=n;i++)  {
         cin>>a[i];
		 b[(i-1)/100]+=a[i];
		 if(c[(i-1)/100]<a[i]) c[(i-1)/100]=a[i];
		}
	int p,x,y,f;int s[m];
	f=0;memset(s,0,sizeof(s));
	for(int i=0;i<m;i++){
		p=x=y=0;
		cin>>p>>x>>y;
		if(p==1) {
			if(y>c[(x-1)/100])  c[(x-1)]=y;
		//	if(x==89 ||x==84 ||x==78)  cout<<a[x]<<"--";
			b[(x-1)/100]=b[(x-1)/100]-a[x]+y;		
		    a[x]=y;
		 //   if(x==89 ||x==84 ||x==78)  cout<<a[x]<<"--"<<b[(x-1)/100]<<endl;
		}
		else if(p==2){
			for(int j=(x-1)/100;j<=(y-1)/100;j++) s[f]+=b[j];
			for(int j=x-1;j>(x-1)/100*100;j--)   s[f]-=a[j];
			for(int j=y+1;j<=((y-1)/100+1)*100;j++)  s[f]-=a[j];
			f++;
		//	if(x==26) cout<<a[84]<<"--"<<b[(x-1)/100]<<endl;
		}
		else if(p==3){
			for(int j=(x-1)/100 +1 ;j<(y-1)/100;j++) if(s[f]<c[j])  s[f]=c[j];
			if(((x-1)/100)!=((y-1)/100)){
			for(int j=x;j<=((x-1)/100 +1)*100;j++)  if(s[f]<a[j])  s[f]=a[j];
			for(int j=y;j>(y-1)/100*100;j--)  if(s[f]<a[j])  s[f]=a[j];
			}
			else{
				for(int j=x;j<=y;j++)  if(s[f]<a[j]) s[f]=a[j];
			}
			f++;
		}
	}
	for(int i=0;i<f;i++) cout<<s[i]<<endl;
	return 0;
}
