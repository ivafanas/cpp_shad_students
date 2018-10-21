class Hasher
{
public:
	virtual ~Hasher() = default;

	virtual std::uint32_t calc_hash(std::istream& is) = 0;
};

Hasher *create_hasher(HasherType type)
{
	if (type == CRC32)
		return new HasherCRC32();
	else
		return new HasherSUM32();
}

bool run(const std::string& filename, HasherType type)
{
	std::ifstream ifs(filename);
	if (!ifs)
		return false;

	Hasher *hasher = create_hasher(type);

	std::cout << hasher->calc_hash(ifs);

	delete hasher;
}
