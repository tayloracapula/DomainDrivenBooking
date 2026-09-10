#include <stdexcept>

class ApplicationException : public std::runtime_error{
public:
    explicit ApplicationException(
	const std::string& message)
    : std::runtime_error(message)
    {}
};

class NotFoundException : public ApplicationException
{
public:
    using ApplicationException::ApplicationException;
};

class AuthorisationException: public ApplicationException
{
public:
    using ApplicationException::ApplicationException;
};

class RepositoryException: public ApplicationException
{
public:
    using ApplicationException::ApplicationException;
};

class ValidationException: public ApplicationException
{
public:
    using ApplicationException::ApplicationException;
};
