#include <iostream>

// простой пример механизма наследования с точки зрения модификаторов доступа
class ParentClass
{
public:
	int public_int;
	void public_func() { std::cout << "Public Parent Class function call" << std::endl; }
private:
	int private_int;
	void private_func() { std::cout << "Private Parent Class function call" << std::endl; }
protected:
	int protected_int;
	void protected_func() { std::cout << "Protected Parent Class function call" << std::endl; }
};

class PublicChildClass : public ParentClass { };				// публчиные и защищенные члены не меняют свою природу в классе-наследнике
class PrivateChildClass : private ParentClass { };			// публичные и защищенные члены становятся приватными в классе-наследнике
class ProtectedChildClass : protected ParentClass { };		// публичные члены становятся защищенными в классе-наследнике

class Shape
{
public:

	Shape() { std::cout << "Shape was created" << std::endl; }					// конструктор по умолчанию	
	virtual ~Shape() { std::cout << "Shape was destroyed" << std::endl; }		// деструктор
	virtual void show() = 0;														// отобразить фигуру (абстрактный)
	virtual void hide() = 0;														// скрыть фигуру (абстрактный)
};

class Point : public Shape
{
protected:

	int x;
	int y;

public:

	Point(int _x = 0, int _y = 0) : x(_x), y(_y)
	{
		std::cout << "Point was created" << std::endl;
	}

	~Point() { std::cout << "Point was destroyed" << std::endl; }

	void show() override
	{
		// Shape::show();			вызов родительской версии метода (если таковая есть)
		std::cout << "Point is shown at (";
		std::cout << x << "," << y << ")" << std::endl;
	}

	void hide() override
	{
		// Shape::hide();
		std::cout << "Point is hidden at (";
		std::cout << x << "," << y << ")" << std::endl;
	}

	void move(int dx = 0, int dy = 0)
	{
		x += dx;
		y += dy;
	}
};

class Circle : virtual public Point
{
protected:

	int radius;

public:

	Circle(int _x = 0, int _y = 0, int rad = 1) : Point(_x, _y),
		radius(rad)
	{
		std::cout << "Circle was created" << std::endl;
	}

	void show() override
	{
		std::cout << "Circle is shown at (";
		std::cout << x << "," << y << "," << radius << ")" << std::endl;
	}

	void hide() override
	{
		std::cout << "Circle is hidden at (";
		std::cout << x << "," << y << "," << radius << ")" << std::endl;
	}

	~Circle() { std::cout << "Circle was destroyed" << std::endl; }
};

class Rectangle : virtual public Point
{
protected:

	int width;
	int height;

public:

	Rectangle(int _x = 0, int _y = 0, int w = 1, int h = 1) : Point(_x, _y), width(w), height(h)
	{
		std::cout << "Rectangle was created" << std::endl;
	}

	void show() override
	{
		std::cout << "Rectangle is shown at (";
		std::cout << x << "," << y << "," << width << "," << height << ")" << std::endl;
	}

	void hide() override
	{
		std::cout << "Rectangle is hidden at (";
		std::cout << x << "," << y << "," << width << "," << height << ")" << std::endl;
	}

	~Rectangle() { std::cout << "Rectangle was destroyed" << std::endl; }
};

class CircleInRectangle : public Circle, public Rectangle
{
public:

	CircleInRectangle(int x = 0, int y = 0, int r = 1) : Point(x,y), Circle(x, y, r), Rectangle(x, y, r, r) 
	{
	}
	
	void show()
	{
		std::cout << "Circle in Rectangle is shown" << std::endl;
		Circle::show();
		Rectangle::show();
	}
	
	void hide()
	{
		std::cout << "Circle in Rectangle is shown" << std::endl;
		Circle::hide();
		Rectangle::hide();
	}
};

class UnmovableShape : public Shape
{
	void show() override
	{
		std::cout << "Showing unmovable shape" << std::endl;
	}

	void hide() override
	{
		std::cout << "Hiding unmovable shape" << std::endl;
	}
};

void Animate(Point& point)
{
	std::cout << "Animating some Point" << std::endl;
	point.move(1, 1);
}

void main()
{
	std::cout << "******** Inheritance and types of inheritance ******** " << std::endl << std::endl;

	std::cout << "ParentClass Calls:" << std::endl;
	ParentClass parent;
	parent.public_func();
	// ошибка при попытке обратиться к приватному или защищенному члену полю
	// parent.protected_func();
	// parent.private_func();

	PublicChildClass public_child;
	ProtectedChildClass protected_child;
	PrivateChildClass private_child;

	public_child.public_func();
	// ошибка при вызове функций
	// protected_child.public_func();
	// private_child.public_func();

	std::cout << std::endl << "******** Shapes ********" << std::endl << std::endl;

	// запрещено, так как Shape - абстрактный
	// std::cout << "Shape:" << std::endl << std::endl;
	// 
	// Shape shape;
	// shape.show();
	// shape.hide();

	std::cout << std::endl << "Point:" << std::endl << std::endl;

	Point point(3,3);
	point.show();
	point.hide();

	std::cout << std::endl << "Circle:" << std::endl << std::endl;

	Circle circle(3,7);
	circle.show();
	circle.hide();

	std::cout << std::endl << "Rectangle:" << std::endl << std::endl;

	Rectangle rectangle(9,3);
	rectangle.show();
	rectangle.hide();

	std::cout << std::endl << "Circle In Rectangle:" << std::endl << std::endl;

	CircleInRectangle cir(1,1,5);
	cir.show();
	cir.hide();

	std::cout << std::endl << "******** Polymorphism with Shapes ********" << std::endl << std::endl;

	Animate(point);
	point.show();
	Animate(circle);
	circle.show();
	Animate(rectangle);
	rectangle.show();
	Animate(cir);
	cir.show();

	std::cout << std::endl << "******** Further Polymorphism with Shapes ********" << std::endl << std::endl;

	Shape* shapes[5];
	shapes[0] = new Point(3,3);
	shapes[1] = new Circle(3,7, 5);
	shapes[2] = new Rectangle(2,-3,4,4);
	shapes[3] = new CircleInRectangle(2,10,6);
	shapes[4] = new UnmovableShape();
	for (int i = 0; i < 5; i++)
	{
		Point* p = dynamic_cast<Point*>(shapes[i]);
		if (p != nullptr)
		{
			p->move(1, 1);
			p->show();
		}
	}

	for (int i = 0; i < 5; i++)
		delete shapes[i];

	system("pause");
}