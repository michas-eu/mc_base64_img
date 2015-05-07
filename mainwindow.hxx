#ifndef MAINWINDOW_HXX
#define MAINWINDOW_HXX

#include <QMainWindow>
#include <QMimeData>
#include <QUrl>
#include <QFile>
#include <QFileDialog>
#include <QPixmap>
#include <QImage>
#include <QMessageBox>

#include "b64_encoder.hxx"
#include "b64_decoder.hxx"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
	Q_OBJECT
	
public:
	explicit MainWindow(QWidget *parent = 0);
	~MainWindow();
	void dragEnterEvent(QDragEnterEvent *ev);
	void dropEvent(QDropEvent *ev);
	
private slots:
	void on_btn_open_clicked();
	void on_btn_convert_clicked();
	void set_converted_tbl(QString s);
	void set_decoded_img(QPixmap img);
	void on_btn_save_clicked();

private:
	Ui::MainWindow *ui;
	b64_encoder b64_encoder_thred;
	b64_decoder b64_decoder_thred;

protected:
	void open(QString fn);
	void base64(QByteArray in, QString fn);
};

#endif // MAINWINDOW_HXX
