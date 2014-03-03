#include "mainwindow.hxx"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::MainWindow)
{
	ui->setupUi(this);
	setAcceptDrops(true);
}

MainWindow::~MainWindow()
{
	delete ui;
}


void MainWindow::dragEnterEvent(QDragEnterEvent *ev)
{
	ev->acceptProposedAction();
}

void MainWindow::dropEvent(QDropEvent *ev)
{
	const QMimeData *m = ev->mimeData();
	if (m->hasUrls()) {
		QString fn = m->urls().first().toLocalFile();
		this->open(fn);
	}
	ev->acceptProposedAction();
}

void MainWindow::on_btn_open_clicked()
{
	QString fn = QFileDialog::getOpenFileName(this);
	if (fn.length()) {
		this->open(fn);
	}
}

void MainWindow::open(QString fn) {
	QFile file(fn);
	QByteArray ctn;
	if (file.open(QIODevice::ReadOnly)) {
		ctn = file.readAll();
		file.close();
	}
	if (ctn.length()) {
		ui->file_name->setText(fn);
		this->base64(ctn, fn);
	} else {
		ui->file_name->setText("Error");
	}
}

void MainWindow::base64(QByteArray in, QString fn) {
	QString b64("data:");
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
	ui->base64->setPlainText(b64);
}

void MainWindow::on_btn_convert_clicked()
{
	QByteArray in = ui->base64_input->toPlainText().toLatin1();
	b64_conv bx(in);
	QPixmap img = bx.get_image();
	if (img.isNull()) {
		ui->base64_input->setPlainText("Wrong input");
	} else {
		ui->img_box->setPixmap(img);
	}
}
