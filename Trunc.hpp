#ifndef __TRUNC_HPP__
#define __TRUNC_HPP__

#include "decorator.hpp" 
class Trunc : public Decorator{
	public:
		Trunc(Base* value) : Decorator() { this->value = value; }
		virtual double evaluate() {};	
		virtual std::string stringify(){
			int num = trunc(value->evaluate());
			return to_string(num);
		}	
		virtual Iterator* create_iterator() { return new UnaryIterator(this); }
		virtual Base* get_left() { return value; }
		virtual Base* get_right() { return nullptr; }

	protected:
		Base* value;
	


};
#endif
