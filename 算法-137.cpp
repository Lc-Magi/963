#include <iostream>
#include <algorithm>

using namespace std;

struct point{
	int now;
	int move;
	int threw;
};
point a[4];
int p[4],w[4],ans=0;
int b[4]={3,3,3,3};// a对应的二进制为011，后三位分别是三个动作：抛出，举起，移动。
                  // 0（不可抛出）1（未进行举起）1（未进行移动）
int near(int i){
	for(int j=1;j<=3;j++){
		if(i==a[j].now-1 ||i==a[j].now+1)
		return 1;
	}
	return 0;
}

void dfs(int d){
	int e=0;
	for(int i=1;i<=3;i++){
		ans=max(ans,a[i].now);
	}
	for(int i=1;i<=3;i++){
		if(w[i]) continue;
		if(b[i]==1 ||b[i]==3){             //未进行移动且不可抛出
			for (int j = 1; j <= a[i].move ; j++)                         //移动
            {
                a[i].now += j;                                      //a[i]向前移动j
                b[i] ^= 1;                                      //已移动
                if (near(a[i].now) || j == a[i].move)                    //如果a[i]移动后的位置旁边有人或者移动距离达到上限
                {
                    dfs(d + 1);
                }
                a[i].now-= j;                                      //归位
                a[i].now -= j;                                      //a[i]向后移动j
                if (near(a[i].now) || j == a[i].move)                    //如果a[i]移动后的位置旁边有人或者移动距离达到上限
                {
                    dfs(d + 1);
                }
                a[i].now += j;                                      //归位
                b[i] ^= 1;                                         //还原为未移动
			}                                    
		}	
        if (b[i] == 2 || b[i] == 3 || b[i] == 5)//（未进行举起）
        {
            for (int j = 1; j <= 3; j++)                            //举起
            {
                if (i != j && !w[j] && a[i].threw  > 0)                //是否可以进行操作
                {
                    if (a[i].now == a[j].now + 1 || a[j].now == a[i].now + 1)   //a[i]附近是否有人
                    {
                        w[j] = 1;                               //即将举起（抛出）j，抛出前将j是否可操作标记变更为否
                        b[i] ^= 2;                              //已举起
                        b[i] ^= 4;                              //可抛出
                        p[i] = j;                               //记录a[i]举起（抛出）了j
                        e = a[j].now;                               //记录a[j]的举起前位置
                        a[j].now = -j;                              //a[j]（被举起）的位置定为负数，只作用于下一层递归时的取最远位置的循环
                        dfs(d + 1);
                        a[j].now = e;                               //归位
                        w[j] = 0;                               //还原为可以进行操作
                        b[i] ^= 2;                              //还原为未举起
                        b[i] ^= 4;                              //还原为不可抛出
                    }
                }
            }
        } 
        if (b[i] == 4 || b[i] == 5)          //（可抛出）
        {
            for (int j = 1; j <= a[i].threw ; j++)                         //抛出
            {
                w[p[i]] = 0;                                    //变更a[j]为可操作（以下a[j]指a[i]所举起的人）
                b[i] ^= 4;                                      //不可抛出
                e = a[p[i]].now;                                    //记录a[j]被举起前位置
                a[p[i]].now = a[i].now + j;                             //抛出a[j]，并更新a[j]位置
                if (near(a[p[i]].now ) || j == a[i].threw  )                 //如果a[j]被抛出后的位置旁边有人或者抛出距离达到上限
                {
                    dfs(d + 1);
                }
                a[p[i]].now  -= j;                                   //归位
                a[p[i]].now  -= j;                                   //a[j]向后抛出j
                if (near(a[p[i]].now ) || j == a[i].threw )                 //如果a[j]被抛出后的位置旁边有人或者抛出距离达到上限
                {
                    dfs(d + 1);
                }
                a[p[i]].now  = e;                                    //还原a[j]为未举起前的位置
                b[i] ^= 4;                                      //还原b[j]为可抛出
                w[p[i]] = 1;                                    //还原b[j]为不可操作
            }
        }
	}
	return ;
}

int main(){
	for(int i=1;i<=3;i++){
		cin>>a[i].now>>a[i].move>>a[i].threw;
	}
	dfs (1);
	cout<<ans<<endl;
	return 0;
	
}
