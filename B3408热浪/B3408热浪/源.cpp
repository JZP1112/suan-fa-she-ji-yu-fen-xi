#include<iostream>
using namespace std;
int arr[2510][2510];
int n, m, s, t;
int ans=9999999;
void dfs(int v, int path)
{
	if (v == n)		return;
	if (v == t)
	{
		ans = min(ans, path);
		return;
	}
	for (int i = 1; i <= n; i++)
	{
		if (arr[v][i] != 0)
		{
			dfs(i, path + arr[v][i]);
		}
	}
}
int main()
{
	cin >> n >> m >> s >> t;
	int u, v, w,i;
	for (i = 0; i < m; i++)
	{
		cin >> u >> v >> w;
		arr[u][v] = w;
	}
	dfs(s, 0);
	cout << ans << endl;
	return 0;
}