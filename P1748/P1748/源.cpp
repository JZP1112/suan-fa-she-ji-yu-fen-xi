#include<iostream>
using namespace std;
int arr[2010][10];
int visit[2010][10];
int ans;
int n;
bool judge()
{
	int i, j;
	int sum = 0;
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= 4; j++)
		{
			if (visit[i][j] == 1)	sum++;
		}
	}
	if (sum == 4)		return true;
	return false;
}
void dfs(int i, int j, int sum)
{
	if (sum == 0 && judge() )
	{
		ans++;
		return;
	}
	if (i == n && j == 4)
	{
		return;
	}
	if (j + 1 > 4)
	{
		dfs(i + 1, j - 4 + 1, sum + arr[i][j]);
	}
	else		dfs(i, j + 1, sum + arr[i][j]);
}
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		cin >> n;
		int i, j;
		for (i = 1; i <= n; i++)
		{
			for (j = 1; j <= 4; j++)
			{
				cin >> arr[i][j];
			}
		}
	}
	dfs(1, 1, 0);
	cout << ans << endl;
	return 0;
}