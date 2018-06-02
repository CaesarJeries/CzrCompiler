#include "RegPool.hpp"
#include <iostream>
#include <sstream>

using std::stringstream;
using std::cout;
using std::endl;

RegPool* RegPool::instance = 0;

RegPool::RegPool(){
	pool = list<string>();
	allocated_regs = list<string>();
	stringstream ss;
	for(int i = 0; i <= 9 ; i++){
		ss << i;
		pool.push_back("$t" + ss.str());
		ss.str(std::string());
	}
	for(int i = 0; i <= 7 ; i++){
		ss << i;
		pool.push_back("$s" + ss.str());
		ss.str(std::string());
	}
}


void RegPool::init(){
	if(instance == NULL){
		instance = new RegPool();
	}
}

void RegPool::release(){
	int n = instance->pool.size();
	cout << "# RegPool: on exit, pool contains " << n << " free registers" << endl;
	if(n != 18){
		cout << "# Registers are not properly deallocated" << endl;
		for(list<string>::iterator it = instance->allocated_regs.begin() ; it != instance->allocated_regs.end(); ++it){
			cout << "# " << *it << endl;
		}
	}
	delete instance;
}


string RegPool::getRegister(){
	if(instance == NULL) throw RegPoolNotInitialized();
	if(instance->pool.size() == 0){
		delete instance;
		instance = new RegPool();
		//throw NoAvailableRegisters();
	}
	string retval = instance->pool.back();
	instance->allocated_regs.push_back(retval);
	instance->pool.pop_back();
	return retval;
}

bool RegPool::isSupported(string r){
	vector<string> regs = getRegisters();
	for(int i = 0; i < regs.size() ; ++i){
		if(r == regs[i]){
			return true;
		}
	}
	return false;
}

static bool contains(list<string> aList, string r){
	for(list<string>::iterator it = aList.begin() ; it != aList.end() ; ++it){
		if(*it == r) return true;
	}
	return false;
}

void RegPool::freeRegister(string r){
	if(r.empty()) return;
	if(instance == NULL){
		//cout << "# RegPool: instance == NULL" << endl;
		throw new RegPoolNotInitialized();
	}
	if(isSupported(r) == false){
		//cout << "# RegPool: isSupported(r) == false" << endl;
		if(r != "$v0"){
			throw new InvalidRegister();
		}
		return; // dont add "$v0" to the register pool
	}
	if(contains(instance->pool, r) == false){
		instance->pool.push_front(r);
		instance->allocated_regs.remove(r);
	}
	
}

void RegPool::freeRegister(list<string> regList){
	for(list<string>::iterator it = regList.begin() ; it != regList.end() ; ++it){
		freeRegister(*it);
	}
}


void RegPool::RegPool::freeAll(){
	delete instance;
	instance = new RegPool();
}


vector<string> RegPool::getRegisters(){
	vector<string> retval = vector<string>();
	stringstream ss;
	for(int i = 0; i <= 9 ; i++){
		ss << i;
		retval.push_back("$t" + ss.str());
		ss.str(std::string());
	}
	for(int i = 0; i <= 7 ; i++){
		ss << i;
		retval.push_back("$s" + ss.str());
		ss.str(std::string());
	}
	return retval;
}


void RegPool::markUsed(string reg){
	instance->pool.remove(reg);
	instance->allocated_regs.push_back(reg);
}

list<string> RegPool::getAllocatedRegs(){
	return instance->allocated_regs;
}
