1. A student has received the following grades: 3.5, 4, 5, 3, 4.5. To calculate its success.
#include <stdio.h>
int main ()
{
float array [5] = {3,3.5,4,4.5,5};
float sum = 0;
int i;
for (i = 0; i <5; i ++)
{
    sum = sum + array [i];
}
printf ("average success% f", sum / 5);
return 0;
}
2. Enter the grades for 5 subjects in the program execution mode and display them in reverse order
#include <stdio.h>
int main ()
{
    float grade [5];
int i;
for (i = 0; i <5; i ++)
scanf ("% f", & grade [i]);
for (i = 4; i> = 0; i--)
printf ("% f \ n", grade [i]);
    return 0;
}



3. To find the average success of n exams, n is in the range [1,10]
#include <stdio.h>
int main ()
{
    float a [10], n, sum = 0;
    scanf ("% f", & n);
    for (int i = 0; i <n; i ++)
    {
        printf ("output score");
        scanf ("% f", & a [i]);
        sum = sum + a [i];
    }
    printf ("average success is:% f", sum / n);
    return 0;
}



4. For the upper array - to find the maximum grade and on which exam it was obtained.
#include <stdio.h>
// # include <conio.h>
int main () {
    int n = 0;
    int i;
    int maxIndex = 0;
    while (n <1 || n> 10)
    scanf ("% d", & n);
    float grade [n];
    for (i = 0; i <n; i ++) {
        printf ("grade [% d] =", i);
        scanf ("% f", & grade [i]);
    }
    float maxNumber = grade [0];
    for (i = 1; i <n; i ++)
    {
        if (maxNumber <= grade [i])
            {
                maxNumber = grade [i];
                maxIndex = i;
            }
    }
    printf ("Index% d and Number% f", maxIndex, maxNumber);
    return 0;
}
5. To introduce for the students from one group two arrays: one with the numbers and one with their average success. To calculate the average success of the group and to display the numbers of those students whose success is higher than the average.
#include <stdio.h>
// # include <conio.h>
int main () {
    int n;
    int i;
    float averageScore = 0;
    printf ("Enter Number of Students:");
    scanf ("% d", & n);
    float averageScores [n];
    int studentNumber [n];
    for (i = 0; i <n; i ++) {
        printf ("student Number:");
        scanf ("% d \ n", & studentNumber [i]);
        printf ("Student average Score:");
        scanf ("% f", & averageScores [i]);
        averageScore = averageScore + averageScores [i];
    }
    averageScore = averageScore / n;
    for (i = 0; i <n; i ++)
    {
        if (averageScores [i]> averageScores)
            {
                printf ("Students with score over average: \ n");
                printf ("% d \ n", studentNumber [i]);
            }
    }
    return 0;
}
6. Enter 10 numbers. To determine and display on the screen the even among them and the serial number when entering them.
#include <stdio.h>
// # include <conio.h>
int main () {
     int i;
     int entryNumbers [10];
    for (i = 0; i <10; i ++)
    {printf ("Number [% d] =", i + 1);
    scanf ("% d", & entryNumbers [i]);
      }
    for (i = 1; i <10; i ++)
    {
        if (entryNumbers [i]% 2 == 0)
            {
                printf ("% d-th entered number is even \ n", i + 1);
            }
    }
    return 0;
}
7. Enter 10 integers in array A. The array is viewed as negative, starting at its end, and the negative numbers encountered are recorded in array B.
#include <stdio.h>
#include <conio.h>
void main ()
{
int A [10];
int i, j, counter = 0;
int indexForB = 0, numberOfNegatives = 0;
for (i = 0; i <10; i ++) {
    printf ("A [% d] =", i);
    scanf ("% d", & A [i]);
    if (A [i] <0)
    numberOfNegatives ++;
}
int B [numberOfNegatives];
  for (i = 9; i> -1; i--)
          if (A [i] <0)
           {B [indexForB] = A [i];
           indexForB + = 1;}
for (i = 0; i <indexForB; i ++)
 printf ("\ nb [% d] =% d", i, B [i]);
  }
