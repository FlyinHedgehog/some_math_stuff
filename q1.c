
// Theorem: In any set A of n ≥ 2 integers, there is nonempty subset of A whose sumis a multiple of n.

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, i, sum, rem, beg, end, flag, count;
    int *data = NULL;
    int *partialSums = NULL;
    int *rems = NULL;

    printf("n: ");
    scanf("%d", &n);
    data = malloc(n * sizeof(*data));
    partialSums = malloc(n * sizeof(*partialSums));

    sum = 0;
    rems = calloc(n, sizeof(*rems));
    printf("enter the elements: ");
    for(i = 0; i < n; i++){
        scanf("%d", &data[i]);
        sum += data[i];
        partialSums[i] = sum;
        rems[sum % n]++;
    }

    beg = 0;
    end = 0;
    flag = -1;
    count = 0;
    if(rems[0] > 0){
        for(i = 0; i < n; i++){
            if(partialSums[i] % n == 0){
                end = i;
                break;
            }
        }
    }
    else{
        for(i = 0; i < n; i++){
            if(rems[i] > 1){
                flag = i;
                break;
            }
        }
        for(i = 0; i < n; i++){
            if(partialSums[i] % n == flag && count != 2){
                beg = end + 1;
                end = i;
                count++;
            }
        }
    }

    printf("{");
    for(i = beg; i < end; i++)
        printf("%d, ", data[i]);
    printf("%d}\n", data[i]);

    free(data);
    free(partialSums);
    free(rems);

    return 0;
}