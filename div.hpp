#ifndef _DIV_HPP_
#define _DIV_HPP_

#include "base.hpp"

using namespace std;

class Div: public Base {
	public:
		Div(Base* A,Base* B) {this->A = A; this->B = B;}	
		virtual double evaluate() {return( A->evaluate() / B->evaluate());}
		virtual std::string stringify() {return (A->stringify() + " / " + B->stringify());}
		virtual Iterator* create_iterator() {return new BinaryIterator(this); }
		virtual Base* get_left() {return A;}
		virtual Base* get_right() {return B;}
	
		void accept(CountVisitor* cv) {
			cv->visit_ceil();
		}
	private:
		
		Base* A; Base* B;

};	
#endif
