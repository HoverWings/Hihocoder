#include<iostream>
#include<string.h>
using namespace std;

const int N = 1070;
int par[1010 * 1010], Rank[1010 * 1010];
char mp[1007][1007];
int dir[4][2] = { { 1, 0 },{ -1, 0 },{ 0, 1 },{ 0, -1 } };
int many = 0;

void init()
{
	memset(mp,0, sizeof(mp));
	for (int i = 0; i<1010 * 1010; ++i)
		par[i] = i, Rank[i] = 0;
}

int Find(int x)
{
	if (x == par[x])
		return x;
	return par[x] = Find(par[x]);
}

void unite(int x, int y)
{
	x = Find(x), y = Find(y);
	if (Rank[x] > Rank[y])
		par[y] = x;
	else
	{
		par[x] = y;
		if (Rank[x] == Rank[y])
			Rank[y] ++;
	}
}

int solve(int x, int y)
{
	mp[x][y] = '#';
#pragma region DFS����
	int res = 0;
	for (int i = 0; i<4; ++i)
	{
		int s = x + dir[i][0], t = y + dir[i][1];
		if (s >= 0 && t >= 0 && mp[s][t] == '#')
		{
			if (Find(s * 1005 + t) != Find(x * 1005 + y))
			{
				many++;//����n�����죬�����ϲ���ʣ�µ������������n��ȥ�ϲ�������
				unite(s * 1005 + t, x * 1005 + y);
			}
			res++;
		}
	}
#pragma endregion
	if (res == 0)
		return 4;
	if (res == 1)
		return 2;
	if (res == 2)
		return 0;
	if (res == 3)
		return -2;
	if (res == 4)
		return -4;
}

int main()
{
	init();
	int n;
	cin >> n;
	int g = 0;
	for (int i = 1; i <= n; ++i)
	{
		int x, y;
		cin >> x >> y;
		g += solve(x, y);//��ÿһ�� ����д��������ȫ��
		cout << i - many << " " << i << " " << g << endl;//   iΪ����� gΪ���ܳ�
	}
	return 0;
}