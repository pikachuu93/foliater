#ifndef HTTP_METHOD_HPP
#define HTTP_METHOD_HPP

#include <string>

class HttpMethod
{
public:
  enum Method : uint8_t
  {
    GET,
    POST,
    PUT,
    PATCH,
    DELETE
  };

  HttpMethod() = default;
  constexpr HttpMethod(Method aHttpMethod) : value(aHttpMethod) { }

  HttpMethod(const std::string &methodString) {
      if (methodString == "POST") {
          value = POST;
      } else if (methodString == "PUT") {
          value = PUT;
      } else if (methodString == "PATCH") {
          value = PATCH;
      } else if (methodString == "DELETE") {
          value = DELETE;
      } else {
          value = GET;
      }
  }

  operator Method() const { return value; }
  explicit operator bool() = delete;
  constexpr bool operator==(HttpMethod a) const { return value == a.value; }
  constexpr bool operator!=(HttpMethod a) const { return value != a.value; }

private:
  Method value;
};

#endif
