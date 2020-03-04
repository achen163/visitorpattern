#include "factory.hpp"

Base* Factory::createAdd(Base* left, Base* right) {
	Base* a = new Add(left, right);
	return a;
}

Base*  Factory::createSub(Base* left, Base* right) {
	Base* s = new Sub(left, right);
	return s;
}

Base*  Factory::createMult(Base* left, Base* right) {
        Base* m = new Mult(left, right);
	return m;
}

Base*  Factory::createDiv(Base* left, Base* right) {
        Base* d = new Div(left, right);
	return d;
}

Base*  Factory::createPow(Base* left, Base* right) {
        Base* p = new Pow(left, right);	
	return p;
}


Base* Factory::parser(int argc, char** argv) {
	if(argc <= 2) {
		cerr << "Error. Invalid input." << endl;
		return nullptr;
	}
	else {
		double value = stod(argv[1]); 
		Base* left = new Op(value);
	
		string expression = "";
		double leftVal = left->evaluate();

		for(int i = 2; i < argc; ++i) {
			if(*(argv[i]) == '+') { 
				Base* right = new Op(stod(argv[i+1]));	
				left = createAdd(left, right);
				leftVal = left->evaluate();
				expression = left->stringify();
			}
			else if(*(argv[i]) == '-') {
                      	  Base* right = new Op(stod(argv[i+1]));
                        	left = createSub(left, right);
				leftVal = left->evaluate();
				expression = left->stringify();
        	        }	
			else if((argv[i][1]) == '*') { // pow?
				Base* right = new Op(stod(argv[i+1]));
				left = createPow(left, right);
				leftVal = left->evaluate();
				expression = left->stringify();
			}
			else if((argv[i][0]) == '*') {
       	                 Base* right = new Op(stod(argv[i+1]));
				left = createMult(left, right);
				leftVal = left->evaluate();
				expression = left->stringify();
       	        	 }
	  		else if(*(argv[i]) == '/') {
       	  	                Base* right = new Op(stod(argv[i+1]));
      	                        left = createDiv(left, right);	
				leftVal = left->evaluate();
				expression = left->stringify();
                	}
		}
		//cout << expression << endl; //print stringify()
		//left = new Op(leftVal);
		return left;
	}
}	
