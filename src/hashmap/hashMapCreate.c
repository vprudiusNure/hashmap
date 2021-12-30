#include <hashmap.h>

#include <stddef.h>
#include <stdlib.h>

HashMap* hashMapCreate(int size, char* (*getKey) (const void*), int (*cmp)(const void*, const void*), void (*freeElement)(const void*))
{
	HashMap* hashMap = (HashMap*) malloc(sizeof(HashMap));

	if (hashMap == NULL)
		return NULL;

	hashMap->getKey = getKey;
	hashMap->cmp = cmp;
	hashMap->freeElement = freeElement;
	hashMap->size = 0;
	hashMap->max = size;
	hashMap->buskets = NULL;

	return hashMap;
}