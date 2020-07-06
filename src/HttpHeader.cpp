#include <HttpHeader.hpp>

#include <HttpErrors.hpp>

HttpHeader::HttpHeader(const std::string &rawHeaderString, bool writeable) :
    headers(),
    writeable(true)
{
    this->writeable = true;

    std::string unprocessed = std::string(rawHeaderString);

    for (
        size_t lineEnd = unprocessed.find("\r\n");
        lineEnd != std::string::npos;
        lineEnd = unprocessed.find("\r\n")
    ) {
        std::string headerLine = unprocessed.substr(0, lineEnd);
        std::size_t colon = headerLine.find(":");

        std::string headerName = headerLine.substr(0, colon);
        std::string headerValue = headerLine.substr(colon + 1);

        set(headerName, headerValue);

        unprocessed = unprocessed.substr(lineEnd + 2);
    }

    this->writeable = writeable;
}

std::string &HttpHeader::get(const std::string &headerName) {
    return headers[headerName];
}

void HttpHeader::set(const std::string &headerName, const int &headerValue) {
    std::string strVal = std::to_string(headerValue);

    this->set(headerName, strVal);
}

void HttpHeader::set(const std::string &headerName, const std::string &headerValue) {
    if (!writeable) {
        throw new HttpError::InternalServerError(
            "Cannot set read only headers. Attempted to set: '" +
            headerName +
            "' to value: '" +
            headerValue +
            "'."
        );
    }

    if (headers.find(headerName) != headers.end()) {
        headers[headerName] += ", " + headerValue;
    } else {
        headers[headerName] = headerValue;
    }
}

std::string HttpHeader::toString() {
    std::string res;

    for (auto const& pair : headers) {
        res += pair.first + ": " + pair.second + "\r\n";
    }

    return res;
}
