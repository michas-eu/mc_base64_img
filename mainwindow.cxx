#include "mainwindow.hxx"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::MainWindow)
{
	connect(&this->b64_encoder_thred,SIGNAL(result_ready(QString)),this,SLOT(set_converted_tbl(QString)));
	connect(&this->b64_decoder_thred,SIGNAL(result_ready(QPixmap)),this,SLOT(set_decoded_img(QPixmap)));
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
	if (this->b64_encoder_thred.isRunning()) {
		this->b64_encoder_thred.terminate();
	}
	ui->base64->setPlainText("Working");
	this->b64_encoder_thred.in = in;
	this->b64_encoder_thred.fn = fn;
	this->b64_encoder_thred.start();
}

void MainWindow::set_converted_tbl(QString s) {
	if (s.size() > (1024 * 1024)) {
		s = "Error";
	}
	ui->base64->setPlainText(s);
}

void MainWindow::on_btn_convert_clicked()
{
	if (this->b64_decoder_thred.isRunning()) {
		this->b64_decoder_thred.terminate();
	}
	ui->img_box->setPixmap(QPixmap());
	QString in = ui->base64_input->toPlainText();
	this->b64_decoder_thred.input = in;
	this->b64_decoder_thred.start();
}

void MainWindow::set_decoded_img(QPixmap img)
{
	if (img.isNull()) {
		ui->base64_input->setPlainText("Wrong input");
	} else {
		ui->img_box->setPixmap(img);
	}
}
