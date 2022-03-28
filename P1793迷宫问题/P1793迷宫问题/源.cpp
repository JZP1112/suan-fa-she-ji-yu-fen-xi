#include<iostream>
#include<cstdio>
using namespace std;
char arr[10][10];
int visit[10][10];
int dx[] = { 0,1,0,-1 };
int dy[] = { 1,0,-1,0 };
void dfs(int x, int y)
{
	if (x == 7 && y == 7)
	{
		int i, j;
		for (i = 0; i < 8; i++)
		{
			for (j = 0; j < 8; j++)
			{
				if (visit[i][j] == 1)			printf(" ");
				else printf("%c", arr[i][j]);
			}
			printf("\n");
		}
		return;
	}
	int k;
	for (k = 0; k < 4; k++)
	{
		if (arr[x + dx[k]][y + dy[k]] == 'O' && visit[x + dx[k]][y + dy[k]] == 0)
		{
			visit[x + dx[k]][y + dy[k]] = 1;
			dfs(x + dx[k], y + dy[k]);
			visit[x + dx[k]][y + dy[k]] = 0;
		}
	}
}
int main()
{
	int i, j;
	for (i = 0; i < 8; i++)
	{
		for (j = 0; j < 8; j++)
		{
			scanf("%c", &arr[i][j]);
		}
		getchar();
	}
	visit[0][0] = 1;
	dfs(0, 0);
	return 0;
}