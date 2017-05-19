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

    return 0;
}
