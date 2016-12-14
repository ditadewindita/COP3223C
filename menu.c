//
//  Haerunnisa Dewindita
//  COP3223 Section 2
//  Assignment #2 - part D
//  Created on 9/26/16
//

#include <stdio.h>
#include <string.h>

void abundant();
void coaster2();
void lastnames();


int main(void){
    
    int choice;
    
    printf("Choose from the menu below and enter the corresponding integer.\n1. abundant\n2. coaster2\n3. lastnames\n4. quit\n");
    scanf("%d", &choice);
    
    while(choice != 4){
        if(choice == 1)
            abundant();
        else if(choice == 2)
            coaster2();
        else if(choice == 3)
            lastnames();
        printf("Next choice: ");
        scanf("%d", &choice);
    }
    
    return 0;
}

void abundant(){
    
    // scanning in for loop bound
    int a;
    printf("Please enter n followed by n integers: ");
    scanf("%d", &a);
    
    // reading in n and simultaneously calculating abundancy
    for(int i=1; i<=a; i++){
        int n;
        int sum = 0;
        scanf("%d", &n);
        for(int j=1; j<=(n/2); j++)
            if(n%j == 0)
                sum += j;
        
        // printing abundancy
        if(sum > n)
            printf("Test case #%d: %d is an abundant number.\n", i, n);
        else
            printf("Test case #%d: %d is NOT an abundant number.\n", i, n);
    }
    
    return;
}

void coaster2(){
    
    int track_length, max_train_length, max_trains;
    int curr_train_length = 10;
    
    //prompt for input
    printf("What is the total length of the track, in feet?\n");
    scanf("%d", &track_length);
    printf("What is the maximum length of a train, in feet?\n");
    scanf("%d", &max_train_length);
    
    //calculate feet of trains allowed
    max_trains = track_length*0.25;
    
    //setup array of avg.
    int possible_lengths = ((max_train_length-10)/8)+1;
    float arr[possible_lengths], a, avg;
    
    //setup max & while loop vals
    int i = 1;
    int max_peop = 0;
    int max_car = 0;
    int curr_peop = 0;
    
    //loop through while in bounds & below max train length
    while(i <= possible_lengths && curr_train_length <= max_train_length){
        
        //calculate avg and store in arr
        a = (i*4)/(float)curr_train_length;
        arr[i-1] = a;
        avg += a;
        
        //calculate max people
        curr_peop = (max_trains/curr_train_length)*i*4;
        if(curr_peop >= max_peop){
            
            //change max # of cars only if more people fit in or if newer car amt is less than old one (w/ same people amt)
            if(curr_peop > max_peop || (curr_peop == max_peop && i < max_car))
                max_car = i;
            
            max_peop = curr_peop;
        }
        
        //increment values for next iteration
        curr_train_length += 8;
        i+=1;
    }
    
    //calculate final avg ratio
    printf("%f ", avg);
    printf("%d\n", possible_lengths);
    avg /= possible_lengths;
    
    //output calculations
    printf("Your ride can have at most %d people on it at one time.\n", max_peop);
    printf("This can be achieved with trains of %d cars.\n", max_car);
    printf("AVG Ratio: %.3f\n", avg); //cuts float to 3 decimal places
    
    return;
    
}

void lastnames(){
    
    int x;
    int str_buffer = 50; // assume last name has max length 50
    
    printf("Enter n, followed by n last names (each last name must be a single word): ");
    scanf("%d", &x); //prompt user for input
    
    //set variables
    int flag = 0;
    char n[str_buffer];
    char name[str_buffer];
    
    //loop through strings, check if repeated
    for(int i=0; i<x; i++){
        scanf("%s", n);
        if(i==0)
            strcpy(name,n);
        else if(strcmp(n, name)==0)
            flag = 1;
    }
    
    //output repetition
    if(flag == 1)
        printf("First name in list is repeated.\n");
    else
        printf("First name in list is not repeated.\n");
    
    return;
    
}