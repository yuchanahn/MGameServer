#pragma once
#include <functional>
#include <queue>
#include <map>

#include "AThreadSafe.h"

typedef std::queue<std::function<void()>> EVQUEUE;

class AStrand
{
	class AThreadSafe<EVQUEUE*>* EventQueue;

	int id_;
public:
	AStrand(int id);
	~AStrand();

	void SFunc(std::function<void()> f);
	void SrdProcess();

	static std::map<int, AStrand*> Strands;
};

