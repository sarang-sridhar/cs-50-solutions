 #include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>


int main(void)
{
    
    string text = get_string("Text: \n");
    float letters = 0;
    float words = 0;
    float sentence = 0;


    for (int i = 0, n = strlen(text); i < n; i++)
    {
        //letters
        if (isalpha(text[i]))
        {
            letters++;
        }
        //words
        else if (text[i] == 32 && (text[i - 1] != 33 && text[i - 1] != 46 && text[i - 1] != 63)) //counts those spaces wgich aren't immediately preceded by a !(33) or .(46) or ?(63)
        {
            words++;
        }
        //sentences
        else if (text[i] == 33 || text[i] == 46 || text[i] == 63)
        {
            sentence++;
            words++; //counts those words that end a sentence ie the ones followed by a !(33) or .(46) or ?(63)
        }
    }



// using formula and outputting result


    float L = letters * 100 / words;
    float S = sentence * 100 / words;
    
    float index = round(0.0588 * L - 0.296 * S - 15.8);

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
        printf("Grade %i\n", (int) index);
    }
}
