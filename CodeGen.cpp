#include "CodeGen.hpp"
#include "bp.hpp"
#include "RegPool.hpp"
#include <vector>
#include <iostream>
#include <sstream>

using std::stringstream;
using std::cout;
using std::endl;
using std::vector;

void CodeGen::emitCode(){
	CodeBuffer::instance().printDataBuffer();
	cout << endl << endl;
	CodeBuffer::instance().printCodeBuffer();
	cout << endl << endl;
}


int CodeGen::emit(string s){
	return CodeBuffer::instance().emit(s);
}

string convertOpToAssembly(string op){
	if(op == "==") return "beq ";
	else if(op == "!=") return "bne ";
	else if(op == "<") return "blt ";
	else if(op == "<=") return "ble ";
	else if(op == ">") return "bgt ";
	else if(op == ">=") return "bge ";
	throw CodeGen::InvalidOperation();
	return "";
}


int CodeGen::emitCondBranch(string r1, string r2, string op){
	string instruction = convertOpToAssembly(op);
	// emits : instruction r1, r2, /* label will be added later */
	return emit(instruction + r1 + ", " + r2 + ", ");
}

int CodeGen::emitTrueCheck(string reg){
	return emit("bne " + reg + ", $zero, ");
}

int CodeGen::emitFalseCheck(string reg){
	return emit("beq " + reg + ", $zero, ");
}


int CodeGen::emitFunctionLabel(string s){
	CodeBuffer::instance().emit(".globl " + s);
	CodeBuffer::instance().emit(".ent " + s);
	return CodeBuffer::instance().emit(s + ":");
}

void CodeGen::popLocals(){
	CodeBuffer::instance().emit("addu $sp, $fp, 4 # pop function locals");
}

void CodeGen::emitReturn(){
	CodeBuffer::instance().emit("jr $ra # return");
}

list<string> CodeGen::saveRegs(){
	emit("# save registers");
	list<string> allocated_regs = RegPool::getAllocatedRegs();
	stringstream ss;
	ss << allocated_regs.size()*4;
	emit("subu $sp, $sp, " + ss.str());
	ss.str("");
	int i = 0;
	for(list<string>::iterator it = allocated_regs.begin(); it != allocated_regs.end() ; ++it){
		ss << i*4;
		emit("sw " + *it + ", " + ss.str() + "($sp)");
		RegPool::freeRegister(*it);
		i++;
		ss.str("");
	}
	emit("# end - save registers");
	//RegPool::freeAll();
	return allocated_regs;
}


void CodeGen::restoreRegs(list<string> regs){
	emit("# restore registers");
	stringstream ss;
	int i = regs.size()-1;
	for(list<string>::reverse_iterator it = regs.rbegin(); it != regs.rend() ; ++it){
		ss << i*4;
		emit("lw " + *it + ", " + ss.str() +"($sp)");
		RegPool::markUsed(*it);
		ss.str("");
		i--;
	}
	ss << regs.size()*4;
	emit("addu $sp, $sp, " + ss.str());
	emit("# end - restore registers");
}

void CodeGen::pushFramePointer(){
	emit("# push frame pointer");
	CodeBuffer::instance().emit("subu $sp, $sp, 4");
	CodeBuffer::instance().emit("sw $fp, ($sp)");
}

void CodeGen::pushReturnAddress(){
	emit("# push return address");
	CodeBuffer::instance().emit("subu $sp, $sp, 4");
	CodeBuffer::instance().emit("sw $ra, ($sp)");
}



void CodeGen::popReturnAddress(){
	emit("# pop return address");
	CodeBuffer::instance().emit("lw $ra, 0($sp)");
	CodeBuffer::instance().emit("addu $sp, $sp, 4");
}



void CodeGen::popFramePointer(){
	emit("# pop frame pointer");
	CodeBuffer::instance().emit("lw $fp, 0($sp)");
	CodeBuffer::instance().emit("addu $sp, $sp, 4");
}



void CodeGen::pushArguments(list<string> regList){
	emit("# push function arguments");
	stringstream ss;
	ss << regList.size()*4;
	emit("subu $sp, $sp, " + ss.str());
	ss.str("");
	int i = 0;
	for(list<string>::iterator it = regList.begin(); it != regList.end(); ++it){
		ss << i;
		emit("sw " + *it + ", " + ss.str() + "($sp)");
		RegPool::freeRegister(*it);
		i += 4;
		ss.str("");
	}
	
	emit("# end - push function arguments");
}



void CodeGen::popArguments(int n){
	emit("# pop function arguments");
	int offset = 4*n;
	stringstream ss;
	ss << "addu $sp, $sp, " << offset;
	CodeBuffer::instance().emit(ss.str());
}



void CodeGen::pushLocalVariable(string reg){
	emit("# push local variable: " + reg);
	CodeBuffer::instance().emit("subu $sp, $sp, 4");
	CodeBuffer::instance().emit("sw " + reg + ", ($sp)");
	RegPool::freeRegister(reg);
}


void CodeGen::pushLocalVariable(){
	emit("# push local variable");
	CodeBuffer::instance().emit("subu $sp, $sp, 4");
	CodeBuffer::instance().emit("sw $zero, ($sp)");
	emit("# end - push local variable");
}



