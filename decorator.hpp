#ifndef __DECORATOR_HPP__
#define __DECORATOR_HPP__
#include "base.hpp"
#include <math.h>
#include <iostream>
#include <string>

using namespace std;
class Decorator : public Base {
	public:
		Decorator() { }	
		virtual double evaluate() = 0;
		virtual string stringify() = 0;
};
#endif
