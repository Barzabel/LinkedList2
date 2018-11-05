#include "stdafx.h"
#include "CppUnitTest.h"
#include "../source/LinkedList2.h"
#include "../source/Node2.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace testlist
{		

	TEST_CLASS(Node)
	{
	public:
		
		TEST_METHOD(konstructorNode)
		{
			Node2<int> *p=new Node2<int>(12);
			Assert::AreEqual(12, p->getval());
			Assert::IsTrue(p->prev == nullptr);
			Assert::IsTrue(p->next == nullptr);
			delete p;
		}

	};
	TEST_CLASS(linklist)
	{
	public:
		TEST_METHOD(konstructorList)
		{
			LinkedList2<int> obg;
			Assert::IsTrue(obg.gethead() == nullptr);
			Assert::IsTrue(obg.gettail() == nullptr);
			Assert::IsTrue(obg.getsize() == 0);
		}
		TEST_METHOD(add_in_tail)
		{
			LinkedList2<int> obg;
			Node2<int> *p = new Node2<int>(10);
			Node2<int> *p2 = new Node2<int>(11);
			obg.add_in_tail(p);
			Assert::AreEqual(p->getval(), obg.gettail()->getval());
			Assert::IsTrue(obg.gettail()->next == nullptr);
			obg.add_in_tail(p2);
			Assert::IsTrue(obg.gethead() == p);
			Assert::IsTrue(obg.gethead()->next == p2);

			Assert::IsTrue(obg.gettail() == p2);
			Assert::IsTrue(obg.gettail()->prev == p);

			delete p;
			delete p2;
		}
		TEST_METHOD(add_in_head)
		{
			LinkedList2<int> obg;
			Node2<int> *p = new Node2<int>(10);
			Node2<int> *p2 = new Node2<int>(11);
			obg.add_in_head(p);
			Assert::AreEqual(p->getval(), obg.gethead()->getval());
			Assert::IsTrue(obg.gethead()->prev == nullptr);
			obg.add_in_head(p2);
			Assert::IsTrue(obg.gethead() == p2);
			Assert::IsTrue(obg.gethead()->next == p);

			Assert::IsTrue(obg.gettail() == p);
			Assert::IsTrue(obg.gettail()->prev == p2);

			delete p;
			delete p2;
		}
		TEST_METHOD(add_in_position)
		{
			LinkedList2<int> obg;
			Node2<int> *p = new Node2<int>(10);
			Node2<int> *p2 = new Node2<int>(11);
			Node2<int> *p3 = new Node2<int>(12);
			Node2<int> *p4 = new Node2<int>(13);
			obg.add_in_position(p4, p);
			Assert::IsTrue(obg.gettail() == p);
			Assert::IsTrue(obg.gethead() == p);

			obg.add_in_position(p, p2);
			Assert::IsTrue(obg.gettail() == p2);
			Assert::IsTrue(obg.gettail()->prev == p);
			Assert::IsTrue(obg.gettail()->next == nullptr);
			obg.add_in_position(p, p3);

			Assert::IsTrue(obg.gettail()->prev->value == p3->value);



			delete p;
			delete p3;
			delete p4;
			delete p2;

		}



		TEST_METHOD(find)
		{
			LinkedList2<int> obg;
			Node2<int> *p = new Node2<int>(10);
			Node2<int> *p2 = new Node2<int>(11);
			Node2<int> *p3 = new Node2<int>(12);
			Node2<int> *p4 = new Node2<int>(13);

			obg.add_in_tail(p);
			obg.add_in_tail(p2);
			obg.add_in_tail(p3);
			obg.add_in_tail(p4);

			Node2<int> *p5 = obg.find(10);

			Assert::IsTrue(obg.gethead() == p5);
			Assert::IsTrue(10 == p5->value);
			Node2<int> *p6 = obg.find(11);
			Assert::IsTrue(11 == p6->value);
			Node2<int> *p7 = obg.find(13);
			Assert::IsTrue(obg.gettail() == p7);
			Node2<int> *p8 = obg.find(99);
			Assert::IsTrue(p8 == nullptr);



			delete p;
			delete p3;
			delete p4;
			delete p2;

		}


		TEST_METHOD(dell) 
		{
			LinkedList2<int> obg;
			Node2<int> *p = new Node2<int>(10);
			Node2<int> *p2 = new Node2<int>(11);
			Node2<int> *p3 = new Node2<int>(12);
			Node2<int> *p4 = new Node2<int>(13);

			obg.add_in_tail(p);
			obg.add_in_tail(p2);
			obg.add_in_tail(p3);
			obg.add_in_tail(p4);

			obg.dell(10);
			Assert::IsTrue(obg.find(10) == nullptr);
			Assert::IsTrue(obg.getsize() == 3);
			Assert::IsTrue(obg.gethead() == p2);
			obg.dell(13);
			Assert::IsTrue(obg.gettail() == p3);
			Assert::IsTrue(obg.getsize() == 2);
			obg.dell(12);
			Assert::IsTrue(obg.gettail() == obg.gethead());
			Assert::IsTrue(obg.gettail() == p2);
			Assert::IsTrue(obg.getsize() ==1);
			obg.dell(11);
			Assert::IsTrue(obg.gethead() == nullptr);
			Assert::IsTrue(obg.gettail() == nullptr);
			Assert::IsTrue(obg.getsize() == 0);


			delete p;
			delete p3;
			delete p4;
			delete p2;

		}


	};
}