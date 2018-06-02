#include "Variable.hpp"


Variable::Variable(){
	name = type = "undefined";
	this->offset = 0;
	this->value = 0;
	offsetValid = valueValid = false;
}

Variable::Variable(string name, string type, int offset, int value){
	this->name = string(name);
	this->type = string(type);
	this->offset = offset;
	this->value = value;
	offsetValid = true;
	valueValid = true;
}

Variable::Variable(string name, string type) {
	this->name = string(name);
	this->type = string(type);
	this->offset = 0;
	this->value = 0;
	offsetValid = valueValid = false;
}

void Variable::setOffset(int offset){
	this->offset = offset;
	offsetValid = true;
}


bool Variable::operator==(const Variable & v){
	return name == v.name;
}

bool Variable::operator!=(const Variable & v){
	return !(*this == v);
}
