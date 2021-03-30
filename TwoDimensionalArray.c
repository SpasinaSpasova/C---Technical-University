1. A two-dimensional array A [m, n] is given, where m and n are integers in the interval [3,6]. Enter the values ??of m and n and the elements of the array and find and derive the sum of its elements whose values ??fall in the interval [3,33].
   #include <stdio.h>
 
int main ()
{
   int m, n, c, d, first [10] [10], sum = 0;
 
   printf ("Enter the number of rows and columns of matrix \ n");
   scanf ("% d% d", & m, & n);
   printf ("Enter the elements of first matrix \ n");
   
   if (m <3 || n <3 || m> 6 || n> 6) {
        return;
        }
 
   for (c = 0; c <m; c ++) {
      for (d = 0; d <n; d ++) {
         scanf ("% d", & first [c] [d]);
         if (first [c] [d]> = 3 && first [c] [d] <= 33) {
                        sum + = first [c] [d];
                        }
         }
}
   
   
   printf (sum:% d, sum);
}


2. Write a program that defines a two-dimensional 3x3 array and loads it with the numbers from 1 to 9.
   #include <stdio.h>

void main () {
     int arr [3] [3], i, k;
     
     for (i = 0; i <3; i ++) {
           for (k = 1; k <= 3; k ++) {
                 arr [i] [k] = i * 3 + k;
                 printf ("% d \ n", i * 3 + k);
                 }
           }
     }



3. Write a program that introduces the elements of a rectangular matrix a [nxm] of integers and finds the minimum element among the maximum elements on its columns.
 #include <stdio.h>
#include <limits.h>

void main () {
     int m, n, max = INT_MAX, min, i, k;
     
     printf ("insert n:");
     scanf ("% d", & n);
     printf ("insert m:");
     scanf ("% d", & m);
     
     int arr [3] [3];
     
     for (i = 0; i <n; i ++) {
           for (k = 0; k <m; k ++) {
                 scanf ("% d", & arr [i] [k]);
                 }
           }
     
     printf ("Min elements:");
     for (i = 0; i <n; i ++) {
           min = max;
           for (k = 0; k <m; k ++) {
                 if (arr [k] [i] <min) {
                      min = arr [k] [i];
                 }
           }
           printf ("% d", min);
     }
     
     
}
