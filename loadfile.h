
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define lib_len 70
#define db_len 10

typedef struct proto_book
{
    char name[50];
    char a_name[50];
    char publisher[20];
    char id[10];
    int cop_av;
}book;

//defining user
typedef struct proto_user
{
    char role[2]; //a for admin, u for user
    char id[50];
    char pass[50];
    int b_num;
}user;

//function to load books
void load_lib(char *file, book lib[])
{
    FILE *flptr1 = fopen(file, "r");
    if (!flptr1) //loop to catch if file is not loaded properly - pointer will point to null.
    {
        printf("Sorry, there was some error in loading the library database.");
        fclose(flptr1);
    }
    
    //loading book database
    for(int i = 0; i < 64; i++)
    {
        char *buf = malloc(sizeof(char) * 100); //memory allocated to string in each loop
        fgets(buf, 200, flptr1);
        //printf("%s", buf);
        char *check = strtok(buf, ","); //setting check to start dividing lines into words using ',' delimiter
        strcpy(lib[i].name, check);
        check = strtok(NULL,",");   //moving check to next word after delimiter
        strcpy(lib[i].a_name, check);
        check = strtok(NULL,",");
        strcpy(lib[i].publisher, check);
        check = strtok(NULL,",");  
        strcpy(lib[i].id, check);
        check = strtok(NULL,"\n"); 
        int n = atoi(check);
        lib[i].cop_av = n;
        free(buf);  //memory taken is freed after every iteration - no memory leak
    }
    fclose(flptr1);
}

//function to load users/admins
void load_user(char *file, user db[])
{
    FILE *flptr2 = fopen(file, "r");
    if (!flptr2) //loop to catch if file is not loaded properly - pointer will point to null.
    {
        printf("Sorry, there was some error in loading the user database.");
        fclose(flptr2);
    }
    
    //loading user database
    for(int i = 0; i < db_len; i++)
    {
        char *bufu = malloc(sizeof(char) * 50); //memory allocated to string in each loop
        fgets(bufu, 100, flptr2);
        //printf("%s", buf);
        char *check = strtok(bufu, ","); //setting check to start dividing lines into words using ',' delimiter
        strcpy(db[i].role, check);
        check = strtok(NULL,",");   //moving check to next word after delimiter
        strcpy(db[i].id, check);
        check = strtok(NULL,"\n"); 
        strcpy(db[i].pass, check);
        db[i].b_num = 0;    //initialising number of books issued to zero - prevent more than 5 books by one person
        free(bufu);  //memory taken is freed after every iteration - no memory leak
    }
    fclose(flptr2);
}

//Admin - add book info
void add(book l[]){
    book adding;
    FILE *fptr;
    fptr = fopen("records.csv", "a+");

    // Entering book name
    printf("Enter the name of the book you want to add: ");
    getchar();  //flushing character so gets works
    gets(adding.name);  //getting input
    printf("%s\n", adding.name);

    // Entering author name
    printf("Enter the name of the author of the book: ");
    gets(adding.a_name); // getting input
    printf("%s\n", adding.a_name);

    // Entering book id
    printf("Enter the ID of the book: ");
    scanf("%s", adding.id);
    printf("%s\n", adding.id);

    // Entering book quantity
    printf("Enter the number of books you are adding: ");
    scanf("%d", &adding.cop_av);
    printf("%d\n", adding.cop_av);

    // Checking where non-null data the array ends
    int i, j=0; // j will inally denote the number of books in catalogue
    for (i=0; i<lib_len; i++){
        if (strcmp(l[i].id, "\0")!=0){
            j++;
        }
        }
    //j is updated
    strcpy(l[j].a_name,adding.a_name);
    strcpy(l[j].name,adding.name);
    l[j].cop_av = adding.cop_av;
    strcpy(l[j].id, adding.id);

    fprintf(fptr, "New book %s added", adding.name);
    fclose(fptr);
    }

//Admin - Delete book info
void del(book l[]){
    char book_id[20];
    FILE *fptr;
    fptr = fopen("records.csv", "a+");
    //Enter book id
    printf("Enter the ID of the book you want to remove: ");
    scanf("%s", book_id);

    for (int i=0; i<lib_len; i++){
        if (strcmp(l[i].id,book_id)==0){
            fprintf(fptr, "Book %s deleted", l[i].name);
            strcpy(l[i].name, "\0");
            strcpy(l[i].a_name, "\0");
            strcpy(l[i].id, "\0");
            l[i].cop_av = 0;
        }
    }
    
    fclose(fptr);
}

