#ifndef B64_ENCODER_HXX
#define B64_ENCODER_HXX

#include <QThread>
#include <QByteArray>
#include <QString>

class b64_encoder : public QThread
{
	Q_OBJECT
public:
	void run();
public:
	QByteArray in;
	QString fn;
	QString b64;
signals:
	void result_ready(QString s);
};

#endif // B64_ENCODER_HXX
