#ifndef __CEIL_HPP__
#define __CEIL_HPP__

#include "decorator.hpp"

class Ceil : public Decorator {
	public:
		Ceil(Base* value) : Decorator() { this->value = value;  }
		virtual double  evaluate() {
			return ceil(value->evaluate());
		}	
		virtual string stringify() { }
	private:
		Base* value;
};
	
#endif
