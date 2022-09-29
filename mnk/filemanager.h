#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <QObject>
#include <QDir>
#include "sourcedata.h"

// файл csv x,y место user/mnkPavlov/files/
// коррекция - игнор мусора, или файла если меньше 2х точек
// и сохранять загруженные исходные данные. сохранять в то же имя+Corrected.csv
class FileManager : public QObject
{
    Q_OBJECT
public:
    explicit FileManager(QObject *parent = nullptr);
    void SetSourceData(SourceData *sdata);
    bool LoadFile(QString filename);
    bool SaveFile(QString filename, QList<QPointF> points);
    void ForceDirectory(QString path);
    QString  GetPath();
//signals:
private:
    QDir dirDataFiles;
    SourceData *sdata;
};

#endif // FILEMANAGER_H
