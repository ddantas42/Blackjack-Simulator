#ifndef BLACKJACK_HPP
# define BLACKJACK_HPP

# include <iostream>
# include <string>
# include <cstdlib>
# include <ctime>

# include "Card.hpp"
# include "Hand.hpp"

/* main.cpp */
void print_table( Hand Player, Hand Dealer );
int random_id();

/* Blackjack.cpp */
int game( Hand *Player, Hand *Dealer );

#endif