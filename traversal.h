#ifndef TRAVERSAL_DOT_H
#define TRAVERSAL_DOT_H

struct Traversal
{
    int changes;
    char *fpath;
};

int traversal(char *word, char *dirname);

void getIndex(char *word, char *dirname);

struct Traversal getArray(char *word, char *dirname);

#endif