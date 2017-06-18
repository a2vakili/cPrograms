//
//  main.c
//  credit
//
//  Created by Arsalan Vakili on 2017-06-18.
//  Copyright © 2017 Arsalan Vakili. All rights reserved.
//

#include <stdio.h>

int getDigits(long long num)
{
    int sum = 0;
    while(num > 0)
    {
        num /= 10;
        sum++;
    }
    return sum;
}

int main() {
    
    long long cardNum = 0;
    // every other digit from 1st
    int EODF = 0;
    // every other digit from 2nd
    int EODS = 0;
   
    printf("Please Enter your credit card number:\n");
    
    scanf("%lld",&cardNum);
    
    // getting the number of the digits of the  card
    int digits = getDigits(cardNum);
    
    // printf("%d\n",digits);
    
    int cardDigits[digits];
    
    // populating the array with digits of the credit card
    for (int i = digits - 1; i >= 0; i--)
    {
        cardDigits[i] = cardNum % 10;
        cardNum /= 10;
        // printf("%d\n",cardDigits[i]);
    }
    
    
    /* Multiply every other digit by 2, starting with the number’s
     second-to-last digit, and then add those products'
     digits together. */
    
    // checking for even cards
    if (digits % 2 == 0)
    {
        for (int sd = 0; sd < digits - 1; sd += 2)
        {
            if ((cardDigits[sd] * 2) >= 10)
            {
                int dummy = (cardDigits[sd] * 2) % 10;
                EODS += dummy + 1;
            }
            else
            {
                EODS += (cardDigits[sd] * 2);
            }
            
        }
        
        for (int fd = 1; fd < digits; fd += 2)
        {
            EODF += cardDigits[fd];
        }
        
    }
    
    // checking for odd cards
    if (digits % 2 == 1)
    {
        for (int sd = 1; sd < digits; sd += 2)
        {
            if ((cardDigits[sd] * 2) > 10)
            {
                int dummy = (cardDigits[sd] * 2) % 10;
                EODS += dummy + 1;
            }
            else
            {
                EODS += (cardDigits[sd] * 2);
            }
            
        }
        
        for (int fd = 0; fd < digits ; fd += 2)
        {
            EODF += cardDigits[fd];
        }
        
    }
    
    
    int sum = EODS + EODF;
    
    // printf("%d\n",sum);
    int reman = sum % 10;
    
    // getting the beginning of the card
    int cardBgn = 10 * cardDigits[0] + cardDigits[1];
    
    if ((cardBgn == 34 || cardBgn == 37) && reman == 0 && digits == 15)
    {
        printf("AMEX\n");
    }
    else if ((cardBgn >= 51 && cardBgn <= 55) && reman == 0 && digits == 16)
    {
        printf("MASTERCARD\n");
    }
    else if (cardDigits[0] == 4 && reman == 0 && (digits >= 13 && digits <= 16))
    {
        printf("VISA\n");
    }
    
    else
    {
        printf("INVALID\n");
    }
    
    return 0;
}
