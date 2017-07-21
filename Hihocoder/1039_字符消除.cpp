#include<iostream>
#include<string>
#include<cstdio>
using namespace std;


int eliminate(string s);
string s;

int main()
{
	int n;
	scanf("%d", &n);
	while (n--)
	{
		cin >> s;
		int ans = 0, len = s.size(),t=0;
		for (int i = 0; i < len; i++)//遍历 模拟插入操作
		{
			string temp = s;
			temp.insert(i, "A");
			t = eliminate(temp); 
			if (t > ans) ans = t;

			temp = s;
			temp.insert(i, "B");
			t = eliminate(temp);
			if (t > ans) ans = t;

			temp = s;
			temp.insert(i, "C");
			t = eliminate(temp);
			if (t > ans) ans = t;
		}
		cout << ans << endl;
	}	
	return 0;
}

int eliminate(string s)//进行消除操作 返回能够消除的个数
{
	int len_s = s.size();
	if (len_s == 0) return 0;//边界条件
	int l = 0;
	string t = "";
	int len_t;

	//s += "$";
	for (int i = 1; i < len_s +1; i++)
	{
		if (s[i] != s[i - 1])
		{
			if (l == i - 1)
			{
				t += s[i - 1];						//删除后剩余的加在t上面
			}
			l = i;									//判断的起始位置
		}
		if ((len_t = t.size()) == len_s) return 0;  //结束条件	
	}
	return len_s - len_t + eliminate(t);
}