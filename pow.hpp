#ifndef __POW_HPP__
#define __POW_HPP__

#include "base.hpp"
#include <cmath>

class Pow : public Base {
	public:
		Pow(Base* A, Base* B) : Base() { this->A = A; this->B = B; }
		virtual double evaluate() { return pow(A->evaluate(), B->evaluate()); }
		virtual string stringify() { return A->stringify()  + "**" + B->stringify(); }
		Iterator* create_iterator() { }
	private:
		Base* A; Base* B;
};
#endif
