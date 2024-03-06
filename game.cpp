#include <iostream>
#include "blackjack.hpp"
#include "Card.hpp"
#include "Hand.hpp"

static void initial_handout(Hand *Player, Hand *Dealer)
{
	Player->addCard(random_id());
	Player->addCard(random_id());
	Dealer->addCard(random_id());

	print_table(*Player, *Dealer);
}

static int insta_win(Hand *Player, Hand *Dealer)
{
	if (Dealer->getValue() == 21)
	{
		std::cout << "Blackjack! Dealer wins!" << std::endl;
		return LOSE;
	}
	else if (Player->getValue() == 21)
	{
		print_table(*Player, *Dealer);
		std::cout << "Blackjack! Player wins!" << std::endl;
		return WIN_BLACKJACK;
	}
	return 0;
}

static int player_draw(Hand *Player, Hand *Dealer)
{
	std::string choice;
	while (Player->getValue() < 21)
	{
		std::cout << "Hit (h) or Stand (s)?";
		std::cin >> choice;
		if (choice == "h" || choice == "H")
		{
			Player->addCard(random_id());
			print_table(*Player, *Dealer);
		}
		else if (choice == "s" || choice == "S")
			break;
	}
	return (0);
}

static int dealer_draw(Hand *Player, Hand *Dealer)
{
	if (Player->getCountCard() == 2)
		print_table(*Player, *Dealer);
	while (Dealer->getValue() < 17)
	{
		Dealer->addCard(random_id());
		print_table(*Player, *Dealer);
		sleep(1);
	}
	return (0);
}

static int check_winner(Hand *Player, Hand *Dealer)
{
	int result;
	
	if ((Player->getValue() > Dealer->getValue() && Player->getValue() <= 21) || Dealer->getValue() > 21)
	{
		std::cout << "Player wins!" << std::endl;
		return (WIN);
	}
	else if (Player->getValue() == Dealer->getValue())
	{
		std::cout << "It's a tie!" << std::endl;
		return (TIE);
	}
	else
	{
		std::cout << "Dealer wins!" << std::endl;
		return (LOSE);
	}
}

int	game(Hand *Player, Hand *Dealer)
{
	// Initial handout
	initial_handout(Player, Dealer);
	int insta_win_check = insta_win(Player, Dealer);
	if (insta_win_check)
		return insta_win_check;
	
	// Player drawing phase
	player_draw(Player, Dealer);
	if (Player->getValue() > 21)
	{
		std::cout << "Player busts! Dealer wins!" << std::endl;
		return LOSE;
	}

	// Dealer drawing phase
	dealer_draw(Player, Dealer);

	// Final result
	return (check_winner(Player, Dealer));
}