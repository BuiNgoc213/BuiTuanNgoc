#include<conio.h>
#include<cstdio>
#include<iostream>
using namespace std;

class StateBase {

public:
	virtual StateBase* GetNextState() = 0;
	virtual char* ToString() = 0;
};

class Closed : public StateBase {
public:
	virtual StateBase* GetNextState();
	virtual  char* ToString(){
	return "Closed";
	}
};
class Locked : public StateBase{
	
public:
	virtual StateBase* GetNextState();
	virtual char* ToString() {
		return "Locked";
	}
};

class Opened : public StateBase {
public:
	virtual StateBase* GetNextState();
	virtual   char* ToString() {
		return "Opened";
	}
};
StateBase* Closed::GetNextState() {
	int a;
	do {
		cout << "Enter 0(Lock) or 1(Open) :"; cin >> a;
	} while (a == 0 || a == 1);
	if (a==0)
		return new Locked();
	if(a==1)
		return new Opened();
}
StateBase* Locked::GetNextState() {
	return new Closed();
}StateBase* Opened::GetNextState() {
	return new Closed();
}
class Door {
protected:
	StateBase* m_pState;
public:
	Door() {};
	Door(StateBase* pContext) {
		m_pState = pContext;
	}
	~Door() {
		delete m_pState;
	}
	void StateChange(){
		if (m_pState) {
			StateBase* pState = m_pState->GetNextState();
			delete m_pState;
			m_pState = pState;
		}
	}
	char* GetStateName() {
		return m_pState->ToString();
	}

};
void main() {
	Door objDoor(new Locked);
	cout << "Door is " << objDoor.GetStateName();
	objDoor.StateChange();
	cout << "Door is " << objDoor.GetStateName();
	objDoor.StateChange();
	cout << "Door is " << objDoor.GetStateName();
	objDoor.StateChange();
	cout << "Door is " << objDoor.GetStateName();
	objDoor.StateChange();
	system("pause");
}