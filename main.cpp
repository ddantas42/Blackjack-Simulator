#include "blackjack.hpp"

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

	(void)game(&Player, &Dealer);

	return 0;
}