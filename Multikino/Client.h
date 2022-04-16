#ifndef CLIENT_H
#define CLIENT_H

#include "Cashbox.h"
#include <iostream>

enum ClientState
{
	/* Czeka na zakup biletu */
	WaitingForTicket = 0, 
	/* Kupuje bilet */
	BuyingTicket = 1,
	/* Czeka na film (wejście do sali) */
	WaitingForMovie = 2,
	/* Ogląda premierę */
	WatchingMovie = 3
};

class Client {
	public:
		Client(std::string name, std::string surname);
		Client(std::string name, std::string surname, Ticket* ticket);

		void SetClientState(ClientState);
		ClientState GetClientState();

		void BuyTicket(Ticket* ticket);
		void DisplayInfo();

	private:
		ClientState _clientState;
		Ticket* _ticket;
		std::string _name;
		std::string _surname;
};

#endif