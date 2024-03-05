#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "Card.hpp"
#include "Hand.hpp"

int random_id() { return rand() % 13; }

void print_table(Hand Player, Hand Dealer)
{
	std::cout << "Dealer: " << Dealer << std::endl;
	std::cout << "Player: " << Player << std::endl;
}

int main()
{
	Hand Player;
	Hand Dealer;

	srand(time(0));

	// Initial handout
	Player.addCard(random_id());
	Player.addCard(random_id());
	Dealer.addCard(random_id());

	print_table(Player, Dealer);
	Dealer.addCard(random_id());

	if (Player.getValue() == 21) { std::cout << "Blackjack! Player wins!" << std::endl; return 0; }
	else if (Dealer.getValue() == 21) { std::cout << "Blackjack! Dealer wins!" << std::endl; return 0; }
	// Player drawing phase
	std::string choice;
	while (Player.getValue() < 21)
	{
		std::cout << "Hit (h) or Stand (s)?";
		std::cin >> choice;
		if (choice == "h")
		{
			Player.addCard(random_id());
			print_table(Player, Dealer);
		}
		else if (choice == "s")
		{
			break;
		}
	}
	if (Player.getValue() > 21)
	{
		std::cout << "Player busts! Dealer wins!" << std::endl; return 0;
	}

	return 0;
}