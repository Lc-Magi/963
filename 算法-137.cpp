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
int b[4]={3,3,3,3};// a��Ӧ�Ķ�����Ϊ011������λ�ֱ��������������׳��������ƶ���
                  // 0�������׳���1��δ���о���1��δ�����ƶ���
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
		if(b[i]==1 ||b[i]==3){             //δ�����ƶ��Ҳ����׳�
			for (int j = 1; j <= a[i].move ; j++)                         //�ƶ�
            {
                a[i].now += j;                                      //a[i]��ǰ�ƶ�j
                b[i] ^= 1;                                      //���ƶ�
                if (near(a[i].now) || j == a[i].move)                    //���a[i]�ƶ����λ���Ա����˻����ƶ�����ﵽ����
                {
                    dfs(d + 1);
                }
                a[i].now-= j;                                      //��λ
                a[i].now -= j;                                      //a[i]����ƶ�j
                if (near(a[i].now) || j == a[i].move)                    //���a[i]�ƶ����λ���Ա����˻����ƶ�����ﵽ����
                {
                    dfs(d + 1);
                }
                a[i].now += j;                                      //��λ
                b[i] ^= 1;                                         //��ԭΪδ�ƶ�
			}                                    
		}	
        if (b[i] == 2 || b[i] == 3 || b[i] == 5)//��δ���о���
        {
            for (int j = 1; j <= 3; j++)                            //����
            {
                if (i != j && !w[j] && a[i].threw  > 0)                //�Ƿ���Խ��в���
                {
                    if (a[i].now == a[j].now + 1 || a[j].now == a[i].now + 1)   //a[i]�����Ƿ�����
                    {
                        w[j] = 1;                               //���������׳���j���׳�ǰ��j�Ƿ�ɲ�����Ǳ��Ϊ��
                        b[i] ^= 2;                              //�Ѿ���
                        b[i] ^= 4;                              //���׳�
                        p[i] = j;                               //��¼a[i]�����׳�����j
                        e = a[j].now;                               //��¼a[j]�ľ���ǰλ��
                        a[j].now = -j;                              //a[j]�������𣩵�λ�ö�Ϊ������ֻ��������һ��ݹ�ʱ��ȡ��Զλ�õ�ѭ��
                        dfs(d + 1);
                        a[j].now = e;                               //��λ
                        w[j] = 0;                               //��ԭΪ���Խ��в���
                        b[i] ^= 2;                              //��ԭΪδ����
                        b[i] ^= 4;                              //��ԭΪ�����׳�
                    }
                }
            }
        } 
        if (b[i] == 4 || b[i] == 5)          //�����׳���
        {
            for (int j = 1; j <= a[i].threw ; j++)                         //�׳�
            {
                w[p[i]] = 0;                                    //���a[j]Ϊ�ɲ���������a[j]ָa[i]��������ˣ�
                b[i] ^= 4;                                      //�����׳�
                e = a[p[i]].now;                                    //��¼a[j]������ǰλ��
                a[p[i]].now = a[i].now + j;                             //�׳�a[j]��������a[j]λ��
                if (near(a[p[i]].now ) || j == a[i].threw  )                 //���a[j]���׳����λ���Ա����˻����׳�����ﵽ����
                {
                    dfs(d + 1);
                }
                a[p[i]].now  -= j;                                   //��λ
                a[p[i]].now  -= j;                                   //a[j]����׳�j
                if (near(a[p[i]].now ) || j == a[i].threw )                 //���a[j]���׳����λ���Ա����˻����׳�����ﵽ����
                {
                    dfs(d + 1);
                }
                a[p[i]].now  = e;                                    //��ԭa[j]Ϊδ����ǰ��λ��
                b[i] ^= 4;                                      //��ԭb[j]Ϊ���׳�
                w[p[i]] = 1;                                    //��ԭb[j]Ϊ���ɲ���
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
