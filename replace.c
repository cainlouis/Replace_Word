#include "traversal.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("No word to modify has been entered. Please enter a word to replace.");
    }
    else {
        int i = 0;
        // char word = argv[0];
        struct Traversal *items = getArray(argv[1], ".");
        while (i < ARRAY_SIZE && items[i].fpath != NULL) {
            // printf("%s\n", items[i].fpath);
            i++;
        }
        free(items);
    }
    return 0;
}