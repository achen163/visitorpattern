#ifndef __FACTORY_HPP__
#define __FACTORY_HPP__
#include "base.hpp"
#include "add.hpp"
#include "sub.hpp"
#include "mult.hpp"
#include "div.hpp"
#include "pow.hpp"
#include "op.hpp"
#include <boost/tokenizer.hpp>
#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <stdio.h>
#include <stdlib.h>
using namespace std; 

class Factory {
	public:
		Factory() {};
		Base* createAdd(Base*, Base*);
		Base* createSub(Base*, Base*);
		Base* createMult(Base*, Base*);
		Base* createDiv(Base*, Base*);
		Base* createPow(Base*, Base*);
		Base* parser(int, char**);

};
#endif
