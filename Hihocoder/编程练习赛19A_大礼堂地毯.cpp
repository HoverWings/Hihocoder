#include<cstdio>
#include<iostream>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

#define me(s)  memset(s,0,sizeof(s))  



typedef long long ll;

int N, M;//NΪ������MΪ���� ������̺
ll carpet[55][55];//������̺����ʽ
char carpet_joint[210][1610];
ll Hash_joint[55][55];

int K;	 //K����Ƭ
int H, W;//��Ƭ�Ĵ�С
		 //int Hash_cmp[105];
ll pict[105][105];//��Ƭ �ܴ�С
ll Hash[105][805];

ll powp[105], powq[105];
char str[105];

const int p = 131;
const int q = 1331;



void init()//��ʼ��p^i,q^i�Ľ��  
{
	powp[0] = powq[0] = 1;
	for (int i = 1; i<N; i++)
	{
		powp[i] = powp[i - 1] * p;
		powq[i] = powq[i - 1] * q;
	}
}


struct matrix
{
	int n;
	int m;
	int hash;
}typedef matrix;


//������̺��������


void joint()
{
	int x = H * 2 / N;
	int y = W * 2 / M;
	for (int i = 1; i <= x; i++)
	{
		for (int j = 1; j <= y; j ++)
		{
			carpet_joint[i][j] = carpet[i%N][j%M];
		}
	}
}

int main()//�ö�άhash����
{
	cin >> N >> M >> K;//������̺��С ��K����Ƭ
	me(Hash);
	me(carpet_joint);
	me(Hash_joint);
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			cin >> carpet[i][j];
		}
	}
	while (K--)
	{
		cin >> H >> W;
		for (int i = 1; i <= H; i++)
		{
			scanf("%s", str + 1); ;
			for (int j = 1; j <= W; j++)
				Hash[i][j] = Hash[i - 1][j] * p + Hash[i][j - 1] * q - Hash[i - 1][j - 1] * p*q + str[j];//������ƬHash����  
		}
		joint();
		int n = 2 * N;
		int m = 2 * M;
		for (int i = 1; i <= n; i++)//����joint
		{
			str[i] = carpet_joint[i];
			for (int j = 1; j <= m; j++)
				Hash[i][j] = Hash[i - 1][j] * p + Hash[i][j - 1] * q - Hash[i - 1][j - 1] * p*q + str[j];//����Hashԭ��������  
		}
		for (int i = 1; i <= N - M + 1; i++)
		{
			for (int j = 1; j <= M - W + 1; j++)//ö��H*W���Ӿ���  
			{
				h = Hash[i + H - 1][j + W - 1] - Hash[i - 1][j + W - 1] * powp[H] - Hash[i + H - 1][j - 1] * powq[W] + Hash[i - 1][j - 1] * powp[H] * powq[W];
				if (h == mat[k].hash)ans++; //��ȣ���ans++  
			}
		}
	}

}
