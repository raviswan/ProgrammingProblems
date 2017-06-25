#include "list.h"

#define SUCCESS 1
#define FAILURE -1

typedef  bool (*MatchFn)(void* arg1,void* arg2);
typedef int (*HashFn)(void* arg);

class HashTable
{
public:
	HashTable(size_t buckets,MatchFn,HashFn);
	int insertData(void* data);
	void destroy();
	int removeData(void** data);
	int lookupData(void** data);
	size_t getBucketSize();
	~HashTable();
private:
	size_t buckets;
	size_t dataCount;
	size_t loadFactor;
	size_t maxLoadFactor;
	List* hTable;
	MatchFn match;
	HashFn hFunc;
};