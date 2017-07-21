#include<cstdio>
#include<iostream>
#include<string>  
#include<cstring>
#define L 10050  
#define M 1000050 
using namespace std;


int match(char*P, char*T);
int *buildNext(char * P);
int num;


int main()
{
	int N;
	char par[L];
	char ori[M];
	scanf("%d", &N);
	while (N--)
	{
		num = 0;
		scanf("%s", par);
		scanf("%s", ori);
		match(par, ori);
		cout << num<<endl;
	}
	return 0;
}


int match(char*P, char*T)//P为模式串(par) T为文本串(ori)
{
	/*int anss[L];
	int *p_anss = anss;*/
	int *next = buildNext(P);
	int m = (int)strlen(P), j = 0;//模式串指针
	int n = (int)strlen(T), i = 0;//文本串指针
	while (i<n)
	{
		if (j < 0)//匹配越过 那么重新开始  理解哨兵含义
		{
			i++;
			j = 0;
		}	
		if (T[i] == P[j])//匹配成功
		{
			if (j == m - 1)
			{
				num++;
				//anss[num] = i - j;
				j = next[j];
			}
			else
			{
				i++;
				j++;
			}
		}
		else
		{
			j = next[j];//P右移 T不回退
		}	
	}
	delete[]next;
	return 1;
	
}

int *buildNext(char * P)
{
	size_t m = strlen(P),j=0; //不同平台的size_t会用不同的类型实现，使用size_t而非int或unsigned可以写出扩展行更好的代码
	int * N = new int[L];
	int t = N[0] = -1;
	while (j<m-1)
	{
		if (0 > t || P[j] == P[t])//匹配成功
		{
			N[++j] = ++t;//进行存储
		}
		else
		{
			t = N[t];
		}
	}
	return N;
}