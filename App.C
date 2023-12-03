/*=== All the Header Files ===*/
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

/*=== No of Room ===*/
int sR = 10, kR = 20, tR = 30, totRes = 0;

/*=== All the Variables ===*/
struct Reservation
{
    char custName[30], roomType;
    int rD, rM, rY, perDay, noOfPer, resId, noOfRoom;
    float billAmt;
} sRes[90];

/*=== Function Decelaration Part ===*/
void report();
void roomAvl();
void hotelInfo();
void res();
void bill();
void gotoxy(int x, int y);


/*=== Degsine Part ===*/
// Example usage of gotoxy to set cursor position
void gotoxy(int x, int y)
{
    printf("\033[%d;%df", y, x);
}

void headerFooter()
{
    /*===   Header  ===*/
    gotoxy(1, 2);
    printf("+==============================================================================+");
    gotoxy(1, 3);
    printf("|                           'Welcome To Our Hotel'                             |");
    gotoxy(1, 4);
    printf("+==============================================================================+");

    /*===   Footer  ===*/
    gotoxy(1, 26);
    printf("________________________________________________________________________________");
    gotoxy(20, 27);
    printf("Visit us at : https://www.ourhotel.com");
}

/*=== Menu ===*/
char menu()
{
    system("cls");
    headerFooter();

    gotoxy(25, 8);
    printf("+-------------------------+");
    gotoxy(25, 9);
    printf("|   D: Data               |");
    gotoxy(25, 10);
    printf("|-------------------------|");
    gotoxy(25, 11);
    printf("|   H: Hotel Information  |");
    gotoxy(25, 12);
    printf("|-------------------------|");
    gotoxy(25, 13);
    printf("|   A: Availability       |");
    gotoxy(25, 14);
    printf("|-------------------------|");
    gotoxy(25, 15);
    printf("|   R: Reservation        |");
    gotoxy(25, 16);
    printf("|-------------------------|");
    gotoxy(25, 17);
    printf("|   E: Exit               |");
    gotoxy(25, 18);
    printf("+-------------------------+");

    gotoxy(25, 20);
    printf("Enter the choice:\t");
    return (getche());
}

/*=== Hotel Data ===*/
void report()
{
    int i;
    system("cls");
    headerFooter();
    if (totRes == 0)
    {
        gotoxy(25, 8);
        printf(" No Info to Display. ");
    }
    else
    {
        gotoxy(5, 6);
        for (i = 0; i < totRes; i++)
        {
            printf("\n");
            printf("\n ID  : %3d      Name: %s", sRes[i].resId, sRes[i].custName);
            printf("\n Date: %2d/%2d    Days: %d     Room: %c \n", sRes[i].rD,
                   sRes[i].rM, sRes[i].perDay, sRes[i].roomType);
            printf("________________________________________________________________________________");
        }
    }
}

/*=== Room Availability ===*/
void roomAvl()
{
    system("cls");
    headerFooter();
    gotoxy(30, 8);
    printf(" Room Information:");
    gotoxy(30, 10);
    printf(" Suite : Total = %d", sR);
    gotoxy(30, 11);
    printf(" King  : Total = %d", kR);
    gotoxy(30, 12);
    printf(" Travel: Total = %d", tR);
}

/*=== Hotel Information ===*/
void hotelInfo()
{
    system("cls");
    headerFooter();

    gotoxy(2, 6);
    printf(" This is 5-star Hotel which is completely Air-condition, Spacious.");
    gotoxy(2, 7);
    printf(" There are total 2 Restaurants and 1 Bar and total 90 rooms");
    gotoxy(2, 9);
    printf(" Amenities: ");
    gotoxy(15, 9);
    printf(" WIFI, Telephone, 24 Hour BAR & Restaurant and Room Service,");
    gotoxy(2, 10);
    printf(" Near By  : ");
    gotoxy(15, 10);
    printf(" Gongabu Bus Park @ 50Mtr. ");

    gotoxy(2, 13);
    printf(" Room Information:");
    gotoxy(2, 14);
    printf("+-----------+----------------------------------------------------+----------+");
    gotoxy(2, 15);
    printf("| Room Type |       Information                                  |   Price  |");
    gotoxy(2, 16);
    printf("+-----------+----------------------------------------------------+----------+");
    gotoxy(2, 17);
    printf("| Suite     |   2Rooms, 120Sq-Mtr, Sofa and King Bed             |  10000/- |");
    gotoxy(2, 18);
    printf("+-----------+----------------------------------------------------+----------+");
    gotoxy(2, 19);
    printf("| KING      |   60Sq-Meter, Sofa, Table and King Bed             |  5000/-  |");
    gotoxy(2, 20);
    printf("+-----------+----------------------------------------------------+----------+");
    gotoxy(2, 21);
    printf("| Travel    |   40Sq-Meter, Table, Queen Bed                     |  2500/-  |");
    gotoxy(2, 22);
    printf("+-----------+----------------------------------------------------+----------+");
}

