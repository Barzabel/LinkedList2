template<class T>
class Node2{
public:
	T value;
	Node2<T>* next;
	Node2<T>* prev;
	Node2(T value) :next(nullptr), prev(nullptr), value( value)
	{
	
	}




private:

};