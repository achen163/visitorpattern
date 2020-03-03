#ifndef __VECTORCONTAINER_HPP__
#define __VECTORCONTAINER_HPP__

#include "container.hpp"

#include <vector>
#include <iostream>

using namespace std;

class VectorContainer: public Container {
	public: 
		VectorContainer() : Container() { }
		void set_sort_function(Sort* sort_function) {
			this->sort_function = sort_function;
		}
	
		virtual void add_element(Base* element) {
			vcontainer.push_back(element);
		}
		virtual void print() {
			for(unsigned i = 0; i < vcontainer.size(); i++) {
				cout << vcontainer.at(i)->evaluate() << endl;
			}	
		} 
		virtual void sort() {	
			if(sort_function == nullptr) 
				cout << "sort_function is null!" << endl;
			else 
				sort_function->sort(this);
		}	
			 
		virtual void swap(int i, int j) { 
			Base* temp = vcontainer.at(i);	
			vcontainer.at(i) = vcontainer.at(j);
			vcontainer.at(j) = temp;
		} 
		virtual Base* at(int i) { return vcontainer.at(i);  }
		virtual int size() { return vcontainer.size(); }
		
	private:
		vector<Base*> vcontainer;
};

#endif
