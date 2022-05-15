// oop1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <stdio.h>
#include <string.h>
#include <memory.h>

#define EOT -1
//#define ВОТ -1 ??

struct BelRow {
    char Name[12];
    char Fam[15];
    unsigned long Tel;
};
class Bel {
    BelRow Table[100];
    int TableEnd;
    int CurrentRecord;
public:
    Bel(void) { TableEnd = 0; }
    int Append(const char* Name, const char* Fam, unsigned long Tel);
    int Append(BelRow* ARow);
    BelRow* FindRowByName(const char* Name);

    //-	First ( ) , който да позиционира на първия запис (CurrentRecord = 0 );
    void First();

    //-	Next ( ) – позиционира на следващ запис, 
    //но не излиза след TableEnd. Ако е достигнат края на таблицата, 
    //функцията да връща “ЕОТ” (“край на таблица”, използвайте  #define EOT -1).
    //В противен случай функцията да връща номер на запис;
    int Next();

    //-Prev() - позиционира на предходния запис.
    //Ако е достигнато началото на таблицата, функцията да връща “ВОТ”.
    //В противен случай функцията да връща номер на запис;
    int Prev();

    //-	Last ( ) - позиционира на последния запис;
    void Last();

    //-	Get ( ) връща указател към текущия запис.
    BelRow* Get();
};
int Bel::Append(const char* Name, const char* Fam, unsigned long Tel) {
    if (TableEnd >= 100) return 0;
    strcpy(Table[TableEnd].Name, Name);
    strcpy(Table[TableEnd].Fam, Fam);
    Table[TableEnd].Tel = Tel;
    TableEnd++;
    return 1;
}
int Bel::Append(BelRow* ARow) {
    if (TableEnd >= 100) return 0;
    memcpy(&Table[TableEnd], ARow, sizeof(BelRow));
    TableEnd++;
    return 1;
}
BelRow* Bel::FindRowByName(const char* Name) {
    for (int i = 0; i < TableEnd; i++)
        if (!strcmp(Table[i].Name, Name)) return &Table[i];
    return NULL;
}
void Bel::First() {
    CurrentRecord = 0;
}
int Bel::Next() {
    if (CurrentRecord > TableEnd) {
        return EOT; 
    }
    CurrentRecord++;
    return CurrentRecord;
}
int Bel::Prev() {
    CurrentRecord--;
    if (CurrentRecord <= 0) {
        //return BOT;?????
    }
    return CurrentRecord;
}
void Bel::Last() {
    CurrentRecord = TableEnd - 1;
}
BelRow* Bel::Get() {
    return &Table[CurrentRecord];
}
void main(void) {
    int x, y;
    Bel Tef1;
    Tef1.Append("Ivan", "Petrov", 342123L);
    BelRow* ARow = Tef1.FindRowByName("Ivan");
    if (ARow)
        printf("\nName = %s, Fam = %s, Tel = %lu", ARow->Name, ARow->Fam, ARow->Tel);
}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
