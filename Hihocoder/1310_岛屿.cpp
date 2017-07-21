#include<cstdio>
#include<iostream>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;//NΪ������MΪ����
char map[55][55];//�洢�ַ�����
bool visit[55][55];//��Ϊ��ǵ�����

int dx[4] = { -1, 0, 1, 0 };//�������飬Ϊ���Ż�dfs����
int dy[4] = { 0, 1, 0, -1 };

int area = 0;
int NumOfIslands = 0, NODAI = 0, NODCI;//����NumOfIslands��ʾ��������NODAI��ʾ��ͬ����ĵ���
									   //���������NumOfIslandsҲ��Ϊĳ������ı�ţ������Ŵ�0��ʼ


struct position
{
	int x;
	int y;
}typedef position;


int num[300];//num[i]�洢�˱��i����������С
position a[300][300];//��ʾ�����300�����죬ÿ������������Ϊ300����Ӧ300������  [����][���]
bool flag[300];

bool cmp(struct position a, struct position b) //��ʱ�Զ���С�ں��� ����sort����
{
	if (a.x != b.x)
		return a.x < b.x;
	else
		return a.y < b.y;
}

int isSame(struct position *c, struct position *d, int x, int y)	//�ж�����������״�Ƿ���ͬ
{
	int flag = 1;
	if (num[x] != num[y])
	{
		return 0;
	}
	for (int i = 1; i < num[x]; i++) 
	{
		if (((c[i].x - c[0].x) == (d[i].x - d[0].x)) && ((c[i].y - c[0].y) == (d[i].y - d[0].y)))//�ж��������������
		{
			continue;
		}		
		else 
		{
			flag = 0;//ֱ�ӷ���
			break;
		}
	}
	return flag;
}

void DFS(int x, int y)
{
	a[NumOfIslands][area].x = x;//�����NumOfIslands�������area������x��ֵ
	a[NumOfIslands][area].y = y;
	area++;//�������1
	visit[x][y] = 1;//������꣨x,y��Ϊ�ѷ���
	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx >= 0 && nx < N && ny >= 0 && ny < M && map[nx][ny] == '#' && visit[nx][ny] == 0)//�������� ��δ���ʹ�
		{
			DFS(nx, ny); 
		}
	}
}



int main()
{
	set<int> v;//�������ֵ��ͬ�Ĵ��� �������ͳ�Ʋ�ͬ�ĸ���
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
				area = 0;//��ʼ��ĳ������������Ϊ0
				DFS(i, j);
				num[NumOfIslands] = area;//num[i]�洢�˱��i����������С
				v.insert(area);
				NumOfIslands++;
			}
		}
	}
	NODAI = v.size();//�����ͬ�ĵ�����
	NODCI = NumOfIslands;//������

	//��ÿ�����������������򣬷���Ƚ�����������״�Ƿ���ͬ
	for (i = 0; i < NumOfIslands; i++)
	{
		sort(a[i], a[i] + num[i], cmp);//����������ṹ���ַ ����
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
				if ((flag[j] == 0) && (isSame(a[i], a[j], i, j)))//����������ǰ����ͬ�ĵ���
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

