/*
 ============================================================================
 Name        : ATM_SYSTEM
 Author      : SOHAIB
 Copyright   : For free
 Date        : 22 / 7 / 2018
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int ATM(int);


int main()
{
    int key =0 ;
    printf("Enter the key is  ");
    scanf("%d",&key);
    ATM(key);
    return 0;
}



int ATM(int num)
{
    int c200,c100,c50,c20,c10,c5,c1;
    int i200,i100,i50,i20,i10,i5,i1;
    int count =0;
    c200 = num / i200 ;
    c100 = num / i100 ;
    c50 = num / i50 ;
    c20 = num / i20 ;
    c10 = num / i10;
    c5 = num / i5 ;
    c1 = num ;

    for (i200=0; i200<=c200; i200++)
    {
        for (i100=0; i100<=c100; i100++)
        {
            for (i50=0; i50<=c50; i50++)
            {
                for (i20=0; i20<=c20; i20++)
                {
                    for (i10=0; i10<=c10; i10++)
                    {
                        for (i5=0; i5<=c5; i5++)
                        {
                            for (i1=0; i1<c1; i1++)
                                if( (i200*200 +i100*100 + i50*50 + i20 *20 + i10*10 + i5*5 +i1 *1) == num)
                                {
                                    count ++;
                                    printf(" %d    %d    %d    %d    %d    %d    %d \n \n", i200,i100,i50,i20,i10,i5,i1);
                                }

                        }
                    }
                }
            }
        }
    }
    return 0;
}
