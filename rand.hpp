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
		virtual std::string stringify() { return to_string(randnum); }
		virtual Iterator* create_iterator() {return NullIterator(this); }              
		virtual Base* get_left() {return nullptr;}
		virtual Base* get_right() {return nullptr;}
		
		void accept(CountVisitor* cv) {
			cv->visit_rand();
		}
	private:
	double	randnum;



};
#endif

