#include<iostream>
#include"Shape.h"
#include<ostream>

class Circle : public Shape{
//Aqui solo definimos las funciones de Circle y de Shape(con override) En el .cpp deberemos implementar todas
private:
	Point2D center;
	double radius;

public:
	Circle();
	Circle(Point2D point, double rad, std::string c);
	Point2D get_center() const;
	void set_center(Point2D p);
	double get_radius() const;
	void set_radius(double r);
	friend std::ostream& operator<<(std::ostream &out, const Circle &c);



	//====Abstractas de SHAPE======
	double area() const override;
	double perimeter() const override;
	void translate( double incX, double incY) override;
	void print() override;
};
