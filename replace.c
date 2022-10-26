#include "report.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("No word to modify has been entered. Please enter a word to replace.");
    }
    else {
        report(argv[1], ".");
    }
    return 0;
}