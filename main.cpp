#include "iterator.hpp"
#include "factory.hpp"
#include "paren.hpp"

#include <iostream>
using namespace std; 

int main(int argc, char** argv) {
	Factory* f = new Factory();
	Base* node = f->parser(argc, argv);
	Base* dummyNode = new Paren(node);
	
	CountVisitor* visitorCount = new CountVisitor();

	Iterator* preorder = new PreorderIterator(dummyNode);
	preorder->first();

	while(!preorder->is_done()) {
		preorder->current()->accept(visitorCount);
		preorder->next();
	}
	
	cout << "op count: " << visitorCount->op_count() << endl;
	cout << "rand count: " << visitorCount->rand_count() << endl;
	cout << "mult count: " << visitorCount->mult_count() << endl;
	cout << "div count: " << visitorCount->div_count() << endl;
	cout << "add count: " << visitorCount->add_count() << endl;
	cout << "sub count: " << visitorCount->sub_count() << endl;
	cout << "pow count: " << visitorCount->pow_count() << endl;
		
	
return 0;
}
