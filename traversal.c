#include "traversal.h" 
#include "text.h"
#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <stdlib.h>

#define ARRAY_SIZE 10

//Go through the current directory and find the occurence of the word in each file
int traversal(char *word, char *dirname, struct Traversal *items) {
    struct dirent *de;
    DIR *dir = opendir(dirname);

    //Check if directory has be opened
    if (dir == NULL) {
        printf("Could not open current directory .Make sure you have read/write privileges\n");
        exit(EXIT_SUCCESS);
    }
    static int index = 0;
    //Go through the directory
    while ((de = readdir(dir)) != NULL) {
        char *name = de->d_name;
        size_t len = strlen(name);
        //Create the full path of the file
        char path[100] = { 0 };
            strcat(path, dirname);
            strcat(path, "/");
            strcat(path, name);
        //if the file is a txt file    
        if (len > 4 && strcmp(name + len - 4, ".txt") == 0){
            char *fname = {0};
            int count;
            count = 0;
            fname = strcpy(fname, path);
            //Find the number of occurence in the file using text.c function
            count = findOccurrences(path, word);
            struct Traversal t = {.changes = count, .filename = *fname};
            items[index] = t;
            index++;
        }
        //If it's a directory and not the current one or the parent of the current one
        if (de->d_type == DT_DIR && strcmp(name, ".") != 0 && strcmp(name, "..") != 0) {
            //Use recurrence to find a file
            traversal(word, path, items);
        }
    }
    //Free memory by closing directory
    closedir(dir);    
    return index;
}

struct Traversal *getRapport(char *word, char *dirname) {
    struct Traversal *items = malloc(sizeof(struct Traversal) * ARRAY_SIZE);
    int index = traversal(word, dirname, items);
    for (int i = 0; i < index; i++) {
        printf(&items[i].filename);
    }
    return items;
}