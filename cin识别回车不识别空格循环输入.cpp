 #include <iostream>
 
 using namespace std;
 
 int main()
 {
   int m,n;
   cin>>m>>n;
   char c[n];int x=0;
   for(int i=1;i<=m;i++)
   {
      char ch=' ';
      while(ch!=10)      //����������֮�������һ��ѭ�����롣
      {
         x++;
         cin>>c[x];
         ch=getchar();
      }
   } 
   for(int j=1;j<n;j++)
   cout<<c[j]<<"-";
   cout<<endl;
   return 0;
}
