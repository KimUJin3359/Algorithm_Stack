#include <stdio.h>
#pragma warning (disable:4996)

void find_exit(char map[16][16], int now_x, int now_y);
int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };
int flag = 0;

int main()
{
	char map[16][16];
	int test_c = 1;

	while (test_c <= 10)
	{
		int now_x;
		int now_y;

		flag = 0;
		scanf("%d", &test_c);
		for (int i = 0; i < 16; i++)
		{
			for (int j = 0; j < 16; j++)
			{
				scanf(" %c ", &map[i][j]);
				if (map[i][j] == '2')
				{
					now_x = j;
					now_y = i;
				}
			}
		}
		find_exit(map, now_x, now_y);
		printf("#%d %d\n", test_c, flag);
		test_c++;
	}
}

void find_exit(char map[16][16], int now_x, int now_y)
{
	if (map[now_y][now_x] == '3' || flag)
	{
		flag = 1;
		return;
	}
	for (int i = 0; i < 4; i++)
	{
		if ((now_x + dx[i] >= 0 && now_x + dx[i] <= 15 && now_y + dy[i] >= 0 && now_y + dy[i] <= 15) &&
			map[now_y + dy[i]][now_x + dx[i]] == '0' || map[now_y + dy[i]][now_x + dx[i]] == '3')
		{
			map[now_y][now_x] = '1';
			find_exit(map, now_x + dx[i], now_y + dy[i]);
			map[now_y][now_x] = '0';
		}
	}
}