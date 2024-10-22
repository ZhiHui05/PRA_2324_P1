#include <ostream>

template <typename T>
class Node {
	public:
	T data;
	Node<T>* next;
//Sin terminar
	//Constructor con argumento opcional para next(inicializado a nullptr)
	Node(T data,Node<T>* next=nullptr): datat(data), next(next){
	}
//=========================================ç

	//Sobrecarga operador >> `para imprimir el contenido nodo
	friend std::ostream& operator<<(std::ostream &out, const Node<T> &node){
	out << node.data;//Imprimimos solo dato almacenado en nodo
	return out;
	
	}


};

