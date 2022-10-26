#include "traversal.h"
#include "report.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
Create the Sorting logic descending
*/
int compare(const void * a, const void * b) {
    const struct Traversal *i = a;
    const struct Traversal *j = b;
    return (i->changes < j->changes) - (j->changes < i->changes);
}

/*
Fetch the struct array from traversal file, sort it and print the report
*/
int report(char *word, char *dirname) {
    int counter = 0;
    struct Traversal *items = getArray(word, dirname); 
    //print info on the report
    printf("Tartget String: %s\n", word);
    printf("|** Search Report **|\n");
    printf("Updates             File Name\n");

    //Compare to get the number of files so the printing wont have to go through the whole array of struct
    for (int j = 0; j < ARRAY_SIZE; j++) {
        if (strcmp(items[j].fpath, "\0")){
            counter++;
        }
    }
    
    //sorting in descending order
    qsort(items, counter, sizeof(*items), compare);

    //Printing the report
    for (int i = 0; i < counter; i++) {
        printf("%d          in       %s\n", items[i].changes, items[i].fpath);
    }
    return 0;
}
