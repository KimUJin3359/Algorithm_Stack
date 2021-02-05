#include <stdio.h>

int pow(int base, int power)
{
	if (power == 0)
		return (1);
	return (base * pow(base, power - 1));
}

int main()
{
	int case_n = 1;
	int base = 0;
	int power = 0;
	int res;

	while (case_n <= 10)
	{
		scanf("%d\n", &case_n);
		scanf("%d ", &base);
		scanf("%d\n", &power);

		res = pow(base, power);
		printf("#%d %d\n", case_n, res);
		case_n++;
	}
}