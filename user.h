#include <stdio.h>

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