#include<cs50.h>
#include<stdio.h>
#include<math.h>

float Get_owed();


int main(void)
{

    float dollars = Get_owed();
    int cents = round(dollars * 100);
    int coins[] = {25, 10, 5, 1}; // Storing the coins values as an array
    int i = 0;
    int change = 0;

    while (cents > 0)
    {
        while (cents >= coins[i]) //takes the largest coin
        {
            cents = cents - coins[i];
            change += 1;
        }
        i++;

    }

    printf("%i\n", change);

}

float Get_owed()
{
    float owed;

    do
    {
        owed = get_float("Change owed: ");
    }
    while (owed < 0);

    return owed;
}

