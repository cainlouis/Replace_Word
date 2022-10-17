#include "traversal.h"
#include <stdio.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("No word to modify has been entered. Please enter a word to replace.");
    }
    else {
        // char word = argv[0];
        traversal(argv[0], ".");
    }
    return 0;
}