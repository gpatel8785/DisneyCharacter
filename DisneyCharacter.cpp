/*
* File: DisneyCharacter
* Program: OOP - Assignment 2
* Programmer: Gaurav Patel
* Date: 08/02/2024
* Description: Creates and destroy the disney character objects
*/

#include "DisneyCharacter.h"

/*
* Function: createDisneyCharacter
* Description: Creates a DisneyCharacter object with given data
* Parameters:
*   - name: The name of the Disney character.
*   - creationDate: The creation date of the Disney character in  "YYYY-MM-DD" format.
*   - numMovies: The number of movies.
*   - whichPark: The park where the character can be found.
* Returns: A pointer to the created DisneyCharacter object.
*/
DisneyCharacter* createDisneyCharacter(char name[], char creationDate[], int numMovies, char whichPark) 
{
    DisneyCharacter* character = (DisneyCharacter*)malloc(sizeof(DisneyCharacter));
    if (character != NULL) 
    {
        strncpy_s(character->name, name, 50);
        character->name[50] = '\0';
        strcpy_s(character->creationDate, creationDate);
        character->numMovies = (numMovies >= 0) ? numMovies : 0;
        const char validParks[] = { 'M', 'S', 'A', 'E', 'C', 'N' };
        int i;
        for (i = 0; i < sizeof(validParks); ++i) 
        {
            if (whichPark == validParks[i]) 
            {
                character->whichPark = whichPark;
                break;
            }
        }
        if (i == sizeof(validParks))
            character->whichPark = 'N';
    }
    return character;
}

/*
* Function: createDisneyCharacterWithDefaults
* Description: Creates a DisneyCharacter object with default values for numMovies and whichPark.
* Parameters:
*   - name: The name of the Disney character.
*   - creationDate: The creation date of the Disney character in  "YYYY-MM-DD" format.
* Returns: A pointer to the created DisneyCharacter object.
*/
DisneyCharacter* createDisneyCharacterWithDefaults(char name[], char creationDate[]) 
{
    return createDisneyCharacter(name, creationDate, 0, 'N');
}

/*
* Function: destroyDisneyCharacter
* Description: Destroys the DisneyCharacter object and frees the allocated memory.
* Parameters:
*   - character: A pointer to the DisneyCharacter object to be destroyed.
*/
void destroyDisneyCharacter(DisneyCharacter* character) 
{
    if (character != NULL) 
    {
        printf("%s destroyed.\n", character->name);
        free(character);
    }
}

/*
* Function: setName
* Description: Sets the name of the Disney character.
* Parameters:
*   - character: A pointer to the DisneyCharacter object.
*   - name: The name to be set.
*/
void setName(DisneyCharacter* character, char name[]) 
{
    strncpy_s(character->name, name, 50);
    character->name[50] = '\0';
}

/*
* Function: setCreationDate
* Description: Sets the creation date of the Disney character.
* Parameters:
*   - character: A pointer to the DisneyCharacter object.
*   - creationDate: The creation date to be set in the format "YYYY-MM-DD".
*/
void setCreationDate(DisneyCharacter* character, char creationDate[]) 
{
    strcpy_s(character->creationDate, creationDate);
}

/*
* Function: setNumMovies
* Description: Sets the number of movies the Disney character has been in.
* Parameters:
*   - character: A pointer to the DisneyCharacter object.
*   - numMovies: The number of movies to be set.
*/
void setNumMovies(DisneyCharacter* character, int numMovies) 
{
    character->numMovies = (numMovies >= 0) ? numMovies : character->numMovies;
}

/*
* Function: setWhichPark
* Description: Sets the park where the Disney character can be found.
* Parameters:
*   - character: A pointer to the DisneyCharacter object.
*   - whichPark: The park where the character can be found.
*/
void setWhichPark(DisneyCharacter* character, char whichPark) 
{
    const char validParks[] = { 'M', 'S', 'A', 'E', 'C', 'N' };
    int i;
    for (i = 0; i < sizeof(validParks); ++i) 
    {
        if (whichPark == validParks[i]) 
        {
            character->whichPark = whichPark;
            return;
        }
    }
}

/*
* Function: ShowInfo
* Description: Displays the information of the Disney character.
* Parameters:
*   - character: A pointer to the DisneyCharacter object.
*/
void ShowInfo(const DisneyCharacter* character) 
{
    printf("Name: %s\n", character->name);
    printf("Creation Date: %s\n", character->creationDate);
    printf("Number of Movies: %d\n", character->numMovies);
    printf("Which Park: %c\n", character->whichPark);
}

/*
* Function: PlaceCharacter
* Description: Places the Disney character at a particular park.
* Parameters:
*   - character: A pointer to the DisneyCharacter object.
*   - whichPark: The park where the character can be found.
* Returns: 1 if successful, 0 otherwise.
*/
int PlaceCharacter(DisneyCharacter* character, char whichPark) 
{
    const char validParks[] = { 'M', 'S', 'A', 'E', 'C', 'N' };
    int i;
    for (i = 0; i < sizeof(validParks); ++i) 
    {
        if (whichPark == validParks[i]) 
        {
            character->whichPark = whichPark;
            return 1;
        }
    }
    return 0;
}

/*
* Function: SameMovies
* Description: Sets the number of movies of one Disney character to be the same as another character.
* Parameters:
*   - character1: A pointer to the first DisneyCharacter object.
*   - character2: A pointer to the second DisneyCharacter object.
*/
void SameMovies(DisneyCharacter* character1, DisneyCharacter* character2) 
{
    character1->numMovies = character2->numMovies;
}
