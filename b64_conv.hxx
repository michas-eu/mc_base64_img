#ifndef B64_CONV_HXX
#define B64_CONV_HXX

#include <QByteArray>
#include <QPixmap>

class b64_conv
{
public:
	b64_conv(QByteArray data);
	bool is_jpeg();
	bool is_png();
	bool is_gif();
	QByteArray get_data();
	QPixmap get_image();

protected:
	QByteArray d;
	enum filetype_e {
		unknown,
		jpeg,
		gif,
		png
	};
	enum filetype_e filetype;
};

#endif // B64_CONV_HXX
