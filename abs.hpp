#ifndef __ABS_HPP__
#define __ABS_HPP__
#include "decorator.hpp"

class Abs : public Decorator {
	public:
		Abs(Base* value) : Decorator() { this->value = value; }
	 	virtual double evaluate() { abs(value->evaluate()); }
		virtual std::string stringify() {}
		virtual Iterator* create_iterator() { return new UnaryIterator(this);}
		virtual Base* get_left() { return value;}
		virtual Base* get_right() { return nullptr; }

		void accept(CountVisitor* cv) {
			cv->visit_abs();
		}
	private:
		Base* value;
};
#endif
