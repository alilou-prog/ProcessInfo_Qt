#include "mainwindow.h"
#include "./ui_mainwindow.h"


#include <iostream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , m_arguments {""}
{
    ui->setupUi(this);
    connect(ui->cancelButton, &QPushButton::clicked, this, &MainWindow::close);
    connect(ui->okButton, &QPushButton::clicked, this, &MainWindow::display);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::constructArguments()
{
    if(ui->argsCheckBox->isChecked())
        m_arguments += "args,";

    if(ui->cmdCheckBox->isChecked())
        m_arguments += "cmd,";

    if(ui->commCheckBox->isChecked())
        m_arguments += "comm,";

    if(ui->pidCheckBox->isChecked())
        m_arguments += "pid,";

    if(ui->ppidCheckBox->isChecked())
        m_arguments += "ppid,";

    if(ui->ttyCheckBox->isChecked())
        m_arguments += "tty,";

    // remove the comma at the end
    m_arguments = m_arguments.left(m_arguments.size()-1);
}


void MainWindow::display()
{   
    // first construct the argument string
    constructArguments();
    try{
        std::string arguments = m_arguments.toStdString();
        m_top.display(arguments);
    }
    catch(const std::invalid_argument& e)
    {
        qDebug() << "the argments are :" + m_arguments;
        qDebug() << QString::fromStdString(e.what());
    }
    // at the end, close the window
    close();
}
