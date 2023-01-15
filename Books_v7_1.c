/***************************************************************
 * Chen Zhang
 * Book System
 * May 1 2022   ---   V7_1
 * 
 *  a. fixes a bug, one keyword, only one book can be searched, and print it twice. 
 * 
 * 	
 * 	
 *  * *********************************************************/  


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>   					// getch()

typedef struct books Book;

struct books {
	long long ISBN;
	char Title[50];
	char Author[50];
	char Publisher[50];
	char Genre[50]; 
	int YearOfPublication;
	int AmountOfStock;
	double SellingPrice;
};
Book books[499];
int k=5;

void welcome();
void preload();
int check_ISBN(long long int t);
void populate_inventory();
int search(char message[]);
void process_transaction();
void delete_record();
void display_books();
void menu();
void purchase_return_menu();


int main() {

	welcome();
	preload();

	int choose = 0;
	while (choose != 6) {
		menu();
		scanf("%d", &choose);
		getchar();
		switch (choose) {

		case 1: //{
			populate_inventory();
			break;
		//}
		case 2: {
			char message[50];
			printf("Please enter any of the following information: Title / Author / Genre / Publisher: ");
			fgets(message, 50, stdin);
			message[strlen(message)-1]='\0';
			if (search(message) != -1) 
				printf("search successfully!\n");
			else {
				printf("search fail!\n");
			}
			printf("\nPress any key to return to menu");
			getch();
			break;
		}
		case 3: {
			process_transaction();
			break;
		}
		case 4: {
			delete_record();
			break;
		}
		case 5: {
			display_books();
			break;
		}
		case 6: {
			printf("goodbye\n");
			exit(0);
			break;
		}
		}
	}
	printf("goodbye\n");
	return 0;
}

void preload(){


	books[0].ISBN = 9780131103627; 
    strcpy(books[0].Title, "The C Programming Language"); 
    strcpy(books[0].Author, "Brian & Dannis"); 
    strcpy(books[0].Genre, "Computer"); 
    strcpy(books[0].Publisher, "Prentice Hall"); 
    books[0].YearOfPublication = 1988;
    books[0].AmountOfStock = 10;
    books[0].SellingPrice = 82.91; 

	books[1].ISBN = 9781451663884; 
    strcpy(books[1].Title, "Super Chien"); 
    strcpy(books[1].Author, "Capitaine Bobette"); 
    strcpy(books[1].Genre, "Cartoon"); 
    strcpy(books[1].Publisher, "Scholastic"); 
    books[1].YearOfPublication = 2020;
    books[1].AmountOfStock = 10;
    books[1].SellingPrice = 46.97; 

	books[2].ISBN = 9780684801346; 
    strcpy(books[2].Title, "Raising a happy unspoiled child"); 
    strcpy(books[2].Author, "Burton L.White"); 
    strcpy(books[2].Genre, "Education"); 
    strcpy(books[2].Publisher, "Simon & Schuster"); 
    books[2].YearOfPublication = 1995;
    books[2].AmountOfStock = 10;
    books[2].SellingPrice = 19.99; 

	books[3].ISBN = 9781451648539; 
    strcpy(books[3].Title, "Steve Jobs"); 
    strcpy(books[3].Author, "Walter Isaacson"); 
    strcpy(books[3].Genre, "Biography"); 
    strcpy(books[3].Publisher, "Simon & Schuster"); 
    books[3].YearOfPublication = 2011;
    books[3].AmountOfStock = 5;
    books[3].SellingPrice = 36.99; 

	books[4].ISBN = 9780753719015; 
    strcpy(books[4].Title, "Brain fitness at work"); 
    strcpy(books[4].Author, "Judith Jewell"); 
    strcpy(books[4].Genre, "Intelligence"); 
    strcpy(books[4].Publisher, "Bounty"); 
    books[4].YearOfPublication = 2009;
    books[4].AmountOfStock = 10;
    books[4].SellingPrice = 12.88; 

}

