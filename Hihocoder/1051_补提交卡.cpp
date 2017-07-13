//补提交卡
//选取最高的几组数据
//可不可以使用状态压缩？
#include<cstdio>
#include<iostream>
using namespace std;

int main()
{
	int t;
	scanf("%d", &t);
	while (t--)
	{
		int n, m;//n个整数 m个补提交卡
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

int*  is_continuous(int *arr)//返回连续的第一天
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