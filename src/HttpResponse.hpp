#ifndef HTTP_RESPONSE_HPP
#define HTTP_RESPONSE_HPP

#include <string>

#include <Socket.hpp>

#include <HttpHeader.hpp>
#include <HttpStatus.hpp>

typedef std::string HttpPath;

class HttpResponse {
private:
public:
    Socket *socket;
    std::string version;
    HttpHeader headers;
    HttpStatus status;
    std::string body;

    std::string getStatusLine();

    HttpResponse();

    std::string toString();
};

#endif
