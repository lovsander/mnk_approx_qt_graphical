#include "filemanager.h"
#include <QPointF>
#include <QDataStream>

FileManager::FileManager(QObject *parent) : QObject(parent)
{

}

bool FileManager::LoadFile(QString filename, QList<QPointF> &points)
{

}

bool FileManager::SaveFile(QString filename, QList<QPointF> points)
{
    int len = points.count();
    int written=0;
    QFile file(GetPath()+filename);

    if (file.open(QIODevice::WriteOnly))
    {
        QDataStream out(&file);

        foreach( QPointF pnt, points )
        {
            out << pnt.x()<< ";" << pnt.y() << "\n";
            written++;
        }
        file.close();
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
