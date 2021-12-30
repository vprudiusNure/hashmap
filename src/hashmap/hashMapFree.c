#include <hashmap.h>

#include <stdlib.h>

void hashMapFree(HashMap* hashMap)
{
	int i;
	HashMapBusket* p1;
	HashMapBusket* p2;
	
	for (i = 0; i < hashMap->max; ++i)
	{
		p1 = hashMap->buskets[i];
		while (p1 != NULL)
		{
			p2 = p1;
			p1 = p1->next;
			hashMap->freeElement(p2->element);
			free(p2);
		}
	}			

	free(hashMap->buskets);
	free(hashMap);
}