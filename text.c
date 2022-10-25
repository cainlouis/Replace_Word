#include "text.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define BUFFER_SIZE 1000

/**
 * Returns total occurrences of a word in given file.
 */
int findOccurrences(FILE *rfile, char *word)
{
    char str[BUFFER_SIZE];
    
    int wordlength, occu, count, strlength, i, j, temp;
    wordlength = strlen(word);
    occu = 0;
    // Read line from file till end of file.
    while ((fgets(str, BUFFER_SIZE, rfile)) != NULL)
    {
        //Get the length of the string for the for loop
        strlength = strlen(str);
        //Go through each char in the string
        for (i = 0; i < strlength; i++) {
            /* We will be incrementing the i to get the through each letter of the word so a temp 
            is made here to keep track of the position */
            temp = i;
            //Go through each character of the word we got as input
            for (j = 0; j < wordlength; j++) {
                //If the character is the same then add to i. Added to lower to make it case insensitive
                if (tolower(str[i]) == tolower(word[j])) {
                    i++;
                }
            }
            //Get the count of letter that were the same
            count = i - temp;
            // If the number of letter that were the same is equal to the length of our word
            if (count == wordlength) {
                // Add 1 to the occurence variable
                occu++;
            }
            // Now give the current position back to our i
            i = temp;
        }
    }
    printf("%d\n", occu);
    return occu;
}

void replaceWord() {
    
}