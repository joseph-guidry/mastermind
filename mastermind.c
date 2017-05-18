#include <stdio.h>
#include <stdlib.h>

typedef struct guess{
    int boxOne;
    int boxTwo;
    int boxThree;
    int boxFour;
} guess ;

void
getAnswer(struct guess *answer);

int main(void)
{
    struct guess answer;

    getAnswer(&answer);
    printf("%d %d %d %d\n", answer.boxOne, answer.boxTwo, answer.boxThree, answer.boxFour);
    return 0;
}

void
getAnswer(struct guess *answer)
{
    /*
        Generate random numbers and store in answer structure.
    */
    int num = 0;
    num =  random() % 10;
    answer->boxOne = num;
    while((num =  (random() % 10)))
    {
        if (num == answer->boxOne)
            continue;
        else
        {
            answer->boxTwo = num;
        }
    }
    while((num =  (random() % 10)))
    {
        if ((num == answer->boxOne) || (num == answer->boxOne))
            continue;
        else
        {
            answer->boxThree = num;
        }
    }
    while((num =  (random() % 10)))
    {
        if ((num == answer->boxOne) || (num == answer->boxOne) || (num == answer->boxThree) )
            continue;
        else
        {
            answer->boxFour = num;
        }
    }
}
