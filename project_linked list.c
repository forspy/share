#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct nlist
{
	struct nlist *next;
	char *name;
	char *defn;
};

#define HASHSIZE 101
static struct nlist *hashtab[HASHSIZE];

main()
{
	
	struct nlist *npp;
	npp=install(npp->name, npp->defn);
	printf("请输入名字，详细信息\n");
	scanf("%s%s", npp->name, npp->defn);
}
unsigned hash(char *s)
{
	unsigned hashval;

	for (hashval = 0; *s != '\0'; s++)
		hashval = *s + 31 * hashval;
	return hashval%HASHSIZE;
}

struct nlist *lookup(char *s)
{
	struct nlist *np;

	for (np = hashtab[hash(s)]; np != NULL; np = np->next)
		if (strcmp(s, np->name) == 0)
			return np;
	return NULL;
}

struct nlist *lookup(char *);
//char *strdup(char *);

//install函数：将(name,defn)加入到hashtab中
struct nlist *install(char *name, char *defn)
{
	struct nlist *np;
	unsigned hashval;

	if ((np = lookup(name)) == NULL)
	{
		np = (struct nlist *)malloc(sizeof(*np));
		if (np == NULL || (np->name = strdup(name)) == NULL)
			return NULL;
		hashval = hash(name);
		np->next = hashtab[hashval];
		hashtab[hashval] = np;
	}
	else
		free((void*)np->defn);
	if ((np->defn = strdup(defn)) == NULL)
		return NULL;
	return np;
}
//char *strup(char *s)
//{
//	char *p;
//
//	p = (char *)malloc(strlen(s) + 1);
//	if (p != NULL)
//		strcpy(p, s);
//	return p;
//}
//
