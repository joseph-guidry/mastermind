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

void
getInput(struct guess *input);
int
makeInt(char letter);

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

void
getInput(struct guess *input)
{
    char c;
    
    printf("Enter a guess of four digits:  ");
    if ( (c = getc(stdin)) != EOF)
    {
        input -> boxOne = makeInt(c);
    }
    if ( (c = getc(stdin)) != EOF)
    {
        input -> boxTwo = makeInt(c);
    }
    if ( (c = getc(stdin)) != EOF)
    {
        input -> boxThree = makeInt(c);
    }
    if ( (c = getc(stdin)) != EOF)
    {
        input -> boxFour = makeInt(c);
    }
    else
    {
        printf("Enter 4 digits please\n");
    }
}

int
makeInt(char letter)
{
    int num = 0;
    num = letter - '0';
    
    return num;
}
