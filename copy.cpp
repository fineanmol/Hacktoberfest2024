// C++ code to copy files

#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char* argv[]) {
    if (argc != 3) {
        std::cerr << "Usage: " << argv[0] << " <source_file> <destination>" << std::endl;
        return 1;
    }

    const std::string sourceFile = argv[1];
    const std::string destinationFile = argv[2];

    // Open the source file for reading
    std::ifstream sourceFileStream(sourceFile, std::ios::binary);
    if (!sourceFileStream) {
        std::cerr << "Error: Could not open the source file." << std::endl;
        return 1;
    }

    // Open the destination file for writing
    std::ofstream destinationFileStream(destinationFile, std::ios::binary);
    if (!destinationFileStream) {
        std::cerr << "Error: Could not create or open the destination file." << std::endl;
        return 1;
    }

    // Copy the content from source to destination
    destinationFileStream << sourceFileStream.rdbuf();

    // Check for any errors during the copying process
    if (!destinationFileStream) {
        std::cerr << "Error: Failed to copy the file." << std::endl;
        return 1;
    }

    std::cout << "File copied successfully." << std::endl;

    // Close the file streams
    sourceFileStream.close();
    destinationFileStream.close();

    return 0;
}
