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
		virtual Iterator* create_iterator() { return new UnaryIterator(this); }
		virtual Iterator* get_left() { return value; }
		virtual Iterator* get_right() { return nullptr;  }
private:
	Base* value;
	

};


#endif
