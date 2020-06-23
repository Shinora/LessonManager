#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <dirent.h>

int main(int argc, char *argvs){

    char subjects[900];
    char subject[100];
    char path[200] = "home/simon/Documents/Code/C/Lessons/data/";
    char command[200] = "dir ";
    

    printf("\n\n");

    printf("------------------------------------------------\n");

    printf("              LESSON WRITER MANAGER             \n");

    printf("------------------------------------------------\n\n\n");

    printf("Welcome to the write part of the program. \n");
    printf("We assume you are here to write a new lesson ?\n");

    printf("Enter the subject ( current ones : \n");


    
    printf("%s \n ) ->", subjects);

    fgets(subject, 100, stdin);
    strncat(path , subject, sizeof(path));


    system(strcat(command, path));

}


void list_files(char path[]){

    DIR *dir;
    struct dirent *ent;
    if ((dir = opendir (path)) != NULL){

        while ((ent = readdir (dir)) != NULL){
            printf("%s\n", ent->d_name);
        }
        closedir (dir);
    }
    else{

        perror ("");
        return EXIT_FAILURE;
    }




}