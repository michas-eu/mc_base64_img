#include "b64_decoder.hxx"

void b64_decoder::run() {
	QByteArray data;
	QPixmap ret;
	data = this->input.toLatin1();
	if (data.startsWith("data:image/jpeg")) {
		this->filetype = this->jpeg;
	} else if (data.startsWith("data:image/png")) {
		this->filetype = this->png;
	} else if (data.startsWith("data:image/gif")) {
		this->filetype = this->gif;
	} else if (data.startsWith("data:image/jpg")) {
		this->filetype = this->jpeg_3_letters;
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
		data = QByteArray::fromBase64(data);
		ret.loadFromData(data);
	}
	emit this->result_ready(ret);
}
