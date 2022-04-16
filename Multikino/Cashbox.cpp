#include "Cashbox.h"

Cashbox::Cashbox(int capacity)
{
	this->_capacity = capacity;
}

Cashbox::Cashbox(int capacity, std::map<Ticket, int> tickets) : Cashbox(capacity)
{
	this->_tickets = tickets;
}

Ticket Cashbox::GetTicket()
{
	/* Obsługujemy pojedynczo klientów */
	pthread_mutex_lock(&this->mutex);
	if(this->_tickets.size() == 0)
	{
		std::cout<<"Nie ma już dostępnych biletów."<<std::endl;
	}

	int ticketPosition = rand() % this->_tickets.size();
	std::cout<<"Przygotowanie biletu dla klienta"<<std::endl;
	sleep(3000); /* czekamy 3 sek na przygotwanie biletu */

	Ticket t = this->_tickets[ticketPosition];
	this->_tickets.erase(this->_tickets.begin() + ticketPosition);

	/* Zwalniamy dostęp do kasy */
	pthread_mutex_unlock(&this->mutex);
	return t;
}

void Cashbox::GenerateTickets()
{
	const char* filmNames[4] = {"Pianista", "Piętro wyżej", "Pociąg", "Niepodległość"};
	const int* durations[4] = {2, 3, 5, 1};
	int endTime = 0;
	for(auto i=0;i<this->_capacity / 4;i++) /* bo na każdy film po 5 biletów */
	{
		for(auto j=0,j<5;j++)
		{
			if(i == 0)
			{
				Ticket* t = new Ticket(filmNames[j], 1, durations[i] + 1);
			}
			else
			{
				Ticket* t = new Ticket(filmNames[i], endTime, endTime + durations[i] + 1);
			}
			this->_tickets.push_back(t);
		}
		endTime = durations[i] + 1;
	}
}