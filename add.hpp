#ifndef __ADD_HPP__
#define __ADD_HPP__

#include "base.hpp"

class Add : public Base {
	public:
		Add(Base* A, Base* B) : Base() { this->A = A; this->B = B; }
		virtual double evaluate() { return A->evaluate() + B->evaluate(); }
		virtual Iterator* create_iterator() {
			 return new BinaryIterator(this);
		}
		virtual Base* get_left() { return A; }
		virtual Base* get_right() { return B; }
		virtual std::string stringify() { return A->stringify() +  "+" +  B->stringify(); }
	private:
		Base* A; Base* B;
};
#endif

