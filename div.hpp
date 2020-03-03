#ifndef _DIV_HPP_
#define _DIV_HPP_

#include "base.hpp"

using namespace std;

class Div: public Base {
	public:
		Div(Base* A,Base* B) {this->A = A; this->B = B;}	
		virtual double evaluate() {return( A->evaluate() / B->evaluate());}
		virtual string stringify() {return (A->stringify() + " / " + B->stringify());}
		Iterator* create_iterator() { }
	private:
		
		Base* A; Base* B;

};	
#endif
