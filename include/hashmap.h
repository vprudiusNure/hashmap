#ifndef HASHMAP_H
#define HASHMAP_H

#define HASHMAP_INIT_SIZE 1
#define HASHMAP_GROWTH_SIZE 2

typedef struct HashMapBusket HashMapBusket;

struct HashMapBusket {
	unsigned int hash;
	void* element;
	HashMapBusket* next;
};

typedef struct HashMap HashMap;

struct HashMap {
	char* (*getKey)(const void*);
	int (*cmp)(const void*, const void*);
	void (*freeElement)(const void*);
	int size;
	int max;
	HashMapBusket** buskets;
};

HashMap* hashMapCreate(int, char* (*)(const void*), int (*)(const void*, const void*), void (*)(const void*));

int hashMapPut(HashMap*, void*);
void* hashMapGet(HashMap*, char*);
unsigned int hashMapGetSize(HashMap*);
unsigned int hashMapGetIndexFor(HashMap*, unsigned int);
void hashMapFree(HashMap*);
unsigned int hashMapHashCode(const char*);

#endif
