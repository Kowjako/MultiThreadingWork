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
	printw("Imie: %s, Nazwisko: %s\n",this->_name.data(),this->_surname.data());
	if(this->_ticket != NULL)
	{
		printw("Bilet: ");
		printw(_ticket->TicketInfo().data());
	}
}

void Client::BuyTicket(Ticket* ticket)
{
	this->_ticket = ticket;
	this->_clientState = BuyingTicket;
	printw("%s %s kupuje bilet...\n", this->_name.data(), this->_surname.data());
	refresh();
}

std::string Client::GetNameAndSurname()
{
	return this->_name + " " + this->_surname;
}

ClientState Client::GetClientState()
{
	return this->_clientState;
}

void Client::SetClientState(ClientState state)
{
	this->_clientState = state;
}

void Client::WatchMovie(std::string filmName)
{
	this->_clientState = WatchingMovie;
	printw("Imie: %s, Nazisko: %s -> Oglada film: %s\n",this->_name.data(), this->_surname.data(), filmName.data());
}

Ticket* Client::GetTicket()
{
	return this->_ticket;
}