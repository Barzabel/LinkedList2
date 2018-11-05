#include<iostream>
#include"LinkedList2.cpp"






using namespace std;



int main() {

	LinkedList2<int>*obg =new LinkedList2<int>;

	Node2<int> *p1 = new Node2<int>(1);
	Node2<int> *p2 = new Node2<int>(2);
	Node2<int> *p3 = new Node2<int>(3);
	Node2<int> *p4 = new Node2<int>(4);
	Node2<int> *p5 = new Node2<int>(5);
	Node2<int> *p6 = new Node2<int>(6);

	obg->add_in_tail(p1);
	obg->add_in_tail(p2);
	obg->add_in_tail(p3);
	
	obg->add_in_tail(p5);
	obg->add_in_tail(p6);
	obg->add_in_position(p6,p4);
	
	obg->dell(6);





	cout << endl;
	obg->printn();

	cout << "\n\n"<<obg->getsize();

	return 0;
}

