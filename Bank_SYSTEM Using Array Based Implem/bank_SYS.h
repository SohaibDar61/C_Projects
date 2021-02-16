#ifndef BANK_SYS_H
#define BANK_SYS_H

/* ==========================================================================*/
/*                           DATA_TYPES                                      */
/* ==========================================================================*/
typedef unsigned char uint8_t;
typedef unsigned short uint16_t;
typedef unsigned int uint32_t;
typedef signed char sint8_t;
typedef signed short sint16_t;
typedef signed int sint32_t;
typedef double uint64_t;
#define nullptr (void*)0
#define ZERO 0
#define ONE 1





#define MAX_APPLICATION 5
//variable to use it as counter for the for loop
uint32_t counter ;
//variable to save Total num. of customers
uint16_t T_NUM;



/*structure to contain the contents of the customer*/
typedef struct customer
{
    uint8_t name[50];
    uint64_t cash ;
    uint8_t type[7] ;
    uint32_t id ;
}customer_t ;


/*structure to contain the constant values*/
typedef enum {
    WRONG_INPUT=-1,
    NO_SPACE=0,
    Empty_List,
    DONE
}STATUS_T;


/* ==========================================================================*/
/*                             PROTOTYPES                                    */
/* ==========================================================================*/
STATUS_T Create_New_Customer(void);
STATUS_T Edit_Customer_Data(uint32_t id);
STATUS_T Print_Customer_Data(uint32_t id);
STATUS_T Transfer_Money(uint32_t source_id ,uint32_t destination_id,double money);
STATUS_T Delete_Customer_Data(uint32_t id );
sint32_t Check_ID(uint32_t id);
uint32_t NUM_Customer(void);

#endif  //BANK_SYS_H

