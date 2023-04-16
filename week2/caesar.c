#include<stdlib.h>
#include<stdio.h>
#include<cs50.h>
#include<string.h>
#include<ctype.h>

bool iskeydigit(string key);

int main(int argc, string argv[])
{
    int key;

    if (argc != 2)
    {
        printf("Caeser takes exactly 1 command-line argument but %i were given\n", argc);
        return 1;
    }

    else if (iskeydigit(argv[1]) == false)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    if (argv[1] < 0)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    else
    {
        key = atoi(argv[1]);
    }

    string plaintext = get_string("plaintext: ");

    int textlen = strlen(plaintext);

    printf("ciphertext:");


    for (int i = 0; i < textlen; i++)
    {
        if (isalpha(plaintext[i]))
        {
            if (islower(plaintext[i]))
            {
                //Ciphers and prints lowercase latters
                printf("%c", (char)((int) plaintext[i] - 97 + key) % 26 + 97);
            }

            else if (isupper(plaintext[i]))
            {
                //Ciphers and prints uppercase latters
                printf("%c", (char)((int) plaintext[i] - 65 + key) % 26 + 65);

            }
        }

        else
        {
            printf("%c", plaintext[i]);
        }

    }

    printf("\n");
}

bool iskeydigit(string key)
{
    for (int i = 0, n = strlen(key); i < n; i++)
    {
        if (isdigit(key[i]) == false)
        {
            return false;
        }
    }
    return true;
}

