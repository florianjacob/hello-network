#ifndef CONNECTION_H
#define CONNECTION_H
#include <QObject>

#include "server.h"
class QTcpSocket;

class Connection : public QObject {
	Q_OBJECT
public:
	Connection(Server* parent, QTcpSocket* socket);
    virtual ~Connection();

private slots:
	void read();
	void sendLine(const QString& line);

signals:
	void lineRead(const QString& line);

private:
	QTcpSocket* socket;
	QByteArray buffer;

};

#endif