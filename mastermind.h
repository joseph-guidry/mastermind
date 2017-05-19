#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct guess{
    int boxOne;
    int boxTwo;
    int boxThree;
    int boxFour;
} guess ; 

/* Prototypes */
int
playGame(struct guess *answer, struct guess *input);
void
getAnswer(struct guess *answer);
int
getInput(struct guess *input, int f_present, FILE *pmm);
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
openMM(struct guess *answer);
//
//Function Definitions
//
int
playGame(struct guess *answer, struct guess *input)
{
    struct guess temp, *ptemp;
    ptemp = &temp;
    structureCopy(ptemp, answer);
    
    int allRed;
    allRed = redCompare(&temp, input);
    printf("Red = %d|",allRed);
    printf("White = %d|\n", getWhiteValue(&temp, input));
    return (allRed == 4 ? 1 : 0);

}
void
getAnswer(struct guess *answer)
{
    /*
        Generate random numbers and store in answer structure.
    */
    
    int num = 0;
    srand(time(NULL));
    num =  random() % 9;
    
    answer->boxOne = num;
    while((num =  (random() % 9)))
    {
        if (num == answer->boxOne)
            continue;
        else
        {
            answer->boxTwo = num;
        }
    }
    while((num =  (random() % 9)))
    {
        if ((num == answer->boxOne) || (num == answer->boxOne))
            continue;
        else
        {
            answer->boxThree = num;
        }
    }
    while((num =  (random() % 9)))
    {
        if ((num == answer->boxOne) || (num == answer->boxOne) || (num == answer->boxThree) )
            continue;
        else
        {
            answer->boxFour = num;
        }
    }
}

void openMM(struct guess *answer)
{
    FILE *pmm;
    
    if((pmm = fopen(".mm", "r")) == NULL)
    {
        //printf(".MM is not present\n");
        getAnswer(answer);
    }
    else
    {
        //printf(".MM is present\n");
        getInput(answer, 1, pmm);
    }
}

int
getInput(struct guess *input, int f_present, FILE *pmm)
{
    // Get input a single character at a time. Skip bad input 
    FILE *pinput;
    
    char c;
    int skip = 0;
    
    pinput = stdin;
    
    if (f_present)
    {
        pinput = pmm;
        printf("Secret file has been used. Press any key to continue...");
    }
    
    
    //printf("Enter a guess of four digits:  ");
    if ( (c = fgetc(pinput)) != EOF)
    {
        if (c == '\n')
        {
            return 1;
        }
        if ((c < '0') || (c > '9'))
        {
            skip = 1;
        }
        else
        {
            input -> boxOne = makeInt(c);
        }
    }
    if ( (c = fgetc(pinput)) != EOF)
    {
        if (c == '\n')
        {
            return 1;
        }
        if ((c < '0') && (c > '9'))
        {
            skip = 1;
        }
        else   
        {
            input -> boxTwo = makeInt(c);
        }    
    }
    if ( (c = fgetc(pinput)) != EOF)
    {
        if (c == '\n')
        {
            return 1;
        }
        if ((c < '0') && (c > '9'))
        {
            skip = 1;
        }
         else 
        {
            input -> boxThree = makeInt(c);
        }
    }
    if ( (c = fgetc(pinput)) != EOF)
    {
        if (c == '\n')
        {
            return 1;
        }
        if ((c < '0') && (c > '9'))
        {
            skip = 1;
        }
        else 
        {
            input -> boxFour = makeInt(c);
        }
    }
    
    // Drop all characters after 4 digits.
    while ((c = fgetc(stdin)) != '\n')
    {
        skip = 1;
        
    }
    return skip;
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
    temp -> boxOne = answer -> boxOne;
    temp -> boxTwo = answer -> boxTwo;
    temp -> boxThree = answer -> boxThree;
    temp -> boxFour =  answer -> boxFour;
}
int 
getWhiteValue(struct guess *answer, struct guess *input)
{
    int white = 0;
    
    white = whiteCompare(answer, input -> boxOne, white);
    //printf("in boxOne: %d \n", white);
    
    if (input -> boxTwo != input -> boxOne)
    {
    white = whiteCompare(answer, input -> boxTwo, white);
    //printf("in boxTwo: %d \n", white);
    }
    
    if ((input -> boxThree != input -> boxTwo) && (input -> boxThree != input -> boxOne))
    {
    white = whiteCompare(answer, input -> boxThree, white);
    //printf("in boxThree: %d \n", white);
    }
    
    if ( (input -> boxFour != input -> boxThree) && (input -> boxFour != input -> boxTwo) && (input -> boxFour != input -> boxOne))
    {
    white = whiteCompare(answer, input -> boxFour, white);
    //printf("in boxFour: %d \n", white);
    }
    
    return white;
}

int
whiteCompare(struct guess *answer, int box, int white)
{
    if (box == answer -> boxOne )
    {
        white++;
        answer->boxOne = 100;
        //printf("Answer One %d White = %d \n", answer->boxOne, white);
    }
    if (box == answer -> boxTwo && ((answer -> boxTwo) != ( answer -> boxOne)) )
    {
        white++;
        //printf("Answer Two White = %d \n", white);
        answer->boxTwo = 100;
    }
    if (box == answer -> boxThree && 
       ((answer -> boxTwo != answer -> boxThree) && (answer -> boxOne != answer -> boxThree)))
    {
        white++;
        //printf("Answer Three White = %d \n", white);
        answer->boxThree = 100;
    }
    if ((box == answer -> boxFour) && 
       ((answer -> boxThree != answer -> boxFour) && (answer -> boxTwo != answer -> boxFour) 
         && (answer -> boxOne != answer -> boxFour)))
    {
        white++;
        //printf("Answer Four White = %d \n", white);
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
