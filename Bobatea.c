#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define LSIZ 128
#define RSIZ 10

int i = 0,j = 0,numMenu = 0,numQty,count,countLoop,checkMenu;
char conti_nue,confirmOrder;
float price_of_menu[] = {50, 60, 75, 55, 60, 85, 65, 60, 70, 80};
int num,line,qty;
char lineofMenu[RSIZ][LSIZ];
int arrayOfChoice[10];
float total = 0, totalbal, recived=0,totalRecived;
//test
struct order
{
	int	qty;
};
struct order cart[10];

void main_menu(void) 
{
	system("cls");
	printf("\t____________________________________\n");
	printf("\t----------- Amtaro Menu ------------\n");

	char name_menu[200];
	theMenu();

	printf("\n\t____________________________________\n");
	printf("\n");
	printf("\t Please enter number of menu : ");
	scanf("%d",&num);
	line = num - 1;
	
	if (num >= 1 && num <= 10) 
	{
		printf("\n\t Quantity : ");
		scanf("%d", &cart[count].qty);
		
		if (cart[count].qty >= 1 ) 
		{
			printf("\n");
			printf("\t Do you need to order %s \n\t Quantity = %d (y/n) : ",lineofMenu[line],cart[count].qty);
			scanf(" %c",&confirmOrder);
			qty = cart[count].qty;
			
			if (confirmOrder == 'y' || confirmOrder == 'Y')
			{	
				
				arrayOfChoice[count] = num-1;
				total += price_of_menu[line] * qty;
				printf("\t____________________________________\n"); 
				       
				printf("\n\t Total :  %.2f",total);
				
				printf("\n\t____________________________________\n");
				count++;
				
			}
			else if (confirmOrder == 'n' ||confirmOrder == 'N')
			{
				
			}
			
			else
			{
				printf("\n\t Invalid choice");
				printf("\n\t Press any button to order again");
				getch();
				main_menu();	
			}
		} 
	else 
	{
		printf("\n\t Invalid Quantity");
		printf("\n\t Press any button to order again");
		getch();
		i = 0;
		main_menu();
	}
    }

	numQty = 0;
	j = 0;
	i = 0;
}

void cont(void) {
	printf("\n");
	printf("\t Would you like anything else? (y/n) : ");
	scanf(" %c",&conti_nue);
}

void ourMember() {
	system("cls");
	printf("\n");
	FILE *fp_organizer = fopen("organizer.txt","r");
	char nameOrganizer[500];

	while((fgets(nameOrganizer, sizeof nameOrganizer, fp_organizer)) != NULL) {
		printf("\t %s", nameOrganizer);
	}

}

void confirm_menu(void) {
	system("cls");
	printf("\t_________________________________\n");
	printf("\t------------- Order -------------\n");
	for (checkMenu = 0 ; checkMenu < count ; checkMenu++)
	{
		printf("\n\t %d.",checkMenu+1);
		printf("\n\t Menu : %s",lineofMenu[arrayOfChoice[checkMenu]]);
		printf("\n\t Price : %.2f",price_of_menu[arrayOfChoice[checkMenu]] * cart[checkMenu].qty);
		printf("\n\t Quantity : %d\n\n",cart[checkMenu].qty);
		
	}
	printf("\t_________________________________\n"); 
				       
	printf("\n\t Total :  %.2f",total);
				
	printf("\n\t_________________________________\n");
	
	while (true)
	{
		printf("\t Total received : ");
		scanf("%f", &totalRecived);
		printf("\t You need to pay more than.\n");
		totalbal = totalRecived - total;
		if (totalbal < 0)
		{	
		
		}
		else if (totalbal >= 0)
		{
			bill();
			break;
		}
		else
		{
		
			printf("\n\t Invalid input");
			printf("\n\t Press any button to do it again");
			getch();
			
		}
	}
}

void bill(void) {
	time_t t;
    t = time(NULL);
    struct tm tm;
	tm = *localtime(&t);
	system("cls");
	printf("\t\t   Amtaro Cafe\n");
	printf("\t Date: %d-%d-%d", tm.tm_mday, tm.tm_mon+1, tm.tm_year+1900);
	printf("\t\t %d:%d:%d", tm.tm_hour, tm.tm_min, tm.tm_sec);
	printf("\n\t-----------------------------------\n");
	printf ("\t Qty\tMenu \t\t    Price");
	printf("\n\t-----------------------------------\n");
	theOrder();
	printf("\n\t-----------------------------------\n");
	printf("\n\t Total : \t\t    %.2f",total);
	printf("\n\t Total Recived :\t    %.2f",totalRecived);
	printf("\n\t Total Balance :\t    %.2f",totalbal);
	printf("\n\n\t------------------------------------\n");
	printf("\n\t----------- Thank you \:\) -----------\n");
	printf("\n\tPlease come back to our cafe again \:\)\n");
}

typedef struct {
	int member_id;
	char member_name[20];
	char member_surname[20];
} MEMBER;
MEMBER mem;

