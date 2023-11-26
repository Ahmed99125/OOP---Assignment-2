#include "volemachine.h"
#include "./ui_volemachine.h"
#include "machine.h"

Machine machine;

voleMachine::voleMachine(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::voleMachine)
{
    ui->setupUi(this);
    ui->reg_field->setText(QString::fromStdString(machine.PrintRegisters()));
    ui->memory_field->setText(QString::fromStdString(machine.PrintMemory()));
    ui->pc->setText(QString::number(machine.GetProgramCounter()));
    ui->ir->setText(QString::fromStdString(machine.GetInstructionRegister()));
}

voleMachine::~voleMachine()
{
    delete ui;
}
