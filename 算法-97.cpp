#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool com (int a,int b){
	return a>b;
}

int main(){
	vector <int> a;
	int b;
	for(int i=0;i<3;i++){
		cin>>b;
		a.push_back(b); 
	}
	sort(a.begin() ,a.end(),com );
	for(int i=0;i<a.size() ;i++)
	cout<<a[i]<<" ";
	return 0;
}
