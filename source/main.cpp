#include<iostream>


# pragma hdrstop
#include"Node2.h"

#include"LinkedList2.h"




using namespace std;



int main() {
	
	Node2<int> *p = new Node2<int>(10);
	Node2<int> *p2 = new Node2<int>(11);
	Node2<int> *p3 = new Node2<int>(12);
	Node2<int> *p4 = new Node2<int>(13);



	LinkedList2<int> obg;

	obg.add_in_tail(p);
	obg.add_in_tail(p2);
	obg.add_in_tail(p3);
	obg.add_in_tail(p4);





	obg.dell(13);




	obg.printe();



	cout << "  \n" << obg.getsize();

	return 0;
}

