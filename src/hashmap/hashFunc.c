#include <hashmap.h>

unsigned int hashMapHashCode(const char* key)
{
	unsigned int h;
	char* p;
	h = 0;
	for (p = (char*) key; *p != '\0'; ++p)
		h = 31 * h + *p;
	return h;
}