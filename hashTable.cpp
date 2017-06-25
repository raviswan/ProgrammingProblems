#include "hashTable.h"
#include <cmath>
#include <cstdlib>

HashTable::HashTable(size_t buckets,MatchFn match,HashFn h):
buckets(buckets),match(match),hFunc(h),dataCount(0){
	hTable = new List[buckets];
}

size_t HashTable::getBucketSize(){
	return this->buckets;
}

/*Look up the value pointed to by "data", which acts as both input and output here. If found, the return value is stored 
in "data" and function returns TRUE*/
int HashTable::lookupData(void** data){
	int bucket;
	int hashCode = hFunc(*data);
	ListElem* node;
	/*Hash the key using division method */
    bucket = floor(fmod(hashCode*0.618,1.0) * this->buckets);
    node = (hTable+bucket)->getListHead();
    while(node != NULL){
    	if(match(*data,node->getData())){
    		*data = node->getData();
    		return SUCCESS;
    	}
    	else
    		node = node->getNextElem();
    }
    return FAILURE;
}

int HashTable::insertData(void* data){
	int bucket;
	int hashCode = hFunc(data);
	void* temp =  data;
	if(this->lookupData(&temp) == SUCCESS)
		return SUCCESS;
	/*Hash the key using division method */
    bucket = floor(fmod(hashCode*0.618,1.0) * buckets);
    if((hTable+bucket)->insertAfter(NULL,data) == 0){
    	this->dataCount++;
    	return SUCCESS;
    }
    else{
    	printf("insertion into hash table failed\n");
    	exit(EXIT_FAILURE);
    }
}

/*remove the value pointed to by "data", which acts as both input and output here. If found, the return value is stored 
in "data"*/
int HashTable::removeData(void** data){
	int bucket;
	int hashCode = hFunc(data);
	ListElem* node;
	ListElem* prev;
	/*Hash the key using division method */
    bucket = floor(fmod(hashCode*0.618,1.0) * buckets);
    prev = NULL;
    node = (hTable+bucket)->getListHead();
    /*Traverse through the linked list for this bucket*/
    while(node != NULL){
    	/*if match found, point prev elem to next(current),remove current*/
    	if(match(*data,node->getData())){
    		if((hTable+bucket)->removeAfter(prev,data) == 0){
	    		this->dataCount--;
	    		return SUCCESS;
	    	}
	    	else{
	    		printf("List element removal failed\n");
	    		return FAILURE;
	    	}
    	}
    	prev = node;
    	node = node->getNextElem();
    }
    return FAILURE;
}

void HashTable::destroy(){
	for(int i=0;i<buckets;i++){
		(hTable+i)->destroyList();
	}
	delete[] hTable;
}

HashTable::~HashTable(){
	if(hTable)
		delete[] hTable;
}