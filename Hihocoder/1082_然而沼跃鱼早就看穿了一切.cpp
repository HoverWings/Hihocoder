#include<cstdio>
#include<iostream>
#include<cctype>
#include<cstring>
using namespace std;


//±éÀúËã·¨
int main()
{
	char str[205];
	//while (fgets(str,200,stdin) != NULL)
	while (fgets(str,205,stdin))
	{
		int len_str = strlen(str);
		//cout << len_str << endl;
		for (int i = 0; i < len_str; i++)
		{
			if (i + 9 < len_str && (str[i] == 'm' || str[i] == 'M')
				&& (str[i + 1] == 'a' || str[i + 1] == 'A')
				&& (str[i + 2] == 'r' || str[i+2] == 'R')
				&& (str[i + 3] == 's' || str[i+3] == 'S')
				&& (str[i + 4] == 'h' || str[i + 4] == 'H')
				&& (str[i + 5] == 't' || str[i + 5] == 'T')
				&& (str[i + 6] == 'o' || str[i + 6] == 'O')
				&& (str[i + 7] == 'm' || str[i + 7] == 'M')
				&& (str[i + 8] == 'p' || str[i + 8] == 'P')
				)
			{
				printf("fjxmlhx");
				i += 9;
			}
			printf("%c", str[i]);
		}
		//printf("\n");
	}
	return 0;
}
