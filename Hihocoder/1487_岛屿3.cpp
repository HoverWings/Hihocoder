//用并查集以便于统计联通集的个数
#include<iostream>
#include<cstdio>
#include <set>
#include <vector>
#include <algorithm>
#include <string.h>

#define N 1000//N为行数，M为列数
#define M 1000

using namespace std;


//int N, M;//N为行数，M为列数
int map[1005][1005];//存储是否是陆地
bool visit[1005][1005];//作为标记的数组

struct position
{
	int x;
	int y;
}typedef position;

int num[1000];//num[i]存储了编号i岛屿的面积大小
position a[1000][1000];//表示最多有300个岛屿，每个岛屿最大面积为300即对应300个坐标  [岛屿][面积]
bool flag[1000];

int area = 0;
int NumOfIslands = 0;

int dx[4] = { -1, 0, 1, 0 };//方向数组，为了优化dfs代码
int dy[4] = { 0, 1, 0, -1 };

int res=0;
int RES = 0;


void DFS(int x, int y)
{
	a[NumOfIslands][area].x = x;//保存第NumOfIslands个岛屿第area个坐标x的值
	a[NumOfIslands][area].y = y;
	area++;//面积数加1
	visit[x][y] = 1;//标记坐标（x,y）为已访问
	if (y == 0 || map[x][y - 1] == 0) ++res;
	if (x == 0 || map[x - 1][y] == 0) ++res;
	if (y == N - 1 || map[x][y + 1] == 0) ++res;
	if (x == M - 1 || map[x + 1][y] == 0) ++res;
	for (int i = 0; i < 4; i++)//扫描四边
	{
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx >= 0 && nx < N && ny >= 0 && ny < M && map[nx][ny]==1 && visit[nx][ny] == 0)//在区域内 且未访问过
		{
			DFS(nx, ny);
		}
	}
}


void init()
{
	NumOfIslands = 0;
	memset(visit, 0, sizeof(visit));//将visit元素全置为0
	RES = 0;
}

void countNumOfIslands()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (map[i][j] == true && visit[i][j] == 0)//这是一个新岛
			{
				area = 0;//初始化某个岛屿的面积数为0
				res = 0;
				DFS(i, j);//初始调用
				RES += res;
				num[NumOfIslands] = area;//num[i]存储了编号i岛屿的面积大小
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