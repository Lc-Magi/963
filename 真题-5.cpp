#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int a, duan, chong;
	int g[110];
	cin >> a;
	int len = 0;
	while(cin >> a)
	{
		g[len++] = a;
	}
	sort(g, g +len);
	for(int i=1; i<len; i++)
	{
		if(g[i] == g[i-1])
		{
			chong = g[i];
		}else if(g[i] != g[i-1] + 1)
		{
			duan = g[i] - 1;
		}
	}
	cout << duan << " " << chong <<endl;
	return 0;
}
