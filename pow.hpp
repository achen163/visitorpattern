#ifndef __POW_HPP__
#define __POW_HPP__

#include "base.hpp"
#include <cmath>

class Pow : public Base {
	public:
		Pow(Base* A, Base* B) : Base() { this->A = A; this->B = B; }
		virtual double evaluate() { return pow(A->evaluate(), B->evaluate()); }
		virtual std::string stringify() { return A->stringify()  + "**" + B->stringify(); }
		virtual Iterator* create_iterator() { return new BinaryIterator(this); }
		virtual Base* get_left() {return A;}
		virtual Base* get_right() {return B;}

		void accept(CountVisitor* cv) {
			cv->visit_pow();
		}
	private:
		Base* A; Base* B;
};
#endif
