#include<iostream>
#include"Point2D.h"
#include"Circle.h"
#include<cmath>
#include<ostream>
#include<string>

#define PI 3.141592
//Aqui implementaremos los metodos de Circke y tmb las abstractas
	Circle::Circle() : center(0,0) ,radius(1), Shape()/*Llama al constructor color defalaut(rojo)*/{
	
	}
//=============================================
	Circle::Circle(Point2D point, double rad, std::string c) : center(point), radius(rad), Shape(c) {}
//===========================================
	Point2D Circle::get_center() const {
		return center;
	}
//============================================
        void Circle::set_center(Point2D p){
	
	this->center = p;
	}
//============================================
        double Circle::get_radius() const{
	
	return radius;
	}
//============================================
        void Circle::set_radius(double r){
	
	this->radius = r;
	}
//============================================
        std::ostream& operator<<(std::ostream &out, const Circle &c){
	out<< "Centro: " << c.center << " " << "Radio: "<< c.radius;
	
		return out;
	}


//====Abstractas de SHAPE======

        double Circle::area() const{
	return (PI * pow(radius,2));
	}

//==========================================
        double Circle::perimeter() const{
	return (2*PI *radius);
	}
//=========================================
        void Circle::translate( double incX, double incY){
	center.x += incX;
	center.y += incY;	
	}
//==========================================
        void Circle::print(){
		std::cout<< "Circulo: Color =" << color << ", Radio = "<<radius << ", Centro= "<<center <<std::endl;	
	}



