#ifndef SERVER_H
#define SERVER_H

#include <QObject>
#include <QList>
#include <QtWebSockets/QWebSocketServer>

#include "Game.h"

namespace BlitServer
{

class Client;

class Server : public QObject
{
    Q_OBJECT
public:
    explicit Server(quint16 port, QObject *parent = 0);
    ~Server();

signals:

public slots:
    /**
     * @brief start Starts the server
     */
    void start();

protected:
    void init();
    void discoverNewConnections();

    QWebSocketServer wsServer;
    QList<Client*> clients;
    quint16 port;
    Game game;
};

} // end BlitServer

#endif // SERVER_H
