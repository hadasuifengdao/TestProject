// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <memory>
using std::shared_ptr;
using std::weak_ptr;
class Cat;
class Dog
{
public:
	shared_ptr<Cat> m_pCat;
	~Dog(void)
	{
		std::cout << "Dog destructor!\n";
	}
};
class Cat
{
public:
	//shared_ptr<Dog> m_pDog;
	weak_ptr<Dog> m_pDog;
	~Cat(void)
	{
		std::cout << "Cat destructor!\n";
	}
};
void LeakMemory()
{
	shared_ptr<Dog> pDog(new Dog);
	shared_ptr<Cat>pCat(new Cat);
	pCat->m_pDog = pDog;
	pDog->m_pCat = pCat;
	

}

int main()
{
	LeakMemory();
    //std::cout << "Hello World!\n"; 
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
