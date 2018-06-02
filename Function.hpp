#ifndef _FUNCTION_HPP_
#define _FUNCTION_HPP_

#include <string>
#include <list>
#include <vector>

using std::vector;
using std::list;
using std::string;

class Function {
	static Function* _func;
	string id;
	string returnType;
	list<string> argumentTypes;
public:
	static void addParamType(string type);
	static Function& getCurrentFunc();
	Function();
	Function(string id, string returnType);
	string getID() { return id; }
	string getReturnType() { return returnType; }
	vector<string> getArgumentTypes();
	bool checkTypeMatch(list<string>);
	bool hasArguments() { return argumentTypes.size() > 0;}
	
};

#endif
