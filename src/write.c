#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include "../headers/write.h"

int main(int argc, char *argvs){

    char subjects[900] = "";
    char subject[100] = "subject";
    char path[200] = "/home/simon/Documents/Code/C/Lessons/data/";
    char slash[200] = "/";
    

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
    subject[sizeof(subject)-1] = 0;
    strncat(path, subject, sizeof(path));
    strncat(path, slash, sizeof(path));
    
    edit_file(path);



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

        //perror ("");
        exit(1);
    }


}


void edit_file(char path[]){

    FILE *filePointer ;
    char lesson[50];
    //char filepath[200] = path[];
    char content[20000];


    printf("Enter the title of your new lesson : \n");

    fgets(lesson, 50, stdin);
    lesson[sizeof(lesson)-1] = 0;

    strncat(path, lesson, 200);
    printf("\n");

    printf("Enter the content of :  %s : \n", lesson);    
    fgets(content, sizeof(content), stdin);
    content[sizeof(content)-1] = 0;
    printf("\n");
    
  
    // Open the existing file GfgTest.c using fopen() 
    // in write mode using "w" attribute 
    filePointer = fopen(path, "w") ; 
      
    // Check if this filePointer is null 
    // which maybe if the file does not exist 
    if ( filePointer == NULL ) 
    { 
        printf( "%s at path %s can't be created or opened", lesson, path); 
    } 
    else
    { 
          
        printf("The file is now opened.\n") ; 
          
        // Write the dataToBeWritten into the file 
        if ( strlen (  content  ) > 0 ) 
        { 
              
            // writing in the file using fputs() 
            fputs(content, filePointer) ;    
            fputs("\n", filePointer) ; 
        } 
          
        // Closing the file using fclose() 
        fclose(filePointer) ; 
          
        printf("Data successfully written the lesson %s\n", lesson); 
        printf("The file is now closed.") ; 
    } 
    return;
}

