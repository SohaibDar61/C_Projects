
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "B_sys.h"




/************************************************************************************
===============================APPLICATIONS==========================================
/************************************************************************************/


/********************Function to return index of the ID_Customer*******************************/
sint32_t Check_ID(Customer_T *PB,uint32_t id)
{
    sint32_t check = -1 ;
    if(PB->head == nullptr)
    {
        check = ZERO ;
    }
    while(PB->head != nullptr)
    {
        if(PB->head->Customer_id == id)
        {
            check = ONE ;
            break ;
        }
        PB->head = PB->head->next ;
    }
    return check ;
}
/************************************************************************************/


/********************Function to create new customer data*******************************/
STATUS_T Create_New_Customer(Customer_T *PB)
{
    //put a pointer in the begin of the linked list
    CUSTOMER *new_customer = (CUSTOMER *)malloc(sizeof(CUSTOMER));
    printf("\nplease Enter the name of the customer number %d: ",counter + 1);
    fflush(stdin);
    //allow the cuntomer to enter the ID
    scanf("%s",new_customer->Customer_name);

L1:
    printf("\nplease Enter cash money of the customer number %d: ",counter + 1);
    //allow the customer to enter the value of money
    scanf("%lf",&new_customer->Customer_cash);
    if(new_customer->Customer_cash < ZERO)
    {
        printf("\nthe cash money should be greater than or equal zero:\n");
        goto L1;
    }
    printf("\nplease Enter the type of the customer number %d(debit or credit): ",counter+1);
    fflush(stdin);
    //allow the customer to select the type of this option
    scanf("%s",new_customer->Customer_type);


    printf("\nplease Enter the ID of the customer number %d: ",counter+1);
    //allow the counter to enter the ID
    scanf("%d",&new_customer->Customer_id);

    /*
	 * include the new customer in the list
	 * by connecting the arrows together
	 */
    new_customer->next = PB->head;
    //move the head to the new node
    PB->head = new_customer;

    printf("\n\n");
    counter++;
    PB->size ++;
    return DONE;

}
/************************************************************************************/


/********************Function to edit customer data*******************************/
STATUS_T Edit_Customer(Customer_T *PB, uint32_t id)
{
    if(PB->head == nullptr)
    {
        printf("the linked is empty \n");
        return Empty_List;
    }
    else
    {
        while(PB->head)
        {
            //condition to check if the current stop at the same entered ID
            if(PB->head->Customer_id == id)
            {
                printf("\nEnter the new name: ");
                fflush(stdin);
                //gets(PB->head->name);
                scanf("%s",PB->head->Customer_name);

                printf("\nEnter the new cash money : ");
                //gets(PB->head->cash);
                scanf("%lf",&PB->head->Customer_cash);

                printf("\nEnter the  new type (debit or credit): ");
                fflush(stdin);
                //gets(PB->head->type);
                scanf("%s",PB->head->Customer_type);


                printf("\nEnter the new ID : ");
                //gets(PB->head->id);
                scanf("%d",&PB->head->Customer_id);
                break ;
            }
            //to move to another node
            PB->head = PB->head->next;

        }
        return DONE;
    }
}
/************************************************************************************/


/********************Function to Move money from customer to other********************/
STATUS_T Transfer_Money(Customer_T *PB,uint32_t source_id,uint32_t destination_id,uint64_t money)
{

    CUSTOMER *temp = PB->head;

    if(PB->head == nullptr)
    {
        printf("the linked list is empty \n");
        return Empty_List ;
    }
    else
    {
        if(PB->head->next == nullptr)
        {
            printf("the linked list is containing just one element and to transfer money it must be at least 2 elements \n");
            return WRONG_INPUT ;
        }
        //if the loop ended and the condition still true
		//that is mean that there is no matched data, so end from the function
        while(PB->head != nullptr)
        {

            if(PB->head->Customer_id == source_id)
            {
                if(PB->head->Customer_cash - money < ZERO)
                {
                    printf("the transfered money is more than client money\n");
                    return WRONG_INPUT;
                }
                PB->head->Customer_cash = PB->head->Customer_cash - money;
                break;
            }

            PB->head = PB->head->next;
        }
        while(temp != nullptr)
        {

            if(temp->Customer_id == destination_id)
            {

            //move the money from source to destinatoin
                temp->Customer_cash = temp->Customer_cash + money;
                break;
            }
            temp = temp->next;
        }
        return DONE;
    }
}
/************************************************************************************/


/********************Function to Delete customer data*******************************/
STATUS_T Delete_Customer_Data(Customer_T *PB,uint32_t id )
{
    //variable to use it as counter for for loop
    uint32_t i = ZERO;
    uint32_t j;
    CUSTOMER *temp;
    //pointer to use to to delete the node
    CUSTOMER *temp2 = PB->head;
    if(PB->head == nullptr)
    {
        printf("the linked list is empty \n");
        return Empty_List;
    }
    else
    {

        if(PB->head->next == nullptr)
        {
            free(PB->head);
            PB->head = nullptr ;
            counter--;
        }
        while(PB->head != nullptr)
        {
            if(PB->head->Customer_id == id)
            {
                break;
            }
            PB->head = PB->head->next;
            i++;
        }
        if(i == ZERO)
        {
            //move the head to the next customer
            PB->head = PB->head->next;
            //delete the node
            free(temp2);
            counter--;
        }
        //to move the current until the required deleted node
        for(j = ZERO; j < i - ONE; j++)
        {
            temp2 = temp2->next;
        }

		/*
		 * save the linked list from lost
		 * connect the previous node to the node after the current
		 */
        printf("i = %d",i);
        printf("j = %d",j);

        temp = temp2->next;
        temp2->next = temp->next;
        //delete the node
        free(temp);
        counter--;
        PB->size --;
        return DONE;
    }
}
/************************************************************************************/


/********************Function to print customer data*********************************/
STATUS_T Print_Customer_Data(Customer_T *PB,uint32_t id)
{
    if(PB->head == nullptr)
    {
        printf("the linked list is empty \n");
        return Empty_List ;
    }
    else
    {

        while (PB->head != nullptr)
        {
            if (PB->head->Customer_id == id)
            {
                printf("the name of the customer number%d is :%s\n",counter+1,PB->head->Customer_name);
                printf("the cash of the customer number%d is :%0.2lf\n",counter+1,PB->head->Customer_cash);
                printf("the type of the customer number%d is :%s\n",counter+1,PB->head->Customer_type);
                printf("the id of the customer number%d is :%i\n",counter+1,PB->head->Customer_id);
                printf("\n\n");
                break;
            }


            PB->head = PB->head->next;
        }
        return DONE;
    }
}
/************************************************************************************/


/********************Function to count NUM.customers in the list*********************/
uint32_t NUM_Customer(Customer_T *PB)
{
    return (PB->size);
}
/************************************************************************************/
