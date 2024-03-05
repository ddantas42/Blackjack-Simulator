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
		case 0: this->card[count_card++] = Card("Ace", 0, 11); break;
		case 1: this->card[count_card++] = Card("2", 1, 2); break;
		case 2: this->card[count_card++] = Card("3", 2, 3); break;
		case 3: this->card[count_card++] = Card("4", 3, 4); break;
		case 4: this->card[count_card++] = Card("5", 4, 5); break;
		case 5: this->card[count_card++] = Card("6", 5, 6); break;
		case 6: this->card[count_card++] = Card("7", 6, 7); break;
		case 7: this->card[count_card++] = Card("8", 7, 8); break;
		case 8: this->card[count_card++] = Card("9", 8, 9); break;
		case 9: this->card[count_card++] = Card("10", 9, 10); break;
		case 10: this->card[count_card++] = Card("Valete", 10, 10); break;
		case 11: this->card[count_card++] = Card("Rainha", 11, 10); break;
		case 12: this->card[count_card++] = Card("Rei", 12, 10); break;
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

