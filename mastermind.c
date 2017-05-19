#include <stdio.h>
#include <stdlib.h>
#include "mastermind.h"

int main(void)
{
    struct guess answer, input;

    getAnswer(&answer);
    printf("%d %d %d %d\n", answer.boxOne, answer.boxTwo, answer.boxThree, answer.boxFour);
    
    getInput(&input);
    printf("%d %d %d %d\n", input.boxOne, input.boxTwo, input.boxThree, input.boxFour);

    
    printf("Red = %d\n", redCompare(&answer, &input));
    printf("white = %d\n", getWhiteValue(&answer, &input));

    return 0;
}
