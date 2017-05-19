#include <stdio.h>
#include <stdlib.h>
#include "mastermind.h"

int
playGame(struct guess *answer, struct guess *input);
int
getInput(struct guess *input, int f_present, FILE *pmm);

int main(void)
{
    struct guess answer, input;
    int guess = 0;
    /* Generate Random Answer */
    openMM(&answer);
    //getAnswer(&answer);
    printf("%d %d %d %d\n", answer.boxOne, answer.boxTwo, answer.boxThree,
            answer.boxFour);
    while(1)
    {
        /* Get user guess */
        printf("Enter a guess of four digits:  ");
        if (getInput(&input, 0, stdin))
        {
            printf("Invalid entry for input\n");
            continue;
        }
        printf("%d %d %d %d\n", input.boxOne, input.boxTwo, input.boxThree,         
                input.boxFour);
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
