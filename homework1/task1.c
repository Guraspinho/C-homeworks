#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

char** generateRandomText(char *wordsA[], char *wordsB[], char expression[], char** answer, int sizeOfA, int sizeOfB)
{
    char* answerArray[100000] = {}; // This is not a good practice but still...
    int index = 0;
    int expressionLength = strlen(expression);

    for (int i = 1; i < expressionLength; i += 3)
    {
        if(expression[i] == 'A')
        {
            // A random number betweem 0 and length of array A
            int randomIndexForA = rand() % sizeOfA; 
            answerArray[index] = wordsA[randomIndexForA];
        }
        else
        {
            // A random number betweem 0 and length of array B
            int randomIndexForB = rand() % sizeOfB;
            answerArray[index] = wordsB[randomIndexForB];
        }
        index++;
    }
    answer = &answerArray[0];
    return answer;
}

int main()
{
    srand(time(NULL));  // Seed the random number generator with the current time

    char *wordsA[] = {"Majula", "Huntsman's copse", "Iron Keep", "Drangelic Castle", "Dragon Aerie", "The Lost Bastille"};
    char *wordsB[] = {"Rust", "C++", "Java", "TypeScript", "C#", "Python", "Go", "Ruby", "Kotlin", "PHP"};

    char* result;
    char** resultPtr = &result;

    char expression[] = "<A><A><B><A><B><A><A><B><A><B><A><B><B><B>";

    int sizeOfA = sizeof(wordsA) / sizeof(wordsA[0]);
    int sizeOfB = sizeof(wordsB) / sizeof(wordsB[0]);

    resultPtr = generateRandomText(wordsA, wordsB, expression, resultPtr,  sizeOfA, sizeOfB);
    int expressionLength = strlen(expression);

    for(int i = 0; i < expressionLength / 3; i++) {
        printf("%s, ", resultPtr[i]);
    }

    return 0;
}


