#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int getResponse(char ip[]){
    int dots=0;

    //length of the ip address:
    int size=strlen(ip);

    //count dots:

    for(int i=0;i<size;i++){
        if(ip[i]=='.'){
            dots++;
        }
    }

    if(dots!=3){
        return 0;
    }

    //check consecutive dots

    for(int i=0;i<size;i++){
        if(ip[i]=='.' && ip[i+1]=='.'){
            return 0;
        }
    }

    // if the code executes the upper segments correctly 
    // then it means we have exactly 3 dots and ther's no 
    // consecutive dots. 3 dots means there will be 4 numbers exactly

    //Now split the string by dots (exactly four segments):

    int segments[4] = {0}; // Array to store the four integer segments
    int currentIndex = 0;  // Index to keep track of the current segment
    int currentNumber = 0; // Variable to construct the current segment's value

    for (int i = 0; i<size; i++) {
        if (ip[i] == '.') {
            segments[currentIndex++] = currentNumber;
            currentNumber = 0;
        } else if (ip[i] >= '0' && ip[i] <= '9') {
            currentNumber = currentNumber * 10 + (ip[i] - '0');
        } else {
            return 0; 
        }
    }


    // check numbers if they are within the range of 0-255;
    for(int i=0;i<4;i++){
        if(segments[i]<0 || segments[i]>255){
            return 0;
        }
    }

    return 1;
}


void checkIP(char ip[]){
    int response=getResponse(ip);

    if(response==1){
        printf("%s is a Valid ip address\n",ip);
    }else{
        printf("%s is an invalid ip address\n",ip);
    }
}

int main(int argc, char const *argv[]) {

    char ip1[]="128.0.0.1";
    char ip2[]="256.0.0.1";
    char ip3[]="128.0.0.3.2";
    char ip4[]="256.0.0..2";
    char ip5[]="a.b.c.d";
    

    checkIP(ip1);
    checkIP(ip2);
    checkIP(ip3);
    checkIP(ip4);
    checkIP(ip5);
    
}