void CodeGen::updateLocalVariable(int offset, string reg){
	offset *= -4;
	stringstream ss;
	ss << offset;
	CodeBuffer::instance().emit("sw " + reg + ", " + ss.str() + "($fp)" + " # update local variable");
	RegPool::freeRegister(reg);
}


	
void CodeGen::pushReg(string reg){
	emit("# push register: " + reg);
	CodeBuffer::instance().emit("subu $sp, $sp, 4");
	CodeBuffer::instance().emit("sw " + reg + ", ($sp)");
	RegPool::freeRegister(reg);
	emit("# end - push register: " + reg);
}


void CodeGen::popReg(string reg){
	emit("# pop register: " + reg);
	CodeBuffer::instance().emit("lw " + reg + ", ($sp)");
	CodeBuffer::instance().emit("addu $sp, $sp, 4");
	emit("# end - pop register: " + reg);
}


void CodeGen::writeToReg(string reg, int value){
	stringstream ss;
	ss << value;
	emit("li " + reg + ", " + ss.str() + " # write " + ss.str() + " to register " + reg);
}



void CodeGen::loadVariableValue(string id, string reg, int offset){
	stringstream ss;
	ss << -4*(offset);
	emit("lw " + reg + ", " + ss.str() + "($fp)" + " # load variable " + id + ". reg = " + reg);
}


void CodeGen::addDivByZeroCode(){
	CodeBuffer::instance().emitData(string("zeroDivErrStr: ") + ".asciiz " + "\"Error division by zero\\n\"");
	CodeBuffer::instance().emit(".globl zeroDivErr");
	CodeBuffer::instance().emit(".ent zeroDivErr");
	CodeBuffer::instance().emit("zeroDivErr:");
	
	// push address of error message
	CodeBuffer::instance().emit("la $a0, zeroDivErrStr");
	// syscall to print
	CodeBuffer::instance().emit("li $v0, 4");
	CodeBuffer::instance().emit("syscall");
	// terminate program
	CodeBuffer::instance().emit("li $v0, 10");
	CodeBuffer::instance().emit("syscall");
	endDeclaration("zeroDivErr");
}

void CodeGen::addPrintCode(){
	// emit code for printi
	CodeBuffer::instance().emit(".globl printi");
	CodeBuffer::instance().emit(".ent printi");
	CodeBuffer::instance().emit("printi:");
	CodeBuffer::instance().emit("lw $a0,0($sp)");
	CodeBuffer::instance().emit("li $v0,1");
	CodeBuffer::instance().emit("syscall");
	CodeBuffer::instance().emit("jr $ra");
	endDeclaration("printi");
	
	// emit code for print
	CodeBuffer::instance().emit(".globl print");
	CodeBuffer::instance().emit(".ent print");
	CodeBuffer::instance().emit("print:");
	CodeBuffer::instance().emit("lw $a0,0($sp)");
	CodeBuffer::instance().emit("li $v0,4");
	CodeBuffer::instance().emit("syscall");
	CodeBuffer::instance().emit("jr $ra");
	endDeclaration("print");
}



void CodeGen::addDivByZeroCheck(string reg){
	CodeBuffer::instance().emit("beqz " + reg + ", " + "zeroDivErr");
}




void CodeGen::endDeclaration(string s){
	CodeBuffer::instance().emit(".end " + s);
	CodeBuffer::instance().emit("\n\n");
}


void CodeGen::bpatch(const vector<int>& address_list, const string &loc){
	CodeBuffer::instance().bpatch(address_list, loc);
}


vector<int> CodeGen::newList(){
	return vector<int>();
}


vector<int> CodeGen::makelist(int litem){
	return CodeBuffer::makelist(litem);
}


vector<int> CodeGen::merge(const vector<int> &l1,const vector<int> &l2){
	return CodeBuffer::merge(l1, l2);
}

list<string> CodeGen::merge(const list<string>& l1, const list<string>& l2){
	list<string> newList(l1.begin(),l1.end());
	newList.insert(newList.end(),l2.begin(),l2.end());
	return newList;
}

string CodeGen::getNext(){
	string str = CodeBuffer::instance().next();
	//cout << "getNext : " << str << endl;	
	return str;
}


// returns a unique label for writing a string to the data section.
string getStringLabel(){
	static int i = 0;
	stringstream ss;
	ss << "str" << i;
	i++;
	return string(ss.str());
}

string CodeGen::emitStringData(string str){
	string label = getStringLabel();
	CodeBuffer::instance().emitData(label + ": " + ".asciiz " + str);
	return label;
}


void CodeGen::emitBoolOp(string dest, list<string> regs, string op){
	if(op == "not"){
		//emit("xor " + dest + ", " + regs.front() + ", 1");
		//RegPool::freeRegister(regs.front());
	}else{
		string r1 = regs.back();
		regs.pop_back();
		string r2 = regs.back();
		emit(op + " " + dest + ", " + r1 + ", " + r2);
		RegPool::freeRegister(r1);
		RegPool::freeRegister(r2);
	}
}

