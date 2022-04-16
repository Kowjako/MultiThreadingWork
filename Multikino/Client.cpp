#include "Client.h"

Client::Client(std::string name, std::string surname)
{
	this->_name = name;
	this->_surname = surname;
}

Client::Client(std::string name, std::string surname, Ticket* ticket) : Client(name, surname)
{
	this->_ticket = ticket;
}

void Client::DisplayInfo()
{
	std::cout<<"Imie: "<<this->_name<<" Nazwisko: "<<this->_surname;
	if(this->_ticket != NULL)
	{
		std::cout<<"Bilet: "<<std::endl;
		std::cout<<_ticket->TicketInfo()<<std::endl;
	}
}

void Client::BuyTicket(Ticket* ticket)
{
	this->_ticket = ticket;
	this->_clientState = BuyingTicket;
}

ClientState Client::GetClientState()
{
	return this->_clientState;
}

void Client::SetClientState(ClientState state)
{
	this->_clientState = state;
}