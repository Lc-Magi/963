#include <iostream>
#include <string.h>

using namespace std;

int main(){
	int n;
	cin>>n;
	int m,x,y;
	m=5+(n-1)*4;
	int map[m+4][m+4];
	memset(map,0,sizeof(map));
	for(int i=0;i<5;i++){
	map[(m+4)/2][(m+4)/2-2+i]=map[(m+4)/2-2+i][(m+4)/2]=1;
	}
	for(int i=1;i<=n;i++){
		for(int j=0;j<5+4*(n-i);j++ ){
			map[(m+4)/2-4-2*(n-i)][2*i+j]=map[(m+4)/2+4+2*(n-i)][2*i+j]=1;
		}
		map[(i-1)*2+1][2*i]=map[(i-1)*2+1][2*i+4+4*(n-i)]=1;
		map[(m+4)/2+4+2*(n-i)-1][2*i]=map[(m+4)/2+4+2*(n-i)-1][2*i+4+4*(n-i)]=1;
		for(int j=0;j<3;j++){
			map[i*2][2*i-2+j]=map[i*2][2*i+4+4*(n-i)+j]=1;
			map[(m+4)/2+4+2*(n-i)-2][2*i+j-2]=map[(m+4)/2+4+2*(n-i)-2][2*i+4+4*(n-i)+j]=1;
		}
		for(int j=0;j<5+4*(n-i);j++ ){
			map[2*i+j][2*i-2]=map[2*i+j][m+3-2*i+2]=1;
		}
	}
	for(int i=0;i<m+4;i++){
		for(int j=0;j<m+4;j++){
			if(map[i][j]==0) cout<<".";
			else cout<<"$";
		}
		cout<<endl;
	}
	return 0;
}
