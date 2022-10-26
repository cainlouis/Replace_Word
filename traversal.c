#include "traversal.h" 
#include "text.h"
#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <stdlib.h>

/* 
Go through the current directory and find the number of occurences of the word in txt file
*/
int traversal(char *word, char *dirname, struct Traversal *items) {
    struct dirent *de;
    DIR *dir = opendir(dirname);
    static int index = 0;
    //Check if the directory could be opened, if not print message and exit
    if (dir == NULL) {
        printf("Could not open current directory. Make sure you have read/write privileges\n");
        exit(EXIT_SUCCESS);
    }
    
    //Go through the directory 
    while ((de = readdir(dir)) != NULL) {
        char *name = de->d_name;
        size_t len = strlen(name);
        //Create the relative path
        char path[100] = { 0 };
            strcat(path, dirname);
            strcat(path, "/");
            strcat(path, name);
        //if it is as txt file
        if (len > 4 && strcmp(name + len - 4, ".txt") == 0){
            int count;
            count = 0;
            //find the number of occurence of the word in file
            count = findOccurrences(path, word);
            //Create struct to add to the array of struct
            struct Traversal item;
            //Populate it
            item.changes = count;
            strcpy(item.fpath, path);
            //add to the array
            items[index] = item;
            //add to the index so the next file populate the next items index
            index++;
        }
        //if it is a directory and is current or parent directory
        if (de->d_type == DT_DIR && strcmp(name, ".") != 0 && strcmp(name, "..") != 0) {
            //use recursive to go through directory and findd file
            traversal(word, path, items);
        }
    }
    //Close opened directory
    closedir(dir);    
    return 0;
}

/*
Create an array of struct on the memory heap to be populated by traversal
*/
struct Traversal *getArray(char *word, char *dirname)
{
    //Create the array of struct on the memory heap
    struct Traversal *items = malloc(sizeof(struct Traversal) *ARRAY_SIZE);
    //call traversal to go through the directory and get the number of file
    traversal(word, dirname, items);
    return items;
};

