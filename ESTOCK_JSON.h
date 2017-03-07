#ifndef _ESTOCK_JSON_H_
#define _ESTOCK_JSON_H_

#include <stdlib.h>
#include <string>
#include <vector>
#include <cstdint>

using namespace std;

// Base class value
struct value {
	public:
		virtual ~value();
		value(bool B)
		{
			// Boolean Constructor
		}
		value(string S)
		{
			// String Constructor
		}
		value(double N)
		{
			// Number Constructor
		}
		value(vector<value*> A)
		{
			// Array Constructor
		}
		value(vector<pair<string,value*>> O)
		{
			// Object Constructor
		}
		value()
		{
			// Default Constructor
		}
};

// Derived classes -- null, Bool, String, Number, Array, Object
struct Null : public value {
};
struct Bool : public value {
	public:
		Bool(bool B){}
		bool B;
		Bool(){}
};
struct String : public value{
	public:
		String(std::string S){}
		std::string S;
		String(){}
};
struct Number : public value {
public:
		Number(double N){}
		double N;
		Number(){}
};
struct Array : public value {
	public:
		Array(vector<value*> Arr){}
		vector<value*> Arr;
		Array(){}
};
// For object, using vector of pairs because I am most familiar with it.
struct Object : public value {
	public:
		Object(vector<pair<string,value*> > Obj){}
		vector<pair<string,value*> > Obj;
		Object(){}
};


#endif