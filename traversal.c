#include "traversal.h" 
#include <stdio.h>
#include <dirent.h>
#include <string.h>

int traversal(char *word, char *dirname) {
    struct dirent *de;
    DIR *dir = opendir(dirname);

    if (dir == NULL) {
        printf("Could not open current directory");
        return 0;
    }
    
    while ((de = readdir(dir)) != NULL) {
        size_t len = strlen(de->d_name);
        if (len > 4 && strcmp(de->d_name + len - 4, ".txt") == 0){
            printf("%s/%s\n", dirname, de->d_name);
        }
        if (de->d_type == DT_DIR && strcmp(de->d_name, ".") != 0 && strcmp(de->d_name, "..") != 0) {
            char path[100] = { 0 };
            strcat(path, dirname);
            strcat(path, "/");
            strcat(path, de->d_name);
            traversal(word, path);
        }
    }

    closedir(dir);    
    return 0;
}