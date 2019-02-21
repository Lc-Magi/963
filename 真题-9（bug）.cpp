#include <iostream>
#include <string.h>

using namespace std;

long long int s[10010][10010];
int flag[10010]={0};
long long int da=0,lo=0,data;
int ggg;

void DFS(int a){
	flag[a]=1;	
	for(int i=1;i<=10001;i++){
		if(flag[i]==0 && s[a][i]!=0) {
		da+=s[a][i];DFS(i);da-=s[a][i];
		}
	}
	if(da!=0 && da>lo) {
	    data=da;
	    lo=da;
	    ggg=a;
	}	
	return;
}

int main(){
	int n;
	cin>>n;
	int a,b;
	memset(s,0,sizeof(s));
	for(int i=0;i<n-1;i++){
		cin>>a>>b;
		cin>>s[a][b];
		s[b][a]=s[a][b];
	}
	DFS(1);
	memset(flag,0,sizeof(flag));
	da=0;
	DFS(ggg);
	cout<<(((data+1)*data)/2+10*data)<<endl;
	return 0;
} 
