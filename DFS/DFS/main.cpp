#include <stdio.h>

void dfs_recursive(bool *visit, int map[7][7], int now);

int main()
{
	int input[16] = { 1, 2, 1, 3, 2, 4, 2, 5, 4, 6, 5, 6, 6, 7, 3, 7 };
	int map[7][7] = { 0, };
	bool visit[7] = { false, };

	for (int i = 0; i < 8; i++)
	{
		map[(input[i * 2] - 1)][(input[i * 2 + 1] - 1)] = 1;
		map[(input[i * 2 + 1] - 1)][(input[i * 2] - 1)] = 1;
	}

	//dfs_recursive
	dfs_recursive(visit, map, 0);
}

void dfs_recursive(bool *visit, int map[7][7], int now)
{
	int i;

	for (i = 0; i < 7; i++)
	{
		if (!visit[i])
			break;
	}
	if (i == 7)
		return;
	visit[now] = true;
	printf("%d ", now+1);
	for (i = 0; i < 7; i++)
	{
		if (map[now][i] == 1 && visit[i] == false)
			dfs_recursive(visit, map, i);
	}
}