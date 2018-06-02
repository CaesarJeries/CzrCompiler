#include "ScopeManager.hpp"
#include "CodeGen.hpp"
#include <iostream>
#include <sstream>

using namespace std;


#define DEBUG 0

static void debug_print(const char* s){
	if(DEBUG) cout << s << endl;
}

ScopeManager::ScopeManager(){
	scopes = list<Scope>();
	insideCaseDecl = stack<bool>();
	hasDefault = stack<bool>();
	debug_print("creating new scope");
	Scope global_scope = Scope(Scope::global_scope);
	debug_print("Global scope created");
	scopes.push_front(global_scope);
	debug_print("Global scope added to scope table");
}


void ScopeManager::addScope(Scope::ScopeType type){
	debug_print("Adding scope with return type");
	// insert at the beginning of the list.
	Scope new_scope = Scope(type);
	new_scope.setOffset(scopes.begin()->getOffset());
	scopes.insert(scopes.begin(), new_scope);
	debug_print("Done");
}

void ScopeManager::addScope(string returnType){
	scopes.insert(scopes.begin(), Scope(returnType));
	//hasDefault.push(false);
}


Scope ScopeManager::popScope(bool unwind_stack){
	Scope retval = scopes.front();
	scopes.pop_front();
	retval.print();
	if(unwind_stack){
		std::stringstream ss;
		ss << retval.getNumVarsDeclared();
		CodeGen::emit("# unwind stack due to exiting a block");
		CodeGen::emit("# total variables declared in block : " + ss.str());
		ss.str(std::string());
		ss << retval.getNumVarsDeclared()*4;
		CodeGen::emit("addu $sp, $sp, " + ss.str());
	}
	return retval;
}

bool ScopeManager::isDeclared(const string& var_id){
	for(list<Scope>::iterator it = scopes.begin() ; it != scopes.end() ; ++it){
		if(it->isDeclared(var_id)){
			return true;
		}
	}
	return false;
}

bool ScopeManager::isInsideWhileBlock(){
	list<Scope>::iterator it = scopes.begin();
	for(; it != scopes.end(); ++it){
		if(it->getType() == Scope::while_scope){
			return true;
		}	
	}
	return false;
}

bool ScopeManager::isInsideSwitchCase(){
	return insideCaseDecl.top();
}

void ScopeManager::addVar(Variable var){
	if(DEBUG){
		std::cout << "Adding var: " + var.getName() << std::endl;
	}
	scopes.begin()->addVar(var);
}

void ScopeManager::addParam(Variable var){
	if(DEBUG){
		std::cout << "Adding param: " + var.getName() << std::endl;
	}
	scopes.begin()->addParam(var);
}

string ScopeManager::getVarType(string id){
	for(list<Scope>::iterator it = scopes.begin() ; it != scopes.end() ; ++it){
		if(it->isDeclared(id)){
			return it->getVarType(id);
		}
	}
	return string("");
}


int ScopeManager::getVarOffset(string id){
	for(list<Scope>::iterator it = scopes.begin() ; it != scopes.end() ; ++it){
		if(it->isDeclared(id)){
			return it->getVarOffset(id);
		}
	}
	throw VariableNotFound();
}

bool isConvertable(string formalType, string actualType){
	return (formalType == "INT") && (actualType == "INT" || actualType == "BYTE");
}

/* @param followedByExp - true iff the return statement was followed by an expression.
*/
bool ScopeManager::checkReturnTypeMatch(string actualType, bool followedByExp){
	list<Scope>::iterator it = scopes.begin();
	for(; it != scopes.end(); ++it){
		if(it->isFunctionScope()){
			string returnType = it->getReturnType();
			if(returnType == "VOID" && followedByExp) return false;
			return (returnType == actualType) || isConvertable(returnType, actualType);
		}
	}
	return false;
}



void ScopeManager::enteredSwitchCase(){
	insideCaseDecl.top() = true;
}


void ScopeManager::exitedSwitchCase(){
	insideCaseDecl.top() = false;
}


void ScopeManager::enteredSwitchScope(){
	hasDefault.push(false);
	insideCaseDecl.push(false);
}



void ScopeManager::exitedSwitchScope(){
	hasDefault.pop();
	insideCaseDecl.pop();
}


void ScopeManager::defaultEncountered(){
	hasDefault.top() = true;
}

bool ScopeManager::hasDefaultStatement(){
	return hasDefault.top();
}
