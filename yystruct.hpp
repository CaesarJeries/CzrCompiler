#ifndef _YYSTRUCT_HPP_
#define _YYSTRUCT_HPP_

#include <string>
#include <list>
#include <vector>


using std::vector;
using std::list;
using std::string;

typedef struct yyStruct{
	string name;
	string lexeme;
	string type;
	string expType;
	string reg;
	string label;
	string quad;
	string quad2;
	string defaultQuad;
	string op;
	int val;
	int line;
	
	list<string> regList;
	list<string> typeList;
	list<string> boolRegs;
	list<string> quadList;
	list<int> valueList;
	vector<int> returnList;
	vector<int> trueList;
    vector<int> falseList;
    vector<int> nextList;
	vector<int> breakList;
	yyStruct(): line(-1) {}
} yystype;

#define YYSTYPE yystype

#endif //_YYSTRUCT_HPP_
