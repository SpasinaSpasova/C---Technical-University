1.Three different numbers 

#include <stdio.h>
void main(void)
{int a;
float b;
char c;
printf("vyvedete cqlo 4islo, drobno 4islo i simvol: ");
scanf("%d %f %s", &a, &b, &c);
printf("cqloto 4islo e %d,drobnoto e %f i cimvola e %c",a,b,c);}


2.Arithmetic operations with 2 numbers

#include <stdio.h>
int main()
{int a,b,suma,chastno,ostatyk;
printf("vyvedete 2 celi 4isla");
scanf("%d" "%d", &a, &b);
suma=a+b;
chastno=a/b;
ostatyk=a%b;
printf("sumata e %d,chastnoto e %d i ostatyka e %d",suma,chastno,ostatyk);
return 0;}


3.Change the sign of a number

 #include <stdio.h>
int main()
{float a;
printf("a=");
scanf("%f",&a);
printf("-%f",a);
return 0;}




4.Square root of a number

#include <stdio.h>
#include <math.h>
int main()
{float a;
printf("a=");
scanf("%f",&a);
a=sqrt(a);
printf("%f",a);
return 0;}



5.Area of the cube


#include <stdio.h>
int main()
{float a;
printf("vyvedete stranata na kuba");
scanf("%f",&a);
a=6*a*a;
printf("liceto na pylnata povyrhnina na kuba e %f",a);
return 0;}


6. Seconds in 1h, 1w, 1m è 1y.

#include <stdio.h>
int main()
{long int chas,sedmica,mesec,godina;
chas=60*60;
sedmica=7*24*chas;
mesec=30*24*chas;
godina=365*24*chas;
printf("sekundite v 1 4as, 1 sedmica, 1 mesec i 1 godina sa syotvetno %d,%d,%d,%d",chas,sedmica,mesec,godina);
return 0;}

7.Swap two numbers
#include <stdio.h>
int main()
{int A,B,P;
printf("vyvedete A i B");
scanf("%d""%d",&A,&B);
P=A;
A=B;
B=P;
printf("%d,%d",A,B);
return 0;}


8.Perimeter and area of rectangle

#include <stdio.h>
int main()
{int a,b,S,P;
printf("vyvedete stranite na pravoygylnika");
scanf("%d""%d",&a,&b);
S=a*b;
P=2*a+2*b;
printf("Liceto i obikolkata sa syotvetno: %dkv.sm.,%dsm.",S,P);
return 0;}


9.Write a program that finds and displays the circumference and face of an arbitrary triangle at a given angle a (Alpha) and its adjacent sides b and c. To find the face to use the formula:
#include <stdio.h>
#include<math.h>
int main()
{int b,c;
float alfa,S;
printf("vyvedete 2 ot stranite na triygylnika i ygyla zakliu4en mejdu tqh: ");
scanf("%d""%d""%f",&b,&c,&alfa);
S=b*c*sin(alfa)/2;
printf("Liceto e: %f",S);
return 0;}



10.	or a given Fahrenheit air temperature, calculate the Celsius temperature. The relationship between the two rocks is as follows:
where C is the Celsius temperature and F is the Fahrenheit temperature.

#include <stdio.h>
int main()
{float C,F;
printf("Wyvedete temperaturata po farenhait ");
scanf("%f",&F);
C=(F-32)*5/9;
printf("Temperaturata po celzii e : %fgradusa",C);
return 0;}


11.	Write a program that finds the sum of the first n natural numbers using the formula for finding the sum of the first n terms of an arithmetic progression

#include <stdio.h>
int main()
{int S,i,n;
printf("n= ");
scanf("%d",&n);
S=(1+n)*n/2;
printf("Sumata na pyrvite %d 4lena na progresiqta e %d",n,S);
return 0;}


12.Write a program that calculates the face of a triangle on three sides a, b and c. Use the formula where p is the perimeter of the triangle.

#include <stdio.h>
#include <math.h>
int main()
{int a,b,c;
float p,S;
printf("wyvedete stranite na triygylnika");
scanf("%d""%d""%d",&a,&b,&c);
p=(a+b+c)/2;
S=sqrt(p*(p-a)*(p-b)*(p-c));
printf("Liceto na triygylnika e %fkv.sm.",S);
return 0;}

13.Write a program for calculating and printing the distance between two points in the plane, given by their coordinates (x1, y1) and (x2, y2).

#include <stdio.h>
#include <math.h>
int main()
{int x1,x2,y1,y2;
float a,b,c;
printf("wyvedete kordinatite na dvete to4ki");
scanf("%d""%d""%d""%d",&x1,&y1,&x2,&y2);
b=abs(y1-y2);
a=abs(x1-x2);
c=sqrt(a*a+b*b);
printf("raztoqnieto mejdu to4kite e %f.",c);
return 0;}


14.	Write a program that finds and displays the value of the expression
#include <stdio.h>
#include <math.h>
int main()
{float x,y,e,z;
printf("wyvedete x i y");
scanf("%f""%f",&x,&y);
e=2.71828183;
e=pow(e,y/3);
z=(abs(x-y)*e)/(1/2+cos(x/2));
printf("z= %f",z);
return 0;}




