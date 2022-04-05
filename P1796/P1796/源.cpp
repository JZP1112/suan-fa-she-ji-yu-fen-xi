#include<iostream>
using namespace std;
int n, m,ans;
void dfs(int x, int y)
{
	if (x > m && y > n)		return;
	if (x == m && y == n)
	{
		ans++;
		return;
	}
	dfs(x + 1, y + 2);
	dfs(x + 2, y + 1);
}
int main()
{
	cin >> n >> m;
	dfs(1, 1);
	cout << ans << endl;
	return 0;
}