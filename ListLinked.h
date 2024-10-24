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

	// Método para agregar nodos al principio de la lista
   	void prepend(T value) override {
        Node<T>* newNode = new Node<T>(value, first);
        first = newNode;
        ++n;
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

//===================================================================================


	// Implementación de métodos de la clase base List<T>
    	void insert(int pos, T e) override {
        if (pos < 0 || pos > n) {
            throw std::out_of_range("Índice fuera del intervalo");
        }
        if (pos == 0) {
            prepend(e);
        } else {
            Node<T>* current = first;
            for (int i = 0; i < pos - 1; ++i) {
                current = current->next;
            }
            Node<T>* newNode = new Node<T>(e, current->next);
            current->next = newNode;
            ++n;
		}
   	
   	}
//=================================================================================

    	void append(T e) override {
        insert(n, e);  // Insertar al final es lo mismo que insertar en la posición n
    	}
//================================================================================

    	T remove(int pos) override {
        	if (pos < 0 || pos >= n) {
           	throw std::out_of_range("Índice fuera del intervalo");
        	}
        	Node<T>* current = first;
        	T removedData;
        	if (pos == 0) {
            		removedData = first->data;
            		first = first->next;
            	delete current;
        	} else {
            		for (int i = 0; i < pos - 1; ++i) {
                	current = current->next;
            	}
            	Node<T>* nodeToRemove = current->next;
            	removedData = nodeToRemove->data;
            	current->next = nodeToRemove->next;
            	delete nodeToRemove;
        	}

        	--n;
        	return removedData;
    		
	}	
//=========================================================

	T get(int pos) const override {
        if (pos < 0 || pos >= n) {
            throw std::out_of_range("La posición está fuera del rango.");
        }
	Node<T>* current = first;

        for (int i = 0;i < pos; i++){
		current = current -> next;
	}

        return current->data;
        }


//=========================================================
    	bool empty() const override {
        	return n == 0;
    	}	

	
//========================================================
	int size() const override {
        	return n;
    	}
//==========================================================
    	int search(T e) const override {
        	Node<T>* current = first;
        	int index = 0;
        	while (current != nullptr) {
            		if (current->data == e) {
                	return index;
            	}
            	
		current = current->next;
            	index++;
        	}	
        	
		return -1;
    	
	}



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


	
	




	
