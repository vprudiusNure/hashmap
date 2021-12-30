#include <stdio.h>
#include <stdlib.h>

#include <hashmap.h>

typedef struct Elem Elem;

struct Elem {
	char* key;
	int value;
};

char* eGetKey(const void* elem)
{
	const Elem* el = (Elem*) elem;
	return el->key;
}

int eCmp(const void* elem1, const void* elem2)
{
	const Elem* el1 = (Elem*) elem1;
	const Elem* el2 = (Elem*) elem2;

	return strcmp(el1->key, el2->key);
}

void eFree(const void* elem)
{
	Elem* el = (Elem*) elem;
	free(el->key);
	free(el);
}

int main()
{
	int i, n = 3;

	HashMap* hashMap = hashMapCreate(n, eGetKey, eCmp, eFree);

	for (i = 0; i < n; ++i)
	{
		Elem* el = (Elem*) malloc(sizeof(Elem));

		char* key = (char*) malloc(16);
		printf("Введите имя: ");
		scanf("%15s", key);

		char* str = (char*) malloc(5);
		printf("Введите возраст: ");
		scanf("%d", &(el->value));

		el->key = key;

		if (hashMapPut(hashMap, el) == -1)
			printf("Коллизия!\n");
	}

	printf("Поиск: ");
	char* strTmp = (char*) malloc(15);
	scanf("%14s", strTmp);
	Elem* search = (Elem*) hashMapGet(hashMap, strTmp);

	while (!search)
	{
		printf("Ничего не найдено, попробуйте ещё раз!\nПоиск: ");
		scanf("%14s", strTmp);
		search = (Elem*) hashMapGet(hashMap, strTmp);
	}

	printf("%s: %d\n", search->key, search->value);

	free(strTmp);
	hashMapFree(hashMap);

	return 0;
}