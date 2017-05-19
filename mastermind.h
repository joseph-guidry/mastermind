#include <stdio.h>
#include <stdlib.h>

typedef struct guess{
    int boxOne;
    int boxTwo;
    int boxThree;
    int boxFour;
} guess ; 

/* Prototypes */
void
getAnswer(struct guess *answer);
void
getInput(struct guess *input);
int
makeInt(char letter);
int
redCompare(struct guess *answer, struct guess *input);
int
getWhiteValue(struct guess *answer, struct guess *input);
int
whiteCompare(struct guess *answer, int box);

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

int getWhiteValue(struct guess *answer, struct guess *input)
{
    int white = 0;
    whiteCompare(answer, input -> boxOne);
    whiteCompare(answer, input -> boxTwo);
    whiteCompare(answer, input -> boxThree);
    white = whiteCompare(answer, input -> boxFour);
    
    return white;
}
int
whiteCompare(struct guess *answer, int box)
{
    static int white = 0;
    if (box == answer -> boxOne)
    {
        white++;
    }
    if (box == answer -> boxTwo)
    {
        white++;
    }
    if (box == answer -> boxThree)
    {
        white++;
    }
    if (box == answer -> boxFour)
    {
        white++;
    }
    
    return white;
    
}


int
redCompare(struct guess *answer, struct guess *input)
{
    int red = 0; 
    
    if (answer -> boxOne == input -> boxOne)
    {
        red++;
    }
    if (answer -> boxTwo == input -> boxTwo)
    {
        red++;
    }
    if (answer -> boxThree == input -> boxThree)
    {
        red++;
    }
    if (answer -> boxFour == input -> boxFour)
    {
        red++;
    }
    
    return red;
}