/*=== Reservation ===*/
void res()
{
    system("cls");
    headerFooter();
    gotoxy(5, 6);
    printf(" Enter Your Name       : ");
    gotoxy(30, 6);
    gets(sRes[totRes].custName);
    // scanf("%s", &sRes[totRes].custName);
    fflush(stdin);
    gotoxy(5, 7);
    printf(" Enter Date            : dd/mm/yy");
    gotoxy(30, 7);
    scanf("%d", &sRes[totRes].rD);
    fflush(stdin);
    gotoxy(33, 7);
    scanf("%d", &sRes[totRes].rM);
    fflush(stdin);
    gotoxy(36, 7);
    scanf("%d", &sRes[totRes].rY);
    fflush(stdin);
    gotoxy(5, 8);
    printf(" Enter No of days      : ");
    gotoxy(30, 8);
    scanf("%d", &sRes[totRes].perDay);
    fflush(stdin);
    gotoxy(5, 9);
    printf(" Enter Room Type(S/K/T): ");
    gotoxy(30, 9);
    scanf("%c", &sRes[totRes].roomType);
    fflush(stdin);
    gotoxy(5, 10);
    printf(" Enter No of Persons   : ");
    gotoxy(30, 10);
    scanf("%d", &sRes[totRes].noOfPer);
    fflush(stdin);

    sRes[totRes].noOfRoom = 1;

    if (sRes[totRes].noOfPer > 3)
    {
        sRes[totRes].noOfRoom = 0;
        sRes[totRes].noOfRoom += (sRes[totRes].noOfPer / 3);
        if (sRes[totRes].noOfPer % 3 != 0)
        {
            sRes[totRes].noOfRoom++;
        }
    }
    bill();
}

/*=== Bill ===*/
void bill()
{
    float damt;
    char ty[10];
    switch (sRes[totRes].roomType)
    {
    case 's':
    case 'S':
        strcpy(ty, "Suite");
        damt = 10000;
        sR = sR - sRes[totRes].noOfRoom;
        break;
    case 'k':
    case 'K':
        strcpy(ty, "King");
        damt = 5000;
        kR = kR - sRes[totRes].noOfRoom;
        break;
    case 't':
    case 'T':
        strcpy(ty, "Travle");
        damt = 2500;
        tR = tR - sRes[totRes].noOfRoom;
        break;
    }
    sRes[totRes].billAmt = sRes[totRes].perDay * damt * sRes[totRes].noOfRoom;

    gotoxy(2, 13);
    printf("Bill:");
    gotoxy(2, 14);
    printf("+---------------+--------------+------------+------------------+------------+");
    gotoxy(2, 15);
    printf("|   Room Type   |  Total Days  |  Per Day   |  No of Rooms     |    Price   |");
    gotoxy(2, 16);
    printf("+---------------+--------------+------------+------------------+------------+");
    gotoxy(2, 17);
    printf("| %8s      |    %5d     |   %5.0f/-  |    %6.0d        | %8.0f/- |",
           ty, sRes[totRes].perDay, damt, sRes[totRes].noOfRoom, sRes[totRes].billAmt);
    gotoxy(2, 18);
    printf("+---------------+--------------+------------+------------------+------------+");
    gotoxy(2, 19);
    printf("|   Total Bill:                                                  %8.0f/- |",
           sRes[totRes].billAmt);
    gotoxy(2, 20);
    printf("+---------------+--------------+------------+------------------+------------+ \t");

    /*=== To Generate  Random Costumer Id's ===*/
    srand(time(0));

    /*=== To Generate  Random number between 101 to 999 ===*/
    sRes[totRes].resId = rand() % (999 - 101 + 1) + 101;

    gotoxy(2, 22);
    printf("Your Reservation number = %d", sRes[totRes].resId);

    totRes++;
}

/*=== Main Module ===*/
int main()
{
    char option;
    do
    {
        system("cls");
        option = menu();
        switch (option)
        {
        case 'd':
        case 'D':
            report();
            break;

        case 'h':
        case 'H':
            hotelInfo();
            break;

        case 'a':
        case 'A':
            roomAvl();
            break;

        case 'r':
        case 'R':
            res();
            break;

        case 'e':
        case 'E':
            gotoxy(20, 22);
            printf("Thank You ... Visit Again ... %c", 2);
            break;
        }
        getch();
    } while (option != 'e' && option != 'E');
}
