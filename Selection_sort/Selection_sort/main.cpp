#include <stdio.h>

void swap(int &a, int &b);
void selection_sort_iterative(int *map, int size);
void selection_sort_recursive(int *map, int size, int cnt);

int main()
{
	int size = 16;
	int map_i[16] = { 5, 4, 3, 2, 1, 10, 9, 8, 7, 6, 15, 14, 13, 12, 11, 16 };
	selection_sort_iterative(map_i, 16);

	int map_r[16] = { 16, 11, 12, 13, 14, 15, 6, 7, 8, 9, 10, 1, 2, 3, 4, 5 };
	selection_sort_recursive(map_r, 16, 0);

	for (int i = 0; i < 16; i++)
		printf("%d ", map_i[i]);
	printf("\n");
	for (int i = 0; i < 16; i++)
		printf("%d ", map_r[i]);
}

void swap(int &a, int &b)
{
	int temp;

	temp = a;
	a = b;
	b = temp;
}

void selection_sort_iterative(int *map, int size)
{
	int i = 0;
	int min_i;
	int min_v;

	for (int i = 0; i < size; i++)
	{
		min_v = 987654321;
		for (int j = i; j < size; j++)
		{
			if (min_v > map[j])
			{
				min_v = map[j];
				min_i = j;
			}
		}
		swap(map[i], map[min_i]);
	}
}

void selection_sort_recursive(int *map, int size, int cnt)
{
	int min_i;
	int min_v = 987654321;

	if (cnt == size)
		return;
	for (int i = cnt; i < size; i++)
	{
		if (map[i] < min_v)
		{
			min_v = map[i];
			min_i = i;
		}
	}
	swap(map[cnt], map[min_i]);
	selection_sort_recursive(map, size, ++cnt);
}