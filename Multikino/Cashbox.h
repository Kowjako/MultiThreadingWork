#ifndef CASHBOX_H
#define CASHBOX_H

#include <iostream>
#include <vector>
#include <pthread.h>
#include <unistd.h> 
#include <ncurses.h>

struct Ticket
{
	std::string filmName;
	short startTime;
	short endTime;

	Ticket(std::string filmName, short start, short end)
	{
		this->filmName = filmName;
		startTime = start;
		endTime = end;
	}

	std::string TicketInfo()
	{
		return "Nazwa filmu: " + this->filmName + 
			   " Termin: " + std::to_string(this->startTime) + " - " + std::to_string(this->endTime) + "\n";
	}
};

class Cashbox
{
	public:
		Cashbox(int capacity);
		Cashbox(int capacity, std::vector<Ticket> tickets);

		void GenerateTickets();
		Ticket* GetTicket();

	private:
		int _ticketPosition=0;
		pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
		int _capacity;
		std::vector<Ticket> _tickets;
};

#endif 