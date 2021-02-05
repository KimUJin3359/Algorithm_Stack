#include <stdio.h>
#pragma warning (disable:4996)

void initialize(bool map[100][100], bool visit[100]);
void dfs(int cnt, bool map[100][100], bool visit[100], int rep);

static int flag = 0;

int main()
{
	bool map[100][100];
	bool visit[100];
	int test_c = 1;
	int input_n;

	while (test_c <= 10)
	{
		int i = 0;
		int last = 0;
		flag = 0;

		initialize(map, visit);
		scanf("%d", &test_c);
		scanf("%d", &input_n);
		while (i < input_n)
		{
			int a, b;

			scanf("%d %d ", &a, &b);
			map[a][b] = true;
			i++;
		}
		for (i = 0; i < 100; i++)
			if (map[i][99] == true)
				last++;
		if (last != 0)
			dfs(0, map, visit, 1);
		printf("#%d %d\n", test_c, flag);
		test_c++;
	}
}

void dfs(int cnt, bool map[100][100], bool visit[100], int rep)
{
	if (cnt == 99)
	{
		flag = 1;
		return;
	}
	if (flag == 1)
		return;
	for (int i = 0; i < 100; i++)
	{
		if (map[cnt][i] == 1 && visit[i] == false)
		{
			visit[i] = true;
			dfs(i, map, visit, rep + 1);
			visit[i] = false;
		}
	}
}

void initialize(bool map[100][100], bool visit[100])
{
	for (int i = 0; i < 100; i++)
	{
		for (int j = 0; j < 100; j++)
			map[i][j] = false;
	}
	for (int i = 0; i < 100; i++)
		visit[i] = false;
}