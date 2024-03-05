#include "blackjack.hpp"
#include "Card.hpp"
#include "Hand.hpp"

int random_id() { return rand() % 13; }

void print_table(Hand Player, Hand Dealer)
{
	std::cout << Dealer << std::endl;
	std::cout << Player << std::endl;
}

int main()
{
	Hand Player;
	Hand Dealer;


	srand(time(0));

	(void)game(&Player, &Dealer);

	return 0;
}