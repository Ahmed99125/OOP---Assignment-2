#ifndef VOLEMACHINE_H
#define VOLEMACHINE_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class voleMachine;
}
QT_END_NAMESPACE

class voleMachine : public QMainWindow
{
    Q_OBJECT

public:
    voleMachine(QWidget *parent = nullptr);
    ~voleMachine();
    void updatewindow();

private slots:


    void on_load_button_clicked();

    void on_fetch_button_clicked();

private:
    Ui::voleMachine *ui;
};
#endif // VOLEMACHINE_H
