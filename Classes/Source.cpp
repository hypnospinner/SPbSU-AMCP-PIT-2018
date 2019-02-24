#include <iostream>
#include <string>

class Vector
{
public:
	// конструктор по умолчанию
	Vector() {
		std::cout << " Vector Constructor call" << std::endl;
		data = new int[1];
		size = 0;
		capacity = 1;
	}

	// конструктор
	Vector(int _size) {
		std::cout << " Vector Constructor call" << std::endl;
		if (_size <= 0)
			throw "size must be more than 0\n";
		capacity = _size;
		data = new int[capacity];
		size = 0;
	}

	// конструктор
	Vector(int source[], int _size)
	{
		std::cout << " Vector Constructor call" << std::endl;
		capacity = _size;
		size = _size;
		data = new int[capacity];
		for (int i = 0; i < capacity; ++i)
			data[i] = source[i];
	}

	// дестркутор
	~Vector()
	{
		std::cout << "Destructor call" << std::endl;
		delete[] data;
	}

	// выводим массив
	void print()
	{
		for (int i = 0; i < size; i++)
			std::cout << data[i] << " ";
		std::cout << std::endl;
	}

	// добавляем элемент в конец массива
	void push_back(int val)
	{

		if (size < capacity)
		{
			data[size++] = val;
			return;
		}
		capacity *= 1.7;
		int* tmp = new int[capacity];
		for (int i = 0; i < size; ++i)
			tmp[i] = data[i];
		tmp[size++] = val;
		delete[] data;
		data = tmp;
	}

	// получаем последний элемент массива
	int pop_back()
	{
		if (size == 0)
			throw "Empty Vector";
		return data[--size];
	}

	// получаем элемент по индексу
	int& getElemAt(int index)
	{
		if (index < 0 || index > size - 1)
			throw "out of range";
		return data[index];
	}

	int getSize()
	{
		return size;
	}

private:
	int* data;		// динамический массив с элементами
	int size;		// количество элементов в массиве
	int capacity;	// количество места в массиве
};

void testlifecycle() {
	std::cout << "function start\n";
	Vector vec;
	std::cout << "finction ends\n";
}

int main()
{
	Vector emptyVector;			// создаем пустой вектор
	Vector sizedVector(5);		// создаем вектор с инициализированным размером

	int* arr = new int[7];
	for (int i = 0; i < 7; i++)
		arr[i] = i + 1;

	Vector fullVector(arr, 7);	// создаем и инициализируем все поля вектора

	// проверяем работу конструктора и дестркутора (время жизни объекта)
	std::cout << "Starting life cycle test" << std::endl;
	testlifecycle();
	std::cout << "Exited life cycle test" << std::endl;

	// выводим вектора
	std::cout << "printing empty vector with " << emptyVector.getSize() << " elems :" << std::endl;
	emptyVector.print();

	std::cout << "printing sized vector with " << sizedVector.getSize() << " elems :" << std::endl;
	sizedVector.print();

	std::cout << "printing full vector with " << fullVector.getSize() << " elems :" << std::endl;
	fullVector.print();

	// добавляем элементы
	for (int i = 0; i < 20; i++)
		sizedVector.push_back(i + 1);

	std::cout << "printing filled sized vector:" << std::endl;
	sizedVector.print();

	// получаем последний элемент вектора
	std::cout << "last element in  fullVector : " << fullVector.pop_back() << std::endl;

	// выведем элементы вектора sizedVector 
	// (мы напрямую получаем к ним доступ, хотя результат сходен с вызовом метода print())
	for (int i = 0; i < sizedVector.getSize(); i++)
		std::cout << sizedVector.getElemAt(i) << " ";
	std::cout << std::endl;

	// работаем с указателем на вектор
	Vector* vectorPointer = new Vector(4);

	for (int i = 0; i < 4; i++)
		vectorPointer->push_back(i + 1);

	std::cout << "printing pointer to vector with " << vectorPointer->getSize() << " elems :" << std::endl;
	vectorPointer->print();

	delete vectorPointer;

	system("pause");
}