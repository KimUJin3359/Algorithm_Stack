#include "list.h"

int main()
{
	List stack;
	int input[16] = { 1, 2, 1, 3, 2, 4, 2, 5, 4, 6, 5, 6, 6, 7, 3, 7 };
	int map[7][7] = { 0, };
	bool visit[7] = { false, };
	int flag = 0;

	for (int i = 0; i < 8; i++)
	{
		map[(input[i * 2] - 1)][(input[i * 2 + 1] - 1)] = 1;
		map[(input[i * 2 + 1] - 1)][(input[i * 2] - 1)] = 1;
	}

	visit[0] = true;
	stack.push(0);
	printf("%d ", stack.top() + 1);
	while (true)
	{
		int i = 0;
		for (i = 0; i < 7; i++)
			if (!visit[i])
				break;
		if (i == 7)
			break;
		flag = 1;
		for (i = 0; i < 7; i++)
		{
			if (map[stack.top()][i] == 1 && !visit[i])
			{
				visit[i] = true;
				stack.push(i);
				printf("%d ", stack.top() + 1);
				flag = 0;
				break;
			}
		}
		if (flag == 1)
			stack.pop();
	}
}