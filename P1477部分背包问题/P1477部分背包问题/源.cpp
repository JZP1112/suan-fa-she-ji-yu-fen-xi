#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
typedef struct coin
{
	int m;
	int v;
	double average;
}Coin;
Coin arr[10010];
bool cmp(Coin& a, Coin& b)
{
	return a.average > b.average;
}
int main()
{
	int n, m;
	cin >> n >> m;
	int i;
	for (i = 0; i < n; i++)
	{
		cin >> arr[i].m >> arr[i].v;
	}
	for (i = 0; i < n; i++)
	{
		arr[i].average = (double)arr[i].v / arr[i].m;
	}
	sort(arr, arr + n, cmp);
	int sum = 0;
	double ans = 0;
	i = 0;
	while (sum <= m)
	{
		if (sum + arr[i].m <= m)
		{
			ans += arr[i].v;
			sum += arr[i].m;
		}
		else
		{
			ans = ans + arr[i].average * (m - sum);
			sum = m + 1;
		}
		i++;
	}
	printf("%.2f\n", ans);
	return 0;
}