#include<ostream>
#include"List.h"
#include"Node.h"

	template<typename T>
	class ListLinked : public List<T>{

		private:
		Node<T>* first;
		int n;


		public:
		
	ListLinked(){
		n = 0;
		first = nullptr;
	}

	~ListLinked(){
		Node<T>* current = first;
		Node<T>* next;

		while (current !=nullptr){
			next = current->next;
			delete current;
			current =next;
		}
		first = nullptr;
		n = 0;
	}

	T operator[](int pos){
		if ( pos < 0 || pos >= n){
		throw std::out_of_range("Valor fuera del intervalo");
		}
	
 // Recorremos la lista hasta llegar a la posición pos
        	Node<T>* current = first;
        	for (int i = 0; i < pos; ++i) {
           	 current = current->next;
       		 }

       		 return current->data;  // Devolvemos dato en la posición pos
		}
	
	friend std::ostream& operator<<(std::ostream& out, const ListLinked<T>& list);

	};

		template<typename T>
   	 	std::ostream& operator<<(std::ostream& out, const ListLinked<T>& list) {
        	Node<T>* current = list.first;
        	while (current != nullptr) {
            	out << current->data;    // Imprime el dato del nodo actual
            	if (current->next != nullptr) {
                	out << " -> ";      // Añadimos una flecha si no es el último nodo
            	}
            	current = current->next; // Avanzamos al siguiente nodo
       		}
       		return out;
   	}


	
	




	
