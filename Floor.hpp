#ifndef __FLOOR_HPP___
#define __FLOOR_HPP__

#include "decorator.hpp"

class Floor : public Decorator {
	public:
		Floor (Base* value) : Decorator () { this->value = value;}	
		virtual double  evaluate() {
			return floor(value->evaluate());

		}
		virtual std::string stringify() { };
		Iterator* create_iterator() { return new UnaryIterator(this); }
		virtual Base* get_left() { return value; }
		virtual Base* get_right() { return nullptr;  }
private:
	Base* value;
	

};


#endif
