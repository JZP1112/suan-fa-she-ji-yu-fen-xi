//ÍØÆËÅÅĞòÄ£°å
/*
#include<iostream>
#include<queue>
#include<vector>
using namespace std;
int graph[1010][1010];
int num[1010];
int in[1010];
vector<int> ans;
int main()
{
	queue<int> arr;
	int n, m;
	cin >> n >> m;
	int i, j,k;
	for (k = 0; k < m; k++)
	{
		cin >> i >> j;
		graph[i][j] = 1;
		in[j]++;
	}
	for (i = 1; i <= n; i++)
	{
		if (in[i] == 0)
		{
			arr.push(i);
		}
	}
	while (!arr.empty())
	{
		int temp = arr.front();
		arr.pop();
		ans.push_back(temp);
		for (i = 1; i <= n; i++)
		{
			if (graph[temp][i] == 1)
			{
				num[i] += num[temp];
				in[i]--;
				if (in[i] == 0)		arr.push(i);
			}
		}
	}
	cout << num[ans[ans.size() - 1]] << endl;
	return 0;
}
*/
#include<iostream>
using namespace std;
int graph[1010][1010];
int in[101000],out[101000];
int ans;
int n, m;
void dfs(int v,int path)
{
	if (out[v] == 0)
	{
		ans = max(ans, path);
		return;
	}
	int i;
	for (i = 1; i <= n; i++)
	{
		if (graph[v][i] == 1)
		{
			dfs(i,path+1);
		}
	}
}
	int main()
	{
		while (cin >> n >> m)
		{
			int i, j, k;
			for (k = 0; k < m; k++)
			{
				cin >> i >> j;
				graph[i][j] = 1;
				in[j]++;
				out[i]++;
			}
			for (i = 1; i <= n; i++)
			{
				if (in[i] == 0)		dfs(i, 1);
			}
			cout << ans << endl;
			ans = 0;
		}
		return 0;
	}