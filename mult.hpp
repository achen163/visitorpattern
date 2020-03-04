#ifndef __MULT_HPP__
#define __MULT_HPP__

#include "base.hpp"

class Mult : public Base {
	public:
		Mult(Base* A, Base* B) : Base() { this->A = A; this->B = B; }
		virtual double evaluate() { return (A->evaluate()*B->evaluate()); }
		virtual std::string stringify() { return A->stringify()  + "*" + B->stringify(); }
		virtual Iterator* create_iterator() {return new BinaryIterator(this);}
		virtual Base* get_left() {return A;}
		virtual Base* get_right() {return B;}

		void accept(CountVisitor* cv) {
			cv->visit_mult();
		}
	private:
		Base* A; Base* B;
};
#endif
