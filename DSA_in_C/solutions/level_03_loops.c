#include <stdio.h>

int main() {
    int n;
    
    printf("Enter a positive number N: ");
    scanf("%d", &n);

    // Write a for loop here to print numbers from 1 to N!
    for(int i=1; i<=n; i++){
        printf("%d\n", i);
    }
    return 0;
}