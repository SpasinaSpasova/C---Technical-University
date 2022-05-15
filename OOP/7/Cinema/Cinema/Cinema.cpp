// Cinema.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Film.h"
#include "Ticket.h"
#include "StudentTicket.h"
#include "TeamTicket.h"
#include "movieТheater.h"


int main()
{
	Film film("The notebook", 1995, "Romantic", 20.60);
	//film.PrintFilm();


	Ticket ticket(2, 3, "16.05.22", &film, film.price);
	//ticket.PrintTicket();
	//ticket.Sell();
	
	Ticket* t;
	t = &ticket;
	t->PrintTicket();
	StudentTicket studentTicket(9, 4, "16.05.22", &film, film.price);
	//studentTicket.PrintTicket();
	//studentTicket.Sell();
	t = &studentTicket;
	t->PrintTicket();

	//TeamTicket TeamTicket(15,7, 4, "16.05.22", &film, film.price);
	/*TeamTicket.PrintTicket();
	TeamTicket.Sell();*/

	//movieТheater mt;
	
	/*printf("\nSave Seat:\n");
	mt.SaveSeat(studentTicket.numOfRow, studentTicket.seatNumber);
	mt.PrintLounge();*/
}
