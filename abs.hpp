#ifndef __ABS_HPP__
#define __ABS_HPP__
#include "decorator.hpp"

class Abs : public Decorator {
	public:
		Abs(Base* value) : Decorator() { this->value = value; }
	 	virtual double evaluate() { abs(value->evaluate()); }
		virtual string stringify() {}
	private:
		Base* value;
};
#endif
