
#include <stdio.h>
#include <stdlib.h>


typedef struct Node{
	int item;
	struct Node *next;
	struct Node *prev;
}Node ;

void * Malloc(int size){
	void *p = malloc(size);
	if (p==NULL){
		printf("malloc failed\n");
		return NULL;
	}
	else 
		return p;
}
Node* CreateNode(int n){
	Node *node = (Node*) Malloc(sizeof(Node));
	node->item = n;
	node->next = NULL;
	node->prev = NULL;
	return node;
}


int CountNumberofItemsInList(Node *node){
	int count=0;
	while(node!=NULL){
		count++;
		node=node->prev;
	}	return count;

}

void PrintLinkList(Node *node){
	int cnt=1;
	printf("PREVIOUS  CURRENT  NEXT\n");
	while(node!=NULL){
		printf("element %d is %3d %3d %3d\n",cnt,(node->prev)->item,node->item,(node->next)->item);
		node=node->next;
		cnt++;
	}

}
//Remember head is pointer to pointer to first element
void InsertItemDoublyLinkList(int elem, int pos, Node **head){
	Node *p=*head;
	Node *q;
	int cnt=1;
	Node *newNode = CreateNode(elem);
	
	if(pos==1){
		if(*head){
			newNode->next=*head;
			(*head)->prev=newNode;
		}
		*head=newNode;
	printf("Element %d inserted at position %d \n",(*head)->item,pos);
		return;

	}
	else{
		while(p->next!=NULL && cnt<pos-1){
			cnt++;
			p=p->next;
			
		}
		q=p;
		newNode->next=p->next;
		q->next=newNode;
		newNode->prev=q;
		p->next->prev=newNode;
		newNode->item=elem;
	}
		
	printf("Element %d inserted at position %d with PREV=%d\n",newNode->item,pos,(newNode->prev)->item);
	return ;
}
	

void DeleteItemDoublyLinkList(int pos, Node **head){
	Node *p=*head;
	Node *q=p;
	int cnt=1;
	
	
	if(pos==1){
		*head=p->next;
		(*head)->prev=NULL;
		free(p);
		return;
	}
	else{
		while(p!=NULL && cnt<pos){
			cnt++;
			q=p;
			p=p->next;
		}
		if(p==NULL){
			printf("the position does not exist\n");
		}
		q->next=p->next;
		(p->next)->prev=q;
		free(p);
	}
		

	return;
}	
		
int main(int argc, char** argv){
	//Node *h=CreateNode(5);
	Node *h;
	InsertItemDoublyLinkList(10,1,&h);
	InsertItemDoublyLinkList(20,2,&h);
	//PrintLinkList(h);

	InsertItemDoublyLinkList(30,3,&h);
	InsertItemDoublyLinkList(50,2,&h);
	InsertItemDoublyLinkList(70,3,&h);
	CountNumberofItemsInList(h);
	//PrintLinkList(h);
	//DeleteItemDoublyLinkList(3,&h);
	//PrintLinkList(h);
	return 0;



}

