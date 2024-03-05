#include "blackjack.hpp"

static void initial_handout(Hand *Player, Hand *Dealer)
{
	Player->addCard(random_id());
	Player->addCard(random_id());
	Dealer->addCard(random_id());

	print_table(*Player, *Dealer);
	Dealer->addCard(random_id());
}

static int insta_win(Hand *Player, Hand *Dealer)
{
	if (Dealer->getValue() == 21)
	{
		std::cout << "Blackjack! Dealer wins!" << std::endl;
		return 1;
	}
	else if (Player->getValue() == 21)
	{
		std::cout << "Blackjack! Player wins!" << std::endl;
		return 1;
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
		if (choice == "h")
		{
			Player->addCard(random_id());
			print_table(*Player, *Dealer);
		}
		else if (choice == "s")
		{
			break;
		}
	}
	return (0);
}

int	game(Hand *Player, Hand *Dealer)
{
	// Initial handout
	initial_handout(Player, Dealer);
	if (insta_win(Player, Dealer))
		return 0;
	
	// Player drawing phase
	player_draw(Player, Dealer);
	if (Player->getValue() > 21)
	{
		std::cout << "Player busts! Dealer wins!" << std::endl;
		return 0;
	}

	// Dealer drawing phase
	while (Dealer->getValue() < 17)
	{
		Dealer->addCard(random_id());
		print_table(*Player, *Dealer);
	}

	return (0);
}