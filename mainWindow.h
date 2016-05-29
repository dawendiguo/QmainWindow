#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include<QtGui>
class QAction;
class QMenu;
class QToolBar;
class QMenuBar;
class QKeySequence;
class MainWindow : public QMainWindow
{
	Q_OBJECT

	public:
		MainWindow (QWidget *parent = 0);
		~MainWindow();
	private slots:
		void open();
	private:
		QAction *openAction;
		QLabel *msgLabel;

};
#endif
