#include<iostream>
#include<vector>
#include<fstream>
#include<limits>

bool is_prime(std::vector<int>& collection, int x) {
	for (int j = 1; collection[j] <= sqrt(x); j++) 
		if (!(x % collection[j]))return false;
	return true;
}

int main() {
	std::fstream results;
	results.open("results1.txt", std::ios::out | std::ios::app);
	std::vector<int> prime{ 2, 3};
	results << 2 << '\n' << 3;
	for (int i = 5; i < std::numeric_limits<int>::max(); i += 2)
		if (is_prime(prime, i)) 
			try {
				results << '\n' << i;
				prime.push_back(i);
			}
			catch(std::bad_alloc & e) {
				std::cout << "\aNot enough memory: " << e.what();
				break;
			}
	results.close();
	std::cout << prime.size();
}
