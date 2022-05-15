//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
struct ResultsTableRow
   {
   int No;
   char Name[33];
   int VotaNumber;
   };
//---------------------------------------------------------------------------
class IzbProtokoll
   {
   char RajonName[50];
   int SectionNo;
   char PredsedatelName[50];
   ResultsTableRow ResultsTable[24];
   int TotalVota;
   public:
   IzbProtokoll(void) {RajonName[0] = 0; SectionNo = 0; PredsedatelName[0] = 0; TotalVota = 0;}
   void SetVota(char *Party, int VotaCount);
   friend int FindPollingPlace(IzbProtokoll *Array, int Broj);
   };
//---------------------------------------------------------------------------
void IzbProtokoll::SetVota(char *Party, int VotaCount)
   {
   for(int i = 0 ; i < 24 ; i++)
      if(!strcmp(Party, ResultsTable[i].Name))
         {
         ResultsTable[i].VotaNumber = VotaCount;
         break;
         }
   }
//---------------------------------------------------------------------------
int FindPollingPlace(IzbProtokoll *Array, int Broj)
   {
   int i, Index = 0;

   for(i = 1 ; i < Broj ; i++)
      if(Array[i].TotalVota > Array[Index].TotalVota)
         Index = i;

   return Array[Index].SectionNo;
   }
//---------------------------------------------------------------------------
IzbProtokoll IzbProtokoll::operator+(IzbProtokoll &IP)
   {
   IzbProtokoll Temp;
   strcpy(Temp.RajonName, RajonName);
   Temp.SectionNo = SectionNo;
   strcpy(Temp.PredsedatelName, PredsedatelName);

   for(int i = 0 ; i < 24 ; i++)
      Temp.ResultsTable[i].VotaNumber = ResultsTable[i].VotaNumber + IP.ResultsTable[i].VotaNumber;

   Temp.TotalVota = TotalVota + IP.TotalVota;
   return Temp;
   }










//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
void main(void)
   {
   ///
   }
//---------------------------------------------------------------------------
 