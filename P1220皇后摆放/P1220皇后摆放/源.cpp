#include<iostream>
using namespace std;
int arr[9][9];
int num = 0;
void dfs(int row, int col)
{
	if (row == 8)
	{
		num++;
		return;
	}
	int i, j;
	for (j = 1; j <= 8; j++)
	{
		if (arr[row][j] == 1)
		{
			dfs(row + 1, col);
		}
	}
	for (i = 1; i <= 8; i++)
	{
		if (arr[i][col] == 1)
		{
			dfs(row, col + 1);
		}
	}

}
int main()
{
	int i, j;
	for (i = 1; i <= 8; i++)
	{
		for (j = 1; j <= 8; j++)
		{
			cin >> arr[i][j];
		}
	}
}