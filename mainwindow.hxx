#ifndef MAINWINDOW_HXX
#define MAINWINDOW_HXX

#include <QMainWindow>
#include <QUrl>
#include <QFile>
#include <QFileDialog>

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

private:
	Ui::MainWindow *ui;

protected:
	void open(QString fn);
	void base64(QByteArray in, QString fn);
};

#endif // MAINWINDOW_HXX
