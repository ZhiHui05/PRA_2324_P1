#ifndef POINT2D_H
#define POINT2D_H

#include <ostream>
#include <math.h>
class Point2D{
	public:
		double x;
		double y;
		
		//COnstructor
		Point2D(double x, double y);
//======================================

		static double distance(const Point2D &a,const Point2D &b) ;
//========================================
		// EL operator== nos dice que vamos hacer una comparacion entre los dos Point2D 
		bool operator==(const Point2D &b) const;
//===================================

		//Ahora una funcion similar pero nos comprueba si los dos puntos son diferentes
		bool operator!=(const Point2D &b) const;

//===================================
		friend std::ostream& operator<<(std::ostream &out, const Point2D &p);

};

#endif
