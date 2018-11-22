#pragma once
#ifndef EXCEPTION_H
#define EXCEPTION_H

#include <exception>
#include <string>

namespace GameEngine
{

	class Exception : public std::exception
	{
	public:
		Exception(std::string _message)
		{
			this->message = _message;
		}

		virtual ~Exception() throw()
		{

		}

		virtual const char* What() const throw()
		{
			return message.c_str();
		}



	private:
		std::string message;
	};

}



#endif