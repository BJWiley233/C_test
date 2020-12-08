#include <boost/version.hpp>


#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
	
	//char *x, *y;
	
	try {
		
		cout << "BOOST_VERSION" << "\n";
		
		}
	} catch (exception& e) {
		cout << "error: " << e.what() << "\n.";
	} catch (...) {
		cout << "Exception unknown type!\n";
		return 1;
	}

	return 0;

}
