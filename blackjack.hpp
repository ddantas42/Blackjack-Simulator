#ifndef BLACKJACK_HPP
# define BLACKJACK_HPP

# include <iostream>
# include <string>
# include <cstdlib>
# include <ctime>
# include <unistd.h>

# include "Hand.hpp"
# include "Card.hpp"


# define ACE 0
# define TWO 1
# define THREE 2
# define FOUR 3
# define FIVE 4
# define SIX 5
# define SEVEN 6
# define EIGHT 7
# define NINE 8
# define TEN 9
# define JACK 10
# define QUEEN 11
# define KING 12

# define WIN 100
# define WIN_BLACKJACK 150
# define LOSE 200
# define TIE 300

/* main.cpp */
void	print_table( Hand Player, Hand Dealer );
int		random_id();

/* Blackjack.cpp */
int		game( Hand *Player, Hand *Dealer );

#endif