//
//  Haerunnisa Dewindita
//  COP3223 Section 2
//  Assignment #1 - part C
//  Created on 8/26/16
//

#include <stdio.h>

#define FIRST_CAR_LENGTH 10
#define NORMAL_CAR_LENGTH 8
#define CAR_CAPACITY 4

int main(void){
    
    //declare variables
    int n, total_track_length, max_train_length;
    
    //prompts for N value
    printf("What is the value for N?\n");
    scanf("%d", &n);
    
    //for loop for multiple inputs
    int i;
    for(i=0; i<n; i++){

        //prompt user for data
        printf("What is the total length of the track, in feet?\n");
        scanf("%d", &total_track_length);
        printf("What is the maximum length of a train, in feet?\n");
        scanf("%d", &max_train_length);
        
        //train computations
        int cars_per_train = ((max_train_length-10)/8)+1; //cars allowed per train
        int trains_allowed = (total_track_length*0.25)/max_train_length; //trains allowed per track
        int surplus = max_train_length-((cars_per_train*8)+2); //surplus of train length
        
        //prints and computes number of people allowed on track at once
        printf("Your ride can have at most %d people on it at one time.\n", (cars_per_train*4)*trains_allowed);
        
        //outputs option of surplus
        if(surplus > 0)
            printf("Maximum Train length has a surplus of %d feet\n", surplus);
        else
            printf("Maximum Train Length fits exactly\n");
        
    }
    
    return 0;
}
