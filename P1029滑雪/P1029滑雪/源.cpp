#include<iostream>
using namespace std;
int arr[110][110];
int r, c;
int ans = 0;
void dfs(int i,int j,int path)
{
	if (arr[i][j] > arr[i - 1][j] && i-1>=1)
	{
		dfs(i - 1, j, path + 1);
	}
	if (arr[i][j] > arr[i][j + 1] && j+1<=c)
	{
		dfs(i, j + 1, path + 1);
	}
	if (arr[i][j] > arr[i + 1][j] && i+1<=r)
	{
		dfs(i + 1, j, path + 1);
	}
	if (arr[i][j] > arr[i][j - 1] && j-1>=1)
	{
		dfs(i, j - 1, path + 1);
	}
	ans = max(ans, path);
	return;
}
int main()
{
	cin >> r >> c;
	int i, j;
	for (i = 1; i <= r; i++)
	{
		for (j = 1; j <= c; j++)
		{
			cin >> arr[i][j];
		}
	}
	int maxnum = -99999;
	int col=0, row=0;
	for (i = 1; i <= r; i++)
	{
		for (j = 1; j <= c; j++)
		{
			dfs(i, j, 1);
		}
	}
	cout << ans << endl;
	return 0;
}