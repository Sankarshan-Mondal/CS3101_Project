#include<stdio.h>


typedef struct proto_book
{
    char *name;
    char *a_name;
    char *id;
    int cop_av;
}book;


// Add book info
void add(book l[]){

    char book1[100];
    char author[100];
    char id[20];
    int num;

    // Entering book name
    printf("Enter the name of the book you want to add: ");
    scanf("%[^\n]s", book1);
    //printf("%s", book1);
    printf("\n");

    // Entering author name
    printf("Enter the name of the author of the book: ");
    scanf("%s", author);
    printf("\n");

    // Entering book id
    printf("Enter the ID of the book: ");
    scanf("%s", id);
    printf("\n");

    // Entering book quantity
    printf("Enter the number of books you are adding: ");
    scanf("%s", num);
    printf("\n");

    // Checking where non-null data the array ends
    for (int i=0; i<20; i++){
        if (l[i].name == NULL)
        printf("%d\n", i);
    }
}

// Delete book info

void del(){

    char id[20];

    //Enter book id
    printf("Enter the ID of the book you want to remove: ");
    scanf("%[^\n]s", id);
}

// Update book info

void update(){

    char book[100];
    char author[100];
    char id[20];
    int num;

    // Entering book id
    printf("Enter the ID of the book: ");
    scanf("%[^\n]s", id);


    // Entering updated book name
    printf("Enter the name of the book you want to add: ");
    scanf("%s", book);

    
    // Entering updated author name
    printf("Enter the name of the author of the book: ");
    scanf("%s", author);

    // Entering updated book quantity
    printf("Enter the number of books you are adding: ");
    scanf("%s", num);
}

// See request

// Add book info

void issue()
{

    char book[100];

    // Entering book name/author name
    printf("Search for the book here!\nAny keyword related to the book: ");
    scanf("%[^\n]s", book);
}

// Delete book info

void ret()
{

    char id[20];

    // Enter book id
    printf("Enter the ID of the book you want to return: ");
    scanf("%[^\n]s", id);
}

// Update book info