#include <stdio.h>
#include <stdlib.h>

#include "mastermind.h"

int main(void)
{
    struct Guess answer, input;
    int guess = 0;
    printf("\n%45s\n\n\n", "Welcome to Mastermind");
    /* Generate Random Answer */
    openMM(&answer);
    while(1)
    {
        /* Get user guess */
        printf("\nEnter a guess of four digits:  ");
        if (getInput(&input, 0, stdin))
        {
            printf("Invalid entry for input\n");
            continue;
        }
        guess++;
        /* If correct answer is returned, game ends */
        if (playGame(&answer, &input))
        {
            printf("You guess it in %d %s.\n", guess, guess == 1 ? "turn" : "turns");
        }
    }
    return 0;
}
