#ifndef __OP_HPP__
#define __OP_HPP__

#include "base.hpp"

class Op : public Base {
    public:
        Op(double value) : Base() {this->value = value; }
        virtual double evaluate() { return value; }
        virtual std::string stringify() { return std::to_string(value); }
	virtual Iterator* create_iterator() { return new NullIterator(this); }
	virtual Base* get_left() { return nullptr; }
	virtual Base* get_right() { return nullptr; }

	void accept(CountVisitor* cv) {
		cv->visit_op();
	}
    private:
	double value;
};

#endif //__OP_HPP__
