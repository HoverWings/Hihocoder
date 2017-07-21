#include<cstdio>
#include<iostream>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;//N为行数，M为列数
char map[55][55];//存储字符矩阵
bool visit[55][55];//作为标记的数组

int dx[4] = { -1, 0, 1, 0 };//方向数组，为了优化dfs代码
int dy[4] = { 0, 1, 0, -1 };

int area = 0;
int NumOfIslands = 0, NODAI = 0, NODCI;//最终NumOfIslands表示岛屿数，NODAI表示不同面积的岛屿
									   //计算过程中NumOfIslands也作为某个岛屿的编号，岛屿编号从0开始


struct position
{
	int x;
	int y;
}typedef position;


int num[300];//num[i]存储了编号i岛屿的面积大小
position a[300][300];//表示最多有300个岛屿，每个岛屿最大面积为300即对应300个坐标  [岛屿][面积]
bool flag[300];

bool cmp(struct position a, struct position b) //此时自定义小于函数 用于sort调用
{
	if (a.x != b.x)
		return a.x < b.x;
	else
		return a.y < b.y;
}

int isSame(struct position *c, struct position *d, int x, int y)	//判断两个岛屿形状是否相同
{
	int flag = 1;
	if (num[x] != num[y])
	{
		return 0;
	}
	for (int i = 1; i < num[x]; i++) 
	{
		if (((c[i].x - c[0].x) == (d[i].x - d[0].x)) && ((c[i].y - c[0].y) == (d[i].y - d[0].y)))//判断这个点的相对坐标
		{
			continue;
		}		
		else 
		{
			flag = 0;//直接返回
			break;
		}
	}
	return flag;
}

void DFS(int x, int y)
{
	a[NumOfIslands][area].x = x;//保存第NumOfIslands个岛屿第area个坐标x的值
	a[NumOfIslands][area].y = y;
	area++;//面积数加1
	visit[x][y] = 1;//标记坐标（x,y）为已访问
	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx >= 0 && nx < N && ny >= 0 && ny < M && map[nx][ny] == '#' && visit[nx][ny] == 0)//在区域内 且未访问过
		{
			DFS(nx, ny); 
		}
	}
}



int main()
{
	set<int> v;//不允许键值不同的存在 因此用来统计不同的个数
	int i, j;
	cin >> N >> M;
	for (i = 0; i < N; i++)
	{
		cin >> map[i];
	}
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < M; j++)
		{
			if (map[i][j] =='#' && visit[i][j] == 0)
			{
				area = 0;//初始化某个岛屿的面积数为0
				DFS(i, j);
				num[NumOfIslands] = area;//num[i]存储了编号i岛屿的面积大小
				v.insert(area);
				NumOfIslands++;
			}
		}
	}
	NODAI = v.size();//面积不同的岛屿数
	NODCI = NumOfIslands;//岛屿数

	//对每个岛屿的坐标进行排序，方便比较两个岛屿形状是否相同
	for (i = 0; i < NumOfIslands; i++)
	{
		sort(a[i], a[i] + num[i], cmp);//传入的两个结构体地址 重载
	}

	for (i = 0; i < NumOfIslands - 1; i++)
	{
		if (flag[i] == 1) 
		{
			continue;		
		}
		else 
		{
			for (j = i + 1; j < NumOfIslands; j++)
			{
				if ((flag[j] == 0) && (isSame(a[i], a[j], i, j)))//后面所有与前面相同的岛屿
				{
					flag[j] = 1;
					NODCI--;
				}
			}
		}

	}
	cout << NumOfIslands << " " << NODAI << " " << NODCI << endl;
	return 0;
}

