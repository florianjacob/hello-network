#include <QApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QtQml>

#include "client.h"

int main(int argc, char* argv[])
{
	Q_INIT_RESOURCE(qmlfiles);

	QApplication app(argc, argv);
	QQmlApplicationEngine engine;
	Client client;

	engine.rootContext()->setContextProperty("client", &client);
	engine.load(QUrl("qrc:/client.qml"));

	/*
	 * Glueing everything together is done in QML here, but
	 * if one would want to do it in C++, it would look like this:
	QObject* root = engine.rootObjects()[0];
	QObject::connect(root, SIGNAL(lineEntered(QString)), &client, SLOT(sendLine(const QString&)));
	QObject::connect(&client, SIGNAL(lineReceived(QVariant)), root, SLOT(appendOutput(QVariant)));
	 */

	return app.exec();
}
