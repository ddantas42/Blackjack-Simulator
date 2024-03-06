#include "blackjack.hpp"
#include "Card.hpp"
#include "Hand.hpp"

int random_id() { return rand() % 13; }

void print_table(Hand Player, Hand Dealer)
{
	system("clear");
	std::cout << "Player's bet: " << Player.getBet() << "€" << std::endl;
	std::cout << Dealer << std::endl;
	std::cout << Player << std::endl;
}

int main()
{
	Hand Player("Player");
	Hand Dealer("Dealer");

	system("clear");
	srand(time(0));
	while (Player.getBankroll() > 0)
	{
		
		Player.getInitialBet();

		int condition = game(&Player, &Dealer);
		Player.setBankroll(condition);
		Player.setBet(0);

		Player.removeCards();
		Dealer.removeCards();

		std::string choice;
question:
		std::cout << "Bankroll: " << Player.getBankroll() << "€" << std::endl;
		std::cout << "Play again? (y/n) ";
		std::cin >> choice;
		if (choice == "n" || choice == "N")
			break;
		else if (choice == "y" || choice == "Y")
		{
			if (Player.getBankroll() <= 0)
				std::cout << "You're out of money! Game over!" << std::endl;
		sleep(1);
		}
		else
			goto question;
	}

	return 0;
}