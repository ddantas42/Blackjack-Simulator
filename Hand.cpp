#include "Hand.hpp"


// Destructor
Hand::~Hand()
{
}


// Operators
Hand & Hand::operator=(const Hand &assign)
{
	(void) assign;
	return *this;
}

void Hand::addCard(int id)
{
	switch (id)
	{
		case ACE: this->card[count_card++] = Card("Ace", 0, 11); break;
		case TWO: this->card[count_card++] = Card("2", 1, 2); break;
		case THREE: this->card[count_card++] = Card("3", 2, 3); break;
		case FOUR: this->card[count_card++] = Card("4", 3, 4); break;
		case FIVE: this->card[count_card++] = Card("5", 4, 5); break;
		case SIX: this->card[count_card++] = Card("6", 5, 6); break;
		case SEVEN: this->card[count_card++] = Card("7", 6, 7); break;
		case EIGHT: this->card[count_card++] = Card("8", 7, 8); break;
		case NINE: this->card[count_card++] = Card("9", 8, 9); break;
		case TEN: this->card[count_card++] = Card("10", 9, 10); break;
		case JACK: this->card[count_card++] = Card("jack", 10, 10); break;
		case QUEEN: this->card[count_card++] = Card("Queen", 11, 10); break;
		case KING: this->card[count_card++] = Card("King", 12, 10); break;
	}
}

void Hand::removeCards( void )
{
	for (int i = 0; i < count_card; i++)
		this->card[i] = Card();
	this->count_card = 0;
}

int Hand::getValue() const
{
	int value = 0;
	for (int i = 0; i < count_card; i++)
	{
		if (card[i].getId() == ACE)
		{
			if (value + card[i].getValue() > 21)
				value += 1;
			else
				value += card[i].getValue();
		}
		else
			value += card[i].getValue();
	}
	return value;
}

// Operator
std::ostream& operator<<( std::ostream& os, const Hand& hand)
{
	for (int i = 0; i < hand.getCountCard(); i++)
		os << hand.getCard(i).getName() << " | ";
	std::cout << "Value = " << hand.getValue() << std::endl;
	return os;
}

