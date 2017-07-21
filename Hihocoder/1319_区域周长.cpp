//DFS BFS Œ Ã‚
#include<cstdio>
#include<iostream>

using namespace std;
int N, M, x, y;

int ans = 0;
bool visited[105][105];
int map[105][105];//¥Ê¥¢ ˝◊÷æÿ’Û

bool isInside(int x,int y)
{
	return (x >= 0 && x < N&&y>=0 && y < M) ?  1 : 0;
}


void DFS(int i, int  j)
{
	int dx[4] = { -1, 1, 0, 0 };
	int dy[4] = { 0, 0, -1, 1 };
	visited[i][j] = true;
	for (int i = 0; i < 4; i++)
	{
		int _x = i + dx[i];
		int _y = j + dy[i];
		if (!isInside(_x,_y)) 
		{
			ans++;
		}
		else 
		{
			if (!visited[_x][_y])
			{
				if (map[_x][_y] == map[i][j])
				{
					DFS(_x, _y);
				}
				else
				{
					ans++;
				}
			}		
		}		
	}
		
			
}
	

int main()
{
	cin >> N >> M >> x >> y;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> map[i][j];
		}
	}
	DFS(x-1, y-1);
	cout << ans<<endl;

	return 0;
}