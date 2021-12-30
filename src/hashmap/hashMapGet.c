#include <hashmap.h>

#include <stddef.h>
#include <string.h>

void* hashMapGet(HashMap* hashMap, char* name)
{
	unsigned int h = hashMapGetIndexFor(hashMap, hashMapHashCode(name));
	unsigned int i = hashMapGetIndexFor(hashMap, h);
	HashMapBusket* busket;

	for (busket = hashMap->buskets[i]; busket != NULL; busket = busket->next)
			if (strcmp(name, hashMap->getKey(busket->element)) == 0)
				return busket->element;

	return NULL;
}