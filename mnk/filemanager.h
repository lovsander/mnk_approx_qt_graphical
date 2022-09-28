#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <QObject>
#include <QDir>

// файл csv x,y место user/mnkPavlov/files/
// коррекция - игнор мусора, или файла если меньше 2х точек
// и сохранять загруженные исходные данные. сохранять в то же имя+Corrected.csv
class FileManager : public QObject
{
    Q_OBJECT
public:
    explicit FileManager(QObject *parent = nullptr);
    static bool LoadFile(QString filename, QList<QPointF> &points);
    static bool SaveFile(QString filename, QList<QPointF> points);
    static void ForceDirectory(QString path);
    static QString  GetPath();
signals:
private:
   static  QDir dirDataFiles;
};

#endif // FILEMANAGER_H
