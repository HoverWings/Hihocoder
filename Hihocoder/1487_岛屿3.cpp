//�ò��鼯�Ա���ͳ����ͨ���ĸ���
#include<iostream>
#include<cstdio>
#include <set>
#include <vector>
#include <algorithm>
#include <string.h>

#define N 1000//NΪ������MΪ����
#define M 1000

using namespace std;


//int N, M;//NΪ������MΪ����
int map[1005][1005];//�洢�Ƿ���½��
bool visit[1005][1005];//��Ϊ��ǵ�����

struct position
{
	int x;
	int y;
}typedef position;

int num[1000];//num[i]�洢�˱��i����������С
position a[1000][1000];//��ʾ�����300�����죬ÿ������������Ϊ300����Ӧ300������  [����][���]
bool flag[1000];

int area = 0;
int NumOfIslands = 0;

int dx[4] = { -1, 0, 1, 0 };//�������飬Ϊ���Ż�dfs����
int dy[4] = { 0, 1, 0, -1 };

int res=0;
int RES = 0;


void DFS(int x, int y)
{
	a[NumOfIslands][area].x = x;//�����NumOfIslands�������area������x��ֵ
	a[NumOfIslands][area].y = y;
	area++;//�������1
	visit[x][y] = 1;//������꣨x,y��Ϊ�ѷ���
	if (y == 0 || map[x][y - 1] == 0) ++res;
	if (x == 0 || map[x - 1][y] == 0) ++res;
	if (y == N - 1 || map[x][y + 1] == 0) ++res;
	if (x == M - 1 || map[x + 1][y] == 0) ++res;
	for (int i = 0; i < 4; i++)//ɨ���ı�
	{
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx >= 0 && nx < N && ny >= 0 && ny < M && map[nx][ny]==1 && visit[nx][ny] == 0)//�������� ��δ���ʹ�
		{
			DFS(nx, ny);
		}
	}
}


void init()
{
	NumOfIslands = 0;
	memset(visit, 0, sizeof(visit));//��visitԪ��ȫ��Ϊ0
	RES = 0;
}

void countNumOfIslands()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (map[i][j] == true && visit[i][j] == 0)//����һ���µ�
			{
				area = 0;//��ʼ��ĳ������������Ϊ0
				res = 0;
				DFS(i, j);//��ʼ����
				RES += res;
				num[NumOfIslands] = area;//num[i]�洢�˱��i����������С
				//v.insert(area);
				NumOfIslands++;
				//cout << "NumOfIslands:" << NumOfIslands<<endl;
			}
		}
	}
}









int main()
{
	int n;
	cin >> n;
	int x, y;
	for (int i=1;i<=n;i++)
	{
		init();
		cin >> x >> y;
		map[x][y] = 1;
		countNumOfIslands();
		//islandPerimeter()
		cout << NumOfIslands <<" "<< i<< " " <<RES<<endl;
	}

	return 0;
}