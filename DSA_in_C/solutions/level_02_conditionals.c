#include <stdio.h>

int main() {
    int number;
    
    printf("Enter a number: ");
    scanf("%d", &number);

    // Write your if / else logic here to check if 'number' is positive, negative, or zero!
    if(number>0){
        printf("Positive");
    }
    else if(number<0){
        printf("Negative");
    }
    else{printf("Zero");}

    return 0;
}