//Admin - Update book info
void update(book l[]){

    book updating;
    FILE *fptr;
    fptr = fopen("records.csv", "a+");

    // Entering book id
    printf("Enter the ID of the book: ");
    scanf("%s", updating.id);


    // Entering updated book name
    printf("Enter the updated name of the book: ");
    scanf("%s", updating.name);

    
    // Entering updated author name
    printf("Enter the updated name of the author of the book: ");
    scanf("%s", updating.a_name);

    // Entering updated book quantity
    printf("Enter the updated number of copies: ");
    scanf("%d", &updating.cop_av);

     // j will finally denote the number of books in catalogue
    for (int i = 0; i < lib_len; i++){
        if (strcmp(l[i].id, updating.id) == 0){
            strcpy(l[i].name, updating.name);
            strcpy(l[i].a_name, updating.a_name);
            l[i].cop_av = updating.cop_av;
        }
    }
    fprintf(fptr, "Book %s updated to %s", updating.id, updating.name);
    fclose(fptr);
}
// See request

//Combined - Query/Search
void query(book lib[])
{
    char s_book[20];
    printf("Enter your query for searching: ");
    getchar();
    gets(s_book);
    //printf("%s\n", s_book);
    printf("Search results:\n");

    for (int i = 0; i < lib_len; i++)
    {
        //only checking against book title and author name
        if (strstr(lib[i].name, s_book) || strstr(lib[i].a_name, s_book))
        {
            printf("%-10s %-40s %-25s %-25s %-3i\n", lib[i].id, lib[i].name, lib[i].a_name, lib[i].publisher,lib[i].cop_av);
        }
    }
}

//Display catalogue
void display(book library[])
{   
    char id[]="Book ID", name[]="Name_of book", a_name[]="Name of author", pub[] = "Publishing house", cop_av[]="Available copies";
    printf("%-10s %-40s %-25s %-20s %-3s\n", id, name, a_name, pub, cop_av);
    for (int i = 0; i < 20; i++)
    {
        if (strcmp(library[i].id, "\0") != 0)
        {
            printf("%-10s %-40s %-25s %-25s %-3i\n", library[i].id, library[i].name, library[i].a_name, library[i].publisher,library[i].cop_av);
        }
    }
    printf("\n");
}

//defining all the necessary user functions
int user_f(book lib[], char role_check[])
{
    char action;
    printf("You are a user or have logged in as a user! Your options are - Issue(I) or Submit(S) or Query(Q) \nEnter your choice: ");
    getchar();
    action = getchar();
    FILE *fptr;
    fptr = fopen("records.csv", "a+");
    int find = 0;   //to check if book was found - 0 for not found

    if (action == 'I' || action == 'i')
    {
        display(lib);
        char i_book[50];
        printf("Enter the name of the book you wish to issue: ");
        getchar();
        gets(i_book);
        //printf("%s", i_book);

        for (int i = 0; i < lib_len; i++)
        {
            if (strcmp(lib[i].name, i_book) == 0)
            {
                if(lib[i].cop_av == 0)
                {
                    printf("Sorry! That book has zero copies available!\n");
                    find = 1;
                    break;
                }
                else if (lib[i].cop_av < 3 && strcmp(role_check, "u") == 0)
                {
                    printf("Sorry! This book has less than three copies, so only admins can issue it!\n");
                    find = 1;
                    break;
                }
                find = 1;                
                lib[i].cop_av--;
                printf("Updated! Remember to return the book in %i days!\n", lib[i].cop_av + 20);
                //display(lib);
                fprintf(fptr, "%s was issued ", lib[i].name);
            }
            
        }
    }

    else if (action == 'S' || action == 's')
    {
        char s_book[50];
        printf("Enter the name of the book you wish to submit: ");
        getchar();
        gets(s_book);

        for (int i = 0; i < lib_len; i++)
        {
            if (strcmp(lib[i].name, s_book) == 0)
            {
                find = 1;
                lib[i].cop_av++;
                printf("Updated!\n");
                //display(lib);
                fprintf(fptr, "%s was submitted ", lib[i].name);
            }   
        }    
    }

    else if (action == 'q' || action == 'Q')
    {
        query(lib);
        find = 1;
    }

    else
    {
        printf("That is not a valid function\n");
    }
    
    fclose(fptr);
    return find;
}

//defining all the necessary admin functions
void admin_f(book lib[])
{   
    // FILE *fptr;
    // fptr = fopen("records.csv","a");    
    char action;
    printf("You are an admin! Your options are - Add(A) or Delete(D) or Update(U)\nEnter your choice: ");
    getchar();
    action = getchar();
    if (action == 'A' || action == 'a')
    {
        add(lib);
        printf("Updated!\n");
        //display(lib);
    }

    if (action == 'D' || action == 'd')
    {
        del(lib);
        printf("Updated!\n");
        //display(lib); 
    }

    if (action == 'U' || action == 'u')
    {
        update(lib);
        printf("Updated!\n");
        //display(lib); 
    }

}
    

