#ifndef HAND_HPP
# define HAND_HPP

# include <iostream>
# include <string>
# include "Card.hpp"

class Hand
{
	public:
		// Constructors
		Hand() : count_card(0), name ("Player"), bankroll(1000) {};
		Hand( std::string const &name ) : count_card(0), name(name), bankroll(1000) {};

		// Destructor
		~Hand();
		
		// Operators
		Hand & operator=( const Hand &assign );
		
		void addCard( int id );
		void removeCards( void );

		std::string getName() const { return name; }
		int getCountCard() const { return count_card; }
		Card getCard( int index ) const { return card[index]; }
		int getValue() const ;
		int getBankroll() const { return bankroll; }
		void getInitialBet();
		int getBet() const { return bet; }

		void setBet(int player_bet) { bet = bet; }
		void setBankroll(int condition);
		
	private:
		std::string name;
		int bet;
		Card card[99];
		int count_card;
		int value;
		int bankroll;
};

std::ostream& operator<<( std::ostream& os, const Hand& hand);

#endif
