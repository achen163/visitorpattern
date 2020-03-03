#ifndef __PAREN_HPP__
#define __PAREN_HPP__
#include "decorator.hpp"

class Paren : public Decorator {
	public:
		Paren(Base* value) : Decorator() { this->value = value; }
		virtual std::string stringify() { return "(" + value->stringify() + ")"; }
		virtual double evaluate() { }
		virtual Iterator* create_iterator() { return new UnaryIterator(this); }
		virtual Iterator* get_left() { return value; }
		virtual Iterator* get_right() { return nullptr; } 
	private:
		Base* value;
};
#endif
