#ifndef Window_H
#define Window_H

#include <QWidget>
#include <paintscene.h>
#include "sourcedata.h"
#include "filemanager.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Window; }
QT_END_NAMESPACE

class Window : public QWidget
{
    Q_OBJECT

public:
    explicit Window(QWidget *parent = 0);
    ~Window();

public slots:
    void CreatePoint(QPointF pnt);
private slots:
    void on_b_addmanual_clicked();

    void on_b_LoadFile_clicked();

    void on_b_SaveFile_clicked();

    void on_b_mnk_calc_clicked();

    void on_b_clear_clicked();

private:
    Ui::Window *ui;
    paintScene *scene;
    SourceData *sdata;
    FileManager *fileman;
};

#endif // Window_H
