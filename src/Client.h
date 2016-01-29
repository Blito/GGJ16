#ifndef CLIENT_H
#define CLIENT_H

#include <QObject>
#include <QJsonDocument>

class QWebSocket;

namespace BlitServer
{

using Message = QJsonDocument;

class Client : public QObject
{
    Q_OBJECT
public:
    explicit Client(QWebSocket * socket, QObject *parent = 0);
    ~Client();

    Message * getInput();

signals:
    void disconnected();

public slots:
    void sendTextMessage(const Message & message);

protected slots:
    void messageReceived(QString message);

protected:
    QWebSocket * socket = nullptr;
};

} // end BlitServer

#endif // CLIENT_H
