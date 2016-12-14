//
//  Haerunnisa Dewindita
//  COP3223 Section 2
//  Assignment #1 - part A
//  Created on 8/26/16
//

#include <stdio.h>

#define TAX_RATE 0.065

int main(void){
    
    //declaring variables
    float item_price;
    int item_quantity, tax_item;
    
    //prompting user info
    printf("What is the cost of the item to be purchased (in dollars)?\n");
    scanf("%f", &item_price);
    printf("How many of the item are you purchasing?\n");
    scanf("%d", &item_quantity);
    printf("Is the item a taxed item (1 = yes, 0 = no)?\n");
    scanf("%d", &tax_item);
    
    //calculate purchase cost and round to dollar format
    float cost = ((TAX_RATE*tax_item)*(item_quantity*item_price))+(item_quantity*item_price)+0.005;
    
    //print final computation
    printf("Your total purchase will cost $%.2f\n", cost);
    
    return 0;
}
