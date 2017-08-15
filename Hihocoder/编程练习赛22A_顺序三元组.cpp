#include<iostream>

using namespace std;
#include<deque>  // 头文件
deque<int> deq;  // 声明一个元素类型为type的双端队列que

//此处使用三个成就
long long comp1 = 0;
long long comp2 = 0;
long long comp3 = 0;//垃圾坑


int a[100];
int length;
int t;
int count;

int main()
{
	
	cin >> length;

	for (int i = 1; i <= length; i++)
	{
		cin >> t;
		if (t == 1)
		{
			comp1 += 1;//养成对数据分析的良好习惯
		}
		if (t == 2)
		{
			comp2 += comp1;
		}
		if (t==3)
		{
			comp3 += comp2;
		}	
	}
	cout <<comp3<<endl;
	return 0;
}