#ifndef TRAVERSAL_DOT_H
#define TRAVERSAL_DOT_H

#define ARRAY_SIZE 10

struct Traversal
{
    int changes;
    char* fpath[100];
};

int traversal(char *word, char *dirname, struct Traversal *items);

void getIndex(char *word, char *dirname);

struct Traversal *getArray(char *word, char *dirname);

#endif