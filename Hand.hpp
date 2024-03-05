#ifndef HAND_HPP
# define HAND_HPP

# include <iostream>
# include <string>
# include "Card.hpp"


class Hand
{
	public:
		// Constructors
		Hand() : count_card(0) {};
		// Destructor
		~Hand();
		
		// Operators
		Hand & operator=( const Hand &assign );
		
		void addCard( int id );
		void removeCards( void );

		int getCountCard() const { return count_card; }
		Card getCard( int index ) const { return card[index]; }
		int getValue() const ;

	private:

		Card card[99];
		int count_card;
		int value;
};

#endif

std::ostream& operator<<( std::ostream& os, const Hand& hand);