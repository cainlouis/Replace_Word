#include "text.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define BUFFER_SIZE 1000

/**
 * Returns total occurrences of a word in given file.
 */
int findOccurrences(char *path, char *word)
{
    FILE *tempf;
    FILE *ftr;
    char str[BUFFER_SIZE], *newstr;
    int wordlength, occu, count, strlength, i, j, temp;
    printf("%s\n", path);

    //Open necessary files
    ftr = fopen(path, "r");
    tempf = fopen("replace.txt", "w");

    //Check if fopen is able to open file
    if (ftr == NULL || tempf == NULL) {
        //If unable to open then exit
        printf("Unable to open file.\n");
        printf("Make sure you have read/write privileges\n");
        exit(EXIT_SUCCESS);
    }

    wordlength = strlen(word);
    occu = 0;
    // Read line from file till end of file.
    while ((fgets(str, BUFFER_SIZE, ftr)) != NULL)
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
                newstr = replaceWord(str, word, temp);
            }
            // Now give the current position back to our i
            i = temp;
        }
        fputs(newstr, tempf);
    }

    fclose(ftr);
    fclose(tempf);

    remove(path);

    rename("replace.txt", path);
    printf("%d\n", occu);
    return occu;
}

char * replaceWord(char *str, char *word, int *pos) {
    char temp[BUFFER_SIZE];
    char *newWord;
    int *wordlength = strlen(word); 
    int index = 0;

    newWord = word;
    for (int i = 0; i < wordlength; i++) {
        newWord[i] = toupper(newWord[i]);
    }
    
    strcpy(temp, str);

    index = pos + wordlength;

    str[index] = '\0';

    strcat(str, newWord);
    printf("%s\n", str);
    strcat(str, temp + index + wordlength); 

    return str;
}