#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

struct User {
    char name[50];
    int id;
    char email[50];
    char address[100];
    char phone[10];
};

struct User users[100];
int size = 0;

void wellcome();
void home();
void addContact();
void editContact();
void viewContact(int userId);
void findContact(int userId);
void deleteContact(int userId);
void loadContacts();

int main() {
    wellcome();
    isValidEmail();
    home();
    return 0;
}

void wellcome() {
	int choice;
    system("cls");
    printf("\n\n\n\n\n\n\n\n\n\n\t\t\t  ********  WELCOME ******* \n");
    printf("\t\t\t------------------------------\n\n");
    printf("Press 1 to enter HOME page\t\t\t\tPress 2 to EXIT the page\n");
    scanf("%d", &choice);
    
    switch (choice) {
    case 1:
    	home();
    break;
    case 2:
        exit(0);
       break;
    default :
    	printf("invalid option, plz enter right option.....! \n");
    }
    getch();
}

void home() {
    int choice, userId;
    
    system("cls");
    while (1) {
        system("cls");
        printf("\n\t\t\t\t========= HOME =========\n\n");
        printf("1. Add New Contact: \n\n");
        printf("2. Edit Contact: \n\n");
        printf("3. View Contact: \n\n");
        printf("4. Find Contact: \n\n");
        printf("5. Delete Contact: \n\n");
        printf("6. Exit\n");
        printf("========================\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        system("cls");
        
        switch (choice) {
            case 1:
                addContact();
                break;
            case 2:
                editContact();
                break;
            case 3:
                printf("\n\t\t\t\t========= View Contact =========\n\n");
                printf("Enter User ID to View Address: ");
                scanf("%d", &userId);
                viewContact(userId);
                break;
            case 4:
                printf("\n\t\t\t\t========= Find Contact =========\n\n");
                printf("Enter User ID to Find Address: ");
                scanf("%d", &userId);
                findContact(userId);
                break;
            case 5:
                printf("\n\t\t\t\t========= Delete Contact =========\n\n");
                printf("Enter User ID to Delete Contact: ");
                scanf("%d", &userId);
                deleteContact(userId);
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
        getch();
    }
}

int isValidEmail(char email[]) {
	return (strchr(email, '@') != NULL && strchr(email, '.') != NULL);
}

void addContact() {
    FILE *file;
    if (size >= 100) {
        printf("User list is full!\n");
        return;
    }
    
    printf("\n\t\t\t\t========= Add Contact =========\n\n");
    
    printf("Enter Name:\n");
    scanf(" %[^\n]", users[size].name);
    
    printf("Enter your ID: \n");
    scanf("%d", &users[size].id);
    do {
	    
    printf("Enter Email: \n");
    scanf(" %[^\n]", users[size].email);
    
    if(!isValidEmail(users[size].email)) {
	printf("invalid");    
       }
      } while(!isValidEmail(users[size].email));
      
    printf("Enter Address: \n");
    scanf(" %[^\n]", users[size].address);
    
    printf("Enter Phone: \n");
    scanf(" %[^\n]", users[size].phone);
    
    file = fopen("contacts.txt", "a");
    
    if (file == NULL) {
        printf("not opening file!! \n");
        return;
    }
 
    fprintf(file, "%d,%s,%s,%s\n", users[size].id, users[size].name, users[size].email, users[size].address);
    
    fclose(file);
    
    size++;
  
    printf("\nUser Added successfully\n");
    getch();
}
	

void deleteContact(int userId) { 
    int i, j, found = 0;
    
    for (i = 0; i < size; i++) {
 	       if (users[i].id == userId) {
            found = 1;
            for (j = i; j < size - 1; j++) {
                users[j] = users[j + 1];
            }
            size--;
            printf("User deleted successfully!\n");
            return;
        }
    }

    if (!found) {
        printf("User with ID %d not found.\n", userId);
    }
}

void viewContact(int userId) {
    int i, found = 0;
        
    for (i = 0; i < size; i++) {
        if (users[i].id == userId) {
            found = 1;
            printf("----------------------------------------\n");
printf("|             View Address             |\n");
printf("----------------------------------------\n");
printf("| %-15s: %-19s\n", "Name", users[i].name);
printf("| %-15s: %-19d\n", "User ID", users[i].id);
printf("| %-15s: %-19s\n", "Email", users[i].email);
printf("| %-15s: %-19s\n", "Address", users[i].address);
printf("| %-15s: %-19s\n", "Phone", users[i].phone);
printf("----------------------------------------\n");
printf("\n");
break;
        }
    }
    if (!found) {
        printf("User with ID %d not found.\n", userId);
    }
}

void findContact(int userId) {
    viewContact(userId);
}

void editContact() {
    int userId, choice, i, found = 0;
    printf("\n\t\t\t\t========= Edit Contact =========\n\n");

    printf("Enter User ID to Edit: ");
    scanf("\n%d", &userId);

    for (i = 0; i < size; i++) {
        if (users[i].id == userId) {
            found = 1;
    printf("\nSelect what information you want to change: \n\n");
    printf("Press 1 to Edit Name\n");
    printf("2 to Edit Email\n");
    printf("3 to Edit Address\n");
    printf("4 to Edit Phone\n");
    scanf("%d", &choice);
    switch(choice) {
    	case 1:         
    	    printf("Enter New Name: ");
            scanf(" %[^\n]", users[i].name);   
    	break;
    	case 2:
            printf("Enter New Email: ");
            scanf(" %[^\n]", users[i].email);
    	break;
    	case 3:
    	    printf("Enter New Address: ");
    	    scanf(" %[^\n]", users[i].address);
    	break;
    	case 4:
    	    printf("Enter New Phone: ");
    	    scanf(" %[^\n]", users[i].phone);
    	break;
    	default:
    	  printf("this is not  option, please enter right option!\n");
      }
        }
    }

    if (!found) {
        printf("User with ID %d not found.\n", userId);
    }
}

void loadContacts() {
      FILE *file = fopen("contact.txt", "r");
      
	if(file == NULL){
	printf("No exiting contact found!!\n");
	return;
       }

     while(fscanf(file, "%d,%49[^,],%49[^,],%14[^\n]\n", 
     			&users[size].id, users[size].name, users[size].email, users[size].address, users[size].phone) != EOF) {
     size++;
     }
     
     fclose(file);
     printf("Contact loaded successfully!!\n");
}



