// Christopher Estock
// JSON Parsing -- Homework 2
// Object Oriented Programming


// Includes
#include "ESTOCK_JSON.h"
#include <string>
#include <cstdlib>
#include <iostream>
#include <fstream>
// Namespace
using namespace std;
// Prototypes
int JSON_parse(vector<char> json_string);
Object JSON_parse_object(vector<char> json_string, vector<char>::iterator &it);
Array JSON_parse_array(vector<char> json_string, vector<char>::iterator &it);
String JSON_parse_string(vector<char> json_string, vector<char>::iterator &it);

// https://www.reddit.com/r/front.json

int main(int argC, char** argV)
{

	// Use wget to fetch a json file from the URL provided. This will overwrite the file.json in the current project directory.
	string com = "C:\\Users\\student16\\Documents\\visual^ studio^ 2012\\Projects\\Estock_JSON_Homework2\\Estock_JSON_Homework2\\wget https://reddit.com/r/front.json --no-check-certificate -O file.json";
	system(com.c_str());

	// Open the json file.
	ifstream json_file;
	json_file.open("file.json");

	// Fill the newly allocated buffer with the file.
	vector<char> buffer;
	if(!json_file.eof() && !json_file.fail())
	{
		json_file.seekg(0, ios_base::end);
		streampos fileSize = json_file.tellg();
		buffer.resize(fileSize);

		json_file.seekg(0, ios_base::beg);
		json_file.read(&buffer[0], fileSize);

		printf("\n\nJSON File Read Success!\n%d Characters\n\n", buffer.size());
	}

	// Optional
	vector<char>::iterator it;
	for(it=buffer.begin(); it != buffer.end(); it++){
		cout << *it;
	}

	// Hold
	while(1);
}

// =============================================================================

int JSON_parse(vector<char> json_string){

	//
	//This is the primary method of the program.
	//INPUTS - A JSON-formatted string for parsing.
	//OUTPUTS - The weight of the JSON.
	//
	
	vector<char>::iterator it;

	for(it = json_string.begin(); it != json_string.end(); it++){
		//cout << *it;

		// Iterate through each character of the vector.
		// Object -- { "String" : Value }
		// Array  -- [ Value ]
		// String -- "Characters" -- ANY Unicode character except " or \ or control character (\", \\, \/, \b, \f, \n, \r, \t, \u)
		// Number -- C Numbers -- Digits (0-9), decimal (.), Scientific (e or E) followed by (+ or -) followed by digits.

		// '{' == 123 denotes the start of an object.
		if(*it == 123){
			JSON_parse_object(json_string, it);
		}
	}

	return;
}

Object JSON_parse_object(vector<char> json_string, vector<char>::iterator &it){
	// Use this is parse from the beginning of an object to the end of an object.
	// Likely used recursively.
	// Object starts with a string.
	Object obj;

	
	return obj;
}

Array JSON_parse_array(vector<char> json_string, vector<char>::iterator &it){
	// Use this to parse from the beginning of an array to the end of an array.
	// Likely used recursively.
	Array arr;


	return arr;
}

String JSON_parse_string(vector<char> json_string, vector<char>::iterator &it){
	// Use this to parse from the beginning of a string to the end of a string.
	// Not used recursively.
	String Str;


	return Str;
}
