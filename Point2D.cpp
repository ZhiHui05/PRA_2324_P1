#include"Point2D.h"
#include<iostream>
#include<cmath>



//COnstructor
		Point2D::Point2D(double x, double y){
                this->x=x;
                this->y=y;
                }
//======================================

                double Point2D::distance(const Point2D &a, const Point2D &b){
                double disnt = 0;
                double dx = a.x - b.x;
                double dy = a.y - a.y;
                disnt = sqrt(pow(dx,2) + pow(dy,2));

                return disnt;

                }
//========================================
                // EL operator== nos dice que vamos hacer una comparacion entre los dos Point2D
                bool Point2D::operator==(const Point2D &b) const {
                //Si son iguales nos devolvera TRUE, en caso contrario FALSE
                //para llamar al operador se llamara de a==b
                return ((this->x == b.x ) && ( this->y == b.y) );

                }
//===================================

                //Ahora una funcion similar pero nos comprueba si los dos puntos son diferentes
                bool Point2D::operator!=(const Point2D &b) const {
                return ((this->x != b.x) || (this->y != b.y));
                }

//===================================
		std::ostream& operator<<(std::ostream &out, const Point2D &p){

                out << "(" <<p.x <<" , " << p.y << ")";
                return out;
                //De esta forma cuando lo llamemos mediante std::cout nos imprimira el contenido que hay en out
                }


