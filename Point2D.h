#ifndef POINT2D_H
#define POINT2D_H

#include <ostream>
#include <math.h>
class Point2D{
	public:
		double x;
		double y;
		
		//COnstructor
		Point2D(double x, double y){
		this->x=x;
		this->y=y;
		}
//======================================

		static double distance(const Point2D &a, const Point2D &b){
		double disnt = 0;
		double dx = a.x - b.x;
		double dy = a.y - a.y;
		disnt = sqrt(pow(dx,2) + pow(dy,2));

		return disnt;	
		
		}
//========================================
		// EL operator== nos dice que vamos hacer una comparacion entre los dos Point2D 
		bool operator==(const Point2D &b) const {
		//Si son iguales nos devolvera TRUE, en caso contrario FALSE
		//para llamar al operador se llamara de a==b
		return ((this->x == b.x ) && ( this->y == b.y) ); 
		
		}
//===================================

		//Ahora una funcion similar pero nos comprueba si los dos puntos son diferentes
		bool operator!=(const Point2D &b) const {
		return ((this->x != b.x) && (this->y != b.y));
		}

//===================================
		friend std::ostream& operator<<(std::ostream &out, const Point2D &p){
		
		out << "(" <<p.x <<" , " << p.y << ")";
		return out;
		//De esta forma cuando lo llamemos mediante std::cout nos imprimira el contenido que hay en out
		}

};

#endif
