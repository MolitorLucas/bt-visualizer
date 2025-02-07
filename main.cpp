#include "btvisualizer.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    BTVisualizer w;
    w.show();
    return a.exec();
}
