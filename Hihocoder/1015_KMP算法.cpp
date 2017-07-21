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


int match(char*P, char*T)//PΪģʽ��(par) TΪ�ı���(ori)
{
	/*int anss[L];
	int *p_anss = anss;*/
	int *next = buildNext(P);
	int m = (int)strlen(P), j = 0;//ģʽ��ָ��
	int n = (int)strlen(T), i = 0;//�ı���ָ��
	while (i<n)
	{
		if (j < 0)//ƥ��Խ�� ��ô���¿�ʼ  ����ڱ�����
		{
			i++;
			j = 0;
		}	
		if (T[i] == P[j])//ƥ��ɹ�
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
			j = next[j];//P���� T������
		}	
	}
	delete[]next;
	return 1;
	
}

int *buildNext(char * P)
{
	size_t m = strlen(P),j=0; //��ͬƽ̨��size_t���ò�ͬ������ʵ�֣�ʹ��size_t����int��unsigned����д����չ�и��õĴ���
	int * N = new int[L];
	int t = N[0] = -1;
	while (j<m-1)
	{
		if (0 > t || P[j] == P[t])//ƥ��ɹ�
		{
			N[++j] = ++t;//���д洢
		}
		else
		{
			t = N[t];
		}
	}
	return N;
}