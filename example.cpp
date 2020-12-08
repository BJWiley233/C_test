#include <boost/lambda/lambda.hpp>
#include <boost/program_options.hpp>
#include <boost/version.hpp>
#include <iostream>
#include <iterator>
#include <algorithm>
#include <vector>
#include <string>
#include <boost/graph/breadth_first_search.hpp>

using namespace std;

void myfunction (int i) {  // function:
  std::cout << ' ' << i;
}

void print_with_CHEBI_prefix(const std::string& i) {
    std::cout << "CHEBI:" << i << '\n';
} 

int main()
{
    using namespace boost::lambda;
    typedef std::istream_iterator<int> in;

    vector<string> msg {"Hello", "C++", "World", "from", "VS Code", "and the C++ extension!"};
    msg.push_back("adding me");

    std::for_each(
        in(std::cin), in(), std::cout << (_1 * 3) << " " << BOOST_VERSION << "\n"
        );

    std::for_each(
        msg.begin(), msg.end(), print_with_CHEBI_prefix
    );
    std::cout << '\n';
 
    
    
}
