// implementing Plants vs Zombies

class NetworkSystem
{
public:
	virtual ~NetworkSystem() = default;

	virtual std::string load(const std::string& url) = 0;
};


class GameResourcesLoader
{
public:
	GameResourcesLoader(std::shared_ptr<NetworkSystem> network) {...}

private:
	std::weak<NetworkSystem> network_;
};


class PromoEventsLoader
{
public:
	PromoEventsLoader(std::shared_ptr<NetworkSystem> network) {...}

private:
	std::weak<NetworkSystem> network_;
};
