#ifndef _FUNCTION_TABLE_HPP_
#define _FUNCTION_TABLE_HPP_

#include <string>
#include <list>
#include <vector>
#include "Function.hpp"

using std::list;
using std::vector;
using std::string;

class FunctionTable {
	list<Function> functions;
public:
	FunctionTable();
	void addFunction(Function& f);
	bool isDeclared(string id);
	list<Function> getFunctions(){ return functions; }
	bool checkTypeMatch(string id, list<string> actualTypeList);
	bool isMainDefined();
	vector<string> getArgumentTypes(string id);
	string getReturnType(string id);
	
};


#endif
