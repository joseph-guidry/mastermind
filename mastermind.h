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
whiteCompare(struct guess *answer, int box, int white);
void
structureCopy(struct guess *temp, struct guess *answer);

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
    if ( (c = fgetc(stdin)) != EOF)
    {
        input -> boxOne = makeInt(c);
    }
    if ( (c = fgetc(stdin)) != EOF)
    {
        input -> boxTwo = makeInt(c);
    }
    if ( (c = fgetc(stdin)) != EOF)
    {
        input -> boxThree = makeInt(c);
    }
    if ( (c = fgetc(stdin)) != EOF)
    {
        input -> boxFour = makeInt(c);
    }
    while((c = fgetc(stdin)) != '\n')
    {
        c = getc(stdin);
        c = 0;
    }
}
int
makeInt(char letter)
{
    int num = 0;
    num = letter - '0';
    
    return num;
}
void
structureCopy(struct guess *temp, struct guess *answer)
{
    //struct guess temp;
    temp -> boxOne = answer -> boxOne;
    temp -> boxTwo = answer -> boxTwo;
    temp -> boxThree = answer -> boxThree;
    temp -> boxFour =  answer -> boxFour;
    
    
}
int 
getWhiteValue(struct guess *answer, struct guess *input)
{
    int white = 0;
    white += whiteCompare(answer, input -> boxOne, white);
    white += whiteCompare(answer, input -> boxTwo, white);
    white += whiteCompare(answer, input -> boxThree, white);
    white = whiteCompare(answer, input -> boxFour, white);
    
    return white;
}
int
whiteCompare(struct guess *answer, int box, int white)
{
    //static int white = 0;
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
        answer -> boxOne = 100;
        red++;
    }
    if (answer -> boxTwo == input -> boxTwo)
    {
        answer -> boxTwo = 100;
        red++;
    }
    if (answer -> boxThree == input -> boxThree)
    {
        answer -> boxThree = 100;
        red++;
    }
    if (answer -> boxFour == input -> boxFour)
    {
        answer -> boxFour = 100;
        red++;
    }
    
    return red;
}
