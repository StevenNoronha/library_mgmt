// LIBRARY MANAGEMENT SYSTEM

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct book {
  char name[10];
  char author[10];
  char pub[10];
  char price[10];
  int num;
  struct book *link1;
};
typedef struct book *BOOK1;
BOOK1 firstb = NULL;
BOOK1 lastb = NULL;

struct student {
  char sname[10];
  char usn[10];
  int sem;
  char branch[10];
  struct student *links;
  struct book *newl;
  struct book *fas;
};
typedef struct student *STU;
STU firsts = NULL;
STU lasts = NULL;

void issue() {
  STU cur1;
  int n1, count1 = 1;
  char str1[10];
  printf("Enter student name whom the book is to be issued\n");
  scanf("%s", str1);
  if (firsts == NULL) {
    printf("Student List is empty\n");
    return;
  }
  cur1 = firsts;
  while (cur1 != NULL) {
    n1 = strcmp((str1), (cur1->sname));
    if (n1 == 0)
      break;
    cur1 = cur1->links;
    count1++;
  }
  if (cur1 == NULL) {
    printf("Search unsuccessful, did not find student name\n");
    return;
  }
  printf("Search successful, student details found at position : %d\n\n\n",
         count1);

  BOOK1 cur, tpq;
  int n, count = 1;
  char str[10];
  printf("Enter the book to be issued\n");
  scanf("%s", str);
  if (firstb == NULL) {
    printf("List is empty\n");
    return;
  }
  cur = firstb;
  while (cur != NULL) {
    n = strcmp((str), (cur->name));
    if (n == 0)
      break;
    cur = cur->link1;
    count++;
  }
  if (cur == NULL) {
    printf("Search unsuccesful\n");
    return;
  }
  printf("Search successful, book found at position : %d\n", count);
  if (cur->num != 0) {

    cur->num--;
    tpq = (BOOK1)malloc(sizeof(struct book));
    strcpy(tpq->name, cur->name);
    strcpy(tpq->author, cur->author);
    strcpy(tpq->pub, cur->pub);
    strcpy(tpq->price, cur->price);
    tpq->link1 = NULL;
    if (cur1->fas == NULL) {
      cur1->fas = tpq;
      printf("Book issued successfully\n");
      return;
    }
    cur1->newl = cur1->fas;
    while (cur1->newl->link1 != NULL) {
      cur1->newl = cur1->newl->link1;
    }
    cur1->newl->link1 = tpq;
    printf("Book issued successfully\n");
  } else {
    printf("No more books available to be issued, come back later!");
    return;
  }
}
void displayl() {
  STU cur1;
  int n1, count1 = 1;
  char str1[10];
  printf("Enter student name \n");
  scanf("%s", str1);
  if (firsts == NULL) {
    printf("List is empty\n");
    return;
  }
  cur1 = firsts;
  while (cur1 != NULL) {
    n1 = strcmp((str1), (cur1->sname));
    if (n1 == 0)
      break;
    cur1 = cur1->links;
    count1++;
  }
  if (cur1 == NULL) {
    printf("Search unsuccessful\n");
    return;
  }
  BOOK1 temp2;
  temp2 = cur1->fas;
  if (temp2 == NULL) {
    printf("No books issued\n");
    return;
  }
  printf("The books issued to %s are :\n", str1);
  printf("Name\tAuthor\tPublication\tPrice\t\n");
  cur1->newl = cur1->fas;
  do {
    printf("----------------------------------------------\n");
    printf("\n%s\t%s\t%s\t%s\t\n", cur1->newl->name, cur1->newl->author,
           cur1->newl->pub, cur1->newl->price);
    printf("----------------------------------------------\n");
    cur1->newl = cur1->newl->link1;
  } while (cur1->newl != NULL);
}

void display() {
  BOOK1 temp1;
  temp1 = firstb;
  if (temp1 == NULL) {
    printf("List is empty\n");
    return;
  }
  printf("The books are :\n");
  printf("Name\t\tAuthor\t\tPublication\t\tPrice\t\tNo of books\n");
  while (temp1 != NULL) {
    printf("-------------------------------------------------------------------"
           "-------\n");
    printf("%s %16s %16s %16s %16d\n", temp1->name, temp1->author, temp1->pub,
           temp1->price, temp1->num);
    temp1 = temp1->link1;
  }
}

