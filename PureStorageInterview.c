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

void printList(LinkedListNode* head){
	LinkedListNode* node = head;
	while(node!=NULL){
		printf("%d ",node->val);
		node = node->next;
	}
	printf("\n\n");

}
int main(){
	int val;
	int arr[] = {3, 5 ,1, 3, 2, 3, 3};
	LinkedListNode* head = NULL;

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
	removeAll(5,&head);
	printList(head);

	return 0;

}
