#include "mainwindow.h"
#include "ui_mainwindow.h"
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <clocale>
#include <cstring>
using namespace std;

#include <QMessageBox>
#include <QString>
#include <QStringList>
#include <QListWidget>
#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    // загружаем картинку нашей области
    ui->setupUi(this);
    QPixmap pix;
    pix.load("C:/Users/almaz/Desktop/Prim/Qt-map.png");
    ui->label->setPixmap(pix);

    // Далее ставим ребрам значения по умолчанию(но мы можем их поменять во время выполнения программы)

    ui->V1V2->setText("15200");
    ui->V1V3->setText("11200");
    ui->V1V4->setText("14100");
    ui->V1V5->setText("10500");
    ui->V1V6->setText("18700");
    ui->V1V7->setText("26500");
    ui->V1V8->setText("30100");

    ui->V2V3->setText("14300");
    ui->V2V7->setText("16300");
    ui->V2V12->setText("10500");
    ui->V2V18->setText("23500");
    ui->V2V21->setText("18000");
    ui->V2V25->setText("15400");

    ui->V3V4->setText("25700");
    ui->V3V25->setText("12600");

    ui->V4V5->setText("13000");
    ui->V4V25->setText("13400");
    ui->V4V26->setText("15100");

    ui->V5V26->setText("47000");
    ui->V5V27->setText("43400");
    ui->V5V28->setText("46600");
    ui->V5V29->setText("41700");
    ui->V5V30->setText("12500");

    ui->V6V7->setText("35000");
    ui->V6V8->setText("38000");
    ui->V6V10->setText("45000");
    ui->V6V11->setText("10500");

    ui->V7V11->setText("44800");
    ui->V7V12->setText("11000");
    ui->V7V13->setText("13700");
    ui->V7V35->setText("10500");

    ui->V8V9->setText("23800");
    ui->V8V10->setText("44000");

    ui->V9V10->setText("57400");
    ui->V9V11->setText("57000");

    ui->V10V11->setText("26700");

    ui->V11V31->setText("56700");
    ui->V11V35->setText("48500");

    ui->V12V13->setText("19000");
    ui->V12V15->setText("11200");
    ui->V12V18->setText("12000");

    ui->V13V14->setText("22000");
    ui->V13V15->setText("29700");
    ui->V13V35->setText("25000");

    ui->V14V15->setText("29100");
    ui->V14V35->setText("21200");

    ui->V15V16->setText("14400");
    ui->V15V18->setText("30500");

    ui->V16V17->setText("26500");
    ui->V16V18->setText("32700");

    ui->V17V18->setText("13300");

    ui->V18V19->setText("17900");
    ui->V18V21->setText("18600");

    ui->V19V20->setText("15600");
    ui->V19V21->setText("19600");

    ui->V20V21->setText("18400");
    ui->V20V22->setText("10700");

    ui->V21V22->setText("16300");
    ui->V21V25->setText("23700");

    ui->V22V23->setText("11200");
    ui->V22V24->setText("27000");
    ui->V22V25->setText("25700");

    ui->V23V24->setText("17000");

    ui->V24V25->setText("15900");
    ui->V24V26->setText("15100");

    ui->V25V26->setText("27200");

    ui->V26V27->setText("10500");

    ui->V27V28->setText("41200");

    ui->V28V29->setText("40500");

    ui->V29V30->setText("11700");

    ui->V31V32->setText("44500");
    ui->V31V35->setText("37800");

    ui->V32V33->setText("57600");
    ui->V32V34->setText("37800");
    ui->V32V35->setText("64400");

    ui->V33V34->setText("47900");

    ui->V34V35->setText("39900");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_ExitButton_clicked() // кнопка выхода из программы
{
    this->close();
}

