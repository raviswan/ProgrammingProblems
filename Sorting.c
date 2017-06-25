#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int funcn(int x)
{
	return (x*x);
}

void * Malloc(int size){
	void *p = malloc(size);
	if (p==NULL){
		fprintf(stderr,"malloc failed\n");
		return NULL;
	}
	else 
		return p;
}


void printArray(int *a, int len)
{
	printf("the array elements are:\n ");
	for(int i=0;i<len;i++){
		printf("%d\n",a[i]);
	}
}


void bubblesort(int *a,int n){
	int largest;
	int temp;
	for (int i=0;i<n;i++){
		//largest=a[i];
		for(int j=0;j<n-i;j++){
			if (a[j]>a[j+1]){
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;

			}
		}
	}
}
void selectionsort(int *a,int n){
	int largest;
	int temp;
	for (int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			if (a[i]>a[j]){
				temp=a[i];
				a[i]=a[j];
				a[j]=temp;

			}
		}
		printf("After %d iteration,%d element is %d\n",i+1,i,a[i]);
	}
}

typedef  int (*compareFunc)(const void * p1, const void *p2);

/*----------QuickSort---------------------------------*/

void quicksort(int *a, int left, int right){
	int i=left, j=right, temp;
	int pivot=a[(left+right)/2];
	while(i<=j){
			while(a[i]<=pivot)
				i++;
			while(a[j]>pivot)
				j--;
			if(i<=j){
				temp=a[i];
				a[i]=a[j];
				a[j]=temp;
				i++;
				j--;
			}
	}
	if(left<j)
		quicksort(a,left,j);

	if(i<right)
		quicksort(a,i,right);
}



/*==========----------Merge Sort---------------==============*/
void merge(int *a, int left, int mid, int right){
	int lpos = left;
	int rpos = mid+1;
	int pos = 0;
	int * temp = (int*) Malloc(sizeof(int)*(right-left+1));
	
	/*Compare left half of array with right half starting at one past mid point*/
	
	while(lpos<=mid && rpos<=right){
		printf(" MERGE:left=%d , mid=%d right=%d\n",left, mid, right);
		if(a[lpos]< a[rpos])
			temp[pos++] = a[lpos++];
		else
			temp[pos++] = a[rpos++];
	}
	while(lpos<=mid)
		temp[pos++] = a[lpos++];
	while(rpos<=right)
		temp[pos++] = a[rpos++];
	memcpy((void*)(a+left),(void*)temp,((right-left+1)*sizeof(int)));
    free(temp);
	//for(int i =0 ;i<pos;i++)
	//	a[left+i] = temp[i];
}

void mergeSort(int *a,int left, int right ){
	unsigned int mid = (unsigned int)((unsigned int)left+ (unsigned int)right) >> 1;
	if (left < right){
		printf("MERGESORT: left=%d , right=%d\n",left, right);
		mergeSort(a,left,mid);
		mergeSort(a,mid+1,right);
		merge(a,left,mid,right);
	}
	return;
}
void swap(int *a, int *b){
	int *temp = (int*)Malloc(sizeof(int)) ;
	*temp = *a;
	*a = *b;
	*b= *temp;
	free(temp);
}
/*=====================Insertion Sort==============================*/

void insertionSort(int *a, int length){
	int i,j;
	for (j=1;j<length;j++){
		i=j-1;
		int curr_elem = a[j];
		printf("\niteration:%d\n",j);
		while(i>=0 && a[i]>curr_elem ){
			a[i+1] = a[i];
			i--;	
		}
		a[i+1] = curr_elem;
		printArray(a,length);
	}
}


int main()
{
	int a[]={32,5,1,99,33,1,0,55};	
	struct node
	{
		int n;
		struct node *next;
		/* data */
	};
	
	printArray(a,8);
	//bubblesort(a,8);
	//selectionsort(a,8);
	//quicksort(a,0,7);
	//mergeSort(a,0,7);
	insertionSort(a,8);
	printf("sizeof(int)=%ld\n",sizeof(int));
	//printArray(a,8);
	return 0;
}


