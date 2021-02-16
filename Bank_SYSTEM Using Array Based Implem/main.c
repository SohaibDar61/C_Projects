/*
 ============================================================================
 Name        : Bank System
 Author      : Sohaib Reda Dar
 Version     : ver 1.0
 Copyright   : For free
 Description : Bank DataBase Project USING Array Based Implemntation
 Date        : 20 / 1 / 2019
 ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bank_SYS.h"
/* ========================================================================== */
/*                 Default declarations                        */
/* ========================================================================== */
/* None */
int main()
{
   //variable to use it for the switch case
   uint8_t choice ;
   //variable to send the entered ID for required function
   uint32_t id_check ;
   //two variables to send the ID's of customers in MoveMoney operation
   uint32_t id_from ;
   uint32_t id_to ;
   //variable to store the value of the required passed money
   uint64_t money_transfer ;

   /****************************************Application Code**************************************/
    while(1)
    {
        //messages in the begin of the program for the user
        printf("please select one of the following options :\n\n1-Create a New Customer (press 1 to select this option)\n2-Edit Customer (press 2 to select this option )\n3-Delete Customer (press 3 to select this option)\n4-Print Customer Data (press 4 to select this option)\n5-Cash Transfer From Customer To Another (press 5 t select this option)\n6-Exit (press 6 to select this option)\n\nPlease Enter Your Choice:");
        fflush(stdin);
        //store the entered option in a variable for switch case
        scanf("%c",&choice);
        printf("\n\n");
    //switch case to obtain the required operation
        switch(choice)
        {
        case '1' :
            if(counter >= MAX_APPLICATION)
            {
                printf("the maximum number of customers is 5 so you can't add anymore\n");
                break ;
            }
            Create_New_Customer();
            break ;

        case '2' :
            printf("please enter the id of the customer who you need to change its data :");
            scanf("%i",&id_check);
            Edit_Customer_Data(id_check) ;
            break ;

        case '3' :
            printf("please enter the id of the customer who you need to delete its data :");
            scanf("%i",&id_check);
            Delete_Customer_Data(id_check);
            break;
        case '4' :
            printf("please enter the id of the customer who you need to print its data :");
            scanf("%i",&id_check);
            Print_Customer_Data(id_check) ;
            break;
        case '5' :
            printf("please enter the id of the customer who the money will transfer from his cash  :");
            scanf("%i",&id_from);
            printf("please enter the id of the customer who the money will transfer to his cash  :");
            scanf("%i",&id_to);
L2:
            printf("please enter the money which will be transfered  :");
            scanf("%lf",&money_transfer);

            if(money_transfer <= ZERO)
            {
                printf("the money transfered should be positive number and greater than zero \n");
                goto L2 ;
            }
            Transfer_Money(id_from,id_to,money_transfer);
            break;

        case '6' :
            exit(0);
        default:
            printf("wrong choice\n\n");
        }

    }

    return 0 ;
}
