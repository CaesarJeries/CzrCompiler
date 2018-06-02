#ifndef _VARIABLE_HPP_
#define _VARIABLE_HPP_

#include <string>

using std::string;

class Variable {
	string name;
	string type;
	int offset;
	int value;
	bool offsetValid, valueValid;
public:
	Variable();
	Variable(string name, string type, int offset, int value);
	Variable(string name, string type);
	string getName() { return name; }
	string getType() { return type; }
	int getOffset() { return this->offset; }
	int getValue() { return value; }
	void setOffset(int offset);
	void setValue(int value) { this->value = value; }
	bool operator<(const Variable& v);
	bool operator==(const Variable& v);
	bool operator!=(const Variable& v);
};

#endif
