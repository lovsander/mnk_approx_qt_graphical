#include "Window.h"
#include "ui_Window.h"
#include <QFileDialog>

const QRect ranges(-240,-240,480,480);

Window::Window(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Window)
{
    ui->setupUi(this);
    scene = new paintScene();
    ui->graphicsView->setScene(scene);
    scene->setSceneRect(ranges);
    scene->drawAxes();
    sdata = new SourceData();
    sdata->SetRanges(ranges);
    connect(scene, &paintScene::CreatePoint , this, &Window::CreatePoint);

    fileman = new FileManager();
    FileManager::ForceDirectory("/mnk/PointDataFiles/");
}

Window::~Window()
{
    delete ui;
}

void Window::CreatePoint(QPointF pnt)
{
    sdata->AddPoint(pnt);
    ui->l_message->setText("Added point: x "+QString::number(pnt.x())+",  y "+ QString::number(pnt.y()));
}

void Window::on_b_addmanual_clicked()
{    
    // silent replace wrong char ','
    ui->le_x->setText(ui->le_x->text().replace(',','.'));
    ui->le_y->setText(ui->le_y->text().replace(',','.'));

    if (SourceData::CheckStringValidity(ui->le_x->text()) && SourceData::CheckStringValidity(ui->le_y->text()))
    {
        QPointF *pnt = new QPointF(ui->le_x->text().toDouble(),ui->le_y->text().toDouble());

        if (sdata->AddPoint(*pnt))
        {
            scene->drawPoint(*pnt,Qt::red);
        }
        else
        {
            ui->l_message->setText("Check Point Validity failed. "+sdata->GetLastErrorMessage());
        }
        delete pnt;
    }
    else
    {
        ui->l_message->setText("Check String Validity failed");
    }

}

void Window::on_b_LoadFile_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this,
                                                    tr("Open File with points data"), FileManager::GetPath(), tr("Point-Data Text Files (*.csv, *.txt)"));
    if(fileName!="") {
        ui->l_message->setText("Selected no file");
    } else {
        ui->l_message->setText("Selected file : "+ fileName);
        QList<QPointF> points;
        FileManager::LoadFile(fileName, points);
        sdata->SetPointList(points);
        scene->drawPointList(points);
    }
}

void Window::on_b_SaveFile_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(this,
                                                    tr("Save File with points data"),
                                                    FileManager::GetPath(),
                                                    tr("Point-Data Text Files (*.csv, *.txt)") );
    if(fileName!="") {
        ui->l_message->setText("Saved no file");
    } else {
        ui->l_message->setText("Saved to file : "+ fileName);
        FileManager::SaveFile(fileName,sdata->GetPointList());
    }
}
