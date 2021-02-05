#ifndef LIST_H
# define LIST_H

# include <stdio.h>
# pragma warning (disable:4996)

class Node {
public:
	int data;
	Node *next;

	Node(int data);
};

class List {
public:
	Node *root;

	List();
	~List();
	void push(int c);
	char top();
	char pop();
	int get_size();
	void free();
};

#endif