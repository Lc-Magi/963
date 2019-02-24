#include<iostream>
#include<algorithm>

using namespace std;

long long int n,a,k,x,y,m,b;

struct node
{
    int x,y,z;//x 表示层数 y 表示的是所需资源单位数  z表示的是科学家的编号
}p[200010];

int cmp(node w,node l)//这里非常巧妙！如果层数相等 在同一层里我们就按照所需资源单位数排序,
//如果资源单位数相同就按照科学家编号排序,否则就按照层数排序
{
    if(w.x==l.x)
        return w.y<l.y||(w.y==l.y&&w.z<l.z);
    return w.x<l.x;
}
int main()
{
    int i,j;
    int ans=-1,cnt=0;
    cin>>n;
    for(i=1;i<=n;i++)
    {
        int t=0;//t 计算为第几层,这里都一样我们还是按照坏对来分层出现一次为一层,
		//没有坏对就是整个序列
        cin>>k>>a>>x>>y>>m;
        for(j=1;j<=k;j++)//这里是分层的关键！
        {
                if(cnt <= 2e5)
                p[cnt++]=(node){t,a,i};
                b=(x*a+y)%m;
                if(b<a&&j!=k)//第k个问题没有最后一个b
                t++;
                a=b;
        }
        ans=max(ans,t);
    }
    cout<<ans<<endl;
    if(cnt <= 2e5)
    {
        sort(p,p+cnt,cmp);
        for(i=0;i<cnt;i++)
        {
            cout<<p[i].y<<" "<<p[i].z<<endl;
        }
 
    }
    return 0;
}