void MainWindow::on_MainButton_clicked() // кнопка активации алгоритма
{
    unsigned short N = 35; // размерность матрицы ребер, количество вершин
    unsigned short min = 0; // минимальное ребро и вспомогательная меременная
    unsigned short EdgeCount = 0; // количество минимальных ребер EdgeCount = N - 1;
    int sum = 0; // стоимость дороги (первоначальная, затем обновленная)
    unsigned short Line = 36; // вспомогательная строка
    unsigned short Column = 36; // вспомогательный столбец
    unsigned short** vertex = new unsigned short* [N]; // изначальная матрица, где показывают ребра
    for (int i = 0; i < N; i++)
        vertex[i] = new unsigned short[N];
    unsigned short** vertexT = new unsigned short* [N]; // новая матрица, где показывают ребра
    for (int i = 0; i < N; i++)
        vertexT[i] = new unsigned short[N];
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++){
            vertex[i][j] = 0;
            vertexT[i][j] = 0;
        }

    // считываем в изначальную матрицу значения

    vertex[0][1]=ui->V1V2->text().toUShort();
    vertex[1][0] = vertex[0][1];
    vertex[0][2]=ui->V1V3->text().toUShort();
    vertex[2][0] = vertex[0][2];
    vertex[0][3]=ui->V1V4->text().toUShort();
    vertex[3][0] = vertex[0][3];
    vertex[0][4]=ui->V1V5->text().toUShort();
    vertex[4][0] = vertex[0][4];
    vertex[0][5]=ui->V1V6->text().toUShort();
    vertex[5][0] = vertex[0][5];
    vertex[0][6]=ui->V1V7->text().toUShort();
    vertex[6][0] = vertex[0][6];
    vertex[0][7]=ui->V1V8->text().toUShort();
    vertex[7][0] = vertex[0][7];

    vertex[1][2]=ui->V2V3->text().toUShort();
    vertex[2][1] = vertex[1][2];
    vertex[1][6]=ui->V2V7->text().toUShort();
    vertex[6][1] = vertex[1][6];
    vertex[1][11]=ui->V2V12->text().toUShort();
    vertex[11][1] = vertex[1][11];
    vertex[1][17]=ui->V2V18->text().toUShort();
    vertex[17][1] = vertex[1][17];
    vertex[1][20]=ui->V2V21->text().toUShort();
    vertex[20][1] = vertex[1][20];
    vertex[1][24]=ui->V2V25->text().toUShort();
    vertex[24][1] = vertex[1][24];

    vertex[2][3]=ui->V3V4->text().toUShort();
    vertex[3][2] = vertex[2][3];
    vertex[2][24]=ui->V3V25->text().toUShort();
    vertex[24][2] = vertex[2][24];

    vertex[3][4]=ui->V4V5->text().toUShort();
    vertex[4][3] = vertex[3][4];
    vertex[3][24]=ui->V4V25->text().toUShort();
    vertex[24][3] = vertex[3][24];
    vertex[3][25]=ui->V4V26->text().toUShort();
    vertex[25][3] = vertex[3][25];

    vertex[4][25]=ui->V5V26->text().toUShort();
    vertex[25][4] = vertex[4][25];
    vertex[4][26]=ui->V5V27->text().toUShort();
    vertex[26][4] = vertex[4][26];
    vertex[4][27]=ui->V5V28->text().toUShort();
    vertex[27][4] = vertex[4][27];
    vertex[4][28]=ui->V5V29->text().toUShort();
    vertex[28][4] = vertex[4][28];
    vertex[4][29]=ui->V5V30->text().toUShort();
    vertex[29][4] = vertex[4][29];

    vertex[5][6]=ui->V6V7->text().toUShort();
    vertex[6][5] = vertex[5][6];
    vertex[5][7]=ui->V6V8->text().toUShort();
    vertex[7][5] = vertex[5][7];
    vertex[5][9]=ui->V6V10->text().toUShort();
    vertex[9][5] = vertex[5][9];
    vertex[5][10]=ui->V6V11->text().toUShort();
    vertex[10][5] = vertex[5][10];

    vertex[6][10]=ui->V7V11->text().toUShort();
    vertex[10][6] = vertex[6][10];
    vertex[6][11]=ui->V7V12->text().toUShort();
    vertex[11][6] = vertex[6][11];
    vertex[6][12]=ui->V7V13->text().toUShort();
    vertex[12][6] = vertex[6][12];
    vertex[6][34]=ui->V7V35->text().toUShort();
    vertex[34][6] = vertex[6][34];

    vertex[7][8]=ui->V8V9->text().toUShort();
    vertex[8][7] = vertex[7][8];
    vertex[7][9]=ui->V8V10->text().toUShort();
    vertex[9][7] = vertex[7][9];

    vertex[8][9]=ui->V9V10->text().toUShort();
    vertex[9][8] = vertex[8][9];
    vertex[8][10]=ui->V9V11->text().toUShort();
    vertex[10][8] = vertex[8][10];

    vertex[9][10]=ui->V10V11->text().toUShort();
    vertex[10][9] = vertex[9][10];

    vertex[10][30]=ui->V11V31->text().toUShort();
    vertex[30][10] = vertex[10][30];
    vertex[10][34]=ui->V11V35->text().toUShort();
    vertex[34][10] = vertex[10][34];

    vertex[11][12]=ui->V12V13->text().toUShort();
    vertex[12][11] = vertex[11][12];
    vertex[11][14]=ui->V12V15->text().toUShort();
    vertex[14][11] = vertex[11][14];
    vertex[11][17]=ui->V12V18->text().toUShort();
    vertex[17][11] = vertex[11][17];

    vertex[12][13]=ui->V13V14->text().toUShort();
    vertex[13][12] = vertex[12][13];
    vertex[12][14]=ui->V13V15->text().toUShort();
    vertex[14][12] = vertex[12][14];
    vertex[12][34]=ui->V13V35->text().toUShort();
    vertex[34][12] = vertex[12][34];

    vertex[13][14]=ui->V14V15->text().toUShort();
    vertex[14][13] = vertex[13][34];
    vertex[13][34]=ui->V14V35->text().toUShort();
    vertex[34][13] = vertex[13][34];

    vertex[14][15]=ui->V15V16->text().toUShort();
    vertex[15][14] = vertex[14][15];
    vertex[14][17]=ui->V15V18->text().toUShort();
    vertex[17][14] = vertex[14][17];

    vertex[15][16]=ui->V16V17->text().toUShort();
    vertex[16][15] = vertex[15][16];
    vertex[15][17]=ui->V16V18->text().toUShort();
    vertex[17][15] = vertex[15][17];

    vertex[16][17]=ui->V17V18->text().toUShort();
    vertex[17][16] = vertex[16][17];

    vertex[17][18]=ui->V18V19->text().toUShort();
    vertex[18][17] = vertex[17][18];
    vertex[17][20]=ui->V18V21->text().toUShort();
    vertex[20][17] = vertex[17][20];

    vertex[18][19]=ui->V19V20->text().toUShort();
    vertex[19][18] = vertex[18][19];
    vertex[18][20]=ui->V19V21->text().toUShort();
    vertex[20][18] = vertex[18][20];

    vertex[19][20]=ui->V20V21->text().toUShort();
    vertex[20][19] = vertex[19][20];
    vertex[19][21]=ui->V20V22->text().toUShort();
    vertex[21][19] = vertex[19][21];

    vertex[20][21]=ui->V21V22->text().toUShort();
    vertex[21][20] = vertex[20][21];
    vertex[20][24]=ui->V21V25->text().toUShort();
    vertex[24][20] = vertex[20][24];

    vertex[21][22]=ui->V22V23->text().toUShort();
    vertex[22][21] = vertex[21][22];
    vertex[21][23]=ui->V22V24->text().toUShort();
    vertex[23][21] = vertex[21][23];
    vertex[21][24]=ui->V22V25->text().toUShort();
    vertex[24][21] = vertex[21][24];

    vertex[22][23]=ui->V23V24->text().toUShort();
    vertex[23][22] = vertex[22][23];

    vertex[23][24]=ui->V24V25->text().toUShort();
    vertex[24][23] = vertex[23][24];
    vertex[23][25]=ui->V24V26->text().toUShort();
    vertex[25][23] = vertex[23][25];

    vertex[24][25]=ui->V25V26->text().toUShort();
    vertex[25][24] = vertex[24][25];

    vertex[25][26]=ui->V26V27->text().toUShort();
    vertex[26][25] = vertex[25][26];

    vertex[26][27]=ui->V27V28->text().toUShort();
    vertex[27][26] = vertex[26][27];

    vertex[27][28]=ui->V28V29->text().toUShort();
    vertex[28][27] = vertex[27][28];

    vertex[28][29]=ui->V29V30->text().toUShort();
    vertex[29][28] = vertex[28][29];

    vertex[30][31]=ui->V31V32->text().toUShort();
    vertex[31][30] = vertex[30][31];
    vertex[30][34]=ui->V31V35->text().toUShort();
    vertex[34][30] = vertex[30][34];

    vertex[31][32]=ui->V32V33->text().toUShort();
    vertex[32][31] = vertex[31][32];
    vertex[31][33]=ui->V32V34->text().toUShort();
    vertex[33][31] = vertex[31][33];
    vertex[31][34]=ui->V32V35->text().toUShort();
    vertex[34][31] = vertex[31][34];

    vertex[32][33]=ui->V33V34->text().toUShort();
    vertex[33][32] = vertex[32][33];

    vertex[33][34]=ui->V34V35->text().toUShort();
    vertex[34][33] = vertex[33][34];

    for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                sum = sum + vertex[i][j]; // определение начальной цены содержания
    ui->BeginTextBrowser->setText(QString::number(sum/2));
    sum = 0;

    bool* NumWhat = new bool[N]; // задействованные вершины (по мере алгоритма false заменяется на true)
        unsigned short* EdgeMinValue = new unsigned short[N-1]; // значения минимальных ребер
        for (int i = 0; i < N; i++) NumWhat[i] = false;

        // РАЗДЕЛЕНИЕ

        // далее идет первый шаг алгоритма Прима : определение минимального ребра
        min = 65535; // присваиваем максимальное значение для нахождения минимального ребра
        for (int i = 0; i < N; i++) // начинаем искать самое минимальное ребро ищем по главной диагонали
            for (int j = i + 1; j < N; j++) // если ребро равно, то игнорим
                if ((vertex[i][j] < min) && (vertex[i][j] != 0)) { // если ребро меньше минимального значения и не равно нулю
                    min = vertex[i][j];
                    Line = i; // присваиваем значение вспомогательной строке
                    Column = j; // присваиваем значение вспомогательному столбцу
                }
        if (Line != 36 && Column != 36) { // если нашли минимальное ребро
            EdgeCount++; // увеличиваем количество минимальных ребер на 1
            NumWhat[Line] = true;
            NumWhat[Column] = true;
            EdgeMinValue[0] = vertex[Line][Column]; // первое значение минимального ребра
            vertexT[Line][Column] = vertex[Line][Column];
            sum = sum + EdgeMinValue[0]; // увеличиваем цену на первое минимальное ребро
        }
        // первый шаг алгоритма окончен

        // РАЗДЕЛЕНИЕ

        // дальше начинается основное веселье (второй(основной) этап алгоритма Прима)
        while (EdgeCount < N - 1) { // пока ребер меньше вершин (пока ребер не станет ровно вершин - 1)
            // сначала удалим лишние узлы, которые образуют цикл
            // лишние узлы удалены
            // теперь ищем новые минимальные ребра
            min = 65535; // присваиваем максимальное значение для нахождения минимального ребра
            // опять будем искать по главной диагонали
            for (int i = 0; i < N; i++)
                if (NumWhat[i] == true) // если вершина задействована, то есть состоит в обновленном графе
                    for (int j = 0; j < N; j++)
                        if ((vertex[i][j] < min) && (vertex[i][j] != 0) && (NumWhat[j] == false)) { // если ребро меньше минимального значения и не равно нулю
                                                                           //и не задействована
                            min = vertex[i][j];
                            Line = i; // присваиваем значение вспомогательной строке
                            Column = j; // присваиваем значение вспомогательному столбцу
                        }
            NumWhat[Line] = true;
            NumWhat[Column] = true;
            EdgeMinValue[EdgeCount] = vertex[Line][Column]; // первое значение минимального ребра
            vertexT[Line][Column] = vertex[Line][Column];
            sum = sum + EdgeMinValue[EdgeCount]; // увеличиваем цену на первое минимальное ребро
            EdgeCount++; // увеличиваем количество минимальных ребер на 1
        }
        ui->EndTextBrowser->setText(QString::number(sum)); // Выводим конечную сумму

        for (int i = 0 ; i < 35; i++)
            for (int j = 0 ; j < 35; j++)
                if (vertexT[i][j] != 0) vertexT[j][i] = vertexT[i][j];

        // далее выводим в окошки значения новой матрицы

        ui->V1V2->setText(QString::number(vertexT[0][1]));
        ui->V1V3->setText(QString::number(vertexT[0][2]));
        ui->V1V4->setText(QString::number(vertexT[0][3]));
        ui->V1V5->setText(QString::number(vertexT[0][4]));
        ui->V1V6->setText(QString::number(vertexT[0][5]));
        ui->V1V7->setText(QString::number(vertexT[0][6]));
        ui->V1V8->setText(QString::number(vertexT[0][7]));

        ui->V2V3->setText(QString::number(vertexT[1][2]));
        ui->V2V7->setText(QString::number(vertexT[1][6]));
        ui->V2V12->setText(QString::number(vertexT[1][11]));
        ui->V2V18->setText(QString::number(vertexT[1][17]));
        ui->V2V21->setText(QString::number(vertexT[1][20]));
        ui->V2V25->setText(QString::number(vertexT[1][25]));

        ui->V3V4->setText(QString::number(vertexT[2][3]));
        ui->V3V25->setText(QString::number(vertexT[2][24]));

        ui->V4V5->setText(QString::number(vertexT[3][4]));
        ui->V4V25->setText(QString::number(vertexT[3][24]));
        ui->V4V26->setText(QString::number(vertexT[3][25]));

        ui->V5V26->setText(QString::number(vertexT[4][25]));
        ui->V5V27->setText(QString::number(vertexT[4][26]));
        ui->V5V28->setText(QString::number(vertexT[4][27]));
        ui->V5V29->setText(QString::number(vertexT[4][28]));
        ui->V5V30->setText(QString::number(vertexT[4][29]));

        ui->V6V7->setText(QString::number(vertexT[5][6]));
        ui->V6V8->setText(QString::number(vertexT[5][7]));
        ui->V6V10->setText(QString::number(vertexT[5][9]));
        ui->V6V11->setText(QString::number(vertexT[5][10]));

        ui->V7V11->setText(QString::number(vertexT[6][10]));
        ui->V7V12->setText(QString::number(vertexT[6][11]));
        ui->V7V13->setText(QString::number(vertexT[6][12]));
        ui->V7V35->setText(QString::number(vertexT[6][34]));

        ui->V8V9->setText(QString::number(vertexT[7][8]));
        ui->V8V10->setText(QString::number(vertexT[7][9]));

        ui->V9V10->setText(QString::number(vertexT[8][9]));
        ui->V9V11->setText(QString::number(vertexT[8][10]));

        ui->V10V11->setText(QString::number(vertexT[9][10]));

        ui->V11V31->setText(QString::number(vertexT[10][30]));
        ui->V11V35->setText(QString::number(vertexT[10][34]));

        ui->V12V13->setText(QString::number(vertexT[11][12]));
        ui->V12V15->setText(QString::number(vertexT[11][14]));
        ui->V12V18->setText(QString::number(vertexT[11][17]));

        ui->V13V14->setText(QString::number(vertexT[12][13]));
        ui->V13V15->setText(QString::number(vertexT[12][14]));
        ui->V13V35->setText(QString::number(vertexT[12][34]));

        ui->V14V15->setText(QString::number(vertexT[13][14]));
        ui->V14V35->setText(QString::number(vertexT[13][34]));

        ui->V15V16->setText(QString::number(vertexT[14][15]));
        ui->V15V18->setText(QString::number(vertexT[14][17]));

        ui->V16V17->setText(QString::number(vertexT[15][16]));
        ui->V16V18->setText(QString::number(vertexT[15][17]));

        ui->V17V18->setText(QString::number(vertexT[16][17]));

        ui->V18V19->setText(QString::number(vertexT[17][18]));
        ui->V18V21->setText(QString::number(vertexT[17][20]));

        ui->V19V20->setText(QString::number(vertexT[18][19]));
        ui->V19V21->setText(QString::number(vertexT[18][20]));

        ui->V20V21->setText(QString::number(vertexT[19][20]));
        ui->V20V22->setText(QString::number(vertexT[19][21]));

        ui->V21V22->setText(QString::number(vertexT[20][21]));
        ui->V21V25->setText(QString::number(vertexT[20][24]));

        ui->V22V23->setText(QString::number(vertexT[21][22]));
        ui->V22V24->setText(QString::number(vertexT[21][23]));
        ui->V22V25->setText(QString::number(vertexT[21][24]));

        ui->V23V24->setText(QString::number(vertexT[22][23]));

        ui->V24V25->setText(QString::number(vertexT[23][24]));
        ui->V24V26->setText(QString::number(vertexT[23][25]));

        ui->V25V26->setText(QString::number(vertexT[24][25]));

        ui->V26V27->setText(QString::number(vertexT[25][26]));

        ui->V27V28->setText(QString::number(vertexT[26][27]));

        ui->V28V29->setText(QString::number(vertexT[27][28]));

        ui->V29V30->setText(QString::number(vertexT[28][29]));

        ui->V31V32->setText(QString::number(vertexT[30][31]));
        ui->V31V35->setText(QString::number(vertexT[30][34]));

        ui->V32V33->setText(QString::number(vertexT[31][32]));
        ui->V32V34->setText(QString::number(vertexT[31][33]));
        ui->V32V35->setText(QString::number(vertexT[31][34]));

        ui->V33V34->setText(QString::number(vertexT[32][33]));

        ui->V34V35->setText(QString::number(vertexT[33][34]));
        for (int i = 0; i < N; i++){
                delete []vertex[i];
                delete []vertexT[i];
            }
        delete []vertex;
        delete []vertexT;

}

