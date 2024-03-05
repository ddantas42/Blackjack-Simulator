#include "Card.hpp"


// Operators
Card & Card::operator=(const Card &assign)
{
	this->id = assign.getId();
	this->name = assign.getName();
	this->value = assign.getValue();
	return *this;
}

