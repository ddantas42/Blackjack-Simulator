#ifndef CARD_HPP
# define CARD_HPP

# include <iostream>
# include <string>

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

class Card
{
	public:
		// Constructors
		Card() {};
		Card(const std::string &name, const int id, const int value) : name(name), id(id), value(value) {};

		std::string getName() const {return name;};
		int getId() const {return id;};
		int getValue() const {return value;};

		
		// Destructor
		~Card() {};
		
		// Operators
		Card & operator=(const Card &assign);
		
	private:
		std::string name;
		int id;
		int value;
};

#endif