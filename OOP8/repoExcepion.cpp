#include "repoExcepion.h"

RepositoryException::RepositoryException(const std::string & initMessage) : message{initMessage}
{
}

RepositoryException::~RepositoryException()
{
}

const char * RepositoryException::what()
{
	return this->message.c_str();
}