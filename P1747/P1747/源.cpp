#include<iostream>
#include<algorithm>
using namespace std;
int arr[100010];
int main()
{
	int n, m;
	cin >> n;
	int i;
	for (i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	cin >> m;
	int x;
	int flag;
	for (i = 0; i < m; i++)
	{
		flag = 0;
		cin >> x;
		int mid;
		int left = 0, right = n - 1;
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
				left = mid + 1;
			}
			else	right = mid - 1;
			if (flag == 1)		break;
		}
		if (flag == 1)	cout << arr[mid] << endl;
		else
		{
			int ans;
			if (mid - 1 >= 0 && mid + 1 <= n - 1)
			{
				if (abs(arr[mid] - x) > abs(arr[mid + 1] - x) && abs(arr[mid + 1] - x) > abs(arr[mid - 1] - x))		cout << arr[mid - 1] << endl;
				else if (abs(arr[mid] - x) < abs(arr[mid + 1] - x) && abs(arr[mid + 1] - x) < abs(arr[mid - 1] - x))	cout << arr[mid] << endl;
				else		cout << arr[mid + 1] << endl;
			}
			else if (mid - 1 < 0)
			{
				if (abs(arr[mid] - x) > abs(arr[mid + 1] - x))
				{
					cout << arr[mid + 1] << endl;
				}
				else cout << arr[mid] << endl;
			}
			else
			{
				if (abs(arr[mid] - x) > abs(arr[mid - 1] - x))		cout << arr[mid - 1] << endl;
				else								cout << arr[mid] << endl;
			}
		}

	}
	return 0;
}