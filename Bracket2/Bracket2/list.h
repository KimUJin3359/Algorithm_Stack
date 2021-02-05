#ifndef LIST_H
# define LIST_H

# include <stdio.h>
# pragma warning (disable:4996)

class Node {
public:
	char data;
	Node *next;

	Node(char data);
};

class List {
public:
	Node *root;

	List();
	~List();
	void push(char c);
	char top();
	char pop();
	int get_size();
	void free();
};

#endif