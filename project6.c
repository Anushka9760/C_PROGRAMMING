#include <stdio.h>
#include <string.h>
struct book 
{
   char title[50];
   char author[50];
   int ISBN; 
};
struct book books[100];
int count=0;
void add()
{ if(count<100){
    printf("Enter title:");
    scanf("%s",books[count].title);
    printf("Enter author:");
    scanf("%s",books[count].author);
    printf("Enter ISBN:");
    scanf("%d",&books[count].ISBN);
    count++;
    printf("book added sucessfully");
}

}
void search()
{
     int searchISBN;
    printf("Enter Book ISBN to search: ");
    scanf("%d", &searchISBN);
    for (int i = 0; i < count; i++) {
        if (books[i].ISBN == searchISBN) {
            printf("Book Found: %s by %s\n", books[i].title, books[i].author);
            return;
        }
    }
    printf("Book not found.\n");
}


int main()
{
    struct book books;
    int 
}

