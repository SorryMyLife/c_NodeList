// hello_c.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
//C语言单向链表


#include "pch.h"
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
typedef struct Node
{
	const char *data;
	int id;
	struct Node *next;
	void (*add)(const char *data);
	int (*size)();
	void (*display)();
	void (*clear)();
	const char*(*search)(int id);
	void(*insert)(int id, const char *data);
	void (*deleteId)(int id);
	void(*setValue)(int id, const char *value);
	const char *(*getId)(int id);
}List;

static int count = 0;
const char *ch = "null";
static int i = 0;
List *mal()
{
	List *l = (List *)malloc(sizeof(List));
	return l;
}

List *l = mal();
List *h = l;
List *s = mal();

void clear()
{
	free(l);
	count = 0;
}

void add(const char *data)
{
	s = mal();
	s->data = data;
	s->id = count;
	h->next = s;
	s->next = NULL;
	h = s;
	count++;
	//return h;
}

int size()
{
	return count;
}

void id_sort()
{
	List *tmp = l->next;
	while (tmp!=NULL)
	{
		if (tmp->next!=NULL)
		{
			if (tmp->id == tmp->next->id)
			{
				tmp->next->id = tmp->id + 1;
			}
			else if(tmp->id < tmp->next->id +1)
			{
				tmp->next->id = tmp->id + 1;
			}
		}
		tmp = tmp->next;
	}
}

const char *search(int id)
{
	id_sort();
	List *t = l->next;
	while (t != NULL)
	{
		if (t->id == id)
		{
			ch = t->data;
		}
		t = t->next;
	}
	return ch;
}

void display()
{
	for (int i = 0;i<size();i++)
	{
		printf("%d -- %s -> ",i,search(i));
	}
	printf("null \n");
	
}

void setValue(int id,const char *value)
{
	id_sort();
	List *t = l->next;
	while (t != NULL)
	{
		if (t->id == id)
		{
			t->data = value;
		}
		t = t->next;
	}
}

void insert(int id,const char *data)
{
	List *n = l;
	List *ss;
	List *nee = mal();
	while (i<id-1)
	{
		n = n->next;
		++i;
	}
	nee->data = data;
	nee->id = i;
	ss = n->next;
	n->next = nee;
	nee->next = ss;
	count++;
}

void deleteId(int id)
{
	List *n = l;
	List *ss;
	while (i < id - 1)
	{
		n = n->next;
		++i;
	}
	ss = n->next;
	n->next = n->next->next;
	free(ss);
	count--;
}

const char *getId(int id)
{
	return search(id);
}

void init_List(List *l)
{
	h->next = NULL;
	l->add = add;
	l->size = size;
	l->clear = clear;
	l->display = display;
	l->search = search;
	l->insert = insert;
	l->deleteId = deleteId;
	l->setValue = setValue;
	l->getId = getId;
}



int main()
{
	/*List *l = mal();
	init_List(l);
	l->add("aa1");
	l->add("aa2");
	l->add("aa3");
	l->add("aa4");
	printf("%s \n",l->getId(1));
	l->display();
	l->insert(1,"aa0");
	printf("%s \n", l->getId(1));
	l->display();
	l->deleteId(2);
	printf("%s \n", l->getId(2));
	l->display();
	l->clear();
	*/
	system("pause");
	return 0;
}

