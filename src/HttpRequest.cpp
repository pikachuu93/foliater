#include <HttpRequest.hpp>

#include <iostream>
#include <sstream>

HttpRequest::HttpRequest(Socket *socket) {
    this->socket = socket;
    std::string rawRequest = socket->read();

    while (rawRequest.find("\r\n\r\n") == std::string::npos) {
        rawRequest += socket->read();
    }

    this->parseRequestLine(rawRequest);
    this->parseHeaders(rawRequest);
}

void HttpRequest::parseRequestLine(const std::string rawRequest) {
    std::string methodString, pathString, versionString;

    std::stringstream ss(rawRequest);

    ss >> methodString >> pathString >> versionString;

    method = HttpMethod(methodString);
    path = HttpPath(pathString);
    version = versionString;

    std::cout << methodString << std::endl;
}

void HttpRequest::parseHeaders(const std::string rawRequest) {
    size_t headerStart = rawRequest.find("\r\n");
    size_t headerEnd = rawRequest.find("\r\n\r\n");

    std::string rawHeaders = rawRequest.substr(headerStart + 2, headerEnd);

    headers = HttpHeader(rawHeaders, false);
}
