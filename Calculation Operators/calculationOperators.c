1. Write a program that finds the sum of n numbers entered. Use a while and do-while loop.

#include <stdio.h>

int main ()
{
int n, sum = 0;
printf ("Enter n:");
scanf ("% d", & n);
int array [n];
to {
scanf ("% d", & array [n-1]);
sum + = array [n-1];
n- = 1;
}
while (n> 0);
printf ("Sum =% d", sum);
return 0;
}
2. Write a program that finds the sum of n consecutive numbers until you enter 9.
#include <stdio.h>

int main ()
{
int n, sum = 0;
to {
printf ("Enter number (9 for end):");
scanf ("% d", & n);
sum + = n;
}
while (n! = 9);
sum- = 9;
printf ("Sum =% d", sum);
return 0;
}

3. Write a program to find the sum of consecutive positive numbers. The summation is interrupted by the first negative number entered.
#include <stdio.h>

int main ()
{
int n, sum = 0;
to {
printf ("Enter number (9 for end):");
scanf ("% d", & n);
sum + = n;
}
while (n> = 0);
sum- = n;
printf ("Sum =% d", sum);
return 0;
}

4. Write a program that requires the user to enter an integer, then determine whether it is even or odd.

#include <stdio.h>

int main ()
{
int n;
printf ("Enter number:");
scanf ("% d", & n);
if (n% 2 == 0)
printf ("Even \ n");
else printf ("Odd \ n");
return 0;
}
5. Write a program that enters two integers and finds their sum if both are even; their work - if both are odd; the private - in parity / oddness.

#include <stdio.h>

int main ()
{
int A, B;
printf ("Enter A:");
scanf ("% d", & A);
printf ("Enter B:");
scanf ("% d", & B);

if (A% 2 == 0 && B% 2 == 0)
printf ("Sum =% d", A + B);
else if (A% 2! = 0 && B% 2! = 0)
printf ("Prod =% d", A * B);
else {
if (A <B)
printf ("Quotient =% d", B / A);
else printf ("Quotient =% d", B / A);
}

return 0;
}
6. Write a program that enters a real variable rad - radius of a circle and if rad is ³ 5.5, determines the length of the circle, otherwise it determines its face.

#include <stdio.h>
#define PI 3.141592653589793238462643383
int main ()
{
float work;
printf ("Enter work:");
scanf ("% f", & rad);
if (work> = 5.5)
printf ("P =% f", PI * work);
else printf ("S =% f", PI * rad * rad / 4);

return 0;
}
7. Write a program that finds the largest of the three numbers A, B, and C entered from the keyboard. Assign the largest number to a variable named MAX and print it.
#include <stdio.h>
int main ()
{
int A, B, C, MAX;
printf ("Enter A:");
scanf ("% d", & A);
printf ("Enter B:");
scanf ("% d", & B);
printf ("Enter C:");
scanf ("% d", & C);
if (A> B && A> C) {
MAX = A;
printf ("% d", MAX);
}
if (C> A && C> B) {
MAX = C;
printf ("% d", MAX);
}
if (B> A && B> C) {
MAX = B;
printf ("% d", MAX);
}
return 0;
}

8. Write a program that enters an integer between 1 and 999 and determines whether it is one-digit, two-digit, or three-digit. If the number is out of range, print an error message.
#include <stdio.h>
int main ()
{
int input;
to {
printf ("Enter a number between 1 and 999:");
scanf ("% d", & input);
if (input <1 || input> 999)
printf ("Bad Input \ n");
}
while (input <1 || input> 999);
if (input / 100> 0)
printf ("Three-digit");
else if (input / 10> 0)
printf ("Double digit");
else printf ("Single digit");
return 0;
}
