#include "text.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1000

/**
 * Returns total occurrences of a word in given file.
 */
int findOccurrences(FILE *rfile, char *word)
{
    char str[BUFFER_SIZE];
    char *pos;

    int wordlength, occu, count, strlength, i, j, temp;
    wordlength = strlen(word);
    occu = 0;
    // printf("%s\n", count);
    // Read line from file till end of file.
    while ((fgets(str, BUFFER_SIZE, rfile)) != NULL)
    {
        strlength = strlen(str);
        printf("%s\n", str);
        for (i = 0; i < strlength; i++) {
            temp = i;
            for (j = 0; j < wordlength; j++) {
                if (str[i] == word[j]) {
                    i++;
                }
            }
            count = i - temp;
            if (count == wordlength) {
                occu++;
            }
            i = temp;
        }
    }
    printf("%s\n", occu);
    return occu;
}