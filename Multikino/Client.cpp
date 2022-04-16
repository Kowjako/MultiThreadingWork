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
	std::cout<<"Imie: "<<this->_name<<", Nazwisko: "<<this->_surname<<std::endl;
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
	printw("%s %s kupuje bilet...\n", this->_name.data(), this->_surname.data());
	refresh();
}

ClientState Client::GetClientState()
{
	return this->_clientState;
}

void Client::SetClientState(ClientState state)
{
	this->_clientState = state;
}

void Client::WatchMovie(std::string filmName, int time)
{
	this->_clientState = WatchingMovie;
	std::cout<<"Imie: "<<this->_name<<" Nazwisko: "<<this->_surname<<" Ogląda film: "<<filmName<<std::endl;
	sleep(time); /* Oglądamy film przez (time) sekund */
}