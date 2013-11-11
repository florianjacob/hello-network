
#include "server.h"

#include <QTcpServer>
#include <QDebug>

#include "connection.h"

Server::Server(QObject* parent): QObject(parent)
{
	tcpServer = new QTcpServer(this);
	tcpServer->listen(QHostAddress::Any, 61377);
	if (!tcpServer->isListening()) {
		qDebug() << "Unable to start server:" << tcpServer->errorString();
		tcpServer->close();
		return;
	}

	qDebug() << "Server listening on port" << tcpServer->serverPort();

	connect(tcpServer, SIGNAL(newConnection()), this, SLOT(acceptConnection()));
}


void Server::acceptConnection()
{
	QTcpSocket* socket = tcpServer->nextPendingConnection();
	Connection* connection = new Connection(this, socket);
	qDebug() << "Acccepted new connection";
}
