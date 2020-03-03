#ifndef __CEIL_HPP__
#define __CEIL_HPP__

#include "decorator.hpp"

class Ceil : public Decorator {
	public:
		Ceil(Base* value) : Decorator() { this->value = value;  }
		virtual double  evaluate() {
			return ceil(value->evaluate());
		}	
		virtual std::string stringify() { }
		virtual Iterator* create_iterator() { return new UnaryIterator(this); }
		virtual Base* get_left() { return value; }
		virtual Base* get_right() { return nullptr; }
	private:
		Base* value;
};
	
#endif
