#include <stdio.h>
#include <stdlib.h>

typedef struct List_node {
	int value;
	struct List_node *next;
} List_node;

typedef struct List_node List;

List *swap(List *head, List *node_1, List *node_2)
{
//不應該用and，應該用or，只要linked-list是空的 or node1/node2 不存在 or node1 = node2
//就直接返回，所以應該用||
	if (!head ||
	        (node_1 == NULL) || (node_2 == NULL) ||
	        (node_1 == node_2))
		return head;

	int num_pre_node_1_and_node_2 = 0;

	List *_head = head;
	List *pre_node_1 = NULL;
	List *pre_node_2 = NULL;
	List *tmp_node = NULL;

//加入else if，減少編譯器執行時的判斷
//兩個if的用意是可以順便判斷node1和node2是否存在

//num_pre_note_1_and_note_2的功用在
//1.尋找node1 or note2 找到 = 1
//2.
	while (head && head->next) {
		if (head->next == node_1) {
			pre_node_1 = head;
			num_pre_node_1_and_node_2 = num_pre_node_1_and_node_2 + 1;
		} else if (head->next == node_2) {
			pre_node_2 = head;
			num_pre_node_1_and_node_2 = num_pre_node_1_and_node_2 + 1;
		}
		head = head->next;
	}

	head = _head;
	if (head == node_1) {
		pre_node_1 = NULL;
		num_pre_node_1_and_node_2 = num_pre_node_1_and_node_2 + 1;
	} else if(head == node_2) {
		pre_node_2 = NULL;
		num_pre_node_1_and_node_2 = num_pre_node_1_and_node_2 + 1;
	}

	if (pre_node_1 == NULL) {
		pre_node_2->next = node_1;
		tmp_node = node_1->next;
		node_1->next = node_2->next;
		node_2->next = tmp_node;
		return node_2;
	}

	if (pre_node_2 == NULL) {
		pre_node_1->next = node_2;
		tmp_node = node_2->next;
		node_2->next = node_1->next;
		node_1->next = tmp_node;
		return node_1;
	}
//兩個相鄰node的交換可以不必做
//只要在交換時先存取node1 和 node2 的值就可以了
	/*
	    if (node_2->next == node_1) {
	        pre_node_2->next = node_1;
	        tmp_node = node_1->next;
	        node_1->next = node_2;
	        node_2->next = tmp_node;
	        return head;
	    }

	    if (node_1->next == node_2) {
	        pre_node_1->next = node_2;
	        tmp_node = node_2->next;
	        node_2->next = node_1;
	        node_1->next = tmp_node;
	        return head;
	    }
	*/
	pre_node_1->next = node_2;
	pre_node_2->next = node_1;
	tmp_node = node_2->next;
	node_2->next = node_1->next;
	node_1->next = tmp_node;
	return head;
}
