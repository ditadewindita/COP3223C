//
//  Haerunnisa Dewindita
//  COP3223C Section 2
//  Assignment 3
//  10/11/16
//

#include <stdio.h>
#include <string.h>

char don_table[100][20], req_table[100][20];
int don_amt[100], req_amt[100];
int donations = 0, requests = 0;

void printReport();
int present(char s[20], char a);
void addDonation(char type[20], int amt);
void addRequest(char type[20], int amt);
void fulfillReq(char type[20], int amt);


int main(void){
    int n;
    char c;
    
    printf("\nWelcome to the Food Bank program!\n1. Add a donation\n2. Add a request\n3. Fulfill a request\n4. Print status report\n5. Exit\n\nEnter your choice: ");
    scanf("%d", &n);
    
    while(n != 5) {
        
        char type[20];
        int amt;
        
        if(n < 3){
            
            printf("Enter inventory type: ");
            scanf("%s", type);
            printf("Enter the amount: ");
            scanf("%d", &amt);
        }
        
        if(n == 1)
            addDonation(type, amt);
            
        else if(n == 2)
            addRequest(type, amt);

        else if(n == 3)
            fulfillReq(req_table[0], req_amt[0]);
        
        else if(n == 4)
            printReport();
        else
            return 0;
            
        n = 0;
        
        printf("\n\nWelcome to the Food Bank program!\n1. Add a donation\n2. Add a request\n3. Fulfill a request\n4. Print status report\n5. Exit\n\nEnter your choice: ");
        scanf("%d", &n);
        
    }
    
    printf("Thank you for running the software. Bye for now!\n");
    
    return 0;
}

void printReport(){
    
    //print donations
    printf("Printing the Donations Table\n");
    for(int i=0; i<donations; i++){
        printf("%d ", don_amt[i]);
        int j = 0;
        while(j < 20 && don_table[i][j] != '\0'){
            printf("%c", don_table[i][j]);
            j++;
        }
        printf("\n");
    }
    
    printf("Printing the Requests Table\n");
    //print requests
    for(int i=0; i<requests; i++){
        printf("%d ", req_amt[i]);
        int j = 0;
        while(j < 20 && req_table[i][j] != '\0'){
            printf("%c", req_table[i][j]);
            j++;
        }
        printf("\n");
    }

}


// checks if item is present in table; returns row if present
int present(char s[20], char a){
    for(int i=0; i<100; i++){
        if((a == 'd' && strcmp(s, don_table[i])==0) || (a == 'r' && strcmp(s, req_table[i])==0))
            return i;
    }
    return -1;
}

void cleanDonTable(){
    int i = 0;
    while(i < 100 && don_amt[i] != 0)
        i ++;
    
    for(int j=i; j<99; j++){
        strcpy(don_table[i], don_table[i+1]);
        don_amt[i] = don_amt[i+1];
    }
    
    donations--;
}

void cleanReqTable(){
    
    for(int i=1; i<requests; i++){
        strcpy(req_table[i-1], req_table[i]);
        req_amt[i-1] = req_amt[i];
    }
    
    requests--;
}


void addDonation(char type[20], int amt){
    
    if(present(type, 'd') == -1){
        int i = 0;
        don_amt[donations] = amt;
    
        while(i<20 && type[i] != '\n') {
            don_table[donations][i] = type[i];
            i += 1;
        }
        donations += 1;
    }
    
    else
        don_amt[present(type, 'd')] += amt;
    
    printf("Donation added!\n");
}

void addRequest(char type[20], int amt){
    
    if(present(type, 'r') == -1){
        int i = 0;
        req_amt[requests] = amt;
        
        while(i<20 && type[i] != '\n') {
            req_table[requests][i] = type[i];
            i += 1;
        }
        requests += 1;
    }
    
    else
        req_amt[present(type, 'r')] += amt;
    
    printf("Request added!\n");
}

void fulfillReq(char type[20], int amt){
    int pos = present(type, 'd');
    
    if(pos == -1){
        printf("Cannot be fulfilled.");
        return;
    }
    
    printf("-------- Fulfilling Requests--------");
    
    else {
        if(amt == don_amt[pos]){
            don_amt[pos] = 0;
            for(int i=0; i<20; i++)
                don_table[pos][i] = ' ';
            cleanDonTable();
            cleanReqTable();
            printf("Request fulfilled!");
        }
        else if(amt > don_amt[pos]){
            req_amt[0] -= don_amt[pos];
            don_amt[pos] = 0;
            cleanDonTable();
            printf("Partially fulfilled.");
        }
        else {
            don_amt[pos] -= amt;
            req_amt[0] = ' ';
            cleanReqTable();
            printf("Request fulfilled!");
        }
    }
}

