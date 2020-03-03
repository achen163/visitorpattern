#ifndef __PAREN_HPP__
#define __PAREN_HPP__
#include "decorator.hpp"

class Paren : public Decorator {
	public:
		Paren(Base* value) : Decorator() { this->value = value; }
		virtual string stringify() { return "(" + value->stringify() + ")"; }
		virtual double evaluate() { }
	private:
		Base* value;
};
#endif
