#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    int width = 500;
    int height = 500;

    this->scene = new Scene();
    this->scene->draw();

    QImage image = QImage(width, height, QImage::Format_RGB32);

    for (int i = 0; i < width; i++)
    {
        for (int j = 0; j < height; j++)
        {
            image.setPixel(i, j, qRgb(this->scene->frameBuffer[i][j][0], this->scene->frameBuffer[i][j][1], this->scene->frameBuffer[i][j][2]));
        }
    }

    QGraphicsScene *graphics = new QGraphicsScene(this);
    graphics->addPixmap(QPixmap::fromImage(image));

    ui->graphicsView->setScene(graphics);
}

MainWindow::~MainWindow()
{
    delete ui;
}