int check_ISBN(long long t) {
	int i;
	for (i = 0; i < k; i++) {
		if (books[i].ISBN == t) {
			return 0;
		}
	}
	return 1;
}
void populate_inventory() {
	char temp[10];
	int x;
	while (1) {
		printf("Please enter ISBN: ");
		do{
			x = scanf("%lld", &books[k].ISBN);     // check int
			if (x == 0){
				printf("Illegal characters were entered, please re-enter:");
				while (getchar() != '\n');
			}
		}while (x==0);
		while (check_ISBN(books[k].ISBN) == 0 ) {
			printf("input error! ISBN exist!");
			printf("Please enter ISBN: ");
			scanf("%lld", &books[k].ISBN);
		}
		getchar();
																								// ↑ ISBN  - long long int
		printf("Please enter Title: ");
		fgets(books[k].Title, 50, stdin);
		books[k].Title[strlen(books[k].Title)-1]='\0';
																								// ↑ Title  - char  
		printf("Please enter Author: ");
		fgets(books[k].Author, 50, stdin);
		books[k].Author[strlen(books[k].Author)-1]='\0';
																								// ↑ Author  - char
		printf("Please enter Publisher: ");
		fgets(books[k].Publisher, 50, stdin);
		books[k].Publisher[strlen(books[k].Publisher)-1]='\0';
																								// ↑ Publisher  - char
		printf("Please enter Genre: ");
		fgets(books[k].Genre, 50, stdin);
		books[k].Genre[strlen(books[k].Genre)-1]='\0';
																								// ↑ Genre  -  char
		printf("Please enter Year of Publication: ");
		do{
			x = scanf("%d", &books[k].YearOfPublication);
			if (x == 0){
				printf("Illegal characters were entered, please re-enter:");
				while (getchar() != '\n');
			}
		}while (x==0);
		// scanf("%d", &books[k].YearOfPublication);
																								// ↑ YearOfPublication   -   int
		printf("Please enter Amount in Stock : ");
		do{
			x = scanf("%d", &books[k].AmountOfStock);
			if (x == 0){
				printf("Illegal characters were entered, please re-enter:");
				while (getchar() != '\n');
			}
		}while (x==0);
		// scanf("%d", &books[k].AmountOfStock);
																								// ↑ AmountOfStock    -  int
		printf("Please enter Selling Price: ");
		do{
			x = scanf("%lf", &books[k].SellingPrice);
			if (x == 0){
				printf("Illegal characters were entered, please re-enter:");
				while (getchar() != '\n');
			}
		}while (x==0);
		// scanf("%lf", &books[k].SellingPrice);
																								// ↑ SellingPrice  - double
		k += 1;
		printf("Do you want to input again?(input y to continue): ");
		scanf("%s", temp);
		if (temp[0] != 'y' && temp[0] != 'Y') {
			break;
		}
	}
}
int search(char message[]) {
	int i, index = -1;
	for (i = 0; i < k; i++) {
		if (strcmp(message, books[i].Title) == 0 ||
			strcmp(message, books[i].Genre) == 0 ||
			strcmp(message, books[i].Author) == 0 ||
			strcmp(message, books[i].Publisher) == 0) {
			printf("%-17s %-38s %-23s %-22s %-15s %-15s %-13s %-20s\n",\
			"ISBN", "Title", "Author", "Publisher", "Genre", "Published in", "In Stock ", "Price");
			printf("%-17lld %-38s %-23s %-22s %-15s %-15d %-13d %-18.2lf\n",\
			books[i].ISBN, books[i].Title, books[i].Author, books[i].Publisher, \
			books[i].Genre, books[i].YearOfPublication, books[i].AmountOfStock, books[i].SellingPrice);
			index = i;
		}
	}
	return index;
}
void process_transaction() {
	int x, y;
	char message[50];
	purchase_return_menu();
	scanf("%d", &x);
	getchar();
	printf("Please enter any of the following information: Title / Author / Genre / Publisher: ");
	fgets(message, 50, stdin);
	message[strlen(message)-1]='\0';
	y = search(message);
	if (y == -1) {
		printf("sorry, books for which no relevant information exists");
		printf("\nPress any key to return to menu");
		getch();
	}
	else {
		if (x == 1) {
			if (books[y].AmountOfStock == 0) {
				printf("Insufficient quantity to purchase\n");
			}
			else {
				printf("purchase successfully\n");
				books[y].AmountOfStock -= 1;
				printf("\nPress any key to return to menu");
				getch();
			}
		}
		else {
			printf("return successfully\n");
			books[y].AmountOfStock += 1;
			printf("\nPress any key to return to menu");
			getch();
		}
	}
}
void delete_record() {
	int i, j;
	long long isbn;
	printf("Please enter ISBN: ");
	scanf("%lld", &isbn);
	for (i = 0; i < k; i++) {
		if (books[i].ISBN == isbn) {
			for (j = i; j < k - 1; j++) {
				books[j] = books[j + 1];
			}
			k -= 1;
			printf("delete successfully\n");
			printf("\nPress any key to return to menu");
			getch();
			return;
		}
	}
	printf("delete fail!\n");
}
void display_books() {
	int i;
	printf("%-17s %-38s %-23s %-22s %-15s %-15s %-13s %-20s\n",\
	"ISBN", "Title", "Author", "Publisher", "Genre", "Published in", "In Stock ", "Price");
	for (i = 0; i < k; i++) {
		printf("%-17lld %-38s %-23s %-22s %-15s %-15d %-13d %-18.2lf\n",\
		books[i].ISBN, books[i].Title, books[i].Author, books[i].Publisher,\
		books[i].Genre, books[i].YearOfPublication, books[i].AmountOfStock, books[i].SellingPrice);
	}
	printf("\nPress any key to return to menu");
	getch();
}
void menu(){

    printf("\n\n");
	printf("\t\t\t *===============================================*\n");
	printf("\t\t\t|                                                |\n");
	printf("\t\t\t|                    Main Manu                   |\n");
	printf("\t\t\t|                                                |\n");
    printf("\t\t\t|                                                |\n");
    printf("\t\t\t|    [1]    Add Books                            |\n");
	printf("\t\t\t|                                                |\n");
	printf("\t\t\t|    [2]    Search Books                         |\n");
	printf("\t\t\t|                                                |\n");
	printf("\t\t\t|    [3]    Purchase and Return                  |\n");
	printf("\t\t\t|                                                |\n");
	printf("\t\t\t|    [4]    Delete Books                         |\n");
	printf("\t\t\t|                                                |\n");
	printf("\t\t\t|    [5]    Display Books                        |\n");
	printf("\t\t\t|                                                |\n");
    printf("\t\t\t|    [6]    Exit                                 |\n");
    printf("\t\t\t|                                                |\n");
    printf("\t\t\t|                                                |\n");
	printf("\t\t\t *===============================================*\n");

}

