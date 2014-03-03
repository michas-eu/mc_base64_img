#include "b64_conv.hxx"

b64_conv::b64_conv(QByteArray data)
{
	if (data.startsWith("data:image/jpeg")) {
		this->filetype = this->jpeg;
	} else if (data.startsWith("data:image/png")) {
		this->filetype = this->png;
	} else if (data.startsWith("data:image/gif")) {
		this->filetype = this->gif;
	} else {
		this->filetype = this->unknown;
	}
	if (this->filetype != this->unknown) {
		int size = data.size();
		size -= 22;
		if (filetype == this->jpeg) {
			size--;
		}
		data = data.right(size);
		this->d = QByteArray::fromBase64(data);
	}
}

bool b64_conv::is_jpeg()
{
	return this->filetype == this->jpeg;
}

bool b64_conv::is_png()
{
	return this->filetype == this->png;
}

bool b64_conv::is_gif()
{
	return this->filetype == this->gif;
}

QByteArray b64_conv::get_data()
{
	return this->d;
}

QPixmap b64_conv::get_image()
{
	QPixmap ret;
	ret.loadFromData(this->d);
	return ret;
}
