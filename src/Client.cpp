#include "Client.h"

#include <QtWebSockets/QWebSocket>

using namespace BlitServer;

Client::Client(QWebSocket * socket, QObject *parent) :
    QObject(parent),
    socket(socket)
{
    connect(socket, &QWebSocket::textMessageReceived,
            this,   &Client::messageReceived);
    connect(socket, &QWebSocket::disconnected,
            this,   &Client::disconnected);
}

Client::~Client()
{
    delete socket;
}

Message * Client::getInput()
{
    return nullptr;
}

void Client::sendTextMessage(const Message & message)
{
    socket->sendTextMessage(message.toJson(QJsonDocument::Compact));
}

void Client::messageReceived(QString message)
{

}
