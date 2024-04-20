#include "DisneyCharacter.h"

int main(void)
{
    char mickeyName[] = "Mickey";
    char mickeyDate[] = "1929-01-01";
    char minnieName[] = "Minnie";
    char minnieDate[] = "1930-01-01";

    DisneyCharacter* mickey = createDisneyCharacter(mickeyName, mickeyDate, 100, 'E');
    DisneyCharacter* minnie = createDisneyCharacter(minnieName, minnieDate, 0, 'N');

    SameMovies(minnie, mickey);

    printf("Mickey's Info:\n");
    ShowInfo(mickey);
    printf("\nMinnie's Info:\n");
    ShowInfo(minnie);

    PlaceCharacter(minnie, 'E');

    destroyDisneyCharacter(mickey);
    destroyDisneyCharacter(minnie);

    return 0;
}
