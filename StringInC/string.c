/*1. Write a function that receives as a parameter a symbol and returns as a result the number of occurrences of this symbol in a string. Write a program that enters a random character string and determines the number of characters: ‘a’, ‘o’ and ‘e’ in it.
2. Write a function that replaces any number of spaces (tabs) with one space in a string. There should be no space in front of the punctuation marks (. And,).
3. Write a function that checks if a string is a palindrome - to be the same even back and forth (for example: beans, calendula ...).
4. Write a function that encodes a string in a new string, starting from the left and alternating taking 1 character from each end (for example: input string - "quarantine"; output string - "kaanriatn").
5. A character string containing words is given. Write a function that generates a string containing all words of length less than a predefined number n.
6. Enter a series of n strings. Write a function that concatenates the elements of this array into a string.
7. An array of n strings is given, each of which contains names of Bulgarian cities. Write a function that converts an array by adding the word "city" to the name of each element.
8. A series of n strings representing integers is given. Write a function that finds the arithmetic mean of the elements of the series. To realize the task in two ways:
- using the atoi function;
- by writing an additional function that converts a string to an integer.
9. To write a program that is a computer version of the game "hangman".*/

//1
#include <stdio.h>
#include <string.h>
void string1(char c, char* string);
int main() {
    char str[1000];
    int bra = 0, bro = 0, brc = 0;
    printf("Vuvedi niza: ");
    fgets(str, sizeof(str), stdin);
    broi(str, bra, bro, brc);
 
}
void string1(char c, char* string)
{
	int count = 0;
	while (*string != 0)
	{
		if (*string == c)
		{
			count++;
		}
		string++;
	}
	return count;
}
printf("Broq na e a = %d\n Broq na o = %d \n Broq na e e = %d",c,count,string);
}





//2

#include <iostream> 
#include<stdio.h> 
void removespace(char* str);
int _tmain(int argc, _TCHAR* argv[])
{
}
void removespace(char* str)
{
	int i, j;
	for (i = j = 0; str[i] != '\0'; ) 
	{
		if (str[i] != ' ')
		{
			str[j] = str[i];
			i++;
			j++;
		}
		else
		{
			while (str[i] == ' ') i++; 
			if (str[i] == '.' || str[i] == ',')
			{
				str[j++] = str[i++];
			}
			else
			{
				str[j++] = ' ';
			}
		}
	}
	str[j] = '\0'; 
}


//3
#include <stdio.h>
#include <string.h>
void polindrom(char* string);
int main()
{
}
void polindrom(char* string)
{
	char* end;
	for (end = string; *end != 0; end++);
	end--; //posleden simvol bez terminirashta 0

	while (string < end)
	{
		if (*string != *end)
		{
			return 0;
		}
		string++;
		end--;
	}
	return 1; //palindrom e
}

//4

void funkciq(char* in, char* out)
{
	char* end;
	for (end = in; *end != 0; end++);
	end--; //posleden simvol bez terminirashta 0

	while (in < end)
	{
		*out = *in;
		out++;
		*out = *end;
		out++;
	}
	if (in == out) //otkriva nechetna sredna bukva, za da ne q kopira vtori put
	{
		*out = *in;
		out++;
	}
	*out = 0;

}

//5
void string(char* in, char* out, int n)
{
	char* start = in; //nachalo na dumata
	while (*in != 0)
	{
		if (*in == ' ')
		{
			if (in - start < n)
			{
				do {
					*out = *start;
					out++;
					start++;
				} while (start != in);

				*out = ' ';
				out++;
			}

			start = in + 1;
		}
		in++;
	}

	if (in - start < n)
	{
		do {
			*out = *start;
			out++;
			start++;
		} while (start != in);
	}
	*out = 0;
}

//6
void konkreten(char z[], char q[]) {
    int x, y;
    x = 0;
    while (z[x] != '\0') {
        x++;
    }
    y = 0;
    while (q[y] != '\0') {
        z[x] = q[y];
        y++;
        x++;
    }
    z[x] = '\0';
}


//7
#include <stdio.h>
#include <string.h>
void str(char[], char[], char[], char[]);
int main() {
}
void str(char series[], char series1[], char series2[], char sseries3[]) {
    printf("Town %s\n", series);
    printf("Town %s\n", series1);
    printf("Town %s\n", series2);
    printf("Town %s\n", series3);
}

//9
#include <stdio.h>
#include <string.h>

int main() {
    char vqrno[1000];
    printf("Vuvedi dumata za poznavane: ");
    fflush(stdout);
    scanf_s(" %s", vqrno);
    int N = strlen(vqrno);
    int z[N];
    for (int i = 0; i < N; ++i) {
        z[i] = 0;
    }
    int krai = 0;
    while (!krai) {
        printf("Dumata e : ");
        for (int j = 0; j < N; ++j) {
            if (z[j]) {
                printf("%c", vqrno[j]);
            }
            else {
                printf("*");
            }
        }
        printf("\n");
        char bukva;
        printf("Sledvashta ");
        fflush(stdout);
        scanf_s(" %c", &bukva);
        for (int k = 0; k < N; ++k) {
            if (vqrno[k] == bukva) {
                z[k] = 1;
            }
        }
        krai = 1;
        for (int m = 0; m < N; ++m) {
            if (!z[m]) {
                krai = 0;
                break;
            }
        }
    }
    printf("Poznahte dumata, koqto e : \"%s\".\n", vqrno);

    return 0;
}

