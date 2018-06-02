#include "FunctionTable.hpp"

#include <iostream>

#define DEBUG 0

using std::cout;
using std::endl;


static void debug_print(const char* s){
	if(DEBUG) cout << s << endl;
}

FunctionTable::FunctionTable(){
	debug_print("Initializing function table");
	functions = list<Function>();
	
	debug_print("Adding print function");
	// Add void print(string)
	Function print_function = Function("print", "VOID");
	debug_print("Function created");
	Function::addParamType("STRING");
	debug_print("Parameter types set");
	functions.push_back(print_function);
	
	debug_print("Adding printi function");
	// Add void printi(int)
	Function printi_function = Function("printi", "VOID");
	Function::addParamType("INT");
	functions.push_back(printi_function);
}



void FunctionTable::addFunction(Function& f){
	functions.push_back(f);
}


bool FunctionTable::isDeclared(string id){
	list<Function>::iterator it = functions.begin();
	for(; it != functions.end() ; ++it){
		if(it->getID() == id) return true;
	}
	return false;
}



bool FunctionTable::checkTypeMatch(string id, list<string> actualTypeList){
	list<Function>::iterator it = functions.begin();
	for(; it != functions.end() ; ++it){
		if(it->getID() == id) return it->checkTypeMatch(actualTypeList);
	}
	return false;
}


bool FunctionTable::isMainDefined(){
	for(list<Function>::iterator it = functions.begin(); it != functions.end(); ++it){
		if(it->getID() == "main"){
			if(it->getReturnType() != "VOID"){
				return false;
			}
			if(it->hasArguments()){
				return false;
			}
			return true;
		}
	}
	return false;
}


vector<string> FunctionTable::getArgumentTypes(string id){
	vector<string> retval;
	list<Function>::iterator it = functions.begin();
	for(; it != functions.end() ; ++it){
		if(it->getID() == id){
			retval = it->getArgumentTypes();
		}
	}
	return retval;
}

string FunctionTable::getReturnType(string id){
	list<Function>::iterator it = functions.begin();
	for(; it != functions.end() ; ++it){
		if(it->getID() == id){
			return it->getReturnType();
		}
	}
}

