//
//  Haerunnisa Dewindita
//  COP3223 Section 2
//  Assignment #2 - part A
//  Created on 9/26/16
//

#include <stdio.h>

int main(void){
    
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
    
    return 0;
}