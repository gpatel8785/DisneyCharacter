#ifndef DISNEYCHARACTER_H
#define DISNEYCHARACTER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct DisneyCharacter 
{
    char name[51];
    char creationDate[11];
    int numMovies;
    char whichPark;
} DisneyCharacter;

DisneyCharacter* createDisneyCharacter(char name[], char creationDate[], int numMovies, char whichPark);
DisneyCharacter* createDisneyCharacterWithDefaults(char name[], char creationDate[]);
void destroyDisneyCharacter(DisneyCharacter* character);
void setName(DisneyCharacter* character, char name[]);
void setCreationDate(DisneyCharacter* character, char creationDate[]);
void setNumMovies(DisneyCharacter* character, int numMovies);
void setWhichPark(DisneyCharacter* character, char whichPark);
void ShowInfo(const DisneyCharacter* character);
int PlaceCharacter(DisneyCharacter* character, char whichPark);
void SameMovies(DisneyCharacter* character1, DisneyCharacter* character2);

#endif
