//1. To write a program in which strings are introduced. The strings should be stored in dynamically allocated memory, and the addresses of the dynamic memory should be stored in an array of directories. The task to be realized through functions.
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;
char * dm (char * str)
{
len = strlen (str);
char * p = (char *) malloc (sizeof (char) * (len + 1));
if (p == NULL)
return NULL;
strcpy_s (p, len + 1, p);
return p;
}
int _tmain (int argc, _TCHAR * argv [])
{
char buffer [30];
char * p;
char * city [30];
int i, number, len;
char key = 'y';
i = 0;
while (key! = 'n' && key! = 'N' && i <30)
{
printf ("city name:");
fflush (stdin);
gets_s (buffer, 30);
 city ??[i] = dm (buffer);
i ++;
printf ("to end enter N or n:");
scanf_s ("% c", & key);
}
number = i;
for (i = 0; i <number; i ++)
printf ("% s \ n", city [i]);
for (i = 0; i <number; i ++)
free (city [i]);
return 0;
}

//2. Write a function that receives as a parameter a string containing words separated by a space. The function to transfer to dynamic memory the first word that starts with a capital letter and return the address of dynamic memory. If there is no such word, the function returns NULL.

#include <iostream>
char * func (char * str);
int main ()
{
    char string [30] = "Today bqh for a lesson";
    char * p;
    p = func (string);
    printf ("% s", p);
    free (p);
    return 0;
    
}
char * func (char * str)
{
    char * temp;
    int i, j, pos, br;
    for (i = 0; str [i]; i ++)
        if (str [i]> = 'A' && str [i] <'Z')
    {
        br = 0;
        poz = i;
        while (str [i]! = "" && str [i])
        {
            br ++;
            i ++;
            
        
        }
        break;
    }
        else
            while (str [i]! = "" && str [i])
        {
            i ++;
        }
    temp = ((char *) malloc (br + 1) * sizeof (char));
    for (j = 0; j <br; j ++)
    {
    temp [j] = str [pos];
        pos ++;
    }
    temp [j] = 0;
    return temp;
}


//3. Write a function that receives as a parameter a one-dimensional array of integers. The function to transfer only the elements with even value to a dynamic array and return the dynamic array. In the first position in this array to write the number of its elements.



#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main ()
{
int buffer [5];
int * p;
int * numbers [5];
int even [5];
int i, j, number, len;



for (i = 0; i <5; i ++)
{
printf ("Enter numbers count:");
scanf ("% d", & buffer [i]);

    }
p = (int *) malloc (5 * sizeof (int));


for (j = i = 0; i <5; i ++)
{
if (buffer [i]% 2 == 0)
{
even [j] = buffer [i];
j ++;
}
}
even [0] = j;
number = j;
for (i = number; i> 1; i--)
{
even [i] = even [i - 1];

}
for (i = 0; i <number + 1; i ++)
printf ("% d", even [i]);

number = i;
for (i = 0; i <number; i ++)
free (numbers [i]);

return 0;
}

//4. Write a function that receives as a parameter a structure with fields: first name, middle name, last name. The function to write the three fields of the structure in one dynamic string and return its address.


#include <iostream>

struct fullname
{
    char firstname [20];
    char secondname [20];
    char lastname [20];
}
char * func (struct fullname * s);
int main ()
{
    struct fullname name;
    char * p;
     strcpy (name.firstname, 20, "Spasina");
     strcpy (name.secondname, 20, "Spasina");
     strcpy (name.lasttname, 20, "Spasina");
    
    p = func (& name);
    printf ("% s \ n", p);
    free (p);
    return 0;
}

char * func (struct fullname * s)
{
    int len;
    char * temp;
    len = strlen (s-> firstname) + strlen (s-> secondname) + strlen (s-> lastname);
    temp = (char *) malloc (len * sizeof (char));
    if (temp == NULL)
        return NULL;
    strcpy (temp, len, s-> firstname);
    strcpy (temp, len, "");
    strcpy (temp, len, s-> secondname);
    strcpy (temp, len, "");
    strcpy (temp, len, s-> lastname);
    strcpy (temp, len, "");
    return temp;

}



//5. Write a function that receives as a parameter a string containing the three names of one person, separated by a space. The function dynamically allocates memory for a structure with the fields: first name, middle name, last name, transfers the corresponding names from the string to the fields and returns the dynamic memory address.

#include "pch.h"
#include <iostream>
struct name
{
	char firstName [30];
	char secondName [30];
	char lastName [40];
};
struct name * StructuraName (char * input);
	int Number (char * input, int * i, int len);
	char * AddName (char * input, char * p, int * z, int br);
	int main ()
	{
	char input [100];
	struct name * name;
	printf ("Enter name:");
	gets_s (input, 99);
	name = StructureName (input);
	printf ("% s% s% s", name-> firstName, name-> secondName, name-> lastName);
}
struct name * StructuraName (char * input)
{
	struct name * p;
	int br1, br2, br3, len = strlen (input), i = 0, k = 0, z = 0;
	char * namePart;
	br1 = Number (input, & i, len);
	i ++;
	br2 = Number (input, & i, len);
	i ++;
	br3 = Number (input, & i, len);
	p = (struct name) malloc (sizeof (struct name) br1 + 1);
	namePart = AddName (input, p-> firstName, & z, br1);
	strcpy_s (p-> firstName, br1 + 1, namePart);
	z ++;
	namePart = AddName (input, p-> secondName, & z, br2);
	strcpy_s (p-> secondName, br2 + 1, namePart);
	z ++;
	namePart = AddName (input, p-> lastName, & z, br3);
	strcpy_s (p-> lastName, br3 + 1, namePart);
return p;
}
int Number (char * input, int * i, int len)
{
	int br = 0;
	int l = * i;
	while (input [l]! = '' && l! = len)
	{
	br ++;
	l ++;
	}
	* i = l;
return br;
}
char * AddName (char * input, char * p, int * z, int br)
{
	int k = 0, l = * z;
	while (br! = 0)
	{
	p [k] = input [l];
	br--;
	l ++;
	k ++;
	}
	* z = l;
	p [k] = 0;
return p;
}
