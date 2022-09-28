#include "Window.h"
#include "ui_Window.h"

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
    if (SourceData::CheckStringValidity(ui->le_x->text()) && SourceData::CheckStringValidity(ui->le_y->text()))
    {
        QPointF *pnt = new QPointF(ui->le_x->text().toDouble(),ui->le_y->text().toDouble());

        if (sdata->AddPoint(*pnt))
        {
            scene->drawPoint(*pnt);
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
