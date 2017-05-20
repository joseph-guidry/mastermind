#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Guess{
    int boxOne;
    int boxTwo;
    int boxThree;
    int boxFour;
} Guess ; 

/* Prototypes */
int
playGame(struct Guess *answer, struct Guess *input);
void
getAnswer(struct Guess *answer);
int
getInput(struct Guess *input, int f_present, FILE *pmm);
int
makeInt(char letter);
int
redCompare(struct Guess *answer, struct Guess *input);
int
getWhiteValue(struct Guess *answer, struct Guess *input);
int
whiteCompare(struct Guess *answer, int box, int white);
void
structureCopy(struct Guess *temp, struct Guess *answer);
void
openMM(struct Guess *answer);
//
//Function Definitions
//
int
playGame(struct Guess *answer, struct Guess *input)
{
    struct Guess temp, *ptemp;
    ptemp = &temp;
    structureCopy(ptemp, answer);
    
    int allRed;
    allRed = redCompare(&temp, input);
    printf("Red = %d|",allRed);
    printf("White = %d|\n", getWhiteValue(&temp, input));
    return (allRed == 4 ? 1 : 0);

}
void
getAnswer(struct Guess *answer)
{
    /*
        Generate random numbers and store in answer structure.
    */
    
    int num = 0;
    srand(time(NULL));
    
    num =  random() % 9;
    answer->boxOne = num;
    
    while((num = (random() % 9)))
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
        if ((num == answer->boxOne) || (num == answer->boxTwo))
        {
            continue;
        }
        else
        {
            answer->boxThree = num;
        }
    }
    while((num =  (random() % 8)))
    {
        if ((num == answer->boxOne) || (num == answer->boxTwo) )
        {
            continue;
        }
        else
        {
            answer->boxFour = num + 1 ;
        }
    }
}
void openMM(struct Guess *answer)
//Attempt to access .mm file, if in current working directory.
{
    FILE *pmm;
    
    if((pmm = fopen(".mm", "r")) == NULL)
    {
        getAnswer(answer);
    }
    else
    {
        getInput(answer, 1, pmm);
    }
}
int
getInput(struct Guess *input, int f_present, FILE *pmm)
{
    // Get input a single character at a time. Skip bad input 
    FILE *pinput;
    
    char c;
    int skip = 0;
    
    pinput = stdin;
    
    if (f_present)
    {
        pinput = pmm;
        printf("A SECRET file has been used. Press any key to continue...");
    }
    
    if ( (c = fgetc(pinput)) != EOF)
    {
        if ((c == '\n') )  // If input is less than 4 
        {
            return 1;
        }
        if ((c < '0') || (c > '9'))
        {
            skip = 1;      // Identify if input is valid.
        }
        else
        {
            input -> boxOne = makeInt(c);
        }
    }
    if ( (c = fgetc(pinput)) != EOF)
    {
        if ((c == '\n') )  // If input is less than 4 
        {
            return 1;
        }
        if ((c < '0') && (c > '9'))
        {
            skip = 1;      // Identify if input is valid.
        }
        else   
        {
            input -> boxTwo = makeInt(c);
        }    
    }
    if ( (c = fgetc(pinput)) != EOF)
    {
        if ((c == '\n') )  // If input is less than 4 
        {
            return 1;
        }
        if ((c < '0') && (c > '9'))
        {
            skip = 1;      // Identify if input is valid.
        }
        else 
        {
            input -> boxThree = makeInt(c);
        }
    }
    if ( (c = fgetc(pinput)) != EOF)
    {
        if ((c == '\n') )  // If input is less than 4 
        {
            return 1;
        }
        if ((c < '0') && (c > '9'))
        {
            skip = 1;      // Identify if input is valid.
        }
        else 
        {
            input -> boxFour = makeInt(c);
        }
    }
    // Drop all characters after 4 digits.
    while ((c = fgetc(stdin)) != '\n')
    {
        skip = 1;  //Signal to empty stream buffer.
    }
    return skip;
}
int
makeInt(char letter)
//Convert input characters into integers.
{
    int num = 0;
    num = letter - '0';
    
    return num;
}
void
structureCopy(struct Guess *temp, struct Guess *answer)
//Copy values into a temp structure.
{
    temp -> boxOne = answer -> boxOne;
    temp -> boxTwo = answer -> boxTwo;
    temp -> boxThree = answer -> boxThree;
    temp -> boxFour =  answer -> boxFour;
}
int 
getWhiteValue(struct Guess *answer, struct Guess *input)
//Determine if values match to get white token. 
{
    int white = 0;
    
    white = whiteCompare(answer, input -> boxOne, white);
    
    if (input -> boxTwo != input -> boxOne)
    {
    white = whiteCompare(answer, input -> boxTwo, white);
    }
    
    if ((input -> boxThree != input -> boxTwo) && (input -> boxThree != input -> boxOne))
    {
    white = whiteCompare(answer, input -> boxThree, white);
    }
    
    if ( (input -> boxFour != input -> boxThree) && (input -> boxFour != input -> boxTwo) && (input -> boxFour != input -> boxOne))
    {
    white = whiteCompare(answer, input -> boxFour, white);
    }
    
    return white;
}

int
whiteCompare(struct Guess *answer, int box, int white)
// Determines the amount of white tokens.  Evaluating each guess number against answer.
{
    if (box == answer -> boxOne )
    {
        white++;
        //answer->boxOne = 10;
    }
    if (box == answer -> boxTwo && ((answer -> boxTwo) != ( answer -> boxOne)) )
    {
        white++;
        //answer->boxTwo = 10;
    }
    if (box == answer -> boxThree && 
       ((answer -> boxTwo != answer -> boxThree) && (answer -> boxOne != answer -> boxThree)))
    {
        white++;
        //answer->boxThree = 10;
    }
    if ((box == answer -> boxFour) &&
       
       ((answer -> boxThree != answer -> boxFour) && (answer -> boxTwo != answer -> boxFour) 
        && (answer -> boxOne != answer -> boxFour)))
    {
        white++;
    }
    
    return white;
}
int
redCompare(struct Guess *answer, struct Guess *input)
// Determines the red tokens. 
{
    int red = 0; 
    
    if (answer -> boxOne == input -> boxOne)
    {
        answer -> boxOne = 10;
        red++;
    }
    if (answer -> boxTwo == input -> boxTwo)
    {
        answer -> boxTwo = 10;
        red++;
    }
    if (answer -> boxThree == input -> boxThree)
    {
        answer -> boxThree = 10;
        red++;
    }
    if (answer -> boxFour == input -> boxFour)
    {
        answer -> boxFour = 10;
        red++;
    }
    
    return red;
}
