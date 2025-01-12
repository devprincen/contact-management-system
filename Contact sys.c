#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct User {
	int id;
	char name[50];
	char email[50];
	char phone[10];
};

struct Address{
	int id;
	int userId;
	char title[30];
	char address[100];
}

struct User users[];
int i, size = 0;

void wellcome();
void home();

int main() {
	wellcome();
}

void wellcome() {
	clrscr();
	printf("\n\n\n\n\n\n\n\n\n\n\t\t\t  ********  WELLCOME ******* \n");
	printf("\t\t\t------------------------------\n\n");
	printf("\n\t\t   Press Enter to continue to the HOME page...\n");
	getch();
	clrscr();
}


void home(){
	struct User user;
	char choice[4];
	int try;

	clrscr();
	printf("\n\n\t\t\t  ********  HOME ******* \n");

	printf("\nId\tName\tEmail\tPhone No.\n";)
	for(i=0; i<size; i++){
		user = users[i];
		printf("%d\t%s\t%s\t%s\n",user.id, user.name, user.email, user.phone);
	}
	
	printf("\n---------------------------------------\n");
	printf("Enter userId to view and use 'ADD' to add new user: ");
	scanf("%s", &choice);
	
	if(choice == "ADD"){
		addUser();
		return;
	}
	
	user = users[((int) choice) - 1]
	if(user == null){
		printf("Invalid UserId!! press 1 to try again: ");
		scanf("%d", &try);
		
		if(try != 1){
			exit(0);
		}
		home();
	}
	viewUser(user);
}

void viewUser(struct User user){
	Id: %d..
	Name: %s ...
	
	...
	
	\n\n
	1. edit 2. goto address 3. delete 4. goto home
	switch()
	{
	...
	}
}
