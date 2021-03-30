//Print all integers from the interval (m, n), in the record of which the digit 5 participates.

#include <stdio.h>
int main ()
{
     int m, n, i, g;
     printf ("output m");
     scanf ("% d", & m);
     printf ("print n");
     scanf ("% d", & n);
     to {
     g = m;
to {
i = g% 10;
if (i == 5)
{
printf ("% d \ n", m);
}
g = g / 10;
}
while (g> = 1);
m ++;
}
while (m <= n);
system ("pause");
return 0;
}
