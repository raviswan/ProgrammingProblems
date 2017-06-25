#include <stdio.h>
#include <stdlib.h>

/*Write Remove function to remove all the elements from linked list with value N */

typedef struct _LinkedListNode{
	int val;
	_LinkedListNode* next;
}LinkedListNode;


void insertNode(int val, LinkedListNode* head){
	LinkedListNode* node = head;
	LinkedListNode* newNode;
	
	while(node->next!=NULL){
		node = node->next;
	}
	newNode = (LinkedListNode*) malloc(sizeof(LinkedListNode));
	newNode->val = val;
	node->next = newNode;
	newNode->next = NULL;

}

void removeAll(int val, LinkedListNode **list){
	LinkedListNode* head = *list;
	LinkedListNode* current;
	LinkedListNode* prev;
	
	while(head != NULL && head->val == val){
		head = head->next;
		free(head);
	}
	if (head == NULL)
		return;

	prev= head;
	current = head->next;
	while(current != NULL){
		if(current->val == val){
			prev->next = current->next;
			free(current);
		}
		prev = current;
		current =  current->next;
	}
}

void removeElement(LinkedListNode* node){
	LinkedListNode* temp;
	if(node!=NULL && node->next != NULL){
		temp = node->next;
		*node = *(node->next);
		free(temp);
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
	LinkedListNode* head=NULL;

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
	removeElement(head->next->next);
	printList(head);

	return 0;

}
