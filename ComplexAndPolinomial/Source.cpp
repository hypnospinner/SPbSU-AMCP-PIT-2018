#include <iostream>
#include <cmath>

class Complex
{
private:
	double real;
	double imag;

public:

	Complex() {
		real = 0;
		imag = 0;
		std::cout << "Creating Complex with Default Constructor\n";
		print();
	}

	Complex(const Complex& a) {
		a.print();
		std::cout << " a adress = " << &a << std::endl;
		real = a.real; 
		imag = a.imag;
		std::cout << "Creating Complex with Copy Constructor\n";
		print();
	}

	Complex(double real){
		this->real = real;
		this->imag = 0;
		std::cout << "Creating Complex by converting primitibe data type to Complex\n";
		print();
	}

	Complex(double real, double imag) {
		this->real = real;
		this->imag = imag;
		std::cout << "Creating Complex with Parametarized Constructor\n";
		print();
	}

	double Real() const {
		return real;
		// std::cout << "Get Real\n";
		// print();
	}

	double Image() const {

		return imag;
		// std::cout << "Get Imaginary\n";
		// print();
	}

	double Normal() {

		return sqrt(real*real + imag * imag);
		// std::cout << "Get Noraml\n";
		// print();
	}

	void print() const {
		std::cout << '(' << real << ", " << imag << ')' << std::endl;
	}

	void Summary(Complex&a, Complex&b) {
		a.real += b.real;
		a.imag += b.imag;
		// std::cout << "Sum Complex Number\n";
		// print();
	}

	operator double()
	{
		return real;
	}

	Complex operator+(const Complex& right) {
		return Complex(real + right.real, imag + right.imag);
	}

	Complex operator*(const Complex& right) {
		return Complex(real * right.real - imag * right.imag, real * right.imag + imag * right.real);
	}

	Complex& operator=(const Complex& right) {
		real = right.real;
		imag = right.imag;
		return *this;
	}

	static Complex testMethod() {
		Complex tmp(1, 5);
		return tmp;
	}

	~Complex() {
		// std::cout << "Destructor Call\n";
	}
};

// перегрузка оператора вывода
std::ostream& operator<<(std::ostream& out, const Complex& c)
{
	out << '(' << c.Real() << ", " << c.Image() << ')';
	return out;
}

//class for polynom
template <typename T>
class Polynom {
public:
	Polynom() {
		length = 1;
		coeffs = new T[1];
		coeffs[0] = 0;
	}

	Polynom(T*_coeffs, int _length) {
		length = _length;
		coeffs = new T[length];
		for (int i = 0; i < length; ++i)
			coeffs[i] = _coeffs[i];
	}

	Polynom(const Polynom& right) {
		length = right.length;
		coeffs = new T[length];
		for (int i = 0; i < length; ++i)
			coeffs[i] = right.coeffs[i];
	}

	int GetLength() const {

		return length;
	}

	~Polynom() {
		delete[]coeffs;
	}

	double& operator[](int index) {
		return coeffs[index];
	}

	T& operator()(double x) {
		std::cout << "Calculating function value" << std::endl;
		T result = 0;
		T currXdegree = 1;
		for (int i = 0; i < length; ++i) {
			result = result + coeffs[i] * currXdegree;
			currXdegree = currXdegree * (T)x;
		}
		std::cout << "Finished calculations" << std::endl;
		return result;
	}

	T& calc(double x)
	{
		std::cout << "Calculating function value" << std::endl;
		T result = 0;
		T currXdegree = 1;
		for (int i = 0; i < length; ++i) {
			result = result + coeffs[i] * currXdegree;
			currXdegree = currXdegree * (T)x;
		}
		std::cout << "Finished calculations" << std::endl;
		std::cout << "Reslult adress = " << &result << std::endl;
		return result;
	}

	void print() const {

		for (int i = length - 1; i >= 0; --i) {
			std::cout << coeffs[i] << "x^" << i;
			if (i != 0) std::cout << "+";
		}
		std::cout << std::endl;
	}

private:
	T* coeffs;
	int length;
};

int main()
{
	std::cout << "Having fun with Complex Type" << std::endl << std::endl;
	// создаем 2 комплексных числа
	Complex a(3, 5), b(7, 8);

	// выводм (a,b) + (c,d) =
	a.print();
	std::cout << " + ";
	b.print();
	std::cout << " = ";

	// складываем числа и выводим
	(a + b).print();

	std::cout << std::endl;

	std::cout << "Converting Complex to other types" << std::endl << std::endl;

	// создаем комплесное число
	Complex c(3, 2);
	std::cout << "Complex c = " << c << std::endl;

	// присваиваем его примитивным целочисленным типам данных
	double d = c;
	float f = c;
	int i = c;

	std::cout << "Double d = " << d << std::endl 
		<< "Float f = " << f << std::endl 
		<< "Int i = " << i << std::endl;

	Complex d_c = d;
	Complex f_c = f;
	Complex i_c = i;

	std::cout << "Complex d_c (converted from double) = " << d_c << std::endl
		<< "Complex f_c (converted from float) = " << d_c << std::endl
		<< "Complex i_c (converted from int) = " << d_c << std::endl;
	
	std::cout << std::endl;

	std::cout << "Having fun with Polynom template" << std::endl;

	// создаем полином c целочисленными коэффициентами
	int i_coeffs[2] = { 1, 2 };
	Polynom<int> int_f(i_coeffs, 2);

	// создаем полином с дробными коэффициентами
	double d_coeffs[2] = { 1, 2 };
	Polynom<double> double_f(d_coeffs, 2);

	// выводм полином с целочисленными коэффициентами
	int_f.print();
	double_f.print();

	// вычислим значение полинома в точке
	std::cout << "int_f(1.5) = " << int_f(1.5) << std::endl;
	std::cout << "double_f(1.5) = " << double_f(1.5) << std::endl;

	// создаем полином с комплексными коэффициентами
	Complex c_coeffs[3] = { Complex(1,1), Complex(1,0), Complex(2,2) };
	Polynom<Complex> complex_f(c_coeffs, 3);
	
	// выводим полином с комплексными коэффициентами
	complex_f.print();
	
	// вычисляем значение полинома в точке 1
	Complex C = complex_f.calc(1);
	std::cout << "complex_f(1) = " << C << std::endl;

	std::cout << std::endl;
	system("pause");

	return 0;
}

// int main() {
// 
// 
// 	//	Complex a = Complex::testMethod();
// 	double coeffs[3] = { 1,2,1 };
// 	Polynom<double> poly(coeffs, 3);
// 	poly.print();
// 	poly[1] = 4;
// 	poly.print();
// 	std::cout << poly(2) << std::endl;
// 	system("pause");
// 	return 0;
// }