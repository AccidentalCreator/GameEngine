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
		Exception(std::string _message);
		~Exception() throw();

		const char *What();



	private:
		std::string message;
	};

}



#endif