#pragma once
#include <unordered_map>
#include <functional>

class AClient
{
public:
	AClient(int id, class AServer* server, class AStrand* strand = nullptr);
	~AClient();


	/* server used */
	static void Create__OnlyServer(AClient*);
	static void ToRead__OnlyServer(int id, char* data, int len);
	static void DropClnt__OnlyServer(int id);
private:

public:
	void ToStrand(std::function<void()> f);

	// 직접 메모리 해제 해줘야함;
	virtual void Read(char* data, int size);
	virtual void Write(char* data, int size, std::function<void()> EndCallback = []() {});

protected:
	class AServer* server_;
	class AStrand* strand_;
	int id_;


	static std::unordered_map<int, AClient*> ClntList;
};

