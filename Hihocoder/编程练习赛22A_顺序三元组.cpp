#include<iostream>

using namespace std;
#include<deque>  // ͷ�ļ�
deque<int> deq;  // ����һ��Ԫ������Ϊtype��˫�˶���que

//�˴�ʹ�������ɾ�
long long comp1 = 0;
long long comp2 = 0;
long long comp3 = 0;//������


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
			comp1 += 1;//���ɶ����ݷ���������ϰ��
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