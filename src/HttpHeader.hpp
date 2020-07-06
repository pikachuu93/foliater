#ifndef HTTP_HEADER_HPP
#define HTTP_HEADER_HPP

#include <string>
#include <map>

class HttpHeader {
private:
    std::map<std::string, std::string> headers;
    bool writeable = true;

public:
    HttpHeader() = default;
    HttpHeader(const std::string &rawHeaderString, bool writeable = true);

    std::string &get(const std::string &headerName);
    void set(const std::string &headerName, const std::string &headerValue);
    void set(const std::string &headerName, const int &headerValue);

    std::string toString();
};

#endif
