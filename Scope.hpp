#ifndef _SCOPE_HPP_
#define _SCOPE_HPP_

#include "Variable.hpp"
#include <list>
#include <vector>
#include <exception>


using std::exception;
using std::list;
using std::vector;

class Scope {
	
public:
	enum ScopeType {
		function_scope,
		if_scope,
		else_scope,
		while_scope,
		switch_scope,
		global_scope,
		brace_scope
	};
private:	
	ScopeType type;
	int local_offset;
	int param_offset;
	int vars_declared;
	list<Variable> ids;
	string returnType;
public:

	class VariableNotFound : public exception {};
	explicit Scope(ScopeType);
	explicit Scope(string);
	/**
	getVar:
	get variable with matching id from the inner most scope.
	*/
	Variable getVar(string id);
	/**
	addVar:
	add variable declaration to current scope.
	*/
	void addVar(Variable var);
	/**
	addParam:
	add function parameter to current scope
	*/
	void addParam(Variable var);

	/**
	isDeclared:
	check if a variable with a matching id is declared in current or parent scopes.
	*/
	bool isDeclared(string id);
	vector<Variable> getVars();
	ScopeType getType(){ return type; }
	string getReturnType(){ return returnType; }
	bool isFunctionScope() { return type == function_scope; }
	string getVarType(string id);
	int getVarOffset(string id);
	void setOffset(int os) {local_offset = os;}
	int getOffset() {return local_offset;}
	int getNumVarsDeclared() const { return vars_declared; }
	void print();
};


#endif
