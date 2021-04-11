
class Animal
{
public:
	virtual ~Animal() = default;

	virtual void say() = 0;
};

class Cat
{
public:
	Cat();
	Cat(const std::string& name, int age);

	void say() override;
};

void usage()
{
	{
		std::unique_ptr<Cat> def_cat_1(new Cat);
		std::unique_ptr<Cat> def_cat_2 = std::make_unique<Cat>();

		std::unique_ptr<Animal> def_cat_3(new Cat);
		std::unique_ptr<Animal> def_cat_4 = std::make_unique<Cat>();

		std::unique_ptr<Cat> barsic(new Cat("barsic", 2));
		std::unique_ptr<Cat> malysh = std::make_unique<Cat>("malysh", 2);

		// compiler error!
		// std::unique_ptr<Cat> barsic_2 = barsic;

		std::unique_ptr<Cat> barsic_2 = std::move(barsic);
		// (barsic is nullptr)

		// ok
		barsic_2->say();

		// crash
		// barsic->say();
	}

	{
		std::shared_ptr<Cat> def_cat_1(new Cat);
		std::shared_ptr<Cat> def_cat_2 = std::make_shared<Cat>();

		std::shared_ptr<Animal> def_cat_3(new Cat);
		std::shared_ptr<Animal> def_cat_4 = std::make_shared<Cat>();

		std::shared_ptr<Cat> barsic(new Cat("barsic", 2));
		std::shared_ptr<Cat> malysh = std::make_shared<Cat>("malysh", 2);

		std::shared_ptr<Cat> barsic_2 = barsic;

		std::shared_ptr<Cat> barsic_3 = std::move(barsic);
		// (barsic is nullptr)

		// ok
		barsic_3->say();

		// crash
		// barsic->say();
	}

	{
		std::unique_ptr<Cat> cat(new Cat);
		std::unique_ptr<Cat[]> cats(new Cat[123]);
	}

	{
		std::shared_ptr<Cat> cat(new Cat);
		std::shared_ptr<Cat[]> cats(new Cat[123]);
	}
}



class Cat
{
public:
	Cat();
	Cat(const std::string& name, int age);

	void say() override;

	std::vector<std::shared_ptr<Cat>> friends;
};

void usage_friends_shared()
{
	{
		std::shared_ptr<Cat> barsic = std::make_shared<Cat>("barsic", 1);
		std::shared_ptr<Cat> malysh = std::make_shared<Cat>("malysh", 2);

		barsic->friends->push_back(malysh);
		malysh->friends->push_back(barsic);

		barsic->friends[0]->say();

		// mem leak
	}

	{
		std::shared_ptr<Cat> barsic = std::make_shared<Cat>("barsic", 1);
		barsic->push_back(barsic);

		barsic->friends[0]->say();

		// mem leak
	}
}




class Cat
{
public:
	Cat();
	Cat(const std::string& name, int age);

	void say() override;

	std::vector<std::weak_ptr<Cat>> friends;
};

void usage_friends_weak()
{
	{
		std::shared_ptr<Cat> barsic = std::make_shared<Cat>("barsic", 1);
		std::shared_ptr<Cat> malysh = std::make_shared<Cat>("malysh", 2);

		barsic->friends->push_back(malysh);
		malysh->friends->push_back(barsic);

		std::shared_ptr<Cat> kitty_friend = barsic->friends[0].lock();
		if (kitty_friend)
			kitty_friend->say();

		// ok
	}
}