void displays() {
  STU temp1;
  temp1 = firsts;
  if (temp1 == NULL) {
    printf("List is empty\n");
    return;
  }
  printf("The students are :\n");
  printf("Name\tUSN\tBranch\tSem\t\n");
  while (temp1 != NULL) {
    printf("----------------------------------------------\n");
    printf("\n%s\t%s\t%s\t%d\t\n", temp1->sname, temp1->usn, temp1->branch,
           temp1->sem);
    printf("----------------------------------------------\n");
    temp1 = temp1->links;
  }
}

void createb() {
  BOOK1 temp;
  temp = (BOOK1)malloc(sizeof(struct book));
  printf("Enter the book name :");
  scanf("%s", temp->name);
  printf("Enter the author name :");
  scanf("%s", temp->author);
  printf("Enter publication name :");
  scanf("%s", temp->pub);
  printf("Enter the number of books to be stored :");
  scanf("%d", &temp->num);
  printf("Enter the price :");
  scanf("%s", temp->price);
  temp->link1 = NULL;
  if (firstb == NULL) {
    firstb = temp;
    lastb = firstb;
    return;
  } else {
    lastb->link1 = temp;
    lastb = temp;
  }
}

void creates() {
  STU tempa;
  tempa = (STU)malloc(sizeof(struct student));
  printf("Enter the student name :");
  scanf("%s", tempa->sname);
  printf("Enter USN :");
  scanf("%s", tempa->usn);
  printf("Enter branch name:");
  scanf("%s", tempa->branch);
  printf("Enter the sem :");
  scanf("%d", &tempa->sem);
  tempa->links = NULL;
  tempa->newl = NULL;
  if (firsts == NULL) {
    firsts = tempa;
    lasts = firsts;
    return;
  } else {
    lasts->links = tempa;
    lasts = tempa;
  }
}

void search() {
  BOOK1 cur;
  int n, count = 1;
  char str[10];
  printf("Enter the book to be searched\n");
  scanf("%s", str);
  if (firstb == NULL) {
    printf("List is empty\n");
    return;
  }
  cur = firstb;
  while (cur != NULL) {
    n = strcmp((str), (cur->name));
    if (n == 0)
      break;
    cur = cur->link1;
    count++;
  }
  if (cur == NULL) {
    printf("Search unsuccesful\n");
    return;
  }
  printf("Search successful, book found at position : %d\n", count);
  printf("\nName : %s\nAuthor : %s\nPublication : %s\nPrice : %s\n", cur->name,
         cur->author, cur->pub, cur->price);
}

void deleteb() {
  BOOK1 cur, prev;
  int n, count = 1;
  char str[10];
  printf("Enter the book to be deleted\n");
  scanf("%s", str);
  if (firstb == NULL) {
    printf("List is empty\n");
    return;
  }
  n = strcmp((str), (firstb->name));
  if (n == 0) {
    cur = firstb;
    firstb = firstb->link1;
    printf("The book that is deleted is : %s", str);
    free(cur);
    return;
  }
  prev = NULL;
  cur = firstb;
  while (cur != NULL) {
    n = strcmp((str), (cur->name));
    if (n == 0)
      break;
    prev = cur;
    cur = cur->link1;
    count++;
  }
  if (cur == NULL) {
    printf("Book not found\n");
    return;
  }
  printf("The book that is deleted is : %s", str);
  prev->link1 = cur->link1;
  free(cur);
}

int main() {
  int ch, i, n;
  while (1) {
    printf("\n\n~~~MENU~~~\n\n");
    printf("\n1.Add books");
    printf("\n2.Add student");
    printf("\n3.Display books");
    printf("\n4.Display student names");
    printf("\n5.Search for a book");
    printf("\n6.Delete a record for a book");
    printf("\n7.Issue a book to a student");
    printf("\n8.Display name of books issued to a particular student");
    printf("\n9.Exit");
    printf("\nEnter your choice :");
    scanf("%d", &ch);
    switch (ch) {
    case 1:
      printf("Enter number of books to be added :\n");
      scanf("%d", &n);
      for (i = 1; i <= n; i++) {
        printf("Enter details for book %d:\n", i);
        createb();
      }
      break;
    case 2:
      printf("Enter number of students to be added :\n");
      scanf("%d", &n);
      for (i = 1; i <= n; i++) {
        printf("Enter details for student %d:\n", i);
        creates();
      }
      break;
    case 3:
      display();
      break;
    case 4:
      displays();
      break;
    case 5:
      search();
      break;
    case 6:
      deleteb();
      break;
    case 7:
      issue();
      break;
    case 8:
      displayl();
      break;
    case 9:
      exit(1);
      free(firstb);
      free(firsts);
    default:
      printf("Enter valid choice\n");
    }
  }
}
