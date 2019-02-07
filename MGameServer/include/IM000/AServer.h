#pragma once
#include <map>
#include <functional>

typedef unsigned short UShort;

class AServer
{
	UShort port_;
	int threadCount_;
	struct _WSABUF * WDataBuffer_;

	std::map<int, struct SOCKETINFO *> Eventsocket;

	void init();
public:
	AServer(UShort port);
	~AServer();


public:
	/* Logic */
	
	void Read(char data[1024], int soc, int len);
	void Write(char* data, int soc, int len, std::function<void()> EndCallback);

	/* process */

	bool ServerStart();


	/* option */

	void SetThreadNum_Option(int num);
	void ClientOUT(struct SOCKETINFO * eventSocket);
};