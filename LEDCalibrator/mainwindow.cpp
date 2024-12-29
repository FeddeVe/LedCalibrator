#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    m_leds = new LEDS();



    ui->setupUi(this);
    m_colorGrid = new ColorGrid(m_leds,this);
    ui->splitter_2->addWidget(m_colorGrid);

    setupTable();

    connect(m_colorGrid, SIGNAL(colorChanged()), this, SLOT(colorChanged()));
}

MainWindow::~MainWindow()
{
    delete ui;
    delete m_colorGrid;
    delete m_leds;
}

void MainWindow::on_pushButton_clicked()
{
    LED *l = m_leds->addLed();
    addRow(l);
}




void MainWindow::on_tableWidget_cellChanged(int row, int column)
{
    if(row < 0){
        return;
    }

    LED *l = m_leds->getLed(ui->tableWidget->item(row, 0)->data(0).toInt());
    if(l == nullptr){
        return;
    }
    switch (column){
    case 1:
    {
        bool enabled = false;
        if(ui->tableWidget->item(row,column)->checkState() == Qt::Checked){
            enabled = true;
        }
        if(l->setEnabled(enabled)){
            int bp = 0;
            bp++;
        }
    }
    break;
    case 2:
    {
        QString name = ui->tableWidget->item(row,column)->data(0).toString();
        if(l->setName(name)){
            m_leds->save();
            ui->tableWidget->resizeColumnsToContents();
        }
    }
    break;
    case 3:
    {
        int waveLenght = ui->tableWidget->item(row,column)->data(0).toInt();
        if(l->setWaveLength(waveLenght)){
            m_leds->save();
            //ui->tableWidget->item(row,4)->setData(0, l->getX());
            //ui->tableWidget->item(row,5)->setData(0, l->getY());
           // ui->tableWidget->item(row,6)->setData(0, l->getR());
           // ui->tableWidget->item(row,7)->setData(0,l->getG());
           // ui->tableWidget->item(row,8)->setData(0,l->getB());
           // ui->tableWidget->resizeColumnsToContents();
        }
    }
    break;
    case 4:
    {
        double x = ui->tableWidget->item(row,column)->data(0).toDouble();
        if(l->setX(x)){
             m_leds->save();
          //  ui->tableWidget->item(row,4)->setData(0, l->getX());
          //  ui->tableWidget->item(row,5)->setData(0, l->getY());
             ui->tableWidget->item(row,6)->setData(0, l->getR());
             ui->tableWidget->item(row,7)->setData(0,l->getG());
             ui->tableWidget->item(row,8)->setData(0,l->getB());
             ui->tableWidget->resizeColumnsToContents();
        }
    }
    break;
    case 5:
    {
        double y = ui->tableWidget->item(row,column)->data(0).toDouble();
        if(l->setY(y)){
            m_leds->save();
         //   ui->tableWidget->item(row,4)->setData(0, l->getX());
         //   ui->tableWidget->item(row,5)->setData(0, l->getY());
            ui->tableWidget->item(row,6)->setData(0, l->getR());
            ui->tableWidget->item(row,7)->setData(0,l->getG());
            ui->tableWidget->item(row,8)->setData(0,l->getB());
            ui->tableWidget->resizeColumnsToContents();
        }
    }
    break;

    }
}

void MainWindow::colorChanged()
{
    for(int i = 0; i < ui->tableWidget->rowCount(); i++){
        LED *l = m_leds->getLed(ui->tableWidget->item(i, 0)->data(0).toInt());
        ui->tableWidget->item(i, 9)->setData(0, l->getDistance());
        ui->tableWidget->item(i, 10)->setData(0, l->getPercent()* 100);
    }
}

void MainWindow::setupTable()
{
    for(size_t i = 0; i < m_leds->m_leds.size(); i++){
        LED *l = m_leds->m_leds[i];
        addRow(l);
    }
}

void MainWindow::addRow(LED *l)
{
    int row = ui->tableWidget->rowCount();
    ui->tableWidget->setRowCount(row+1);

    QTableWidgetItem *it = new QTableWidgetItem();
    it->setData(0,l->getID());
    it->setFlags(it->flags() ^ (Qt::ItemIsSelectable|Qt::ItemIsEditable));
    ui->tableWidget->setItem(row, 0, it);

    it = new QTableWidgetItem();
    if(l->getEnabled()){
        it->setCheckState(Qt::Checked);
    }else{
        it->setCheckState(Qt::Unchecked);
    }
    ui->tableWidget->setItem(row, 1, it);

    it = new QTableWidgetItem();
    it->setText(l->getName());
    ui->tableWidget->setItem(row, 2, it);

    it = new QTableWidgetItem();
    it->setData(0, l->getWaveLength());
    ui->tableWidget->setItem(row, 3, it);

    it = new QTableWidgetItem();
    it->setData(0, l->getR());
    ui->tableWidget->setItem(row, 6, it);
    it = new QTableWidgetItem();
    it->setData(0, l->getG());
    ui->tableWidget->setItem(row, 7, it);
    it = new QTableWidgetItem();
    it->setData(0, l->getB());
    ui->tableWidget->setItem(row, 8, it);

    it = new QTableWidgetItem();
    it->setData(0, l->getDistance());
    ui->tableWidget->setItem(row, 9, it);

    it = new QTableWidgetItem();
    it->setData(0, l->getPercent() * 100);
    ui->tableWidget->setItem(row, 10, it);

    it = new QTableWidgetItem();
    it->setData(0, QString::number(l->getX()));

    ui->tableWidget->setItem(row, 4, it);

    it = new QTableWidgetItem();
    it->setData(0, QString::number(l->getY()));
    ui->tableWidget->setItem(row, 5, it);



    ui->tableWidget->resizeColumnsToContents();
}

