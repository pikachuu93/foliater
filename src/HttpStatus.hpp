#ifndef HTTP_STATUS_HPP
#define HTTP_STATUS_HPP

#include <string>

typedef int HttpStatusCode;
typedef std::string HttpStatusString;

class HttpStatus {
public:
    HttpStatusCode code = 200;
    HttpStatusString string = "OK";

    HttpStatus() {};
    HttpStatus(HttpStatusCode code, HttpStatusString string) : code(code), string(string) {} ;
};

#endif
