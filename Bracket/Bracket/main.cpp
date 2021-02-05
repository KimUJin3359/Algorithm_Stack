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
	List stack;
	char str[256];
	char arr[128];
	arr[')'] = '(';
	arr['>'] = '<';

	scanf("%s", str);
	while (str[i])
	{
		if (str[i] == '(' || str[i] == '<')
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
		printf("Right");
	else
		printf("Wrong");
	stack.free();
}