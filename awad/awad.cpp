#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QString>
#include <vector>
#include <bits/stdc++.h>
#include <QDebug>
#include <classes.h>

using namespace std;
vector<string>instrc(256,"00");
int countt = 0;
ControlUnit controlunit;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    fillTable();
    QString styleSheet = "\
        QMainWindow {\
            background-color: #1a1e27;\
    }\
        QPushButton {\
            background-color: #ff5733;\
            color: #ffffff;\
            border: none;\
            border-radius: 25px;\
            padding: 15px 30px;\
            font-size: 16px;\
            font-weight: bold;\
            cursor: pointer;\
    }\
    \
        QPushButton::after {\
            content: '';\
            position: absolute;\
            top: 50%;\
            left: 50%;\
            width: 300%;\
            height: 300%;\
            background: rgba(255, 255, 255, 0.3);\
            border-radius: 50%;\
            transform: translate(-50%, -50%) scale(0);\
            transition: transform 0.5s ease;\
            z-index: 0;\
    }\
\
        QPushButton:hover {\
            background-color: #DF6951;\
    }\
\
        QPushButton:hover::after {\
            transform: translate(-50%, -50%) scale(1);\
    }\
        QListWidget#listWidget_6 ,#listWidget_5{\
            background-color: #282c34;\
            border: none;\
    }\
    \
        QListWidget#listWidget_6::item {\
            color: #ffffff;\
            padding: 10px;\
            font-size: 18px;\
    }\
    \
        QListWidget#listWidget_6::item:selected {\
            background-color: #61dafb;\
    }\
\
        QLabel{\
            font-weight: bold; \
            color: #61dafb;\
    }\
        QLabel#logo{\
            font-size: 24px;\
            font-weight: bold; \
            color: #61dafb;\
            padding: 10px;\
    }\
        QTableWidget {\
            border-radius: 8px ;\
    }";
        this->setStyleSheet(styleSheet);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::read_m(){
 for (int j = 0; j < 64; ++j) {
        for (int i = 1; i < 3; ++i) {
            QTableWidgetItem *item = ui->tableWidget->item(j, i);
            QTableWidgetItem *item1 = (i == 1) ? ui->tableWidget->item(j, i - 1) : ui->tableWidget->item(j, i + 1);

            if (item && item1) {
                qDebug() << "Writing to memory:" << item1->text() << "->" << item->text();
                controlunit.memory.write(item1->text().toStdString(), item->text().toStdString());
                instrc[countt++]= item->text().toStdString();
            } else {
                qDebug() << "Null item found at tableWidget(" << j << ", " << i << ")";
            }
        }
    }

     for (int j = 0; j < 64; ++j) {
        for (int i = 1; i < 3; ++i) {
            QTableWidgetItem *item = ui->tableWidget_2->item(j, i);
            QTableWidgetItem *item1 = (i == 1) ? ui->tableWidget_2->item(j, i - 1) : ui->tableWidget_2->item(j, i + 1);

            if (item && item1) {
                qDebug() << "Writing to memory:" << item1->text() << "->" << item->text();
                controlunit.memory.write(item1->text().toStdString(), item->text().toStdString());
                instrc[countt++]= item->text().toStdString();
            } else {
                qDebug() << "Null item found at tableWidget(" << j << ", " << i << ")";
            }
        }
    }
}

void MainWindow::print_m(){

for (int j = 0; j < 64; ++j) {
        for (int i = 1; i < 3; ++i) {
            QTableWidgetItem *item = ui->tableWidget->item(j, i);
            QTableWidgetItem *item1 = (i == 1) ? ui->tableWidget->item(j, i - 1) : ui->tableWidget->item(j, i + 1);

            if (item && item1) {
                QString temp = QString::fromStdString(controlunit.memory.read(item1->text().toStdString()));
                qDebug() << "Read from memory:" << item1->text() << "->" << temp;
                item->setText(temp);
            } else {
                qDebug() << "Null item found at tableWidget(" << j << ", " << i << ")";
            }
        }
    }

    for (int j = 0; j < 64; ++j) {
        for (int i = 1; i < 3; ++i) {
            QTableWidgetItem *item = ui->tableWidget_2->item(j, i);
            QTableWidgetItem *item1 = (i == 1) ? ui->tableWidget_2->item(j, i - 1) : ui->tableWidget_2->item(j, i + 1);

            if (item && item1) {
                QString temp = QString::fromStdString(controlunit.memory.read(item1->text().toStdString()));
                qDebug() << "Read from memory:" << item1->text() << "->" << temp;
                item->setText(temp);
            } else {
                qDebug() << "Null item found at tableWidget(" << j << ", " << i << ")";
            }
        }
    }

}

void MainWindow::read_r(){
     vector<char> regs {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};

    for (int i = 0; i < 16; ++i) {
        QTableWidgetItem *item = ui->tableWidget_3->item(i, 1);
        if (item) {
            qDebug() << "Writing to register:" << regs[i] << "->" << item->text();
            controlunit.reg.write(regs[i], item->text().toStdString());
        } else {
            qDebug() << "Null item found at tableWidget_3(" << i << ", 1)";
        }
    }

}

