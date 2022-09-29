#include "Window.h"
#include "ui_Window.h"
#include <QFileDialog>
#include <QDebug>

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
    connect(scene, &paintScene::CreatePoint , this, &Window::CreatePoint);

    sdata = new SourceData();
    sdata->SetRanges(ranges);
    sdata->SetScene(scene);
    connect(scene, &paintScene::CreatePoint , sdata, &SourceData::CreatePoint);

    fileman = new FileManager();
    fileman->ForceDirectory("/mnk/PointDataFiles/");
    fileman->SetSourceData(sdata);
}

Window::~Window()
{
    delete ui;
    delete fileman;
    delete sdata;
    delete scene;
}

void Window::CreatePoint(QPointF pnt)
{
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
                                                    tr("Open File with points data"),  fileman->GetPath(), tr("Point-Data Text Files (*.csv, *.txt)"));
    if(fileName=="") {
        ui->l_message->setText("Selected no file");
    } else {
        ui->l_message->setText("Selected file : "+ fileName);
        if(fileman->LoadFile(fileName))
        {
            ui->l_message->setText("Loaded file : "+ fileName);
            //sdata->SetPointList(points);
            //scene->drawPointList(points);
        }
    }
}

void Window::on_b_SaveFile_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(this,
                                                    tr("Save File with points data"),
                                                     fileman->GetPath(),
                                                    tr("Point-Data Text Files (*.csv, *.txt)") );
   qDebug() << "fileName = " << fileName;
    if(fileName=="") {
        ui->l_message->setText("Saved no file");
    } else {
        ui->l_message->setText("Saved to file : "+ fileName);
         fileman->SaveFile(fileName,sdata->GetPointList());
    }
}
