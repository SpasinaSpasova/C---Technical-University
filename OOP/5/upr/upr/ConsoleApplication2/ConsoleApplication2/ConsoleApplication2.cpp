// ConsoleApplication2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "descriptors.h"
#include "lexicalUnit.h"
#include <stdio.h>
#include <stdlib.h>
#include "DihotTable.h"
using namespace std;
int lexicalUnit::newAddress = 0;     // инициализация на статична променлива
int lexicalUnit::newDescriptor = 1;  // инициализация на статична променлива

int _tmain(int argc, _TCHAR* argv[])
{
	DihotTable dt;
	lexicalUnit lu("i","int");
	lexicalUnit lu1("b", "int");
	lexicalUnit lu2("c", "int");


	dt.AddLexicalUnit(lu);
	dt.AddLexicalUnit(lu1);
	dt.AddLexicalUnit(lu2);

	dt.Print();

	return 0;
}

