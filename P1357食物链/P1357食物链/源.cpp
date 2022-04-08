#include<iostream>
using namespace std;
int in[1010],out[1010];
int graph[1010][1010];
int main()
{
	int n, m;
	while (cin >> n >> m)
	{
		int a, b;
		cin >> a >> b;
		out[a]++;
		in[b]++;
		graph[a][b] = 1;
	}
	
}