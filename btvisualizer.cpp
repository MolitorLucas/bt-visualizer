#include "btvisualizer.h"
#include "./ui_btvisualizer.h"

BTVisualizer::BTVisualizer(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::BTVisualizer)
{
    ui->setupUi(this);
}

BTVisualizer::~BTVisualizer()
{
    delete ui;
}
