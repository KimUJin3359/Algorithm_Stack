#include "list.h"

int main()
{
	List stack;

	stack.push('a');
	stack.push('b');
	stack.push('c');

	printf("%c\n", stack.pop());
	printf("%c\n", stack.pop());
	printf("%c\n", stack.pop());
	stack.free();
}