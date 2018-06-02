#include "Scope.hpp"
#include <list>
#include <string>
#include <stack>
#include <exception>

using std::exception;
using std::string;
using std::list;
using std::stack;

class ScopeManager{
	list<Scope> scopes;
	stack<bool> insideCaseDecl;
	stack<bool> hasDefault;
	
public:

	class VariableNotFound : public exception {};
	ScopeManager();
	void addVar(Variable);
	void addParam(Variable);
	/**
		@param - mustHaveDecl:
		The scope must contain at least one variable declaration in
		order to be considered a new scope.
	*/
	void addScope(Scope::ScopeType type);
	void addScope(string returnType);
	bool checkReturnTypeMatch(string actualType, bool);
	Scope popScope(bool unwind_stack);
	bool isDeclared(const string& var_id);
	string getVarType(string id);
	int getVarOffset(string id);
	bool isInsideWhileBlock();
	bool isInsideSwitchCase();
	void enteredSwitchCase();
	void exitedSwitchCase();
	void enteredSwitchScope();
	void exitedSwitchScope();
	void defaultEncountered();
	bool hasDefaultStatement();
};
