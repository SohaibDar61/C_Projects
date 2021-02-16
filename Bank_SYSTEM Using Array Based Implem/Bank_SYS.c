
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "bank_SYS.h"



/************************************************************************************/
//===============================APPLICATIONS=======================================//
/************************************************************************************/


customer_t arr[MAX_APPLICATION] ;
/********************Function to create new customer data*******************************/
STATUS_T Create_New_Customer(void)
{
    customer_t new_customer ;
    printf("please enter the name of the customer number %i:",counter+1);
    fflush(stdin);
    scanf("%s",(new_customer.name));
    //gets(new_customer.name);

label:
    printf("please enter the cash of the customer number %i:",counter+1);
    scanf("%lf",&(new_customer.cash));
    if(new_customer.cash<0)
    {
        printf("the cash money should be positive number and greater than or equal zero  \n");
        goto label ;
    }

    printf("please enter the type of the customer number %i (debit or credit):",counter+1);
    fflush(stdin);
    scanf("%s",(new_customer.type));
    //gets(new_customer.type);


    printf("please enter the id of the customer number %i:",counter+1);
    scanf("%i",&(new_customer.id));

    printf("\n\n");
    arr[counter]=new_customer ;
    counter++ ;
    return DONE;
}
/************************************************************************************/


/********************Function to edit customer data*******************************/
STATUS_T Edit_Customer_Data(uint32_t id )
{
    uint32_t i ;
    for(i = 0; i <= counter; i++)
    {
        if(id == arr[i].id)
        {
            printf("please enter the new name :");
            fflush(stdin);
            scanf("%s",(arr[i].name));
            //gets(arr[i].name);

            printf("please enter the new cash :");
            scanf("%lf",&(arr[i].cash));

            printf("please enter the new type (Debit or credit):");
            fflush(stdin);
            scanf("%s",(arr[i].type));
            gets(arr[i].type);

            printf("please enter the new id :");
            scanf("%i",&(arr[i].id));

            printf("\n\n");
            break ;
        }
    }
    return DONE;

}
/************************************************************************************/


/********************Function to Move money from customer to other********************/
STATUS_T Transfer_Money(uint32_t source_id,uint32_t destination_id,uint64_t money)
{
    uint32_t i ;
    uint32_t index_from = -1 ;
    uint32_t index_to = -1 ;
L1:
    for(i = 0; i <= counter; i++)
    {
        if(arr[i].id == source_id)
        {
            index_from = i ;
        }
        else if (arr[i].id == destination_id)
        {
            index_to=i ;
        }
        if((index_from != -1)&&(index_to != -1))
        {
            break;
        }

    }
    if((index_from == -1)||(index_to == -1))
    {
        printf("please enter valid id\n");


    }
    if(money > arr[index_from].cash)
    {
        printf("the money transfered is greater than your cash \n");
        printf("please enter the money transfered again and take care :");
        scanf("%lf",&money);
        goto L1;
    }

    arr[index_from].cash = arr[index_from].cash - money;
    arr[index_to].cash = arr[index_to].cash + money;
    return DONE;
}
/************************************************************************************/


/********************Function to Delete customer data*******************************/
STATUS_T Delete_Customer_Data(uint32_t id )
{
    uint32_t i ;
    uint32_t index ;
    for(i = 0; i <= counter - 1; i++)
    {
        if(arr[i].id == id)
        {
            index=i ;
            for(i = index; i <= counter - 1; i++)
            {
                arr[i] = arr[i + 1];

            }
        }
    }
    arr[counter].cash = -1; // -1 indicate this is empty place for new customer
    arr[counter].id = -1 ;  // -1 indicate this is empty place for new customer
    strcpy(arr[counter].name,"-1"); // -1 indicate this is empty place for new customer
    strcpy(arr[counter].type,"-1"); // -1 indicate this is empty place for new customer
    counter--;
    return DONE;
}
/************************************************************************************/


/********************Function to print customer data*********************************/
STATUS_T Print_Customer_Data(uint32_t id)
{
    uint32_t i ;
    for(i = 0; i <= counter; i++)
    {

        if (id == arr[i].id)
        {
            printf("the name of the customer number%i is :%s\n",i+1,arr[i].name);
            printf("the cash of the customer number%i is :%0.2lf\n",i+1,arr[i].cash);
            printf("the type of the customer number%i is :%s\n",i+1,arr[i].type);
            printf("the id of the customer number%i is :%i\n",i+1,arr[i].id);
            printf("\n\n");
            break ;
        }
    }
    return DONE;
}
/************************************************************************************/
