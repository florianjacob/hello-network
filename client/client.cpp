
#include "client.h"

#include <QHostAddress>
#include <QDebug>

Client::Client(QObject* parent) : QObject(parent)
{
	socket = new QTcpSocket(this);

	connect(socket, SIGNAL(readyRead()), this, SLOT(read()));
	connect(socket, SIGNAL(error(QAbstractSocket::SocketError)), this, SLOT(forwardError(QAbstractSocket::SocketError)));

	// cleanup on disconnect
	connect(socket, &QTcpSocket::disconnected, []() {qDebug() << "disconnected";});
	connect(socket, SIGNAL(disconnected()), socket, SLOT(deleteLater()));
	connect(socket, SIGNAL(disconnected()), this, SLOT(deleteLater()));


	socket->connectToHost(QHostAddress::LocalHost, 61377);
}

void Client::sendLine(const QString& line)
{
	QByteArray buffer;
	buffer.append(line);
	socket->write(buffer);
}


void Client::read()
{
	buffer += socket->read(socket->bytesAvailable());
	if (buffer.endsWith('\n')) {
		QString line{buffer};
		emit lineReceived(QString{"Received: %1"}.arg(line));
		buffer.clear();
	}
}

void Client::forwardError(QAbstractSocket::SocketError socketError)
{
	emit error(QString{"Connection error: %1"}.arg(socket->errorString()));
}
