#include "traversal.h" 
#include "text.h"
#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <stdlib.h>

int traversal(char *word, char *dirname) {
    struct dirent *de;
    DIR *dir = opendir(dirname);

    if (dir == NULL) {
        printf("Could not open current directory");
        return 0;
    }
    
    while ((de = readdir(dir)) != NULL) {
        size_t len = strlen(de->d_name);
        char path[100] = { 0 };
            strcat(path, dirname);
            strcat(path, "/");
            strcat(path, de->d_name);
        if (len > 4 && strcmp(de->d_name + len - 4, ".txt") == 0){
            FILE *ftr;
            int count;
            count = 0;
            ftr = fopen(path, "r");
            count = findOccurrences(ftr, word);
            // printf("%d  in %s\n", count, path);
        }
        if (de->d_type == DT_DIR && strcmp(de->d_name, ".") != 0 && strcmp(de->d_name, "..") != 0) {
            traversal(word, path);
        }
    }
    closedir(dir);    
    return 0;
}