void MainWindow::on_ReturnButton_clicked() // Возврат начального состояния
{
    ui->EndTextBrowser->setText("");
    ui->BeginTextBrowser->setText("");

    ui->V1V2->setText("15200");
    ui->V1V3->setText("11200");
    ui->V1V4->setText("14100");
    ui->V1V5->setText("10500");
    ui->V1V6->setText("18700");
    ui->V1V7->setText("26500");
    ui->V1V8->setText("30100");

    ui->V2V3->setText("14300");
    ui->V2V7->setText("16300");
    ui->V2V12->setText("10500");
    ui->V2V18->setText("23500");
    ui->V2V21->setText("18000");
    ui->V2V25->setText("15400");

    ui->V3V4->setText("25700");
    ui->V3V25->setText("12600");

    ui->V4V5->setText("13000");
    ui->V4V25->setText("13400");
    ui->V4V26->setText("15100");

    ui->V5V26->setText("47000");
    ui->V5V27->setText("43400");
    ui->V5V28->setText("46600");
    ui->V5V29->setText("41700");
    ui->V5V30->setText("12500");

    ui->V6V7->setText("35000");
    ui->V6V8->setText("38000");
    ui->V6V10->setText("45000");
    ui->V6V11->setText("10500");

    ui->V7V11->setText("44800");
    ui->V7V12->setText("11000");
    ui->V7V13->setText("13700");
    ui->V7V35->setText("10500");

    ui->V8V9->setText("23800");
    ui->V8V10->setText("44000");

    ui->V9V10->setText("57400");
    ui->V9V11->setText("57000");

    ui->V10V11->setText("26700");

    ui->V11V31->setText("56700");
    ui->V11V35->setText("48500");

    ui->V12V13->setText("19000");
    ui->V12V15->setText("11200");
    ui->V12V18->setText("12000");

    ui->V13V14->setText("22000");
    ui->V13V15->setText("29700");
    ui->V13V35->setText("25000");

    ui->V14V15->setText("29100");
    ui->V14V35->setText("21200");

    ui->V15V16->setText("14400");
    ui->V15V18->setText("30500");

    ui->V16V17->setText("26500");
    ui->V16V18->setText("32700");

    ui->V17V18->setText("13300");

    ui->V18V19->setText("17900");
    ui->V18V21->setText("18600");

    ui->V19V20->setText("15600");
    ui->V19V21->setText("19600");

    ui->V20V21->setText("18400");
    ui->V20V22->setText("10700");

    ui->V21V22->setText("16300");
    ui->V21V25->setText("23700");

    ui->V22V23->setText("11200");
    ui->V22V24->setText("27000");
    ui->V22V25->setText("25700");

    ui->V23V24->setText("17000");

    ui->V24V25->setText("15900");
    ui->V24V26->setText("15100");

    ui->V25V26->setText("27200");

    ui->V26V27->setText("10500");

    ui->V27V28->setText("41200");

    ui->V28V29->setText("40500");

    ui->V29V30->setText("11700");

    ui->V31V32->setText("44500");
    ui->V31V35->setText("37800");

    ui->V32V33->setText("57600");
    ui->V32V34->setText("37800");
    ui->V32V35->setText("64400");

    ui->V33V34->setText("47900");

    ui->V34V35->setText("39900");
}
