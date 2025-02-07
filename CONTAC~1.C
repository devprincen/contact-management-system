#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

struct User {
    int id;
    char name[50];
    char email[50];
    char phone[15];
};

struct User users[100];
int size = 0;

void wellcome();
void home();
void viewUser(struct User user);
void addUser();
void editUser(struct User *user);
void deleteUser(int userId);
void addAddress() { 
	printf("Adding new address...\n"); }
void viewAddresses() { 
	printf("Viewing all addresses...\n"); }
void searchAddress() { 
	printf("Searching an address...\n"); }
void editAddress() { 
	printf("Editing an address...\n"); }
void deleteAddress() { 
	printf("Deleting an address...\n"); }
void saveToFile() { 
	printf("Saving addresses to file...\n"); }
void loadFromFile() { 
	printf("Loading addresses from file...\n"); }

int main() {
    wellcome();
    home();
    return 0;
}

void wellcome() {
    clrscr();
    printf("\n\n\n\n\n\n\n\n\n\n\t\t\t  ********  WELCOME ******* \n");
    printf("\t\t\t------------------------------\n\n");
    printf("\n\t\t   Press Enter to continue to the HOME page...\n");
    getch();
}

void home() {
    struct User user;
    int choice;
    clrscr();
    while (1) {
        printf("\n=================    HOME    ===================\n");
        printf(" Choose an option as per your choice\n");
        printf("====================================\n");
        printf("1. Add New Address\n");
        printf("2. View All Addresses\n");
        printf("3. Search Address\n");
        printf("4. Edit Address\n");
        printf("5. Delete Address\n");
        printf("6. Save Addresses to File\n");
        printf("7. Load Addresses from File\n");
        printf("8. Exit\n");
        printf("====================================\n");
        printf("Enter your choice: ");
        
        scanf("%d", &choice);
        
        if (choice == 8) {
            printf("Exiting...\n");
            break; 
        }
        
        switch (choice) {
            case 1:
            	clrscr();
                addAddress();
                break;
            case 2:
             	clrscr();           
                viewAddresses();
                break;
            case 3:
               	clrscr();         
                searchAddress();
                break;
            case 4:
              	clrscr();          
                editAddress();
                break;
            case 5:
                clrscr();       
                deleteAddress();
                break;
            case 6:
                clrscr();
                saveToFile();
                break;
            case 7:
                clrscr();
                loadFromFile();
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
            getch();
    }
}

void addUser() {   

     struct User newUser;
    if (size >= 100) {
        printf("User limit reached!\n");
        return;
    }


    newUser.id = size + 1;

    printf("Enter name: ");
    scanf("%s", newUser.name);
    printf("Enter email: ");
    scanf("%s", newUser.email);
    printf("Enter phone number: ");
    scanf("%s", newUser.phone);

    users[size] = newUser;
    size++;

    printf("User added successfully!\n");
    getch();
}

void viewUser(struct User user) {
    int choice;
    clrscr();
    printf("\nUser Details\n");
    printf("Id: %d\n", user.id);
    printf("Name: %s\n", user.name);
    printf("Email: %s\n", user.email);
    printf("Phone: %s\n", user.phone);

    printf("\n1. Edit\n");
    printf("2. Delete\n");
    printf("3. Go to Home\n");

    printf("Choose an option: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            editUser(&users[user.id - 1]);
            break;
        case 2:
            deleteUser(user.id);
            home();
            break;
        case 3:
            home();
            break;
        default:
            printf("Invalid option selected.\n");
            getch(); 
            viewUser(user);
    }
}

void editUser(struct User *user) {
    clrscr();
    printf("Enter new name: ");
    scanf("%s", user->name);
    printf("Enter new email: ");
    scanf("%s", user->email);
    printf("Enter new phone number: ");
    scanf("%s", user->phone);
    printf("User updated successfully!\n");
    getch(); 
}

void deleteUser(int userId) {
    int i;
    
    if (userId < 1 || userId > size) {
        printf("Invalid UserId!\n");
        return;
    }

    for (i = userId - 1; i < size - 1; i++) {
        users[i] = users[i + 1];
        users[i].id = i + 1;
    }
    size--;

    printf("User deleted successfully!\n");
    getch();
}
