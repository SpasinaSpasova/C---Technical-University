//---------------------------------------------------------------------------
#include <stdio.h>
#include <conio.h>
//---------------------------------------------------------------------------
class MyArray
   {
   public:
   int Masiv[100];
   int Broj;
   double AverageValue;
   MyArray(void) {Broj = AverageValue = 0;}
   int Add(int Chislo);
   double GetAverage(void) {return AverageValue;}
   };
//---------------------------------------------------------------------------
int MyArray::Add(int Chislo)
   {
   if(Broj > 99) return 0;
   Masiv[Broj] = Chislo;
   AverageValue *= Broj;
   AverageValue += Chislo;
   Broj++;
   AverageValue /= Broj;
   return 1;
   }
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
class CyclicQueue : public MyArray
   {
   int CurrentElement;
   public:
   CyclicQueue(void) : MyArray() {CurrentElement = 0;}
   int Get(void);
   CyclicQueue &operator=(MyArray &MA);
   };
//---------------------------------------------------------------------------
int CyclicQueue::Get(void)
   {
   if(CurrentElement > (Broj - 1)) CurrentElement = 0;
   CurrentElement++;
   return Masiv[CurrentElement-1];
   }
//---------------------------------------------------------------------------
CyclicQueue &CyclicQueue::operator=(MyArray &MA)
   {
   Broj = MA.Broj;
   AverageValue = MA.AverageValue;
   CurrentElement = 0;
   for(int i = 0 ; i < Broj ; i++) Masiv[i] = MA.Masiv[i];
   return *this;
   }
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
void main(void)
   {
   MyArray Mas;
   CyclicQueue CQ;

   Mas.Add(7);
   Mas.Add(22);
   Mas.Add(33);

   CQ = Mas;

   for(int i = 0 ; i < 7 ; i++) printf("\nelement = %d", CQ.Get());

   printf("\nThe average value of all the elements is = %lf", CQ.GetAverage());
   getch();
   }
//---------------------------------------------------------------------------
