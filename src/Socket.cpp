#include <Socket.hpp>

#include <sys/socket.h>
#include <unistd.h>

Socket::Socket(int socket) : socket(socket) {
    int timeout = 100;
    setsockopt(socket, 0, SO_RCVTIMEO, &timeout, sizeof(int));
};

std::string Socket::read() {
    std::string buffer(1, '\0');
    size_t read = recv(socket, &buffer[0], buffer.length(), 0);

    return buffer;
}

void Socket::write(const std::string &buffer) {
    size_t sent = 0, toWrite = buffer.length();
    const char *bufferData = buffer.c_str();

    while (sent < toWrite) {
        sent += send(socket, bufferData + sent, toWrite - sent,0);
    }
}

void Socket::close(void) {
    ::shutdown(socket, SHUT_RDWR);
    ::close(socket);
}
