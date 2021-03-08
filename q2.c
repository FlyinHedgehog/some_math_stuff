
// Theorem: if n+1 integers between 1 and 2n (inclusive) are chosen, the set of chosen
// integers will contain at least one number which divides another member of the same set.

#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int num;
    int oddFactor;
} Number;

int main()
{
    int n, i, j, temp, num1, num2;
    Number *arr = NULL;

    printf("n: ");
    scanf("%d", &n);
    arr = malloc((n + 1) * sizeof(Number));
    printf("enter %d elements between %d-%d: ", n + 1, 1, 2 * n);
    i = 0;
    while(i < n + 1){
        scanf("%d", &temp);
        if(temp < 1 || n > 2 * n){
            printf("please enter a number between 1-%d.\n", n * 2);
            return -1;
        }
        arr[i].num = temp;
        while(temp % 2 == 0)
            temp = temp >> 1;
        arr[i++].oddFactor = temp;
    }

    for(i = 0; i < n + 1; i++){
        for(j = 0; j < n + 1; j++){
            if(arr[i].oddFactor == arr[j].oddFactor && i != j){
                printf("%d %d\n", arr[i].num, arr[j].num);
                return 0;
            }
        }
    }

    return -1;
}