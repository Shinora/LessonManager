#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include "../headers/write.h"

int main(int argc, char *argvs){

    char subjects[900] = "";
    char subject[100] = "";
    char path[200] = "/home/simon/Documents/Code/C/Lessons/data/";
    char command[200] = "dir ";
    

    printf("\n\n");

    printf("------------------------------------------------\n");

    printf("              LESSON WRITER MANAGER             \n");

    printf("------------------------------------------------\n\n\n");

    printf("Welcome to the write part of the program. \n");
    printf("We assume you are here to write a new lesson ?\n");

    printf("Enter the subject from thoses : \n");

    list_files(path);
    printf("\n");


    fgets(subject, 100, stdin);
    strncat(path , subject, sizeof(path));

    edit_file(subject);



    return 0;
    


    

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
        exit(1);
    }




}


void edit_file(char subject[]){

    char title[50] = "";
    char path[200] = "../data/";
    char command[300] = "touch ";
    char slash[1] = "/";


    strncat(path, subject, 200);
    strncat(path, slash, 200);
    strncat(command, path, 250);

    
    

    printf("Enter a title for your lesson : \n");

    fgets(title, 50, stdin);
    strncat(command, title, 300);
    system(command);





    

}


