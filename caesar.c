# include <stdio.h>
# include <cs50.h>
# include <string.h>
# include <stdlib.h>
# include <ctype.h>


int variable_number(int);
string get_words();
void encording(int);




int main(int argc, string argv[])
{


// checking for predictable error
// number of variable in the command line

    if (variable_number(argc) == 1)
    {
        printf("\n\nError - invalid numbers of variables ..\n\n");
        return 1;
    }

// access the key from the command line
// manipulation below avoids segementaton fault

    char *Cpkey = argv[1];
    char Ckey = * Cpkey;


    int  n = isdigit(Ckey);
    int  key = atoi(& Ckey);

// check that the key is an integer value

    if (atoi(argv[1]) != atof(argv[1]))
    {
        printf("\nError - key must must be an integer and not a float ..\n\n");
        return 1;
    }


// check key is not a float variable.
    else if (isdigit(Ckey) == 0)
    {
       printf ("\nError - key should must be an integer and not a char...\n\n");
       return 1;
    }

    else
    {
        encording(key);
        return 0;
    }

    printf("\n\n");

}




//  verifying the command line has 2 input value
// catching command line errors

int variable_number(argc)
{

    if (argc == 2)
    {
        return 0;
    }
    else
    {
        return 1;
    }

}


// key affects only alphabets character only
// case sensitive.


void encording(key)
{
    string s = get_string("\nplaintext :");
    printf("\nciphertext:");


    for (int i = 0, n = strlen(s); i < n; i++)
    {

        if (s[i] >= 'A' && s[i] <= 'Z')
        {

// circle round from Z back to A

            int value = 65 + ((s[i] - 65 + key) % 26) ;
            printf("%c", (char) value);

        }

        else if (s[i] >= 'a' && s[i] <= 'z')
        {

// circle round from z back to z

            int value = 97 + ((s[i] - 97 + key) % 26);
            printf("%c", (char) value);

        }

        else
        {
            printf("%c", s[i]);
        }
    }

    printf("\n\n");
}