#include <iostream>
#include <string>

using namespace std;

void Two(int m,int n){ 
    if(m==0) return ;
    int r=m%2;
    m=m>>1;
    Two(m,n+1);
    if(r && m)  cout<<"+";
    if(r!=0){	
       if(n==1) cout<<"2";
       else{
    	  cout<<"2(";
    	  if(n>2) Two(n,0);
    	  else cout<<n;
    	  cout<<")";
     	}
	}
}
int main(){
    int m;
    cin>>m;
    Two(m,0); 
    return 0;
}
