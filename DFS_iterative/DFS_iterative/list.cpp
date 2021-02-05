#include "list.h"

Node::Node(int data)
{
	this->data = data;
	this->next = NULL;
}


List::List() {};
List::~List() {};

void List::push(int c)
{
	Node *item = new Node(c);
	if (root)
	{
		item->next = root;
		root = item;
	}
	else
		root = item;
}

char List::top()
{
	if (!root)
		return ('\0');
	return (root->data);
}

char List::pop()
{
	char data = root->data;
	Node *temp = root->next;
	delete root;
	root = temp;
	return (data);
}

int List::get_size()
{
	int size = 0;
	Node *temp = root;
	if (!root)
		return (0);
	while (temp)
	{
		temp = temp->next;
		size++;
	}
	return (size);
}

void List::free()
{
	Node *temp;

	while (root)
	{
		temp = root->next;
		delete root;
		root = temp;
	}
}