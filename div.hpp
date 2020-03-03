#ifndef _DIV_HPP_
#define _DIV_HPP_

#include "base.hpp"

using namespace std;

class Div: public Base {
	public:
		Div(Base* A,Base* B) {this->A = A; this->B = B;}	
		virtual double evaluate() {return( A->evaluate() / B->evaluate());}
		virtual string stringify() {return (A->stringify() + " / " + B->stringify());}
		Iterator* create_iterator() {return new BinaryIterator(this) }
	Base* get_left() {return A;}
	Base* get_right() {return B;}
	private:
		
		Base* A; Base* B;

};	
#endif
