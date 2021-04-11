Talk about:
	1. IR of unique_ptr: raw pointer + d-tor
	2. IR of shared_ptr:
		reference counter - why?
		ask how to store reference counter - control block?
		show control block operations with:
			create shared_ptr from a pointer
			create default shared_ptr
			copy shared_ptr
			another copy of shared_ptr
			deleting shared_ptr
			another instance of shared_ptr of another object
			getting weak pointer from shared pointer
			locking weak pointer
			make_shared
			deleting the last shared_ptr

		
		std::shared_ptr<Cat> cat1(new Cat());
		std::shared_ptr<Cat> cat2;
		std::shared_ptr<Cat> cat3 = cat1;
		std::shared_ptr<Cat> cat4 = cat3;
		cat4.reset();
		std::shared_ptr<Cat> cat5(new Cat());

		std::weak_ptr<Cat> cat6(cat3);
		std::weak_ptr<Cat> cat7(cat5);
		std::shared_ptr<Cat> cat6_as_shared = cat6.lock();
		if (cat6_as_shared)
		{ ... }
		cat5.reset();
		std::shared_ptr<Cat> cat7_as_shared = cat7.lock();
		if (cat7_as_shared)
		{ ... }

		// and the all d-tors
		
	3. shared_ptr specific:
		std::shared_ptr<Cat> x = std::make_shared<Cat>();

		Cat* y = new Cat();
		std::shared_ptr<Cat> cat1(y);
		std::shared_ptr<Cat> cat2(y);
