#include <hashmap.h>

#include <stddef.h>
#include <stdlib.h>

int hashMapPut(HashMap* hashMap, void* element)
{
	unsigned int max = hashMap->max;

	if (hashMap->buskets == NULL)
	{
		if (max < HASHMAP_INIT_SIZE)
			max = HASHMAP_INIT_SIZE;

		hashMap->buskets = (HashMapBusket**) calloc(max, sizeof(HashMapBusket*));

		if (hashMap->buskets == NULL)
			return -1;

		hashMap->size = 0;
		hashMap->max = max;
	}
	else if (hashMap->size >= hashMap->max)
	{
		max = HASHMAP_GROWTH_SIZE * hashMap->max;
		
		HashMapBusket** tmp = (HashMapBusket**) realloc(hashMap->buskets, max * sizeof(HashMapBusket*));
		
		if (tmp == NULL)
			return -1;

		hashMap->buskets = tmp;
		hashMap->max = max;
	}

	unsigned int h = hashMapHashCode(hashMap->getKey(element));
	unsigned int i = hashMapGetIndexFor(hashMap, h);

	HashMapBusket* busket;

	for (busket = hashMap->buskets[i]; busket != NULL; busket = busket->next)
			if (hashMap->cmp(element, busket->element) == 0)
				return -1;

	busket = (HashMapBusket*) malloc(sizeof(HashMapBusket));

	if (busket == NULL)
		return -1;

	busket->hash = h;
	busket->element = element;
	busket->next = hashMap->buskets[i];

	hashMap->buskets[i] = busket;
	++hashMap->size;

	return 0;
}