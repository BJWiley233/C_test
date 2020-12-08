#include <boost/program_options.hpp>
namespace po = boost::program_options;

#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
	
	//char *x, *y;
	
	try {
		// Declare
		po::options_description desc("Allowed options");
		desc.add_options()
			("help", "produce help message")
			("compression", po::value<int>(), "set compresssion level")
		;

		po::variables_map vm;
		po::store(po::parse_command_line(argc, argv, desc), vm);
		po::notify(vm);

		if (vm.count("help")) {
			cout << desc << "\n";
			return 0;
		}

		if (vm.count("compression")) {
			cout << "Compression level was set to "
		  << vm["compression"].as<int>() << ".\n";
		} else {
			cout << "Compression level was not set.\n";
		}
	} catch (exception& e) {
		cout << "error: " << e.what() << "\n.";
	} catch (...) {
		cout << "Exception unknown type!\n";
		return 1;
	}

	return 0;

}
