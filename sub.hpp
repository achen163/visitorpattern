#ifndef __SUB_HPP__
#define __SUB_HPP__

#include "base.hpp"

using namespace std;

class Sub : public Base {
	public:
		Sub(Base* A, Base* B) : Base() {this->A = A; this->B = B; }
		virtual double evaluate() { return (A->evaluate() - B->evaluate());}
		virtual string stringify() { return A->stringify() + " - " + B->stringify(); }
		Iterator* create_iterator() { }
	private:
		Base* A;
		Base* B;

};
#endif

