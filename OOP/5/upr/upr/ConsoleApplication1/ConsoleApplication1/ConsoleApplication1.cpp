// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string.h>

class smartphone
{
	char model[20];
	int price;
	char os[20];

	public:
		smartphone();
		smartphone(char Model, int Price, char OS);
};
smartphone::smartphone(){
	model[0] = 0;
	price = 0;
	os[0] = 0;

}
smartphone::smartphone(char Model, int Price, char OS){
	strcpy_s(model, 20, Model);
		

}
int main(){
	smartphone SM;
//		int tmp;
//		tmp = SM.checkprice;
	//	SM.printdata();
	return 0;
}

