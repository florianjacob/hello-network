
#include "connection.h"
#include <QTcpSocket>
#include <QDebug>


Connection::Connection(Server* parent, QTcpSocket* socket) : QObject(parent)
{
	this->socket = socket;
	connect(socket, SIGNAL(readyRead()), this, SLOT(read()));
	connect(this, SIGNAL(lineRead(const QString&)), this, SLOT(sendLine(const QString&)));

	// cleanup on disconnect
	connect(socket, SIGNAL(disconnected()), socket, SLOT(deleteLater()));
	connect(socket, SIGNAL(disconnected()), this, SLOT(deleteLater()));
}

void Connection::read()
{
	buffer += socket->read(socket->bytesAvailable());
	qDebug() << "received bytes.";
	if (buffer.endsWith('\n')) {
		qDebug() << "received a line:" << buffer;
		emit lineRead(QString{buffer});
		buffer.clear();
	}
}

void Connection::sendLine(const QString& line)
{
	QByteArray buffer;
	buffer.append(line);
	socket->write(buffer);
	qDebug() << "sent out a line";
}


Connection::~Connection()
{
	qDebug() << "Connection closed.";
}
