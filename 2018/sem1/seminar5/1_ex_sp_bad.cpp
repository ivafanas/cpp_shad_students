
class NetworkSystem
{
public:
	virtual ~NetworkSystem()  = default;

	virtual std::string load(const std::string& url) = 0;
};

class GameResourcesLoader
{
public:
	GameResourcesLoader(NetworkSystem* network) {...}

private:
	NetworkSystem* network_;
};

class PromoEventsLoader
{
public:
	PromoEventsLoader(NetworkSystem* network) {...}

private:
	NetworkSystem* network_;
};
