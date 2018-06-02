#include "Function.hpp"
#include <iostream>

using std::cout;
using std::endl;

#define DEBUG 0

static void debug_print(const char* s){
	if(DEBUG) cout << s << endl;
}

Function* Function::_func;

void Function::addParamType(string type){
	_func->argumentTypes.push_back(type);
}

Function& Function::getCurrentFunc(){
	return *_func;
}
Function::Function(string id, string returnType){
	debug_print("in Function constructor");
	this->id = string(id);
	this->returnType = string(returnType);
	debug_print("Done");
	_func = this;
	debug_print("Done2");
	// todo : delete print statement
	//std::cout << "New function: " + id << std::endl;
}

Function::Function(){
	_func = this;
}

vector<string> Function::getArgumentTypes(){
	int size = argumentTypes.size();
	vector<string> v = vector<string>(size, "");
	list<string>::iterator it = argumentTypes.begin();
	for(int i = 0 ; it != argumentTypes.end(); i++, ++it){
		v[i] = it->c_str();
	}
	
	return v;
}

bool Function::checkTypeMatch(list<string> actualTypes){
	if(DEBUG){
		cout << "in function: " << id << endl;
		for(list<string>::iterator it = actualTypes.begin(); it != actualTypes.end(); ++it){
			cout << *it << ",";
		}
		cout << endl;
	}
	// case : function takes no arguments, and actualTypes is an empty list. 
	if(argumentTypes.size() == 0 && actualTypes.size() == 0) return true;
	if(argumentTypes.size() != actualTypes.size()) return false;
	list<string>::iterator it_exp = argumentTypes.begin();
	list<string>::iterator it_act = actualTypes.begin();
	for(; it_exp != argumentTypes.end(); ++it_exp, ++it_act){
		if(*it_exp != *it_act){
			if(!(*it_exp == "INT" && *it_act == "BYTE")){
				return false;
			}
		}
	}
	return true;
}



