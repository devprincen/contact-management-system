#include <stdio.h>
#include <conio.h>
#include <stdlib.h>


void wellcomePage();
void menuPage();

struct Person {
	char name[50];
	int choice;
};

struct Detail {
	char name[50];
	int phone;
	char email;
	int choice;
	char address;
};

int main() {

    wellcomePage();
    menuPage();

    return 0;
}

void wellcomePage() {
	clrscr();
    printf("\n\n\n\n\n\n\n\n\n\n\t\t\t  ********  Wellcome ******* \n");
    printf("\t\t\t------------------------------\n\n");
    printf("\n\t\t   Press Enter to continue to the MENU page...\n");
    getch();
}

void menuPage(struct Person. person) {
    clrscr();

    printf("\n\n\t\t\t\t----- MENU ----- \n");
    printf("\t-----------------------------------------------------------------\n\n");
    printf("1. Prince Goswami\n");
	printf("-----------------------------------------------------------------\n\n");
    printf("2. Mohit Goswami\n");
	printf("-----------------------------------------------------------------\n\n");
    printf("3. Anop Goswami\n");
	printf("-----------------------------------------------------------------\n\n");
    printf("4. Uttam Goswami\n");
	printf("-----------------------------------------------------------------\n\n");
    printf("5. Puran Goswami\n");
	printf("-----------------------------------------------------------------\n\n");
    scanf("%d", &choice);

    switch (choice) {
       case 1:
	   printf("");



    }
    getch();



}


