#include "filemanager.h"
#include <QPointF>
#include <QTextStream>
#include <QDebug>

void FileManager::SetSourceData(SourceData *sdata)
{
    this->sdata = sdata;
}

bool FileManager::LoadFile(QString filename)
{
    qDebug() << "LoadFile starts";
    QList<QPointF> points;
    QFile loadingFile(filename);
    if (loadingFile.open(QIODevice::ReadOnly))
    {
        QTextStream in(&loadingFile);
        while (!in.atEnd())
        {
            QString line = in.readLine();
            line = line.replace(',','.');
            QStringList pair = line.split(";");
            if(pair.size()==2) {
                if(SourceData::CheckStringValidity(pair.at(0)) && SourceData::CheckStringValidity(pair.at(1)) )
                {
                    QPointF pnt;
                    pnt.setX(pair.at(0).toDouble());
                    pnt.setY(pair.at(1).toDouble());
                    if(sdata->CheckPointValidity(pnt))
                    {
                        qDebug() << "point" << pnt.x() << pnt.y();
                        sdata->AddPoint(pnt);
                    }
                }

            }
        }
        loadingFile.close();
    }
    if(sdata->GetPointsCount()>=2) {
        return true;
    }
    else return false;
}

bool FileManager::SaveFile(QString filename, QList<QPointF> points)
{
    int len = points.count();
    int written=0;
    QFile savingfile(filename);

    if (savingfile.open(QIODevice::WriteOnly))
    {
        QTextStream out(&savingfile);
        out.setCodec("UTF-8");
        foreach( QPointF pnt, points )
        {
            out << pnt.x()<< ";" << pnt.y() << "\n";
            written++;
        }
        savingfile.close();
    }  else return false;

    if (written==len) return true;
    else return false;
}

void FileManager::ForceDirectory(QString path)
{
    dirDataFiles.setPath(QDir::homePath()+path);

    if (!dirDataFiles.exists())
        dirDataFiles.mkpath(".");
}

QString FileManager::GetPath()
{
    return  dirDataFiles.path();
}
