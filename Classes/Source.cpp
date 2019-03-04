#include <iostream>
#include "Vector.h"

// перегружаем оператор вывода
std::ostream& operator<<(std::ostream& out, const Vector& vec)
{
	for (int i = 0; i < vec.size; i++)
		out << vec.data[i] << " ";
	out << std::endl;
	return out;
}

int main()
{
	// создадим вектор
	Vector vector;

	std::cout << "ObjCount: " << vector.getObjCount() << std::endl;

	// заполним вектор
	for (int i = 0; i < 5; i++)
		vector.push_back(i + 1);

	// присваеваем
	Vector vectorToCopy = vector;

	std::cout << "ObjCount: " << Vector::getObjCount() << std::endl;

	// Изя Хакерман!!1 (получаем доступ к приватным полям класса)
	
	Vector* vec = new Vector();
	
	for (int i = 0; i < 5; i++)
		vec->push_back(i + 1);

	std::cout << "First elemnt before magic: "<< vec->getElemAt(0) << std::endl;

	((int*)((int*)vec)[0])[0] = 3;

	std::cout << "First elemnt after magic: " << vec->getElemAt(0) << std::endl;

	delete vec;

	// выводим вектор с перегруженным оператором
	std::cout << vector << std::endl;

	system("pause");
	return 0;
}

