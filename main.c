#include <stdio.h>
#include <stdlib.h>
#include <wiringPi.h>
#define NUM_L 4

void writePin(int pin, bool state){
    digitalWrite(pin, state?HIGH:LOW);
}

int main(){
    wiringPiSetup();
    
    int[] pins = new int[NUM]{8,9,7,0};
    
    for(int i =0;i<NUM;i++)
        pinMode(pins[i], OUTPUT);
    
    char* s[NUM_L], file_name[25];
    int value;
    FILE* fp;
    
    printf("Enter name of a file you wish to see\n");
    fflush(stdout);
    gets(file_name);
    
    fp = fopen(file_name, "r");
    
    if(!fp){
        perror("Error while opening the file.\n");
        exit(EXIT_FAILURE);
    }       
    
    printf("The contents of %s file are:\n", file_name);
    
    fgets(s, NUM, fp);
    
    value = atoi(ch);
    
    var bytevalue = int_to_binary(value, NUM);
    
    printf("%i\nIn byte form\n",i);
    
    for(int i =NUM-1;i>=0;i--){
        printf("%i", bytevalue[i]);
        writePin(pins[i], bytevalue[i]);
    }
    
    printf("Written to pins ");
    
    
    for(int i =NUM-1;i>=0;i--)
        printf("%i", pins[i]);
        
    printf("\n");
}
