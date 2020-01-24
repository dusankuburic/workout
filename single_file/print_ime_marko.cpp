#include<iostream>


int main() {


	for (int i = 0; i < 21; i++) {
		if (i == 0 || i == 20) {
			std::cout << "+";
		}
		else {
			std::cout << "-";
		}
	}
	std::cout << '\n';

	for (int i = 0; i < 11; i++)
	{
		for (int j = 0; j < 21; j++) {


			if (j == 0 || j == 20)
				std::cout << "|";
			else if (i == 5 && j == 8) {
				std::cout << "D";
			} 
			else if (i == 5 && j == 9) {
				std::cout << "u";
			}
			else if (i == 5 && j == 10) {
				std::cout << "s";
			}
			else if (i == 5 && j == 11) {
				std::cout << "a";
			} 
			else if (i == 5 && j == 12) {
				std::cout << "n";
			}
			else
				std::cout << " ";
			
		

		}
		std::cout << '\n';
	}


	for (int i = 0; i < 21; i++) {
		if (i == 0 || i == 20) {
			std::cout << "+";
		}
		else {
			std::cout << "-";
		}
	}

	return 0;
}

