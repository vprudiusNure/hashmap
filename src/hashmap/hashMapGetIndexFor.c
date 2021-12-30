#include <hashmap.h>

unsigned int hashMapGetIndexFor(HashMap* hashMap, unsigned int h)
{
	return h % (hashMap->max);
}
