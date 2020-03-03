#ifndef __TRUNC_HPP__
#define __TRUNC_HPP__

#include "decorator.hpp" 
class Trunc : public Decorator{
	public:
		Trunc(Base* value) : Decorator() { this->value = value; }
		virtual double evaluate() {};	
		virtual string stringify(){
			int num = trunc(value->evaluate());
			return to_string(num);
			

		}	


	protected:
		Base* value;
	


};
#endif
