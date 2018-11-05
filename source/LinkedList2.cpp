#include"Node2.cpp"
#include<iostream>
using namespace std;


template<class T>
class  LinkedList2{
public:
	LinkedList2():head(nullptr), tail( nullptr), count(0)
	{
	

	}
	void add_in_position(Node2<T>*position,Node2<T>*val)
	{
		if (this->head == nullptr)
		{
			this->head = val;
			this->tail = val;
			this->head->prev = nullptr;
			this->head->next = nullptr;
			this->count++;
			cout << "\n" << tail->value << "  ";
		}
		else
		{
			val->next = position->next;
			position->next = val;
			val->prev = position;
			if (val->next == nullptr) {
				this->tail = val;
			}
			this->count++;
		}
	}


	void add_in_tail(Node2<T>*val)
	{
		if(this->head==nullptr)
		{
			this->head = val;
			this->tail = val;
			this->head->prev = nullptr;
			this->head->next = nullptr;
			this->count++;
			
		}
		else
		{
			
			val->prev = this->tail;
			this->tail->next = val;
			this->tail = val;
			this->tail->next = nullptr;
			this->count++;
			
		}
	}


	void add_in_head(Node2<T>*val) 
	{
		if (this->head == nullptr)
		{
			this->head = val;
			this->tail = val;
			this->head->prev = nullptr;
			this->head->next = nullptr;
			this->count++;
		}
		else
		{
			val->next = this->head;
			this->head->prev = val;
			this->head = val;
			this->head->prev = nullptr;
		
		


			this->count++;
		}

	}

	Node2<T>* find(T val) {
		Node2<T>(*H) = this->head;
		while (H != nullptr) {
			if (H->value == val)
			{
				return H;
			}
			H = H->next;
		}
		return nullptr;
	}


	void dell(T val) {
		Node2<T>*H = this->head;
		while (H != nullptr) 
		{
			if(H->value==val)
			{
				if(H->prev==nullptr)
				{
					this->head = this->head->next;
					if (this->head != nullptr)
					{
						this->head->prev = nullptr;
					}
					this->count--;
					return;
				}
				if (H -> prev != nullptr) 
				{
					H->prev->next = H->next;
					H->next->prev = H->prev;
					if(H==nullptr)
					{
						this->tail = H->prev;
					}
					this->count--;
					return;
				}
			}
			H = H->next;
		}








		
	}

	void printn()
	{
		Node2<T>*H = this->head;
		while (H != nullptr)
		{
			cout << H->value << endl;
			H = H->next;
		}

	
	
	}



	void printe() {
		Node2<T>*H = this->tail;
		while (H!=nullptr)
		{
			cout << H->value << endl;
			

			H = H->prev;
		}



	}


	unsigned int getsize() {
		return this->count;
	}


	Node2<T>* gethead() 
	{
		return this->head;
	}
	Node2<T>* gettail() 
	{

		return this->tail;
	}

private:
	Node2<T>*head;
	Node2<T>*tail;
	unsigned int count;
};