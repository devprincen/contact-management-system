#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

struct Address {
    int id;
    char name[50];
    char email[50];
    char address[100];
    char phone[10];
};

struct Address addre[100];
int size = 0;

void wellcome();
void home();
void addContact();
void editContact();
void viewContact(int addreId);
void findContact(int addreId);
void deleteContact(int addreId);
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
    printf("     1  HOME page\n\n");
    printf("     2  EXIT page\n");
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
    int choice, addreId;
    
    system("cls");
    while (1) {
        system("cls");
        printf("\n\t\t\t\t========= HOME =========\n\n");
        printf("1. Add New Contact: \n\n");
        printf("2. Edit Contact: \n\n");
        printf("3. View Contact: \n\n");
        printf("4. List Contacts: \n\n");
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
                printf("\n\t\t\t========= View Contact =========\n\n");
                printf("Enter Address ID to View Address: ");
                scanf("%d", &addreId);
                viewContact(addreId);
                break;
            case 4:
                printf("\n\t\t\t========= Find Contacts =========\n\n");
                printf("Enter Address ID to View Address: ");
                scanf("%d", &addreId);
                findContact(addreId);
                break;
            case 5:
                printf("\n\t\t\t========= Delete Contact =========\n\n");
                printf("Enter Address ID to Delete Contact: ");
                scanf("%d", &addreId);
                deleteContact(addreId);
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
    char digit;
    if (size >= 100) {
        printf("Address list is full!\n");
        return;
    }
    
    printf("\n\t\t\t   ========= Add Contact =========\n\n");
    
    printf("Enter Name:\n");
    scanf(" %[^\n]", addre[size].name);
    
    printf("Enter your ID: \n");
    scanf("%d", &addre[size].id);
    do {
	    
    printf("Enter Email: \n");
    scanf(" %[^\n]", addre[size].email);
    
    if(!isValidEmail(addre[size].email)) {
	printf("invalid");    
       }
      } while(!isValidEmail(addre[size].email));
      
    printf("Enter Address: \n");
    scanf(" %[^\n]", addre[size].address);


    printf("Enter Phone: \n");
    scanf(" %[^\n]", addre[size].phone);	
 
    file = fopen("contacts.txt", "a");
    
    if (file == NULL) {
        printf("not opening file!! \n");
        return;
    }
 
    fprintf(file, "%d,%s,%s,%s\n", addre[size].id, addre[size].name, addre[size].email, addre[size].address, addre[size].phone);
    
    fclose(file);
    
    size++;
  
    printf("\nAddress Added successfully\n");
    getch();
}

void editContact() {
    int addreId, choice, i, found = 0;
    printf("\n\t\t\t\t========= Edit Contact =========\n\n");

    printf("Enter Address ID to Edit: ");
    scanf("\n%d", &addreId);

    for (i = 0; i < size; i++) {
        if (addre[i].id == addreId) {
            found = 1;
    printf("\nSelect what information you want to change: \n\n");
    printf("Press 1 to Edit Name\n");
    printf("2 to Edit Email\n");
    printf("3 to Edit Address\n");
    printf("4 to Edit Phone\n");
    printf("5 to Change all information\n");
    scanf("%d", &choice);
    switch(choice) {
    	case 1:         
    	    printf("Enter New Name: ");
            scanf(" %[^\n]", addre[i].name);   
    	break;
    	case 2:
        do {
	    
            printf("Enter Email: \n");
            scanf(" %[^\n]", addre[size].email);
    
       if(!isValidEmail(addre[size].email)) {
	    printf("invalid");    
       }
       } while(!isValidEmail(addre[size].email));
       
    	break;
    	case 3:
    	    printf("Enter New Address: ");
    	    scanf(" %[^\n]", addre[i].address);
    	break;
    	case 4:
    	    printf("Enter New Phone: ");
    	    scanf(" %[^\n]", addre[i].phone);

    	break;
    	case 5:
 	    printf("Enter New Name: ");
            scanf(" %[^\n]", addre[i].name); 
        do {
	    
            printf("Enter Email: \n");
            scanf(" %[^\n]", addre[size].email);
    
        if(!isValidEmail(addre[size].email)) {
	    printf("invalid");    
          }
        } while(!isValidEmail(addre[size].email));
        
            printf("Enter New Address: ");
    	    scanf(" %[^\n]", addre[i].address);
    	    printf("Enter New Phone: ");
    	    scanf(" %[^\n]", addre[i].phone);
    	break;
    	
    	     
    	default:
    	  printf("this is not  option, please enter right option!\n");
      }
        }
    }

    if (!found) {
        printf("Address with ID %d not found.\n", addreId);
    }
}

	

void deleteContact(int addreId) { 
    int i, j, found = 0;
    
    for (i = 0; i < size; i++) {
 	       if (addre[i].id == addreId) {
            found = 1;
            for (j = i; j < size - 1; j++) {
                addre[j] = addre[j + 1];
            }
            size--;
            printf("Address deleted successfully!\n");
            return;
        }
    }

    if (!found) {
        printf("Address with ID %d not found.\n", addreId);
    }
}

void viewContact(int addreId) {
    int i, found = 0;
        
    for (i = 0; i < size; i++) {
        if (addre[i].id == addreId) {
            found = 1;
            printf("----------------------------------------\n");
printf("|             View Address             |\n");
printf("----------------------------------------\n");
printf("| %-15s: %-19s\n", "Name", addre[i].name);
printf("| %-15s: %-19d\n", "Address ID", addre[i].id);
printf("| %-15s: %-19s\n", "Email", addre[i].email);
printf("| %-15s: %-19s\n", "Address", addre[i].address);
printf("| %-15s: %-19s\n", "Phone", addre[i].phone);
printf("----------------------------------------\n");
printf("\n");
break;
        }
    }
    if (!found) {
        printf("Address with ID %d not found.\n", addreId);
    }
}

void findContact(int addreId) {
    viewContact(addreId);
}


void loadContacts() {
      FILE *file = fopen("contact.txt", "r");
      
	if(file == NULL){
	printf("No exiting contact found!!\n");
	return;
       }

     while(fscanf(file, "%d,%49[^,],%49[^,],%14[^\n]\n", 
     			&addre[size].id, addre[size].name, addre[size].email, addre[size].address, addre[size].phone) != EOF) {
     size++;
     }
     
     fclose(file);
     printf("Contact loaded successfully!!\n");
}



