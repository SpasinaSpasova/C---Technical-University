//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
#include <string.h>
#include <stdio.h>
#include <conio.h>
//---------------------------------------------------------------------------
class Fish
   {
   int Nomer[10];
   char Data[11];
   int Tiraj;
   int Chisla[6];
   public:
   Fish(int *NomerIni, char *Data, int Tiraj, int *Chisla);
   int Find(int Chislo);
   int operator==(int *Chisla);
   };
//---------------------------------------------------------------------------
Fish::Fish(int *NomerIni, char *DataIni, int TirajIni, int *ChislaIni)
   {
   int i;
   for(i = 0 ; i < 10 ; i++) Nomer[i] = NomerIni[i];
   strcpy(Data, DataIni);
   Tiraj = TirajIni;
   for(i = 0 ; i < 6 ; i++) Chisla[i] = ChislaIni[i];
   }
//---------------------------------------------------------------------------
int Fish::Find(int Chislo)
   {
   for(int i = 0 ; i < 6 ; i++) if(Chisla[i] ==  Chislo) return 1;
   return 0;
   }
//---------------------------------------------------------------------------
int Count(Fish *Fishove, int Broj, int Chislo)
   {
   int i, BrojFishove;
   for(i = BrojFishove = 0 ; i < Broj ; i++) if(Fishove[i].Find(Chislo)) BrojFishove++;
   return BrojFishove;
   }
//---------------------------------------------------------------------------
int Fish::operator==(int *ChislaToCheck)
   {
   for(int i = 0 ; i < 6 ; i++) if(!Find(ChislaToCheck[i])) return 0;
   return 1;
   }
//---------------------------------------------------------------------------
/*
int Fish::operator==(int *ChislaToCheck)
   {
   int i, j;
   for(i = 0 ; i < 6 ; i++)
      for(j = 0 ; i < 6 ; i++)
         if(Chisla[i] != ChislaToCheck[j])) return 0;
   return 1;
   }
*/

//---------------------------------------------------------------------------
void main(void)
   {
   int x[] = {5, 7, 10, 3, 2, 3, 2, 1, 1, 1};
   int y[] = {5, 7, 10, 12, 22, 49};
   int z[] = {6, 7, 10, 12, 22, 49};

   Fish F(x, "02.02.2002", 7, y);

   if(F == z) printf("Stava");
   else       printf("Ni Stava");

   getch();
   }
//---------------------------------------------------------------------------
