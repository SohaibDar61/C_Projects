#ifndef _BANK_H
#define _BANK_H



/* ==========================================================================*/
/*                           DATA_TYPES                                      */
/* ==========================================================================*/
typedef unsigned char uint8_t;
typedef unsigned short uint16_t;
typedef unsigned int uint32_t;
typedef signed char sint8_t;
typedef signed short sint16_t;
typedef signed int sint32_t;
typedef  double uint64_t;
#define nullptr (void*)0
#define ZERO 0
#define ONE 1




//variable to use it as counter for the for loop
uint32_t counter ;
//variable to save Total num. of customers
uint16_t T_NUM;


/*structure to contain the constant values*/
typedef enum {
    WRONG_INPUT=-1,
    NO_SPACE=0,
    Empty_List,
    DONE
}STATUS_T;


/*structure to contain the data of any user in the bank*/
typedef struct customer
{
    /*Data of users*/
    uint8_t Customer_name[50];
    uint8_t Customer_type[7] ;
    uint64_t Customer_cash ;
    uint32_t Customer_id ;
    /*
	 * pointer to enable us to create another customer
	 * or in general to control the linked list
	 */
    struct customer *next;
}CUSTOMER;   /*variable to use it to create a new customer*/


/*pointer to act as the begin of the list of the bank*/
typedef struct
{
    CUSTOMER *head;
    /*act as count NUm.of customers*/
    uint32_t size;
}Customer_T;



/* ==========================================================================*/
/*                             PROTOTYPES                                    */
/* ==========================================================================*/
STATUS_T Create_New_Customer(Customer_T *PB);
STATUS_T Edit_Customer(Customer_T *PB,uint32_t id);
STATUS_T Print_Customer_Data(Customer_T *PB,uint32_t id);
STATUS_T Transfer_Money(Customer_T *PB,uint32_t source_id ,uint32_t destination_id,double money);
STATUS_T Delete_Customer_Data(Customer_T *PB ,uint32_t id );
sint32_t Check_ID(Customer_T *PB,uint32_t id);
uint32_t NUM_Customer(Customer_T *PB);

#endif // _BANK_H

