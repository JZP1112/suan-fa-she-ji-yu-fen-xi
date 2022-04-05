#include<iostream>
using namespace std;
int arr[100010];
int main()
{
	int n;
	cin >> n;
	int i;
	for (i = 1; i <= n; i++)
	{
		cin >> arr[i];
	}
	int m;
	cin >> m;
	while (m--)
	{
		int flag = 0;
		int k;
		cin >> k;
		int left = 1, right = n;
		while (left + 1 < right)
		{
			int mid = (left + right) / 2;
			if (arr[mid] == k)
			{
				flag = 1;
				break;
			}
			if (arr[mid] < k)		left = mid;
			else							right = mid;
		}
		if (flag)			cout << k << endl;
		else if (abs(arr[left] - k) <= abs(arr[left + 1] - k))		cout << arr[left] << endl;
		else cout << arr[left + 1] << endl;
	}
	return 0;
}