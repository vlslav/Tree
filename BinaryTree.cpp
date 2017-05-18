#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <string>
#include <cstring>
#include <windows.h>
#include <vector>
#include <cmath>
using namespace std;

template <typename T>
class Tree{
public:
    Tree():Root(NULL), high(0){};
    ~Tree();
    struct Leaf{
        T element;
        Leaf *Right;
        Leaf *Left;
    };
    Leaf *Root;
    int high;
    void Del(Leaf *kot);
    void insert(T);
    bool isEmpty() const { return Root==NULL; }
};
template <class T>
void Tree<T>::insert(T d)
{
	Leaf* t = new Leaf;
	t->element = d;
	t->Left = NULL;
	t->Right = NULL;
	Root = NULL;
	//
	if (isEmpty()) Root = t;
	else
	{
		Leaf* curr;
		curr = Root;
		while(curr)
		{
			Root = curr;
			if(t->element > curr->element) curr = curr->Right;
			else curr = curr->Left;
		}

		if(t->element < Root->element)
			Root->Left = t;
		else
			Root->Right = t;
	}
}
template <typename T>
void Tree <T> :: Del(Leaf *kot){
    if (kot!=NULL)
    {
        Del(kot->Left);
        Del(kot->Right);
        delete kot;
    }
}
class Student{
    public:
    string surname;
    string name;
    string patronymic;
    string group;
    bool operator<(Student& p1)
    {
        if(strcmp(surname.c_str(),p1.surname.c_str())<0) return 1;
        else return 0;
    }
    bool operator>(Student& p1)
    {
        if(strcmp(surname.c_str(),p1.surname.c_str())<0)return 0;
        else return 1;
    }
    
    friend ostream& operator<<(ostream& os, Student& petr){
        os << petr.surname << " " << petr.name << " " << petr.patronymic << " " << petr.group << endl;
        return os;
    }
    friend istream& operator>>(istream& is, Student& petr){
        is >> petr.surname;
        is >> petr.name;
        is >> petr.patronymic;
        is >> petr.group;
        return is;
    }
};
class Professors{
    public:
    string surname;
    string name;
    string patronymic;
    string subject;
    bool operator<(Professors& p1){
        if(strcmp(surname.c_str(),p1.surname.c_str())<0)return 1;
        else return 0;
        }
     bool operator>(Professors& p1){
        if(strcmp(surname.c_str(),p1.surname.c_str())<0)return 0;
        else return 1;
    }
    friend ostream& operator<<(ostream& os, Professors& petr){
        os << petr.surname << " " << petr.name << " " << petr.patronymic << " " << petr.subject << endl;
        return os;
    }
    friend istream& operator>>(istream& is, Professors& petr){
        is >> petr.surname;
        is >> petr.name;
        is >> petr.patronymic;
        is >> petr.subject;
        return is;
    }

};

template <typename T>
Tree <T> :: ~Tree(){
    this->Del(Root);
}


int main(){
    Tree <Student> Stud1;
}

