/*
 ============================================================================
 Name        : Bank Database System
 Author      : Sohaib Dar
 Version     : ver 1.0
 Copyright   : For free
 Description : Bank Database Project USING singly Linked List
 Date        : 20 / 1 / 2018
 ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include "B_sys.h"
/* ========================================================================== */
/*                 Default declarations                        */
/* ========================================================================== */
/* None */
Customer_T head;
int main()
{
    //variable to use it for the switch case
   uint8_t choice ;
   //variable to send the entered ID for required function
   uint32_t id_check ;
   //two variables to send the ID's of customers in MoveMoney operation
   uint32_t id_from ;
   uint32_t id_to ;
   //two variables to receive the ID's of customers in edit operation
   sint32_t check1;
   sint32_t check2;
   //variable to store the value of the required passed money
   uint64_t money_transfer ;

   /****************************************Application Code**************************************/
   while(1)
   {
    //messages in the begin of the program for the user
    printf("please select one of the following options :\n\n1-create anew customer (press 1 to select this option)\n2-edit customer (press 2 to select this option )\n3-delete customer (press 3 to select this option)\n4-print customer data (press 4 to select this option)\n5-cash transfer from customer to another (press 5 t select this option)\n6-exit (press 6 to select this option)\n\nplease enter your choice:");
    fflush(stdin);
    //store the entered option in a variable for switch case
    scanf("%c",&choice);
    printf("\n\n");
    //switch case to obtain the required operation
    switch(choice)
    {
    //if user choose first option
    case '1' :
        Create_New_Customer(&head);
        break ;

    //if user choose second operation
    case '2' :
        //ask him to enter the ID of the required customer to edit, then choose what he want to edit
  edit: printf("please enter the id of the customer who you need to change its data :");
        scanf("%i",&id_check);
        check1 = Check_ID(&head,id_check);
        if (check1 == WRONG_INPUT)
        {
           printf("please enter valid id \n");
           goto edit ;
        }

        Edit_Customer(&head,id_check);
        break ;

    //if user choose third operation
    case '3' :
        //ask him to enter the ID want to delete his data from the bank
    L4:    printf("please enter the id of the customer who you need to delete its data :");
        scanf("%i",&id_check);
        check1=Check_ID(&head,id_check);
        if(check1 == -1)
        {
            printf("please enter valid id\n");
            goto L4 ;
        }
        Delete_Customer_Data(&head , id_check);
        break;

     //if user choose fifth option
    case '4' :
  print: printf("please enter the id of the customer who you need to print its data :");
        scanf("%i",&id_check);
        check1 = Check_ID(&head,id_check);
        if(check1==-1)
        {
            printf("please enter a valid id\n ");
            goto print ;
        }
        Print_Customer_Data(&head,id_check) ;
        break;

    //if user choose fifth option
    case '5' :
     L1:printf("please enter the id of the customer who the money will transfer from his cash  :");
        scanf("%i",&id_from);
        check1 = Check_ID(&head,id_from);
        if(check1 == WRONG_INPUT)
        {
           printf("please enter valid id\n");
           goto L1;
        }
    L2: printf("please enter the id of the customer who the money will transfer to his cash  :");
        scanf("%i",&id_to);
        check2 = Check_ID(&head,id_to);
        if(check2 == WRONG_INPUT)
        {
           printf("please enter valid id\n");
           goto L2;
        }


   L3:  printf("please enter the money which will be transfered  :");
        scanf("%lf",&money_transfer);

         if(money_transfer <= ZERO)
        {
            printf("the money transfered should be positive number and greater than zero \n");
            goto L3 ;
        }
        Transfer_Money(&head,id_from,id_to,money_transfer);
        break;
    //if user choose sixth option
    case '6' :
        T_NUM = NUM_Customer(&head);
        printf("the number of the Customers is : %d",T_NUM);
        break;

    case '7' :
        exit(0);
    default:
        printf("wrong choice\n\n");

    }

   }

}
