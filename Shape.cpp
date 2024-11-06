#include<ostream>
#include<string>
#include<stdexcept>
#include"Shape.h"
#include"Point2D.h"

	//protected:
        //std::string Shape::color(solo puede ser de color: red,green, blue )
	
	//public:
	Shape::Shape():color("red"){
	}

//==========================
	Shape::Shape(std::string color){
	if( color != "red" && color != "green" && color != "blue"){
	throw std::invalid_argument("Color no valido");
	}

	this-> color  = color;
	}

//=========================
        std::string Shape::get_color() const{
	
	return color;	
	}
//========================
        void Shape::set_color(std::string c){
	 if( color != "red" &&  color != "green" && color != "blue"){
        throw std::invalid_argument("Color no valido");
        }
	this -> color = c;


	}

//==============ABSTRACTAS======

/*
	double area() const override;
	
	
	
        
//==========================
	double perimeter() const override;
	
	

        
//===========================
	void translate(double incX, double incY) override;
	
	
	
        
//============================
	void print() override;
	
	
*/
