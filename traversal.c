#include "traversal.h" 
#include "text.h"
#include "report.h"
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
            char *fname;
            int count;
            fname = path;
            count = 0;
            //find the number of occurence of the word in file
            count = findOccurrences(path, word);
            // printf("%d  in %s\n", count, path);
            struct Traversal item;
            item.changes = count;
            strcpy(item.fpath, fname);
            items[index] = item;
            // printf("%s\n", items[index].fpath);
            index++;
        }
        //if it is a directory and is current or parent directory
        if (de->d_type == DT_DIR && strcmp(name, ".") != 0 && strcmp(name, "..") != 0) {
            //use recursive to go through directory and findd file
            traversal(word, path, items);
        }
    }
    //Free memory by directory
    closedir(dir);    
    return index;
}

struct Traversal *getArray(char *word, char *dirname)
{
    int n = 0;
    struct Traversal *items = malloc(sizeof(struct Traversal) *ARRAY_SIZE);
    int index = traversal(word, dirname, items);
    while (n < index) {
        printf("%d in %s\n", items[n].changes, items[n].fpath);
        n++;
    }
    return items;
};

// void getIndex(char *word, char *dirname) {
//     int index = traversal(word, dirname);
//     printf("%d\n", index);
// }
