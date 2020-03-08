#pragma once
#include <exception>
#include <string>

class RepositoryException :public std::exception
{
protected:
	std::string message;
public:
	RepositoryException(const std::string& message);
	~RepositoryException();
	const char* what();
};