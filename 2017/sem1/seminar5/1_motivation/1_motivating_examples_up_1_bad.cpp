
class Hasher
{
public:
	virtual ~Hasher() = default;

	std::uint32_t calc_hash(std::istream& is) = 0;
};

Hasher *create_hasher_of_type(HasherType type)
{
	if (type == CRC32)
		return new HasherCRC32();
	else
		return new HasherSum32();
}

bool run(const std::string& filename, HasherType type)
{
	Hasher* hasher = create_hasher_of_type(type)

	std::ifstream ifs(file);
	if (!ifs)
		return false;

	std::cout << hasher->cacl_hash(ifs);

	delete hasher;
}
