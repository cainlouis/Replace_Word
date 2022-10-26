#ifndef TRAVERSAL_DOT_H
#define TRAVERSAL_DOT_H

struct Traversal
{
    int changes;
    char filename;
};

int traversal(char *word, char *dirname, struct Traversal *items);

char* getRelativePath(char *dname, char *fname);

struct Traversal *getRapport(char *word, char *dirname);


#endif