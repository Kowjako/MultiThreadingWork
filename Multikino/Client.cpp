#include <Client.h>

Client::Client(std::string name, std::string surname)
{
	this->_name = name;
	this->_surname = surname;
}

Client::Client(std::string name, std::string surname, Ticket ticket) : Client(name, surname)
{
	this->_ticket = ticket;
}

void Client::DisplayInfo()
{
	std::cout<<"Imie: "<<this->_name<<" Nazwisko: "<<this->_surname;
	if(this->_ticket != null)
	{
		std::cout<<"Bilet: "<<endl;
		std::cout<<_ticket.TicketInfo()<<endl;
	}
}

void Client::BuyTicket(Ticket ticket)
{
	this->ticket = ticket;
}