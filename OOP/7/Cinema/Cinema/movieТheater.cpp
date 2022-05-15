#include "movie“heater.h"
#include <stdio.h>

movie“heater::movie“heater() {
	countOfSoldTikets = 0;
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 16; j++)
        {
            lounge[i][j] = 0;
        }
    }
}
void movie“heater::SaveSeat(int rowNum, int seatNum) {
    if (rowNum < 10 && seatNum < 16) {
        lounge[rowNum][seatNum] = 1;
    }
}
void movie“heater::PrintLounge() {
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 16; j++)
        {
            printf("%d ", lounge[i][j]);
        }

        printf("\n");
    }

}