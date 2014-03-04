#ifndef B64_DECODER_HXX
#define B64_DECODER_HXX

#include <QThread>
#include <QByteArray>
#include <QString>
#include <QPixmap>

class b64_decoder : public QThread
{
	Q_OBJECT
public:
	void run();
	QString input;
protected:
	enum filetype_e {
		unknown,
		jpeg,
		jpeg_3_letters,
		gif,
		png
	};
	enum filetype_e filetype;
signals:
	void result_ready(QPixmap img);
};

#endif // B64_DECODER_HXX
