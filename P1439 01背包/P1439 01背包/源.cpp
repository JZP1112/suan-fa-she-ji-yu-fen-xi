#include<iostream>
using namespace std;
typedef struct box
{
	int val;
	int weight;
}box;
box arr[100];
int dp[100][20000];
int main()
{
	int n, v;
	while (cin >> v >> n)
	{
		int i, j;
		for (i = 1; i <= n; i++)
		{
			cin >> arr[i].weight >> arr[i].val;
		}
		for (i = 1; i <= n; i++)
		{
			for (j = 0; j <= v; j++)
			{
				if (j >= arr[i].weight)		dp[i][j] = max(dp[i - 1][j], arr[i].val + dp[i - 1][j - arr[i].weight]);
				else									dp[i][j] = dp[i - 1][j];
			}
		}
		cout << dp[n][v] << endl;
		for (i = 1; i <= n; i++)
		{
			for (j = 0; j <= v; j++)
			{
				dp[i][j] = 0;
			}
		}
	}
	
	return 0;
}