#include<iostream>
using namespace std;
int main()
{
	int n;
	cin >> n;
	int ans = 0;
	int arr[10010];
	int i,j;
	for (i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	for (i = 0; i < n; i++)
	{
		int temp = arr[i];
		for (j = i + 1; j < n; j++)
		{
			temp += arr[j];
			ans = max(ans, temp);
		}
	}
	cout << ans << endl;
	return 0;
}