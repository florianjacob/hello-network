#ifndef SERVER_H
#define SERVER_H

#include <QObject>
class QTcpServer;

class Server : public QObject {
	Q_OBJECT
public:
	Server(QObject* parent = nullptr);

private slots:
	void acceptConnection();

private:
	QTcpServer* tcpServer;
};

#endif