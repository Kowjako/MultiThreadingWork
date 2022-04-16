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
	if(this->_tickets.size() == 0)
	{
		std::cout<<"Nie ma już dostępnych biletów."<<std::endl;
	}

	int ticketPosition = rand() % this->_tickets.size();

	Ticket t = this->_tickets[ticketPosition];
	this->_tickets.erase(this->_tickets.begin() + ticketPosition);
	return t;
}