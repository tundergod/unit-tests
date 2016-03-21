#include "swap.c"

//返回中間節點的位置
List find_middle(List *head)
{
	List *fast;
	List *slow;
	fast = head;
	slow = head;
//如果是空的(head = NULL)：結束
	if(head == NULL)
		return *head;
//當快的節點沒有找到最後，繼續
//找到了退出while迴圈，返回slow節點當前的位置(*head)
//即，中間節點位置(slow)
	while(fast->next->next != NULL) {
		slow = slow->next;
		fast = fast->next->next;
	}
	return *slow;
}


//把分解的各個節點結合，利用swap函式排列，返回排序好的linked-list
List merge_linked_list(List *first, List *second)
{
	//因爲之後的尋找會把first移動，先紀錄head的節點位置
	List *sub_head = first;

	//先串起來再比大小，因爲有swap函式存在
	//第一個在前面，第二個接在後面
	while(first->next != NULL) {
		first = first->next;
	}

	//找到最後一個節點，指向第二個linked-list的head
	first->next = second;
	second = NULL;

	//first指回head
	first = sub_head;

	//比整個linkedlist的大小，利用swap排序
	while(first->next != NULL) {
		if(first > first->next)
			swap(sub_head,first,first->next);
		first = first -> next;
	}
	return *sub_head;
}

List split_linked_list(List *head)
{
	List *first;
	List *middle;
	List *second_head;
	first = head;

	//if只有一個node
	if(first->next != NULL ) {
		*middle = find_middle(first);//尋找中間節點
		second_head = middle->next;//中間節點的下一個節點爲分開後linked-list的head
		//檢查是否最後了（兩個node）
		if(first->next->next == NULL) {
			return merge_linked_list(first,second_head);
		}

		return merge_linked_list(split_linked_list(first), split_linked_list(second_head));
	}
}

void merge_sort(List **head)
{
	List *merge_head;
	merge_head = *head;
	//空集則結束
	if(merge_head == NULL || (*head == NULL) || merge_head->next == NULL)
		return;
	*merge_head = split_linked_list(merge_head);
	return;
}
