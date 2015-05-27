/*
Developer: Enrique A Arzamendi
Date: 05/01/2015/


The one file to rule all the input checking files. This one was one of the longest parts of the program to
develop. Basically, it checks for the specified streams of input and output and then the content. Two strings are
given to it, one that asks for whatever we want it to get, and another one to say what will be shown if the given
infromation is wrong. The variable for it to be held is given, there is another function which works in a similar
fashion, but it does not require the variable be given to it as a parameter. This function particularly demonstrates 
a more advanced sense of templating.


Future note: This version will be called V 0.0.0.1 and will most likely involve oop in the future 
in the event of creating a library that handles different kinds of exceptions. The reason why I deter as most as
I can from exceptions is for the numerous articles that talk about the 


*/


#ifndef VERIFY_INPUT
#define VERIFY_INPUT

#include <iostream>
#include <string>
#include <limits>


//utilize input and output streams as well as a template that takes any type
template<typename AnyType> void GetInputGeneric(std::ostream & outputStream, std::istream & inputStream, const std::string & Display, const std::string & ErrorMessage, AnyType & EndResult)
{
	//Loop at least once to show the errors and input getters
	do
	{
		outputStream << Display.c_str();
		//if the process fails, clear the buffer and ignore the buffer limits, this
		//resets the buffer.
		if (inputStream.fail())
		{
			inputStream.clear();
			inputStream.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
		//otherwise the code will continue
		//The code will add to the given variable and check the information, if not the error message
		//will be appended to the output stream
		inputStream >> EndResult;
		if (inputStream.fail())
			outputStream << ErrorMessage.c_str();
	} while (inputStream.fail());//The main looping point, this idea came from the internet
								//it is a good and very interesting addition to such constructs because
								//it shows the true value of .fail() being given.
}

template<typename AnyType> AnyType GetInputGeneric(std::ostream & outputStream, std::istream & inputStream, const std::string & Display, const std::string & ErrorMessage)
{
	AnyType tholder;
	GetInputGeneric(outputStream, inputStream, Display, ErrorMessage, tholder);
	return tholder;
}

#endif