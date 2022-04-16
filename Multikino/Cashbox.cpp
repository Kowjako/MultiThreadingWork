#include "Cashbox.h"

Cashbox::Cashbox(int capacity)
{
	this->_capacity = capacity;
}

Cashbox::Cashbox(int capacity, std::vector<Ticket> tickets) : Cashbox(capacity)
{
	this->_tickets = tickets;
}

void Cashbox::AddTicket(Ticket ticket)
{
	this->_tickets.push_back(ticket);
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