#include<cs50.h>
#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<math.h>

int main(void)
{
    string text = get_string("Text: ");

    int letters_count = 0;
    int words_count = 0;
    int sentences_count = 0;

    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (isalpha(text[i]))
        {
            letters_count += 1; //counting letters
        }

        if (isspace(text[i]))
        {
            words_count += 1; // counting words
        }

        if (text[i] == '.' || text[i] == '?' || text[i] == '!')
        {
            sentences_count += 1; // counting sentences
        }

    }

    float L = letters_count / (float)(words_count + 1) * 100; // calculating the average of letters per 100 words
    float S = sentences_count / (float) words_count * 100; // calculating the average of words per 100 sentences
    int index = round(0.0588 * L - 0.296 * S - 15.8); // calculating Coleman-Lieu index

    if (index < 1)
    {
        printf("Before Grade 1\n");
    }

    else if (index >= 16)
    {
        printf("Grade 16+\n");
    }

    else
    {
        printf("Grade %i\n", index);
    }

}

