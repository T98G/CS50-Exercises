#include <cs50.h>
#include <stdio.h>

int get_start_size(void);
int get_end_size(int start);
int calculate_years(int start, int end);

int main(void)
{
    int start;
    int end;
    int years;

    start = get_start_size();

    end = get_end_size(start);

    years = calculate_years(start, end);

    printf("Years: %i\n", years);

}

int get_start_size(void)
{
    int start;

    do
    {
        start = get_int("Start size: ");
    }
    while (start < 9);

    return start;

}

int get_end_size(int start)
{
    int end;

    do
    {
        end = get_int("End size: ");
    }
    while (end < 9 || end < start);

    return end;

}

int calculate_years(int start, int end)
{

    int n = start;
    int years = 0;

    do
    {
        n = n + (n / 3) - (n / 4);
        years += 1;
    }
    while (n < end);

    if (start == end)
    {
        return 0;
    }

    return years;
}
