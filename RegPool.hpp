#ifndef _REG_POOL_HPP_
#define _REG_POOL_HPP_

#include <list>
#include <string>
#include <exception>
#include <vector>

using std::vector;
using std::exception;
using std::string;
using std::list;

class RegPool{
	static RegPool* instance;
	RegPool();
	list<string> pool;
	list<string> allocated_regs;
	static bool isSupported(string r);
public:
	struct RegPoolNotInitialized : public exception{
		const char * what () const throw (){
			return "Using an uninitialized register pool";
		}
	};
	struct InvalidRegister : public exception{
		const char * what () const throw (){
			return "Invalied register name";
		}
	};
	struct NoAvailableRegisters : public exception{
		const char * what () const throw (){
			return "There are no available registers in the register pool";
		}
	};
	static void init();
	static void release();
	static string getRegister();
	static void freeRegister(string r);
	static void freeRegister(list<string> regList);
	static void freeAll();
	static vector<string> getRegisters();
	
	static void markUsed(string reg);
	static list<string> getAllocatedRegs();
};



#endif