void MainWindow::print_r(){
    vector<char> regs {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
for (int i = 0; i < 16; ++i) {
        QTableWidgetItem *item1 = ui->tableWidget_3->item(i, 1);
        if (item1) {
            QString temp = QString::fromStdString(controlunit.reg.read(regs[i]));
            qDebug() << "Read from register:" << regs[i] << "->" << temp;
            item1->setText(temp);
        } else {
            qDebug() << "Null item found at tableWidget_3(" << i << ", 1)";
        }
    }

}
void MainWindow::fillTable() {


    qDebug() << "Entering fillTable()";
    ui->tableWidget->setColumnWidth(0, 20);
    ui->tableWidget->setColumnWidth(3, 20);
    ui->tableWidget_2->setColumnWidth(0, 20);
    ui->tableWidget_2->setColumnWidth(3, 20);
    ui->tableWidget_3->setColumnWidth(0, 120);
    ui->tableWidget_3->setColumnWidth(1, 58);

    int rowCount = 64;
    int colCount = 4;
    ui->tableWidget->setRowCount(rowCount);
    ui->tableWidget->setColumnCount(colCount);

    for (int i = 0; i < 16; i++) {
        for (int j = 0; j <2; j++) {
            if (!ui->tableWidget_3->item(i, j)) {
                ui->tableWidget_3->setItem(i, j, new QTableWidgetItem());
            }
            Qstring s = "00";
            QTableWidgetItem *item1 = ui->tableWidget_3->item(i, 1);
            item1->setText(s);
        }
    }

    for (int i = 0; i < 64; i++) {
        for (int j = 1; j <3; j++) {
            if (!ui->tableWidget_2->item(i, j)) {
                ui->tableWidget_2->setItem(i, j, new QTableWidgetItem());
            }
            Qstring s = "00";
            QTableWidgetItem *item1 = ui->tableWidget_2->item(i, j);
            item1->setText(s);
        }
    }

    for (int i = 0; i < 64; i++) {
        for (int j = 1; j <3; j++) {
            if (!ui->tableWidget->item(i, j)) {
                ui->tableWidget->setItem(i, j, new QTableWidgetItem());
            }
            Qstring s = "00";
            QTableWidgetItem *item1 = ui->tableWidget->item(i, j);
            item1->setText(s);
        }
    }



    char v [] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
    vector<QString> ans;

    for (int i = 0; i < 16; ++i) {
        for (int j = 0; j < 16; ++j) {
            QString s;
            s += v[i];
            s += v[j];
            ans.push_back(s);
        }
    }

    int totalCombinations = ans.size();
    int cnt = 0;
    qDebug() << "fillTable() - Filling tableWidget";
    for (int i = 0; i < rowCount; ++i) {
        if (i + cnt < totalCombinations) {
            QTableWidgetItem *item0 = new QTableWidgetItem(ans[i+cnt]);
            ui->tableWidget->setItem(i, 0, item0);
            cnt++;
        }
        if (i + cnt < totalCombinations) {
            QTableWidgetItem *item3 = new QTableWidgetItem(ans[i + cnt]);
            ui->tableWidget->setItem(i, 3, item3);
        }
    }

    qDebug() << "fillTable() - Filling tableWidget_2";
    ui->tableWidget_2->setRowCount(rowCount);
    ui->tableWidget_2->setColumnCount(colCount);
    cnt = 128;
    for (int i = 0; i < rowCount; ++i) {
        if (i + cnt < totalCombinations) {
            QTableWidgetItem *item0 = new QTableWidgetItem(ans[i+cnt]);
            ui->tableWidget_2->setItem(i, 0, item0);
            cnt++;
        }
        if (i + cnt < totalCombinations) {
            QTableWidgetItem *item3 = new QTableWidgetItem(ans[i + cnt]);
            ui->tableWidget_2->setItem(i, 3, item3);
        }
    }


    qDebug() << "fillTable() - Filling tableWidget_3";
    for (int i = 0; i < 16; ++i) {
        QString s = "Register ";
        if (i <= 9) s += QString::number(i);
        else s += char('A' + i - 10);
        QTableWidgetItem *item3 = new QTableWidgetItem(s);
        ui->tableWidget_3->setItem(i, 0, item3);
    }

}

void MainWindow::on_omar_clicked()
{
    read_m();
    read_r();
    controlunit.loadProgram(instrc);
     while (true) {
        controlunit.executeNext();
        if (controlunit.programCounter >= controlunit.instructions.size()) {
            break; 
        }
    
     }
    print_m();
    print_r();
    qDebug() << "Button clicked: on_omar_clicked()";
    map<int, string> mp;
    vector<string> v1 {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "A", "B", "C", "D", "E", "F"};
    vector<string> ans1;

    for (int i = 0; i < v1.size(); ++i) {
        for (int j = 0; j < v1.size(); ++j) {
            string s;
            s += v1[i];
            s += v1[j];
            ans1.push_back(s);
        }
    }

    for (int i = 0; i < ans1.size(); ++i) {
        mp[i] = ans1[i];
    }

}
