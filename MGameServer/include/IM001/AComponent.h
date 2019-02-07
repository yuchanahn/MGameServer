#pragma once
#include "AObject.h"
#include <functional>


class AComponent
{
	AObject* owner_;
	int mCpnNum_;

	static int numofComponent_;

	static std::function<void()> eventView_;

	template <typename T>
	static int GetComponentNUM()
	{
		static int CpnNum = 0;
		if (CpnNum == 0) {
			CpnNum = numofComponent_++;
		}
		return CpnNum;
	}

public:
	AComponent();
	virtual ~AComponent();


	template <typename T>
	T* AddComponent()
	{
		T* obj = Create<T>();
		owner_->Component(obj);
		return obj;
	}

	template <typename T>
	T* GetComponent()
	{
		return (T*)owner_->GetComponent__OnlyComponent(mCpnNum_);
	}

	void SetOwner(AObject* NewOwner);

	int GetCpnNum();

	void Destroy();



	virtual void Update();
	virtual void OnDestroy();

public:

	template <typename T>
	static T* Create()
	{
		T* obj = new T();
		static int CpnNum = 0;
		if (CpnNum == 0) {
			CpnNum = numofComponent_++;
		}
		obj->mCpnNum_ = CpnNum;
		return obj;
	}	
};

