#include<iostream>
#include <list>
using namespace std;

class Object {
protected:
	int id;
	string name;
	int position;
public:
	Object(int id,string name, int position);
	string getName() { return name; };
	int getId() { return id; };
	virtual void move() {};
	void printPosition();
};
Object::Object(int id, string name, int position) {
	this->id = id;
	this->name = name;
	this->position = position;
}
void Object::printPosition() {
	cout <<name <<"(  id:"<<id<<" ,position:" << position<<"  )"<<endl;
}
class StaticObject: public Object{
public:
	StaticObject(int id, string name, int position);
	void move() {cout << "Static Object cant move" << endl;
	};
};
StaticObject::StaticObject(int id, string name, int position): Object(id,name,position){}
class DynamicObject: public Object{
	int range;
public:
	DynamicObject(int id, string name,int range, int position);
	void move();
};
DynamicObject::DynamicObject(int id, string name,int range, int position) : Object(id, name, position) {
	this->range = range;
}
void DynamicObject::move() {
	cout << "Move" << endl;
	position += range;
}
class Tree:	public StaticObject{
public:
	Tree(int id, string name, int position);
};
Tree::Tree(int id, string name, int position): StaticObject(id,name,position){};
class House:	public StaticObject{
public:
	House(int id, string name, int position);
};
House::House(int id, string name, int position) : StaticObject(id, name, position) {}
class Motobike:	public DynamicObject{
public:
	Motobike(int id, string name, int position);
};
Motobike::Motobike(int id, string name, int position): DynamicObject(id,name,5,position){}
class Car: public DynamicObject{
public:
	Car(int id, string name, int position);
};
Car::Car(int id, string name, int position) : DynamicObject(id, name, 10, position) {}
int main() {
	list<shared_ptr<Object>> listObject;
	listObject.push_back(make_shared<Tree>(1,"Tree",0));
	listObject.push_back(make_shared<House>(2,"House",0));
	listObject.push_back(make_shared<Motobike>(3,"Motobike",0));
	listObject.push_back(make_shared<Car>(4,"Car",0));

	for (auto obj : listObject) {
		obj->printPosition();
		obj->move();
		obj->printPosition();
	}
	listObject.clear();
	return 0;
}
