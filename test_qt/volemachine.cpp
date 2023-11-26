#include "volemachine.h"
#include "./ui_volemachine.h"
#include "machine.h"

Machine machine;

voleMachine::voleMachine(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::voleMachine)
{
    ui->setupUi(this);
    updatewindow();
}

voleMachine::~voleMachine()
{
    delete ui;
}




void voleMachine::on_load_button_clicked()
{
    Machine machine1;
    machine = machine1;
    string s = machine.GetInstructions(ui->lineEdit->text().toStdString());
    ui->isoppend->setText(QString::fromStdString(s));
    updatewindow();
    ui->lineEdit->setText("");

}


void voleMachine::on_fetch_button_clicked()
{
    ui->isValed->setText( QString::fromStdString(machine.FetchNextInstruction()));
    updatewindow();
}

void voleMachine:: updatewindow(){
    ui->reg_field->setText(QString::fromStdString(machine.PrintRegisters()));
    ui->memory_field->setText(QString::fromStdString(machine.PrintMemory()));
    ui->pc->setText(QString::number(machine.GetProgramCounter()));
    ui->ir->setText(QString::fromStdString(machine.GetInstructionRegister()));
    ui->screen->setText(QString::fromStdString(machine.PrintScreen()));

}

