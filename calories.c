//
//  Haerunnisa Dewindita
//  COP3223 Section 2
//  Assignment #1 - part B
//  Created on 8/26/16
//

#include <stdio.h>

#define WALK_CAL 5
#define STAND_CAL 2
#define DRINK_CAL 20
#define FOOD_CAL 40
#define CALS_PER_POUND 3500

int main(void){
    
    //declare variables
    int walking_mins, standing_mins, drinking_mins, eating_mins;
    
    //prompt for user info
    printf("How many minutes were you walking?\n");
    scanf("%d", &walking_mins);
    
    printf("How many standing were you walking?\n");
    scanf("%d", &standing_mins);
    
    printf("How many drinking were you walking?\n");
    scanf("%d", &drinking_mins);
    
    printf("How many eating were you walking?\n");
    scanf("%d", &eating_mins);
    
    //calorie gain/loss calculation
    int calories_burned = (walking_mins*WALK_CAL) + (standing_mins*STAND_CAL);
    int calories_gained = (drinking_mins*DRINK_CAL) + (eating_mins*FOOD_CAL);
    
    //computation of weight loss/gain
    float weight_loss = (calories_burned-calories_gained)/(float)CALS_PER_POUND;
    
    //output correct line for weight gain/loss
    if(weight_loss<=0)
        printf("Weight lost is %.3f pounds.\n", weight_loss);
    else
        printf("You lost %.3f pounds today!\n", weight_loss);
    
    return 0;
}