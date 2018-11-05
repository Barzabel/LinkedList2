#pragma once


template<class T>
	LinkedList2<T>::LinkedList2():head(nullptr), tail( nullptr), count(0)
	{
	

	}

	template<class T>
	void LinkedList2<T>::add_in_position(Node2<T>*position,Node2<T>*val)
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
			if (position->next != nullptr) 
			{

				position->next->prev = val;
			}
			
			val->prev  = position;
			val->next = position->next;

			
			position->next = val;
			
			
			if (val->next == nullptr) {
				this->tail = val;
			}
			this->count++;
		}
	}

	template<class T>
	void LinkedList2<T>::add_in_tail(Node2<T>*val)
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

	template<class T>
	void LinkedList2<T>::add_in_head(Node2<T>*val)
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


	template<class T>
	Node2<T>* LinkedList2<T>::find(T val) {
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

	template<class T>
	void LinkedList2<T>::dell(T val) {

		Node2<T>*H = this->find(val);
		if (H->prev == nullptr)
		{
			if(H->next==nullptr)
			{
				this->head = nullptr;
				this->tail = nullptr;
				this->count = 0;
				return;
			}
			this->head = this->head->next;
			
		
				this->head->prev = nullptr;
			this->count--;
			return;
		}
		if(H->next==nullptr)
		{
	
			this->tail = this->tail->prev;
			this->tail->next = nullptr;
			this->count--;
			return;
		}
		if (H->prev != nullptr)
		{

			H->prev->next = H->next;
			H->next->prev = H->prev;

			this->count--;
			return;


		}


		
	}

	template<class T>
	void LinkedList2<T>::printn()
	{
		Node2<T>*H = this->head;
		while (H != nullptr)
		{
			cout << H->value << endl;
			H = H->next;
		}

	
	
	}


	template<class T>
	void LinkedList2<T>::printe() {
		Node2<T>*H = this->tail;
		while (H!=nullptr)
		{
			cout << H->value << endl;
			

			H = H->prev;
		}



	}

	template<class T>
	unsigned int LinkedList2<T>::getsize() {
		return this->count;
	}

	template<class T>
	Node2<T>* LinkedList2<T>::gethead()
	{
		return this->head;
	}

	template<class T>
	Node2<T>* LinkedList2<T>::gettail()
	{

		return this->tail;
	}

