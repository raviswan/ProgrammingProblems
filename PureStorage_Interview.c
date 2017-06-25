#include <stdio.h>
#include <stdlib.h>

/*Write Remove function to remove all the elements from linked list with value N */

typedef struct _LinkedListNode{
	int val;
	struct _LinkedListNode* next;
}LinkedListNode ;


/*Inserting node at the end of the list. Assumes the head is not NULL*/
void insertNode(int val, LinkedListNode* head){
	LinkedListNode* node = head;
	LinkedListNode* newNode;
	/*Get to the last element*/
	while(node->next!=NULL){
		node = node->next;
	}
	/*Make newNode the last element*/
	newNode = (LinkedListNode*) malloc(sizeof(LinkedListNode));
	newNode->val = val;
	node->next = newNode;
	newNode->next = NULL;

}

void removeAll(int val, LinkedListNode **list){
	LinkedListNode* current;
	LinkedListNode* prev;
	LinkedListNode* temp;
	/*starting at head, loop through, freeing elements until you hit a node that equal val*/
	while(*list != NULL && (*list)->val == val){
		temp = *list;
		*list = (*list)->next;
		free(temp);
	}
	/*if end of list, return*/
	if (*list == NULL)
		return;
	prev= *list;
	current = (*list)->next;
	//printf("prev val = %d , current = %d\n",prev->val,current->val);
	while(current != NULL){
		//printf("prev val = %d , current = %d\n",prev->val,current->val);
		if(current->val == val){
			//printf("gonna remove %d\n",current->val );
			prev->next = current->next;
			temp = current->next;
			//printf("Freeing value %d\n",current->val);
			free(current);
			current = temp;
			//printf("head=%p ;value at head=%d",*list,(*list)->val);
		}
		else{
			prev = current;
			current =  current->next;
		}
	}
}

void removeElement(LinkedListNode *ptr){
	if (ptr==NULL || ptr->next ==NULL){
		printf("Not possible to remove element here");
		return;
	}
	else{
		LinkedListNode* temp = ptr->next;
		ptr->val = temp->val;
		ptr->next = temp->next;
		free(temp);
	}
}

LinkedListNode* getNode(int val,LinkedListNode* head){
	LinkedListNode* node = head;;
	while (node != NULL){
		if(node->val == val)
			return node;
		else
			node = node->next;
	}
	return NULL;
}

void printList(LinkedListNode* head){
	LinkedListNode* node = head;
	while(node!=NULL){
		printf("%d ",node->val);
		node = node->next;
	}
	printf("\n\n");

}

LinkedListNode* reverseList(LinkedListNode* head){
	printf("headInside1 =%p\n",head);
	if(head==NULL)
		return NULL;
	LinkedListNode* prev;
	LinkedListNode* curr;
	LinkedListNode* temp;
	curr = head;
	prev = NULL;

	while(curr->next !=NULL){
		temp = curr->next;
		curr->next = prev;
		prev = curr;
		curr = temp;
		//printf("curr value = %d\n",curr->val );
	}
	curr->next = prev;
	head = curr;
	printf("headInside2 =%p\n",head);
	return head;
}

int main(){
	int val;
	int arr[] = {3, 5 ,1, 88,4,77,3, 2, 13, 3, 3};
	LinkedListNode* head = NULL;
	LinkedListNode* newHead;

	for(int i=0;i<sizeof(arr)/sizeof(*arr);i++){
		if(head == NULL){
			head = (LinkedListNode*) malloc(sizeof(LinkedListNode));
			head->val =  arr[i];
			head->next = NULL;
		}
		else{
			insertNode(arr[i],head);
		}
	}
	printList(head);
	removeAll(3,&head);
	printList(head);
	removeElement(getNode(88,head));
	printList(head);
	removeAll(5,&head);
	printf("reversed list\n");
	printf("headOutside1 =%p\n",head);
	newHead = reverseList(head);
	printf("headOutside2 =%p\n",head);
	printf("newHead =%p\n",newHead);
	printList(newHead);

	return 0;

}