#ifndef CARD_HPP
# define CARD_HPP

# include <iostream>
# include <string>

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