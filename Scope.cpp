#include "Scope.hpp"
#include <iostream>

using std::cout;
using std::endl;

#define DEBUG 0

static void debug_print(const char* s){
	if(DEBUG) cout << s << endl;
}
Scope::Scope(ScopeType type){
	
	vars_declared = 0;
	local_offset = 0;
	param_offset = -1;
	ids = list<Variable>();
	this->type = type;
	returnType = string("VOID");
}

Scope::Scope(string returnType){
	vars_declared = 0;
	local_offset = 0;
	param_offset = -1;
	ids = list<Variable>();
	this->type = function_scope;
	this->returnType = returnType;
}

Variable Scope::getVar(string id){
	for(list<Variable>::iterator it = ids.begin(); it != ids.end(); ++it){
		if(it->getName() == id){
			return *it;
		}
	}
	return Variable();
}


void Scope::addVar(Variable var){
	var.setOffset(local_offset);
	local_offset++;
	vars_declared++;
	ids.push_back(var);
}

void Scope::addParam(Variable var){
	var.setOffset(param_offset);
	param_offset--;
	ids.push_front(var);
}

bool Scope::isDeclared(string id){
	for(list<Variable>::iterator it = ids.begin(); it != ids.end(); ++it){
		if(it->getName() == id){
			return true;
		}
	}
	return false;
}


vector<Variable> Scope::getVars(){
	vector<Variable> v;
	list<Variable> params = list<Variable>();
	list<Variable> vars = list<Variable>();
	list<Variable>::iterator it = ids.begin();
	for(; it != ids.end(); ++it){
		if(it->getOffset() < 0){
			params.push_front(*it);
		}else{
			vars.push_back(*it);
		}
	}
	for(it = params.begin(); it != params.end(); ++it){
		v.push_back(*it);
	}
	for(it = vars.begin(); it != vars.end(); ++it){
		v.push_back(*it);
	}
	
	return v;
}

void Scope::print(){
	/*
	cout << "Printing scope data:" << endl;
	cout << "has declarations: " << hasDecl << endl;
	for(map<string, Variable>::iterator it = ids.begin(); it != ids.end() ; ++it){
		cout << it->first << endl;
	}
	*/
}

string Scope::getVarType(string id){
	for(list<Variable>::iterator it = ids.begin(); it != ids.end(); ++it){
		if(it->getName() == id){
			return it->getType();
		}
	}
	return string("");
}

int Scope::getVarOffset(string id){
	for(list<Variable>::iterator it = ids.begin(); it != ids.end(); ++it){
		if(it->getName() == id){
			return it->getOffset();
		}
	}
	throw VariableNotFound();
}

