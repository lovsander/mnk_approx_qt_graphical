# mnk_approx_qt_graphical
Аппроксимация входных данных линейной зависимостью, используя Метод Наименьших Квадратов. 


Разработать графическое приложение, позволяющее:

qpainter - рисование мышью точек
ввод с клавиатуры точек



1. Вводить данные для расчёта. 
Предусмотреть проверку корректности вводимых данных;
https://www.youtube.com/watch?v=f12HM1rZSD4

проверка данных
1 не число
2 все одинаковые (в одной точеке)
3 нет 2х разных точек
4 слишком вне диапазона числа (?)



2. Загружать исходные данные для расчёта из файла. 
Загрузку и сохранение исходных данных реализовать в классе FileManager. 

файл csv x,y
место user/mnkPavlov/files/

Корректировать  
коррекция - игнор мусора, или файла если меньше 2х точек


и сохранять загруженные исходные данные. 
сохранять в то же имя+Corrected.csv


Для хранения исходных данных реализовать класс SourceData;
private 
			Qlist<QPointF> points
public

			bool CheckPointValidity(QPointF pnt, QString &ErrMessage){
			// not number
			// out range
			}
			
			bool SetPoint(QPointF pnt) {
				if(CheckPointValidity(pnt))
				points.add(pnt);
			}
			
			
			GetPintSize() { return points.size();}
			bool GetPoint(int n ,QPointF *pnt) 
			{
				if (GetPintSize() > n) {
					pnt = points.at(n); 
					return true;
				}else {
					pnt = nullptr;
					return false;
				}
			}
			double GetPoint_x(int n);
			double GetPoint_y(int n);
			
			
			
3. Выводить результат расчёта на экран (либо сообщение об ошибке, если расчёт невозможен). Алгоритм расчёта реализовать в классе MnkCalculator.
https://studfile.net/preview/6218855/page:2/



Результат представить в виде исходных текстов программы и файла (файлов) с входными данными для расчётов.

Язык разработки: C++ с использованием библиотек Qt. 

Разработка под ОС семейства Linux.

Особое внимание уделить принципам ООП. 


FileManager


SourceData{
QPointF{
 double x
 double y
}
number
}


MnkCalculator () {
if( n == 0 )then return error

for i to number {
	X+=xi
	Y+=yi
	XX+=xi*xi
	Y+=xi*yi
}

a_bottom = ( n*XX - X*X )
if (a_bottom == 0 )then return error


a = (n*XY-X*Y) / ( n*XX - X*X )
b = (Y - a*X ) / n

}
