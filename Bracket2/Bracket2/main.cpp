#include "list.h"

size_t	ft_strlen(char *str)
{
	int i = 0;

	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

int main()
{
	int i = 0;
	int size = 0;
	int test_c = 1;
	List stack;
	char str[1024];
	char arr[128];
	arr[')'] = '(';	arr['>'] = '<';	arr[']'] = '[';	arr['}'] = '{';


	while (test_c <= 10)
	{
		i = 0;
		scanf("%d\n", &size);
		scanf("%s", str);
		while (str[i])
		{
			if (str[i] == '(' || str[i] == '<' || str[i] == '[' || str[i] == '{')
				stack.push(str[i]);
			else
			{
				if (stack.top() == arr[str[i]])
					stack.pop();
				else
					break;
			}
			i++;
		}
		if (i == ft_strlen(str) && stack.get_size() == 0)
			printf("#%d 1\n", test_c);
		else
			printf("#%d 0\n", test_c);
		stack.free();
		test_c++;
	}
}