void member(void) 
{
	system("cls");
	printf("\t_________________________________\n");
	printf("\t--------Welcome to Amtaro--------\n");
	printf("\tEnter member ID : ");
	scanf("%d", &mem.member_id);
	printf("\tEnter name : ");
	scanf("%s", &mem.member_name);
	printf("\tEnter surname : ");
	scanf("%s", &mem.member_surname);
	printf("\n\tID : %d\n", mem.member_id);
	printf("\tName : %s\n", mem.member_name);
	printf("\tSurname : %s\n", mem.member_surname);
}

void theMenu() {
	FILE *fptr_menu = NULL;
	int numMenu = 0;

	fptr_menu = fopen("amtaro_menu.txt", "r");
	if(!fptr_menu)
		printf("\tFile not found");
	while(fgets(lineofMenu[i], LSIZ, fptr_menu)) {
		lineofMenu[i][strlen(lineofMenu[i]) - 1] = '\0';
		i++;
	}
	numMenu = i;
	for(i = 0; i < numMenu; ++i) {
		j++;
		printf("\t %d. %s %.2f.-\n",j, lineofMenu[i],price_of_menu[i]);

	}
	i = 0;
	j = 0;
}

void theOrder()
{
	for (checkMenu = 0 ; checkMenu < count ; checkMenu++)
	{
	
		printf("\n\t %d  %s %.2f",cart[checkMenu].qty,lineofMenu[arrayOfChoice[checkMenu]],price_of_menu[arrayOfChoice[checkMenu]] * cart[checkMenu].qty);
	
	}
}

void setValue()
{
	for (i=0 ; i < 11 ;i++ )
	{
		arrayOfChoice[i] = 0;
	}
	i = 0;
}

void fileBill()
{
	FILE *fileBill = fopen("bill.txt","w");
	time_t t;
    t = time(NULL);
    struct tm tm;
	tm = *localtime(&t);
	fprintf(fileBill,"\t\t   Amtaro Cafe\n");
    fprintf(fileBill,"\t Date: %d-%d-%d", tm.tm_mday, tm.tm_mon+1, tm.tm_year+1900);
    fprintf(fileBill,"\t\t %d:%d:%d", tm.tm_hour, tm.tm_min, tm.tm_sec);
    fprintf(fileBill,"\n\t-----------------------------------\n");
    fprintf (fileBill,"\t Qty\tMenu \t\t    Price");
    fprintf(fileBill,"\n\t-----------------------------------\n");
    for (checkMenu = 0 ; checkMenu < count ; checkMenu++)
    {
        fprintf(fileBill,"\n\t %d  %s %.2f",cart[checkMenu].qty,lineofMenu[arrayOfChoice[checkMenu]],price_of_menu[arrayOfChoice[checkMenu]] * cart[checkMenu].qty);
    }
    fprintf(fileBill,"\n\t-----------------------------------\n");
    fprintf(fileBill,"\n\t Total : \t\t    %.2f",total);
    fprintf(fileBill,"\n\t Total Recived :\t    %.2f",totalRecived);
    fprintf(fileBill,"\n\t Total Balance :\t    %.2f",totalbal);
    fprintf(fileBill,"\n\n\t------------------------------------\n");
    fprintf(fileBill,"\n\t----------- Thank you :) -----------\n");
    fprintf(fileBill,"\n\tPlease come back to our cafe again :)\n");
}

int main() {
	system("cls");
	member();
	int choice;
	printf("\t_________________________________\n");
	printf("\t-----------  Welcome  -----------\n");
	printf("\t1. Order menu\n");
	printf("\t2. Manager\n");
	printf("\t3. exit\n");
	printf("\t_________________________________\n");
    setValue();
	
	printf("\tEnter choice : ");
	scanf("%d",&choice);

	switch(choice) {
		case 1:
			while (true) {
				main_menu();
				
				cont();
				
				if (conti_nue == 'n' || conti_nue == 'N') 
				{
					break;
					
				}

				else if (conti_nue == 'y' || conti_nue == 'Y') 
				{

				}

				else 
				{
					printf("\n\tInvalid choice");
					printf("\n\tPress any button to order again");
					getch();
				}
			}
			confirm_menu();
			fileBill();
			total = 0;
			count = 0;
			break;
		case 2:
			ourMember();
			printf("\n\n\t1. back \n");
			printf("\tEnter choice : ");
			scanf("%d",&choice);
			switch(choice)
			{
				case 1:
					system("cls");
					main();
					break;
				
				default:
					system("cls");
					printf("\n\tInvalid choice");
					break;
			}
			break;

		case 3:
			system("cls");
			printf("\n\n\t------------------------------------\n");
			printf("\n\t\t    Thank you \:\)");
			printf("\n\n\t------------------------------------\n");
            break;

		default:
			system("cls");
            printf("\n\tInvalid choice");
            printf("\n\tPress any button to again");
            getch();
            main();
            break;
	}
	return 0;
}