void welcome()
{
	printf("\n\n");
	printf("\t\t\t *===============================================*\n");
	printf("\t\t\t|                                                |\n");
	printf("\t\t\t|      Welcome to Book management system         |\n");
	printf("\t\t\t|                                                |\n");
    printf("\t\t\t|                                                |\n");
    printf("\t\t\t|                                                |\n");
	printf("\t\t\t|         This is the final project of AP        |\n");
	printf("\t\t\t|                     AND                        |\n");
	printf("\t\t\t|                I declare that                  |\n");
	printf("\t\t\t|           This is an original work             |\n");
	printf("\t\t\t|                                                |\n");
	printf("\t\t\t|                 Chen Zhang                     |\n");
	printf("\t\t\t|                 April 2022                     |\n");
	printf("\t\t\t|                                                |\n");
	printf("\t\t\t|                                                |\n");
	printf("\t\t\t *===============================================*\n");
    printf("\n\n\t\t\t Press any key to continue.....");
	getch();
}

void purchase_return_menu(){

    printf("\n\n");
	printf("\t\t\t *===============================================*\n");
	printf("\t\t\t|                                                |\n");
	printf("\t\t\t|               Purchase and Return              |\n");
	printf("\t\t\t|                                                |\n");
    printf("\t\t\t|                                                |\n");
    printf("\t\t\t|    [1]    Purchase                             |\n");
	printf("\t\t\t|                                                |\n");
	printf("\t\t\t|    [2]    Return                               |\n");
    printf("\t\t\t|                                                |\n");
    printf("\t\t\t|                                                |\n");
	printf("\t\t\t *===============================================*\n");
}




/***************************************************************
 * April 25 2022   ---   V2 ; check() ISBN - Unique ID
 * April 25 2022   ---   V3 ; Main Menu, if  ----->  Switch 
 * April 27 2022   ---   V4 ; a. ISBN, int ------> long long int / b. Preload 5 books, preload(); / c. k = 5;
 * April 27 2022   ---   V5 ; a. The interface is more user-friendly / b. add menu() && welcome() ; 
 * April 28 2022   ---   V6 ; a. adjust display interface / b. my_string[strlen(my_string)-1]='\0' / c. check, user input ISBN, other than integer. 
 * April 29 2022   ---   V7 ; a. check input (int/double) /  b. add Purchase and return Manu.
 **************************************************************/  