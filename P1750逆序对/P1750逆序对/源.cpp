#include<iostream>
using namespace std;
int ans;								//记录逆序的组数
//归并排序
void merge_sort(int arr[], int temp[], int left, int mid, int right)
{
	int i = left, j = mid + 1;
	int k = left;
	//将分割成的两个有序数组排序，并且求逆序的个数
	while (i <= mid && j <= right)
	{
		if (arr[i] >= arr[j])
		{
			ans += mid - i + 1;
			temp[k++] = arr[j++];
		}
		else
		{
			temp[k++] = arr[i++];
		}
	}
	//判断两个数组中的元素是否全部放入最后排序的数组中
	while (i <= mid)
	{
		temp[k++] = arr[i++];
	}
	while (j <= right)
	{
		temp[k++] = arr[j++];
	}
	//复制
	for (i = left; i <= right; i++)
	{
		arr[i] = temp[i];
	}
	return;
}
//将数组分割成有序，即分割至只含一个元素
void merge(int arr[], int left, int right, int temp[])
{
	if (left < right)
	{
		int mid = (left + right) / 2;
		merge(arr, left, mid, temp);
		merge(arr, mid + 1, right,temp);
		merge_sort(arr, temp,left, mid, right);
	}
}
int main()
{
	int n;
	cin >> n;
	int arr[10010];
	int i;
	for (i = 1; i <= n; i++)
	{
		cin >> arr[i];
	}
	int temp[10010];
	merge(arr, 1, n, temp);
	cout << ans << endl;
	return 0;
}