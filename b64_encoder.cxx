#include "b64_encoder.hxx"

void b64_encoder::run() {
    b64 = "data:";
    if (fn.endsWith(".jpeg") || fn.endsWith(".jpg")) {
	b64+= "image/jpeg";
    } else if (fn.endsWith(".png")) {
	b64+= "image/png";
    } else if (fn.endsWith(".gif")) {
	b64+= "image/gif";
    } else {
	b64+= "application/octet-stream";
    }
    b64+= ";base64,";
    b64+= in.toBase64();
    emit this->result_ready(b64);
}
