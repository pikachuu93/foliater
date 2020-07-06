#include <HttpResponse.hpp>

#include <sstream>

HttpResponse::HttpResponse() :
    version("HTTP/1.1"),
    status(),
    body("")
{};

std::string HttpResponse::getStatusLine() {
    std::ostringstream ss;

    ss << version << " " << status.code << " " << status.string;

    return ss.str();
}

std::string HttpResponse::toString() {
    return (
        this->getStatusLine() +
        "\r\n" +
        this->headers.toString() +
        "\r\n" +
        body
    );
}
