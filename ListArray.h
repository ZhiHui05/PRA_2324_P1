#include <ostream>
#include "List.h"

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


};



