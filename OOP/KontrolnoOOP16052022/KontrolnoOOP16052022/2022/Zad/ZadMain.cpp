//---------------------------------------------------------------------------
class MyArray
   {
   protected:
   int Arr[100], Broj;
   float SrSt;
   public:
   MyArray(void) {Broj = SrSt = 0;}
   int Add(int Element);
   };
//---------------------------------------------------------------------------
int MyArray::Add(int Element)
   {
   int i, Suma;
   if(Broj >= 100) return 0;
   Arr[Broj] = Element;
   Broj++;
   for(i = Suma = 0; i < Broj ; i++) Suma += Arr[i];
   SrSt = Suma / Broj;
   return 1;
   }
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
class MyCyclicArray : public MyArray
   {
   int Pointer;
   public:
   MyCyclicArray(void) : MyArray() {Pointer = 0;}
   int Get(void);
   MyCyclicArray &operator=(MyArray &A);
   };
//---------------------------------------------------------------------------
int MyCyclicArray::Get(void)
   {
   int Help;
   Help = Arr[Pointer];
   if(Pointer >= Broj) Pointer = 0;
   else                Pointer++;
   return Help;
   }
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
MyArray &MyCyclicArray::operator=(MyArray &A)
   {
   Broj = A.Broj;
   SrSt = A.SrSt;
   for(int i = 0 ; i < Broj ; i++) Arr[i] = A.Arr[i];
   Pointer = 0;

   return *((MyArray *)this);
   }
//---------------------------------------------------------------------------
void main(void)
   {
   MyArray MA;
   MyCyclicArray CA1, CA2;

   CA2 = CA1 = MA;
   }
//---------------------------------------------------------------------------
 