8. A one-dimensional array A with n elements, 5=n=15 is given. Find the sum of the maximum and minimum element and if this sum is greater than the arithmetic mean, replace the maximum and minimum element with the arithmetic mean.
#include <stdio.h>
void main () {
    int n, i;
    to {
        scanf ("% d", & n);
    }
    while (n <5 || n> 15);
    float array [n];
    float averageNumber = 0;
    for (i = 0; i <n; i ++)
        scanf ("% f", & array [i]);
    float maxNumber = array [0], minNumber = array [0];
    for (i = 1; i <n; i ++) {
        if (maxNumber <= array [i]) {
                maxNumber = array [i];
            }
        if (minNumber> = array [i]) {
                minNumber = array [i];
        }
        averageNumber = averageNumber + array [i];
    }
    averageNumber = averageNumber / n;
    float sumMinMax = maxNumber + minNumber;
    if (averageNumber> sumMinMax) {
        maxNumber = averageNumber;
        minNumber = averageNumber;
    }
    printf ("Average number is:% f, with Max number being:% f and minimal number equals:% f", averageNumber, maxNumber, minNumber);
}
9. A one-dimensional array A with n elements, 5=n=15 is given. To exchange the places of the first with the last element, of the second with the penultimate, etc.
#include <stdio.h>
void main () {
    int n, i, switcher;
   // do {
        scanf ("% d", & n);
    //}
    // while (n <5 && n> 15);
    float array [n];
    for (i = 0; i <n; i ++)
        scanf ("% f", & array [i]);
    for (i = 0; i <n / 2; i ++) {
        switcher = array [i];
        array [i] = array [n-i-1];
        array [n-i-1] = switcher;
    }
   for (i = 0; i <n; i ++)
        printf ("New Array [% d] Arrangement =% f \ n", i, array [i]);
}
10.A one-dimensional array A with n elements, 3=n=25 is given. Find the number of elements whose values ??are multiples of their index.
#include <stdio.h>
void main () {
    int n, i, switcher;
   // do {
        scanf ("% d", & n);
    //}
    // while (n <3 && n> 15);
    int array [n];
    int counter = 0;
    for (i = 0; i <n; i ++) {
        scanf ("% d", & array [i]);
        if (array [i]% (i + 1) == 0)
         counter ++;
        }
    printf ("Number of numbers, divisible by their index:% d \ n", counter);
}
11. A one-dimensional array A with n elements, 3=n=25 and number k is given. Check and if k is greater than the sum of all elements to change the array, increasing each element by k. Otherwise change as the negative elements become -1, the positive ones become 1, and the zero ones do not change.
#include <stdio.h>
void main () {
    int n, i, switcher, k;
   // do {
        scanf ("% d", & n);
    //}
    // while (n <3 && n> 15);
    int A [n];
    int sum = 0;
    for (i = 0; i <n; i ++) {
        printf ("A [% d] =", i);
        scanf ("% d", & A [i]);
        sum = sum + A [i];
    }
    scanf ("% d", & k);
    if (k> sum) {
        for (i = 0; i <n; i ++)
            A [i] = A [i] + k;
    }
    else if (k <sum) {
               for (i = 0; i <n; i ++)
                    if (A [i] <0)
                        A [i] = - 1;
                    else if (A [i]> 0)
                        A [i] = 1;
                    else A [i] = 0;
        }
    for (i = 0; i <n; i ++) {
            printf ("\ n New Array element [% d] =% d", i, A [i]);
        }
}

12. A one-dimensional array A with n elements, 3=n=25 is given. To "thicken" the array by removing the elements with zero value.
#include <stdio.h>
void main () {
    int n, i;
   // do {
        scanf ("% d", & n);
    //}
    // while (n <3 && n> 15);
    int A [n];
    int nonZeroVariables = 0;
    int indexForNewA = 0;
    for (i = 0; i <n; i ++) {
        printf ("A [% d] =", i);
        scanf ("% d", & A [i]);
        if (A [i]! = 0)
        nonZeroVariables ++;
    }
    int NewA [nonZeroVariables];
    for (i = 0; i <n; i ++)
        if (A [i]! = 0) {
            NewA [indexForNewA] = A [i];
            indexForNewA ++;
        }
    for (i = 0; i <nonZeroVariables; i ++)
        printf ("Non-zero Element [% d] =% d \ n", i, NewA [i]);
}
