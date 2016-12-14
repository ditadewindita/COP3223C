//
//  assign5.c
//  
//
//  Created by Haerunnisa Dewindita on 11/21/16.
//
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 30
#define LEN 20

struct employee {
    char first[MAX_LEN];
    char last[MAX_LEN];
    double payperhr;
    double gross;
    double taxes;
    double hours_in_week;
};

FILE* inputf;
FILE* outputf;
struct employee arr[LEN];
int n, weeks;

void update();
void print();

int main(){

    inputf = fopen("clock.txt", "r");
    outputf = fopen("w2.txt", "w");
    
    fscanf(inputf, "%d", &n);
    for(int i=0; i<n; i++){
        struct employee a;
        fscanf(inputf, "%s %s %lf", a.first, a.last, &a.payperhr);
        arr[i] = a;
    }
    
    fscanf(inputf, "%d", &weeks);
    for(int i=0; i<weeks; i++){
        int days;
        fscanf(inputf, "%d", &days);
        for(int j=0; j<days; j++){
            char first[MAX_LEN], last[MAX_LEN];
            int h1, m1, h2, m2;
            fscanf(inputf, "%s %s %d %d %d %d", last, first, &h1, &m1, &h2, &m2);
            for(int i=0; i<n; i++){
                if(strcmp(arr[i].first,first) && strcmp(arr[i].last,last)){
                    arr[i].hours_in_week += (abs(h2-h1) + (abs(m2-m1)/60.0));
                    if(arr[i].hours_in_week > 40){
                        arr[i].gross += ((40)*(arr[i].payperhr));
                        arr[i].taxes += ((40)*(arr[i].payperhr)*.1);
                        arr[i].gross += ((arr[i].hours_in_week - 40)*(arr[i].payperhr*1.5));
                        arr[i].taxes += ((arr[i].hours_in_week - 40)*(arr[i].payperhr*1.5)*.2);
                
                    }
                    else {
                        arr[i].gross += (arr[i].hours_in_week * arr[i].payperhr);
                        arr[i].taxes += (arr[i].hours_in_week * arr[i].payperhr)*.1;
                    }
                }
            }
        }
        update();
    }
    print();
    fclose(inputf);
    fclose(outputf);
    
    return 0;
}

void update(){
    for(int i=0; i<n; i++){
        arr[i].hours_in_week = 0;
    }
}

void print(){
    fprintf(outputf, "Number of employees: %d\n\n", n);
    for(int i=0; i<n; i++)
        fprintf(outputf, "W2 Form\n-------\nName: %s %s\nGross Pay: %.2lf\nTaxes Withheld: %.2lf\nNet Pay: %.2lf\n\n", arr[i].first, arr[i].last, arr[i].gross, arr[i].taxes, (arr[i].gross-arr[i].taxes));
}
