#ifndef _CODE_GEN_HPP_
#define _CODE_GEN_HPP_

#include <list>
#include <string>
#include <vector>
#include <exception>

using std::list;
using std::vector;
using std::exception;
using std::string;

namespace CodeGen{
	class InvalidOperation : public exception {};
	void emitCode();
	int emit(string s);
	int emitCondBranch(string r1, string r2, string op);
	int emitTrueCheck(string reg);
	int emitFalseCheck(string reg);
	int emitFunctionLabel(string s);
	void popLocals();
	void emitReturn();
	list<string> saveRegs();
	void restoreRegs(list<string>);
	void pushFramePointer();
	void pushReturnAddress();
	void popReturnAddress();
	void popFramePointer();
	void pushArguments(list<string>);
	void popArguments(int);
	void pushLocalVariable(string reg);
	// used for pushing an uninitialized local variable
	// variable is initialized to 0 as default value
	void pushLocalVariable();
	void updateLocalVariable(int offset, string reg);
	void pushReg(string reg);
	void popReg(string reg);
	void writeToReg(string, int);
	void loadVariableValue(string id, string reg, int offset);
	void addDivByZeroCode();
	void addPrintCode();
	void addDivByZeroCheck(string reg);
	void endDeclaration(string s);
	
	void bpatch(const vector<int>& address_list, const string &loc);
	/*	List handling	*/
	vector<int> newList();
	vector<int> makelist(int litem);
	vector<int> merge(const vector<int> &l1,const vector<int> &l2);
	list<string> merge(const list<string>& l1, const list<string>& l2);
	/*	Label handling	*/
	string getNext();
	string emitStringData(string);
	
	void emitBoolOp(string dest, list<string> regs, string op);
};

#endif

