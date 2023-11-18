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
#include "loadfile.h"

#define lib_len 64
#define db_len 10

int main()
{
    book lib[lib_len];   //creating array to store books (space for extra)
    user db[db_len]; // create array for users (more space for addition)

    //initialise entire array to null terminator and 0 - shall be useful later
    for (int i = 0; i <= lib_len; i++)
    {
        strcpy(lib[i].name, "\0");
        strcpy(lib[i].a_name, "\0");
        strcpy(lib[i].publisher, "\0");
        strcpy(lib[i].id, "\0");
        lib[i].cop_av = 0;
    }

    load_lib("books.csv", lib); //calling function to load books
    load_user("users.csv", db); //calling function to load users

    char ename[50], epass[50], action[2];  //variables to store entered names
    printf("Welcome to the Library Interactive Interface! Please enter your credentials to proceed:\n");
    printf("Enter username: ");
    scanf("%s", ename);
    printf("Enter password: ");
    scanf("%s", epass);

// Main loop in which the system will run
int agree; // variable for continuation
do
{
    // variable to catch if username is in the db
    int u_find = 0;

    for (int i = 0; i < db_len; i++)
    {
        if (strcmp(db[i].id, ename) == 0)
        {
            u_find++;
            for (int p = 0; p < 3; p++)
            {
                if (strcmp(db[i].pass, epass) == 0)
                {
                    printf("Welcome! \n\n");
                    //display(lib);

                    if (strcmp(db[i].role, "u") == 0)
                    {
                        FILE *fptr;
                        fptr = fopen("records.csv","a");
                        //int f_check = user_f(lib);
                        if (user_f(lib) == 0)
                        {
                            printf("Error! Enter book name correctly\n");
                            break;
                        }
                        //user_f(lib);
                        fprintf(fptr, " by %s\n", ename);
                        fclose(fptr);
                    }
                    else if (strcmp(db[i].role, "a") == 0)
                    {   int d_o = 1;
                        printf("Do you want to login as admin? (yes=1/no=0): ");    //admin has user and admin priviledges so asking which method of access
                        scanf("%d", &d_o);
                        FILE *fptr;
                        fptr = fopen("records.csv", "a");
                        if (d_o==1){
                        admin_f(lib); // call to functions
                        } 
                        else if (d_o==0){
                        user_f(lib); // call to functions
                        }
                        fprintf(fptr, " by %s\n", ename);
                        fclose(fptr);
                    }
                    break;
                }
                else
                {
                    printf("Incorrect Password! Access denied. Try again. %d attempt(s) left\n", 3 - p);
                    printf("Enter password: ");
                    scanf("%s", epass);
                }
            }
        }
    }

    // in case no match found - printing appropriate message
    if (u_find == 0)
    {
        printf("Sorry, we do not have a record of you in our database.\n");
    }

    // Condition to continue
    printf("Do you wish to continue? (yes=1/no=0): ");
    scanf("%d", &agree);
    } while (agree != 0);

    printf("Thank you for visiting the Interactive Library Interface!");
}