#ifndef SOCKET_HPP
#define SOCKET_HPP

#include <string>


class Socket {
private:
    int socket;

public:
    Socket(int socket);

    std::string read();
    void write(const std::string &buffer);
    void close(void);
};

#endif
