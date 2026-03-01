# include <iostream>
# include <fstream>
# include <vector>
# include <string>
# include <algorithm> // For std::find

int main() {

	// 01. Load the dictionary
		std::vector<std::string> dictionaryWords;
	std::ifstream dictFile("C:\\Users\\nickg\\Downloads\\words"); // Or the path of the dictionary file on your system

	if (!dictFile.is_open()) {
		std::cerr << "Error: Could not open the dictionary file." << std::endl;
		return 1;
	}

	std::string word;
	while (dictFile >> word) {
		dictionaryWords.push_back(word);
	}
	dictFile.close();
	std::cout << "Dictionary loaded with " << dictionaryWords.size() << " words." << std::endl;
	
	// 02. Open the file to be checked
		std::ifstream
		checkFile("C:\\Users\\nickg\\Downloads\\test.txt"); // Replace with the actual file name

	if (!checkFile.is_open()) {
		std::cerr << "Error: Could not open the file to check." << std::endl;
		return 1; // Indicate the error
	}
	
	
	// 03. Check each word
		std::cout << "Misspelled words:" << std::endl;
	while (checkFile >> word) {
		// std::find returns an iterator to the element if found, otherwise it returns dictionaryWords.end()
		if (std::find(dictionaryWords.begin(), dictionaryWords.end(), word) == dictionaryWords.end()) {
			std::cout << word << std::endl;
	}
} 
	checkFile.close();

	return 0; // Indicate successful execution
}
