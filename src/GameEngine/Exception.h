#pragma once
#ifndef EXCEPTION_H
#define EXCEPTION_H

#include <exception>
#include <string>

namespace GameEngine
{
	/**
	* Handles any thrown exceptions and outputs the to the console
	*/
	class Exception : public std::exception
	{
	public:
		/// Takes a message parameter to be outputted in the console
		Exception(std::string _message)
		{
			this->message = _message;
		}

		/// Exception deconstructor
		virtual ~Exception() throw()
		{

		}

		/// Outputs the thrown exception message 
		virtual const char* What() const throw()
		{
			return message.c_str();
		}



	private:
		std::string message;
	};

}



#endif