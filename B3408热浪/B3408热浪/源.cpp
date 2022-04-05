#include<iostream>
using namespace std;
int dis[10010][10010];
#define inf 999999
int n, m, s, t;
int main()
{
	cin >> n >> m >> s >> t;
	int i, j, k,x;
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= n; j++)
		{
			dis[i][j] = inf;
		}
	}
	for (i = 1; i <= n; i++)
	{
		dis[i][i] = 0;
	}
	for (k = 1; k <= m; k++)
	{
		cin >> i >> j >> x;
		dis[i][j] = x;
		dis[j][i] = x;
	}
	for (k = 1; k <= n; k++)
	{
		for (i = 1; i <= n; i++)
		{
			for (j = 1; j <= n; j++)
			{
				if (dis[i][k]!=inf && dis[k][j] != inf && dis[i][j] > dis[i][k] + dis[k][j])
					dis[i][j] = dis[i][k] + dis[k][j];
			}
		}
	}
	cout << dis[s][t] << endl;
	return 0;
}