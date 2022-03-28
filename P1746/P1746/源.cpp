#include<iostream>
using namespace std;
int arr[100010];
int main()
{
	int n, m;
	cin >> n >> m;
	int i;
	for (i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	int x;
	int flag;
	for (i = 0; i < m; i++)
	{
		flag = 0;
		cin >> x;
		int mid;
		int left=0, right=n-1;
		while (left < right)
		{
			mid = (left + right) / 2;
			if (x == arr[mid])
			{
				flag = 1;
				break;
			}
			else if (x > arr[mid])
			{
				left = mid+1;
			}
			else	right = mid - 1;
			if (flag == 1)		break;
		}
		mid = (left + right) / 2;
		if (arr[mid] <= x)			cout << arr[mid] << endl;
		else							cout << arr[mid - 1] << endl;
	}
	return 0;
}