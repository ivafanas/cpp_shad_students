class Animal
{
public:
	virtual ~Animal() = default;

	virtual void say() = 0;
};

class Cat : public Animal
{
public:
	Cat();
	Cat(const std::string& name, int age);

	void say() override;

private:
	std::string name_;
	int age_;
};

void usage()
{
	{
		std::unique_ptr<Cat> def_cat_1(new Cat);
		std::unique_ptr<Cat> def_cat_2 = std::make_unique<Cat>();

		std::unique_ptr<Animal> def_cat_3(new Cat);
		std::unique_ptr<Animal> def_cat_4 = std::make_unique<Cat>();

		std::unique_ptr<Cat> barsic(new Cat("barsic", 2));
		std::unique_ptr<Cat> malysh = std::make_unique<Cat>("malysh", 1);

		// compiler error
		// std::unique_ptr<Cat> barsic_2 = barsic;

		std::unique_ptr<Cat> barsic_2 = std::move(barsic);
		// barsic == nullptr

		barsic_2->say();

		barsic->say();
	}

	{
		std::shared_ptr<Cat> def_cat_1(new Cat);
		std::shared_ptr<Cat> def_cat_2 = std::make_shared<Cat>();

		std::shared_ptr<Animal> def_cat_3(new Cat);
		std::shared_ptr<Animal> def_cat_4 = std::make_shared<Cat>();

		std::shared_ptr<Cat> barsic(new Cat("barsic", 2));
		std::shared_ptr<Cat> malysh = std::make_shared<Cat>("malysh", 1);

		{
			std::shared_ptr<Cat> barsic_2 = barsic;
		}

		std::shared_ptr<Cat> barsic_3 = std::move(barsic);
		// barsic == nullptr

		barsic_3->say();
	}
}



class Cat : public Animal
{
public:
	Cat();
	Cat(const std::string& name, int age);

	void say() override;

	std::vector<std::shared_ptr<Cat>> friends;

private:
	std::string name_;
	int age_;
};

void usage_shared()
{
	std::shared_ptr<Cat> barsic(new Cat("barsic", 2));
	std::shared_ptr<Cat> malysh = std::make_shared<Cat>("malysh", 1);

	barsic->friends.push_back(malysh);
	malysh->friends.push_back(barsic);
}


class Cat : public Animal
{
public:
	Cat();
	Cat(const std::string& name, int age);

	void say() override;

	std::vector<std::weak_ptr<Cat>> friends;

private:
	std::string name_;
	int age_;
};

void usage_weak()
{
	std::shared_ptr<Cat> barsic(new Cat("barsic", 2));
	std::shared_ptr<Cat> malysh = std::make_shared<Cat>("malysh", 1);

	barsic->friends.push_back(malysh);
	malysh->friends.push_back(barsic);

	std::shared_ptr<Cat> kitty = barsic->friends[0].lock();
	if (kitty)
		kitty->say();
}
