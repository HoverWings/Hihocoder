#include<iostream>
#include <map>
#include <string>
#include <vector>
#include <string.h>
#include<string>
#include <algorithm>
using namespace std;
//ά��һ����
int num=0;

typedef pair<int, string> Token_t;
void token(const string &str, vector<Token_t> &vec)
{
	string word;
	string::size_type cur, pre = 0; 
	while ((cur = str.find('/', pre)) != string::npos) 
	{
		if (cur > pre)
			vec.push_back(make_pair(vec.size(), str.substr(pre, cur - pre)));
		pre = cur + 1;
	}
	cur = str.size();
	if (cur > pre)
		vec.push_back(make_pair(vec.size(), str.substr(pre, cur - pre)));
}

void put(map<Token_t, vector<Token_t> > & cont, const vector<Token_t> & vec) {
	map<Token_t, vector<Token_t> >::iterator iter;
	Token_t token;
	for (size_t i = 0; i < vec.size(); ++i) {
		iter = cont.find(vec[i]);
		if (iter != cont.end()) {
			token = vec[i];
			continue;
		}
		cont[vec[i]];
		cont[token].push_back(vec[i]);
		token = vec[i];
	}
}

void print(const map<Token_t, vector<Token_t> > & cont, map<Token_t, vector<Token_t> >::const_iterator iter) 
{
	if (iter != cont.end())
	{
		int n = iter->first.first;
		for (int i = 0; i < n; ++i)
			cout << "    ";
		if (!(iter->first.second.empty()))
			cout << iter->first.second << "\n";

		const vector<Token_t> &vec = iter->second;
		for (size_t i = 0; i < vec.size(); ++i) {
			iter = cont.find(vec[i]);
			print(cont, iter);
		}
	}
}

void display(const map<Token_t, vector<Token_t> > & cont) 
{
	Token_t t;
	if (cont.count(t) > 0)
	{
		// ���õݹ��㷨��ӡtoken
		print(cont, cont.find(t));
		num++;
	}
}

int main() {
	//string dir[5] = { "usr/local/bin", "usr/bin", "bin", "usr/share", "zip" };
	int length;
	cin >> length;
	string dir;
	map<Token_t, vector<Token_t> > content;
	vector<Token_t> vec;
	for (int i = 0; i < length; ++i) {
		// �ֽ�dir
		cin >> dir;
		token(dir, vec);
		// ��ÿ��token���뵽һ��map�У�map�ļ�Ϊtoken�Ĳ��������ƣ�ֵΪÿ��token
		// ��Ӧ����Ŀ¼��token
		put(content, vec);
		vec.clear();
	}
	map<Token_t, vector<Token_t> >::iterator iter = content.begin();
	// ����ÿ��token����Ӧ��Ŀ¼������token
	for (; iter != content.end(); ++iter)
		sort(iter->second.begin(), iter->second.end());
	// ��ʾ
	display(content);
	cout<< num;
}


