// discuss: what is it, how it works
#include <algorithm>
#include <cctype>
#include <exception>
#include <iostream>
#include <iterator>
#include <sstream>
#include <string>
#include <tuple>
#include <unordered_map>
#include <utility>
#include <vector>

// discuss:
//   * what is it
//   * what const means
//   * what static means
//   * where data lives
//   * when is it created and destroyed
static const std::string song = "\
Yellow Submarine\n\
\n\
In the town where I was born\n\
Lived a man who sailed to sea\n\
And he told us of his life\n\
In the land of submarines\n\
So we sailed up to the sun\n\
Till we found a sea of green\n\
And we lived beneath the waves\n\
in our yellow submarine\n\
\n\
We all live in a yellow submarine\n\
Yellow submarine, yellow submarine\n\
We all live in a yellow submarine\n\
Yellow submarine, yellow submarine\n\
\n\
And our friends are all aboard\n\
Many more of them live next door\n\
And the band begins to play\n\
\n\
We all live in a yellow submarine\n\
Yellow submarine, yellow submarine\n\
We all live in a yellow submarine\n\
Yellow submarine, yellow submarine\n\
\n\
(Full speed ahead Mr. Parker, full speed ahead\n\
Full speed ahead it is, Sergeant\n\
Action station, action station\n\
Aye, aye, sir, fire\n\
Captain, captain)\n\
\n\
As we live a life of ease\n\
Every one of us has all we need\n\
Sky of blue and sea of green\n\
In our yellow submarine\n\
\n\
We all live in a yellow submarine\n\
Yellow submarine, yellow submarine\n\
We all live in a yellow submarine\n\
Yellow submarine, yellow submarine\n\
We all live in a yellow submarine\n\
Yellow submarine, yellow submarine";

// discuss:
//   * what is it
//   * what assembler this line produce
//   * what is unordered_map? internal structure? difference with std::map
using WordsCounter = std::unordered_map<std::string, int>;

// discuss
//   * what static means
//   * what & means
static void to_lower_inplace(std::string& s)
{
    for (char& c : s)
        c = static_cast<char>(std::tolower(static_cast<unsigned char>(c)));
}

// discuss:
//   * why erase
static void remove_non_alpha_inplace(std::string& s)
{
    s.erase(
        std::remove_if(
            s.begin(),
            s.end(),
            [](unsigned char c) { return !std::isalpha(c); }),
        s.end());
}

// discuss:
//   * what nodiscard means
//   * why const&? rules
[[nodiscard]] static std::vector<std::string> split_by_words(const std::string& text)
{
    std::istringstream ss{text};

    std::vector<std::string> words;

    std::for_each(
        std::istream_iterator<std::string>(ss),
        std::istream_iterator<std::string>(),
        [&](std::string s){
            remove_non_alpha_inplace(s);
            if (!s.empty())
            {
                to_lower_inplace(s);
                words.emplace_back(std::move(s));
            }
        });

    return words;
}

[[nodiscard]] static WordsCounter make_words_counter(const std::string& text)
{
    const std::vector<std::string> words = split_by_words(text);

    WordsCounter counter;
    for (const std::string& word : words)
        counter[word] += 1;
    
    return counter;
}

// discuss:
//   * why namespace
//   * why struct
//   * what is the difference between class/struct
namespace {
struct CountAndWord
{
    int count;
    std::string word;
};
}  // namespace

// discuss:
//   * why reserve
//   * what is partial_sort (+begin/end)
//   * lambda (+capture techniques)
static void print_top_n_words(const WordsCounter& counter, const int topn)
{
    if (topn <= 0)
        return;

    std::vector<CountAndWord> caws;
    caws.reserve(counter.size());
    for (const auto& [word, count] : counter)
        caws.emplace_back(CountAndWord{ count, word });

    const int top_ix = std::min<int>(topn, caws.size());

    std::partial_sort(
        caws.begin(),
        caws.begin() + top_ix,
        caws.end(),
        [](const CountAndWord& l, const CountAndWord& r) {
            return std::tie(r.count, r.word) < std::tie(l.count, l.word);
        });

    for (int i = 0; i < top_ix; ++i)
        std::cout << caws[i].word << " -> " << caws[i].count << '\n';
}

// discuss:
//   * what is main
//   * what is argc, argv
int main(int argc, char **argv)
{
    // discuss:
    //   * why 2
    //   * what is <<
    //   * what is argv[0]
    //   * what is endl
    //   * why return 1
    if (argc != 2)
    {
        std::cout << "Usage: " << argv[0] << " top_n" << std::endl;
        return 1;
    }

    // discuss:
    //   * what is try-catch
    //   * where exception might be thrown here (look through all functions)
    try
    {
        const int top_n = std::stoi(argv[1]);

        const WordsCounter words_counter = make_words_counter(song);

        print_top_n_words(words_counter, top_n);
    }
    catch (const std::exception& e)
    {
        // discuss:
        //   * what is cerr
        //   * why return 1
        //   * why std::exception
        std::cerr << "ERROR: failed to find top n words: " << e.what() << std::endl;
        return 1;
    }

    return 0;  // discuss: why return 0
}

