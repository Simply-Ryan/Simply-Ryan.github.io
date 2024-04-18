// File with different functions I make to practice.
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

/* ------------------------------ UTILITIES ------------------------------ */

/* LINKED LIST / NODE (ARRAY) Dynamically allocate space for anything (string for example). */
typedef struct node
{
    char c;
    struct node* nextNode;
} node;

/* ------------------------------ STRING MANAGEMENT ------------------------------ */

/* Count the number of characters in a string. NULL TERMINATOR NOT INCLUDED! */
unsigned int StringLength(const char* string)
{
    int length = 0;

    // Loop through the string and counting characters unless it is the end.
    while (1)
    {
        if (string[length] == '\0')
        {
            return length;
        }

        length++;
    }
}

/* Return whether a string is an integer in its entirety. TO DO*/
bool StringIsNumber(const char* string)
{
    
}

/* Count the number of times a character occurs in a string. */
unsigned int OccurrenceC(const char* string, const char c)
{
    int occurrence = 0;

    // Loop through the string, counting occurrences
    for (int i = 0, n = StringLength(string); i < n; i++)
    {
        if (string[i] == c)
        {
            occurrence++;
        }
    }

    return occurrence;
}

/* Return whether a character occurs in a given string. */
bool OccursC(const char *string, const char c)
{
    for (int i = 0, n = StringLength(string); i < n; i++)
    {
        if (string[i] == c)
        {
            return true;
        }
    }

    return false;
}

/* Count the number of times a string occurs in another string. RETURNS ONLY 1 & 0. */
int OccurrenceStr(const char* parent, const char* child)
{
    int occurrences = 0;
    bool finding = false;
    
    // Loop through parent
    for (int i = 0; parent[i] != '\0'; i++)
    {
        // If first match, loop through child until no match
        if (parent[i] == child[0])
        {
            finding = true;

            // Loop through child in parallel
            for (int j = 1; finding = true; j++)
            {
                // Next letter in parent (already did next letter in child)
                i++;
                
                if (parent[i] == '\0')
                {
                    // String ended before full match
                    return occurrences;
                }

                // Check whether still match
                if (child[j] != parent[i])
                {
                    finding = false;
                }
                else if (child[j + 1] == '\0')
                {
                    // If the end of child (therefore whole match)
                    occurrences++;
                    finding = false;
                }
            }
        }
    }

    // Return final answer
    return occurrences;
}

/* Return whether a string exists in a parent one. */
bool OccursStr(const char* parent, const char* child)
{
    bool finding = false;
    
    // Loop through parent
    for (int i = 0; parent[i] != '\0'; i++)
    {
        // If first match, loop through child until no match
        if (parent[i] == child[0])
        {
            finding = true;

            // Loop through child in parallel
            for (int j = 1; finding = true; j++)
            {
                // Next letter in parent (already did next letter in child)
                i++;
                
                if (parent[i] == '\0')
                {
                    // String ended before full match
                    return 0;
                }

                // Check whether still match
                if (child[j] != parent[i])
                {
                    finding = false;
                }
                else if (child[j + 1] == '\0')
                {
                    // If the end of child (therefore whole match)
                    return true;
                }
            }
        }
    }

    // For loop broke out at the end, therefore no match
    return false;
}

/* Convert a digit from char to int */
int CharToInt(const char c)
{
    // Return the difference between c and the ASCII of 0
    return c - '0';
}

/* ------------------------------ MATHEMATICS SECTION ------------------------------ */

/* Calculate the missing side using Pythagorus' Theorem. SET UNKNOWN TO 0! */
double PythagoreanTheorem(const int a, const int b, const int c)
{
    if (a == 0)
    {
        return sqrt(c * c - b * b);
    } 
    else if (b == 0)
    {
        return sqrt(c * c - a * a);
    } 
    else
    {
        return sqrt(a * a + b * b);
    }
}

/* Main function: */
int main(void)
{
    printf("Debug: Enter string.\n");
    char* str = malloc(sizeof(char) * 10);
    char* s = "bi";
    scanf("%s", str);

    printf("%d", OccurrenceStr(str, s));
    
    return 0;
}