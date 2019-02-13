#include <iostream>
#include <string>

using namespace std;

int main(){
	int n,m;
	int count =0;
	cin>>n>>m;
	int a;
	string x[n],y[n];
	string c="2";string d="1";
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
	    	cin>>a;
			if(a==0) {x[i]+=c;y[i]+=d;
			}
			else {x[i]+=d;y[i]+=c;}	
		}
		for(int j=0;j<i;j++)
		if(x[i].compare(y[j])!=0 ) continue;
		else count++;
	}
	cout<<count<<endl;
	return 0;
}
