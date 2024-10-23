#include <ostream>
#include "List.h"
//prueba
template <typename T>
class ListArray : public List<T>{

	private:
	T* arr;//Puntero al array dianmico
	int max;//Capacidad del array
	int n; //Numero actural de elementos lista
	static const int MINSIZE;//Tamaño min del array

	//Metodo para redimensionar el array dinamico	
	void resize(int new_size){
        if (new_size <= max){
                return; //Si nuevo tamaño es menor o igual al actual, no hacemos nada
        }

        T* new_arr = new T[new_size];//Reservamos nueva memoria
        for (int i = 0;i <n;i++){
                new_arr[i] = arr[i]; //Copiamos los elem en el nuevo array
        }

        delete[] arr; //liberamos memoria del antiguo array
        arr = new_arr; // Puntero apunta nuevo array
        max = new_size; //Actualizamos cap max
        }

	
//=========================================

	public:
	
	//COnstructor defecto
	ListArray(){
	static const int MINSIZE = 10;
	max = MINSIZE;
	arr = new T[max];
	n =0;
	}
//==========================================
	~ListArray(){
		delete[]arr;
	}
//==========================================
	T operator[](int pos){
		if (pos < 0 || pos >=n){
			throw std::out_of_range("Index out of bounds");
		}
		return arr[pos];
	}
//==========================================
	friend std::ostream& operator<<(std::ostream &out, const ListArray<T> &list){
	for (int i=0; i< list.n;i++){
		out<< list.arr[i] << " ";//Imprime cada elemento
	}
	return out;
	}

	void insert(int pos,T e) override{
		 if (pos < 0 || pos > n) {
			 throw std::out_of_range("La posición está fuera del rango.");
		 }
// Desplaza los elementos a la derecha para hacer espacio
        for (int i = n; i > pos; --i) {
            arr[i] = arr[i - 1];
        }

        // Inserta el nuevo elemento en la posición pos
        arr[pos] = e;

        // Incrementa el número actual de elementos
        ++n;

	}
//=========================================
	void append(T e) override{
		arr[n]= e;
		n++;	
	}

//=========================================
	void prepend(T e) override{
       // Desplaza los elementos a la derecha para hacer espacio al principio
        for (int i = n; i > 0; --i) {
            arr[i] = arr[i - 1];
        }

        // Inserta el nuevo elemento en la primera posición (índice 0)
        arr[0] = e;

        // Incrementa el número actual de elementos
        ++n;	
	}
//=========================================
	T remove(int pos) override{
	if ( 0 > pos || pos >n-1){
	throw std::out_of_range("POSICION fuera de rango ");
	}	
	// Guarda el elemento a eliminar
        T removedElement = arr[pos];

        // Desplaza los elementos a la izquierda para llenar el hueco
        for (int i = pos; i < n - 1; ++i) {
            arr[i] = arr[i + 1];
        }

        // Decrementa el número de elementos
        n--;

        // Devuelve el elemento eliminado
        return removedElement;
	}
//=========================================

	T get(int pos) const override {
	if (pos < 0 || pos >= n) {
            throw std::out_of_range("La posición está fuera del rango.");
        }
	T get = arr[pos];
	
	return get;	
	}
//=========================================

	int search(T e) const override {
	for(int i =0; i< n;i++){
	if(arr[i] == e){
	return i;
	}
	}
	return -1;
	}
//=========================================

	bool empty() const override{

	return n==0;
	}
//========================================

	int size() const override{
	
	return n;
	}
//=======================================
};



