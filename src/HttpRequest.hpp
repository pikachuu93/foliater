#ifndef HTTP_REQUEST_HPP
#define HTTP_REQUEST_HPP

#include <string>

#include <Socket.hpp>

#include <HttpMethod.hpp>
#include <HttpHeader.hpp>

typedef std::string HttpPath;

class HttpRequest {
private:
    Socket *socket;

public:
    HttpMethod method;
    HttpPath path;
    std::string version;
    HttpHeader headers;

    void parseRequestLine(const std::string rawRequest);
    void parseHeaders(const std::string rawRequest);

    HttpRequest(Socket *socket);

};

#endif
