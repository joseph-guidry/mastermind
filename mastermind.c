#include <stdio.h>
#include <stdlib.h>
#include "mastermind.h"

int
playGame(struct guess *answer, struct guess *input);

int main(void)
{
    struct guess answer, input;
    int guess = 0;
    /* Generate Random Answer */
    getAnswer(&answer);
    printf("%d %d %d %d\n", answer.boxOne, answer.boxTwo, answer.boxThree, answer.boxFour);
    while(1)
    {
        /* Get user guess */
        getInput(&input);
        printf("%d %d %d %d\n", input.boxOne, input.boxTwo, input.boxThree, input.boxFour);
        guess++;
        
        /* If correct answer is returned, game ends */
        if (playGame(&answer, &input))
        {
            break;
        }
    }
    printf("You guess it in %d %s.\n", guess, guess == 1 ? "turn" : "turns");

    return 0;
}
int
playGame(struct guess *answer, struct guess *input)
{
    struct guess temp, *ptemp;
    ptemp = &temp;
    structureCopy(ptemp, answer);
    
    int allRed;
    allRed = redCompare(&temp, input);
    printf("Red = %d\n",allRed);
    printf("%d %d %d %d\n", answer->boxOne, answer->boxTwo, answer->boxThree, answer->boxFour);
    printf("White = %d\n", getWhiteValue(&temp, input));
    if (allRed == 4)
    {
        return 1;
    }
    else
    {
    
        return 0;
    }

}

