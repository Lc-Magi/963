#include<iostream>
#include<algorithm>

using namespace std;

long long int n,a,k,x,y,m,b;

struct node
{
    int x,y,z;//x ��ʾ���� y ��ʾ����������Դ��λ��  z��ʾ���ǿ�ѧ�ҵı��
}p[200010];

int cmp(node w,node l)//����ǳ�������������� ��ͬһ�������ǾͰ���������Դ��λ������,
//�����Դ��λ����ͬ�Ͱ��տ�ѧ�ұ������,����Ͱ��ղ�������
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
        int t=0;//t ����Ϊ�ڼ���,���ﶼһ�����ǻ��ǰ��ջ������ֲ����һ��Ϊһ��,
		//û�л��Ծ�����������
        cin>>k>>a>>x>>y>>m;
        for(j=1;j<=k;j++)//�����Ƿֲ�Ĺؼ���
        {
                if(cnt <= 2e5)
                p[cnt++]=(node){t,a,i};
                b=(x*a+y)%m;
                if(b<a&&j!=k)//��k������û�����һ��b
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
