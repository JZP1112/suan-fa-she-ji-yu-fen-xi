#include<iostream>
using namespace std;
int graph[1001][1001];
int col[1001];
int n, k, m;
int ans;
bool judge(int v)
{
	int i;
	for (i = 1; i <= n; i++)
	{
		if (graph[v][i]==1 && col[v] == col[i])
		{
			return false;
		}
	}
	return true;
}
void dfs(int v)
{
	int i;
	if (v > n)
	{
		ans++;
		return;
	}
	else
	{
		for (i = 1; i <= m; i++)
		{
			col[v] = i;
			if (judge(v))
			{
				dfs(v + 1);
			}
			col[v] = 0;
		}
	}
}
int main()
{
	cin >> n >> k >> m;
	int i;
	for (i = 0; i < k; i++)
	{
		int x, y;
		cin >> x >> y;
		graph[x][y] = 1;
		graph[y][x] = 1;
	}
	dfs(1);
	cout << ans << endl;
	return 0;
}