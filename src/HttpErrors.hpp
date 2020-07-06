#include <exception>
#include <string>

#include <HttpStatus.hpp>

#include <HttpStatus.hpp>

class HttpBaseException : public std::exception {
    std::string message;

public:
    HttpStatus status;

    HttpBaseException(
        std::string message
    ) :
        std::exception(),
        message{ message },
        status{ 500, "Internal Server Error" }
    {};

    virtual const char *what() const throw (){
        return message.c_str();
    }
};

namespace HttpError {
    class InternalServerError : public HttpBaseException {
    public:
        InternalServerError(std::string message) :
            HttpBaseException{ message }
        {}
    };
    class BadRequest : public HttpBaseException {};
};
