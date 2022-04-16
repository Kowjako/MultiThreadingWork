#ifndef CLIENT_H
#define CLIENT_H

#include "Cashbox.h"
#include <iostream>

class Client {
	public:
		Client(std::string name, std::string surname);
		Client(std::string name, std::string surname, Ticket* ticket);

		void BuyTicket(Ticket* ticket);
		void DisplayInfo();

	private:
		Ticket* _ticket;
		std::string _name;
		std::string _surname;
};

#endif