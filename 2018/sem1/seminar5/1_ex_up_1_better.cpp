class Hasher
{
public:
	virtual ~Hasher() = default;

	virtual std::uint32_t calc_hash(std::istream& is) = 0;
};

std::unique_ptr<Hasher> create_hasher(HasherType type)
{
	if (type == CRC32)
		return std::make_unique<HasherCRC32>();
	else
		return std::make_unique<HasherSUM32>();
}

bool run(const std::string& filename, HasherType type)
{
	std::ifstream ifs(filename);
	if (!ifs)
		return false;

	std::unique_ptr<Hasher> hasher = create_hasher(type);

	std::cout << hasher->calc_hash(ifs);
}
