#ifndef LISTENER_HPP
#define LISTENER_HPP

#include <Socket.hpp>

class Listener {
private:
    int port;
    int socketd;

public:
    Listener(int listenPort);

    Socket accept(void);
};

#endif
