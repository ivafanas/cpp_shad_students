
class Hasher
{
public:
	virtual ~Hasher() = default;

	std::uint32_t calc_hash(std::istream& is) = 0;
};

std::unique_ptr<Hasher> create_hasher_of_type(HasherType type)
{
	if (type == CRC32)
		return std::make_unique<HasherCRC32>();
	else
		return std::make_unique<HasherSum32>();
}

bool run(const std::string& filename, HasherType type)
{
	std::unique_ptr<Hasher> hasher = create_hasher_of_type(type)

	std::ifstream ifs(file);
	if (!ifs)
		return false;

	std::cout << hasher->cacl_hash(ifs);
}
