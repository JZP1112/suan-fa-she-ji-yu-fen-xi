#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
int main()
{
	int n;
	while (cin >> n)
	{
		int arr[10010];
		int i;
		for (i = 0; i < n; i++)
		{
			cin >> arr[i];
		}
		sort(arr, arr + n);
		double sum=0;
		for (i = 0; i < n - 1; i++)
		{
			sum += arr[i];
		}
		if (sum > arr[n - 1])
		{
			sum += arr[n - 1];
			double ans = sum / 2;
			printf("%.1f\n", ans);
		}
		else		printf("%.1f\n", sum);
	}
	return 0;
}