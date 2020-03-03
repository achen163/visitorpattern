#ifndef _RAND_HPP_
#define _RAND_HPP_

#include "base.hpp"
#include <stdlib.h>
#include <time.h>

using namespace std;

class Rand : public Base {
	public:
		Rand(){ this->randnum = rand()%100;}
		virtual double evaluate()  { return randnum; }
		virtual string stringify() { return to_string(randnum); }
		Iterator* create_iterator() {return NullIterator(this); }              
		Base* get_left() {return A;}
		Base* get_right() {return nullptr;}
	private:
	double	randnum;



};
#endif

