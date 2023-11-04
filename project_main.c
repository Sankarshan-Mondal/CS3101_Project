/*
General outline:
Chosen System: Library
admin (update, add, delete) and user (reissue, submit, issue) functionality

create datatype for book
db for books, user/admin ids + passwords 
file handling lmao
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include"admin.h"

int main()
{
    //defining new datatype for books
    // typedef struct proto_book
    // {
    //     char *name;
    //     char *a_name;
    //     char *id;
    //     int cop_av;
    // }book;

    book lib[20]; //create array for storing books (more space for addition)
    FILE *flptr = fopen("books.csv", "r");
    if (!flptr) //loop to catch if file is not loaded properly - pointer will point to null.
    {
        printf("Sorry, there was some error in loading the library database.");
    }
    
    char *buf = malloc(sizeof(char) * 100);
    while(fgets(buf, 100, flptr) != NULL)
    {
        int i = 0;
        char *check = strtok(buf, ","); //setting check to start dividing lines into words using ',' delimiter
        lib[i].name = check;
        check = strtok(NULL,",");   //moving check to next word after delimiter
        lib[i].a_name = check;
        check = strtok(NULL,","); 
        lib[i].id = check;
        check = strtok(NULL,","); 
        int n = atoi(check);
        lib[i].cop_av = n;

        //printf("%s, %s, %s, %i\n", lib[i].name, lib[i].a_name, lib[i].id, lib[i].cop_av);
        i++;
    }

    add(lib);
    update();

    //defining user
    typedef struct proto_user
    {
        char role; //a for admin, u for user
        char *id;
        char *pass;
    }user;

    free(buf);  //memory taken should be freed    
}