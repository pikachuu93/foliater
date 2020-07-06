#include <Listener.hpp>

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

Listener::Listener(int listenPort) : port(listenPort) {
    struct sockaddr_in addr;

    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = INADDR_ANY; 
    addr.sin_port = htons(port); 

    socketd = socket(AF_INET, SOCK_STREAM, 0);

    int reuse = 1;
    setsockopt(socketd, SOL_SOCKET, SO_REUSEADDR, &reuse, sizeof(int));

    bind(socketd, (struct sockaddr*)&addr, sizeof(addr));
    listen(socketd, 5);
}

Socket Listener::accept() {
    return Socket(::accept(socketd, (struct sockaddr*)nullptr, 0));
}
