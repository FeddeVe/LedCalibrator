#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    m_colorGrid = new ColorGrid();
    ui->splitter_2->addWidget(m_colorGrid);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete m_colorGrid;
}
