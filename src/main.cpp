#include <iostream>

#include <Listener.hpp>
#include <Socket.hpp>
#include <HttpRequest.hpp>
#include <HttpResponse.hpp>
#include <HttpErrors.hpp>

const char *message = "HTTP/1.1 200 OK\r\nServer: Dans-awesome-server\r\nConnection: close\r\nContent-Length: 13\r\nContent-Type: text/html; charset=UTF-8\r\n\r\nHello, World!";

int main() {
    std::cout << "Hello, World!" << std::endl;

    Listener l(8080);

    while (true) {
        Socket s = l.accept();
        HttpRequest request(&s);
        HttpResponse response;

        try {
            response.headers.set("Server", "Dans-awesome-server");
            response.headers.set("Connection", "close");
            response.headers.set("Content-Length", "13");
            response.headers.set("Content-Type", "text/html");
            response.body = "Hello, World!";
            request.headers.set("sdkfj", "sjkdfhj");

            s.write(response.toString());
        } catch (HttpBaseException* e) {
            std::cerr << e->what() << std::endl;

            HttpResponse errResponse;
            errResponse.status = e->status;
            errResponse.body = e->what();

            errResponse.headers.set("Content-Length", errResponse.body.length());

            s.write(errResponse.toString());
        }

        s.close();

    }

    return 0;
}
