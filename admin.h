#include<stdio.h>

// Add book info

void add(){

    char book[100];
    char author[100];
    char id[20];
    int num;

    // Entering book name
    printf("Enter the name of the book you want to add: ");
    scanf("%[^\n]s", book);

    // Entering author name
    printf("Enter the name of the author of the book: ");
    scanf("%[^\n]s", author);

    // Entering book id
    printf("Enter the ID of the book: ");
    scanf("%[^\n]s", id);

    // Entering book quantity
    printf("Enter the number of books you are adding: ");
    scanf("%[^\n]s", num);
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
    scanf("%[^\n]s", book);

    
    // Entering updated author name
    printf("Enter the name of the author of the book: ");
    scanf("%[^\n]s", author);

    // Entering updated book quantity
    printf("Enter the number of books you are adding: ");
    scanf("%[^\n]s", num);
}

// See request