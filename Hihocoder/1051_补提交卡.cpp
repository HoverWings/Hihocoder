//���ύ��
//ѡȡ��ߵļ�������
//�ɲ�����ʹ��״̬ѹ����
#include<cstdio>
#include<iostream>
using namespace std;

int main()
{
	int t;
	scanf("%d", &t);
	while (t--)
	{
		int n, m;//n������ m�����ύ��
		int arr[101]; 
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &arr[i]);
		}

	}

	return 0;
}

void max_day(int *arr)
{
	
}

int*  is_continuous(int *arr)//���������ĵ�һ��
{
	int len=(sizeof(arr) / sizeof(arr[0]));
	int con_arr[10] = {}, j;
	for (int i = 1; i < len+1; i++)
	{
		if (arr[i] == arr[i - 1])
		{
			con_arr[j++] = i - 1;
		}
	}
	if (con_arr != NULL)
	{
		return con_arr;
	}
	else
	{
		return NULL;
	}
	
}