#include <QPushButton>
#include <QGridLayout>
#include <QTableWidget>
#include <QLabel>
#include <QHeaderView>

#include "clientpersonalaccountwindow.h"

ClientPersonalAccountWindow::ClientPersonalAccountWindow(QWidget *parent) : QDialog(parent)
{
    setFixedWidth(500);
    setFixedHeight(500);

    setWindowTitle("Личный кабинет");

    QGridLayout* gridLayout = new QGridLayout(this);

    QLabel* userInfoLabel = new QLabel(this);
    userInfoLabel->setText("Информация о пользователе:");

    QTableWidget* infoTable = new QTableWidget(this);
    infoTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    infoTable->setRowCount(4);
    infoTable->setColumnCount(2);
    infoTable->setItem(0, 0, new QTableWidgetItem("Имя"));
    infoTable->setItem(1, 0, new QTableWidgetItem("Id"));
    infoTable->setItem(2, 0, new QTableWidgetItem("Email"));
    infoTable->setItem(3, 0, new QTableWidgetItem("Телефон"));

    infoTable->setItem(0, 1, new QTableWidgetItem("Лоло опшцуш ывлоа"));
    infoTable->setItem(1, 1, new QTableWidgetItem("234989"));
    infoTable->setItem(2, 1, new QTableWidgetItem("iajdawjidaj@asdjasidi"));
    infoTable->setItem(3, 1, new QTableWidgetItem("+92842394"));

    infoTable->setEditTriggers(QAbstractItemView::NoEditTriggers);

    /*QPushButton* openAccount = new QPushButton("Открыть счёт", this);

    QPushButton* closeAccount = new QPushButton("Закрыть счёт", this);

    QPushButton* withdraw = new QPushButton("Снять деньги со счёта", this);

    QPushButton*
    gridLayout->addWidget(openAccount, 2, 0);
    gridLayout->addWidget(closeAccount, 3, 0);
    gridLayout->addWidget(withdraw, 4, 0);
*/

    QPushButton* accDepWork = new QPushButton("Счета и вклады", this);
    QPushButton* credits = new QPushButton("Кредиты", this);
    QPushButton* installments = new QPushButton("Рассрочки", this);

    QPushButton* back = new QPushButton("Назад", this);
    connect(back, &QPushButton::pressed, this, &ClientPersonalAccountWindow::back);

    gridLayout->addWidget(userInfoLabel, 0, 0);
    gridLayout->addWidget(infoTable, 1, 0);
    gridLayout->addWidget(accDepWork, 2, 0);
    gridLayout->addWidget(credits, 3, 0);
    gridLayout->addWidget(installments, 4, 0);
    gridLayout->addWidget(back, 5, 0);
}

void ClientPersonalAccountWindow::back()
{
    this->close();
    emit showAuthorizationWindow();
}
