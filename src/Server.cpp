#include "Server.h"

#include <QtWebSockets/QWebSocket>

using namespace BlitServer;

Server::Server(quint16 port, QObject * parent) :
    QObject(parent),
    wsServer(QString("BlitServer"), QWebSocketServer::NonSecureMode, this),
    port(port)
{

}

Server::~Server()
{
    wsServer.close();
}

void Server::start()
{
    init();

    while (true)
    {
        discoverNewConnections();

        // Read input from clients and update game state
        Message * msg = nullptr;
        for (auto client : clients)
        {
            if ((msg = client->getInput()))
            {
                game.newInput(*msg);
            }
        }

        // Update game state
        auto newState = game.update(std::chrono::milliseconds(30));

        // Send changes to clients
        for (auto client : clients)
        {
            client->sendTextMessage(newState);
        }
    }
}

void Server::init()
{
    wsServer.listen(QHostAddress::Any, port);

    game.init();
}

void Server::discoverNewConnections()
{
    QWebSocket * socket = nullptr;
    while ((socket = wsServer.nextPendingConnection()))
    {
        auto client = new Client(socket);

        // Remove client on disconnection
        connect(client, &Client::disconnected,
                [this]
                {
                    auto client = qobject_cast<Client*>(sender());
                    clients.removeOne(client);
                });

        clients << client;
    }
}
