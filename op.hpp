#ifndef __OP_HPP__
#define __OP_HPP__

#include "base.hpp"

class Op : public Base {
    public:
        Op(double value) : Base() {this->value = value; }
        virtual double evaluate() { return value; }
        virtual std::string stringify() { return to_string(value); }
	Iterator* create_iterator() { return new NullIterator(new Op(value)); }
	Base* get_left() { return nullptr; }
	Base* get_right() { return nullptr; }
    private:
	double value;
};

#endif //__OP_HPP__
