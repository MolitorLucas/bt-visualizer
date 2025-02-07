#ifndef BTVISUALIZER_H
#define BTVISUALIZER_H

#include <QMainWindow>
#include <QGraphicsView>

QT_BEGIN_NAMESPACE
namespace Ui {
class BTVisualizer;
}
QT_END_NAMESPACE

class BTVisualizer : public QMainWindow
{
    Q_OBJECT

public:
    BTVisualizer(QWidget *parent = nullptr);
    ~BTVisualizer();

private:
    Ui::BTVisualizer *ui;
    QGraphicsView *graphicsView;

};
#endif // BTVISUALIZER_H
