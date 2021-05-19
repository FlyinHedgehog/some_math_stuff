
// Theorem: Let y1 and y2 are relatively prime numbers.
//           z = x1 (mod y1),   z = x2 (mod y2);
// No mather what x1 and x2 are, there is a number (z)
// that satisfies these conditions.

#include <stdio.h>

int main()
{
    int num1, num2, rem1, rem2, temp;

    printf("x1 (mod y1) - enter x1 and y1 respectively.\n");
    scanf("%d %d", &rem1, &num1);
    printf("x2 (mod y2) - enter x2 and y2 respectively.\n"
           "(y1 and y2 should be relatively prime.)\n");
    scanf("%d %d", &rem2, &num2);

    if(num1 < num2){
        temp = num1;
        num1 = num2;        
        num2 = temp;    //  :(
        temp = rem1;
        rem1 = rem2;
        rem2 = temp;
    }

    while(rem2 % num1 != rem1 || rem2 == 0)
        rem2 += num2;

    printf("%d\n", rem2);

    return 0;
}

