#include <stdio.h>

int* representBook(char bookTitle[], char authorName[], char authorSurname[], short pages, int* resultPtr)
{
    unsigned int memoryPlaceholder[3] = {}; // This is where im gonna store the values
    
    char* bookTitlePtr = &bookTitle[0];
    char authorNameInitial = authorName[0];
    char authorSurnameInitial = authorSurname[0];

    memoryPlaceholder[2] |= (unsigned char)authorNameInitial; // 00000000 00000000 00000000 /occupied/
    memoryPlaceholder[2] |= ((unsigned char)authorSurnameInitial << 8); // 00000000 00000000 /occupied/ /oddupied/
    memoryPlaceholder[2] |= ((unsigned short)pages << 16); // /occupied/ /occupied/ /occupied/ /occupied/

    memoryPlaceholder[0] = *(int*)(&bookTitlePtr);  // First 32 bits
    memoryPlaceholder[1] = *((int*)(&bookTitlePtr) + 1);

    resultPtr[0] = memoryPlaceholder[0];
    resultPtr[1] = memoryPlaceholder[1];
    resultPtr[2] = memoryPlaceholder[2];

    return resultPtr;
}


int main()
{
    char bookTitle[] = "Jojo's Bizzare Adventure";
    char authorName[] = "Araki";
    char authorSurname[] = "Hirohiko";
    short pages = 5000;

    int memory[3];
    int* randomPtr = memory;

    randomPtr = representBook(bookTitle, authorName, authorSurname, pages, randomPtr);

    char authorInitial = randomPtr[2] & 0xFF;
    char surnameInitial = (randomPtr[2] >> 8) & 0xFF;
    short bookPages = (randomPtr[2] >> 16) & 0xFFFF;
    char* recoveredTitle = *(char**)(&randomPtr[0]);

    printf("Author: %c.%c.; Book: %s; Number of pages: %d;\n",
        authorInitial, surnameInitial, recoveredTitle, bookPages);

    return 0;
}