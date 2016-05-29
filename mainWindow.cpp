#include "mainWindow.h"


MainWindow::MainWindow(QWidget *parent)
		: QMainWindow(parent)
{
	openAction = new QAction(tr("&Open"),this);
	openAction->setShortcut(QKeySequence::Open);
	openAction->setStatusTip(tr("Open a file"));
    openAction->setIcon(QIcon(":open.png"));

	connect(openAction, SIGNAL(triggered()),this, SLOT(open()));

	QMenu *file = menuBar()->addMenu(tr("&File"));
	file->addAction(openAction);

	QToolBar *toolBar = addToolBar(tr("&File"));
	toolBar->addAction(openAction);

	QLabel *msgLabel = new QLabel;
	msgLabel->setMinimumSize(msgLabel->sizeHint());
	msgLabel->setAlignment(Qt::AlignHCenter);
	
	statusBar()->addWidget(msgLabel);
}

MainWindow::~MainWindow()
{
}

void  MainWindow::open()
{
	QString path = QFileDialog::getOpenFileName(this , tr("Open a image"), "." ,tr("Image Files(*.jpg *.png);;All File (*)"));
	if(path.isEmpty()){
		QMessageBox::information(NULL,tr("path"),tr("You don't select any files "));
	}
		else {

		QMessageBox::information(NULL,tr("Open"),tr("You selected")+path);
		}
}

