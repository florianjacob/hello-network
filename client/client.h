#ifndef CLIENT_H
#define CLIENT_H

#include <QTcpSocket>

class Client : public QObject {
	Q_OBJECT

public:
	Client(QObject* parent = nullptr);

signals:
	void lineReceived(const QString& line);
	void error(const QString& error);

public slots:
	void sendLine(const QString& line);

private slots:
	void read();
	void forwardError(QAbstractSocket::SocketError socketError);

private:
	QTcpSocket* socket;
	QByteArray buffer;
};

#endif
