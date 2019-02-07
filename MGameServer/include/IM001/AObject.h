#pragma once
#include <map>
#include <list>
#include <queue>

class AObject
{

private:
	std::map<int,class AComponent*> inputCpn_;

	AObject();

	void Update_();


public:
	virtual ~AObject();

	
	AObject* Component(class AComponent*);


	AComponent* GetComponent__OnlyComponent(int CpnNum);
	void DropComponent__OnlyComponent(int CpnNum);




	/* static field */

private:
	static std::list<AObject*> allofObject_;


public:
	static void Update();
	static void Destroy(AObject* Garbage);
	static void Destroy(class AComponent* Garbage);
	static AObject* Create();
};

