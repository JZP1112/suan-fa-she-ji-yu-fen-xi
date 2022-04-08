#include<iostream>
using namespace std;
int k, v, m;
int ans;
int col[1010];
int graph[1010][1010];
bool judge(int p, int color)
{
    int i, flag = 1;
    for (i = 1; i <= v; i++)
    {
        if (graph[p][i] == 1 && color == col[i])     return false;
    }
    return true;
}
void dfs(int vec)
{
    if (vec > v)
    {
        ans++;
        return;
    }
    int i;
    for (i = 1; i <= m; i++)
    {
        if (judge(vec, i))
        {
            col[vec] = i;
            dfs(vec + 1);
            col[vec] = 0;
        }
    }
}
int main()
{
    cin >> v >> k >> m;
    int i;
    for (i = 1; i <= k; i++)
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