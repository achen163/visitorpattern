#ifndef __MULT_HPP__
#define __MULT_HPP__

#include "base.hpp"

class Mult : public Base {
	public:
		Mult(Base* A, Base* B) : Base() { this->A = A; this->B = B; }
		virtual double evaluate() { return (A->evaluate()*B->evaluate()); }
		virtual string stringify() { return A->stringify()  + "*" + B->stringify(); }
		Iterator* create_iterator() {return new BinaryIterator(new Mult(A,B);}
		Base* get_left() {return A;}
		Base* get_right() {return B;}
	private:
		Base* A; Base* B;
};
#endif
