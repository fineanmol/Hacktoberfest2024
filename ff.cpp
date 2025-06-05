// find file in dir with its perm and size

#include <iostream>
#include <string>
#include <filesystem>
#include <sys/stat.h>
#include <iomanip>

namespace fs = std::filesystem;

void findFile(const fs::path& directory, const std::string& filename) {
    if (fs::exists(directory) && fs::is_directory(directory)) {
        for (const auto& entry : fs::directory_iterator(directory)) {
            if (entry.is_regular_file() && entry.path().filename() == filename) {
                struct stat fileStat;
                if (stat(entry.path().c_str(), &fileStat) == 0) {
                    std::cout << "File: " << entry.path() << std::endl;
                    std::cout << "Permissions: ";
                    std::cout << ((fileStat.st_mode & S_IRUSR) ? "r" : "-");
                    std::cout << ((fileStat.st_mode & S_IWUSR) ? "w" : "-");
                    std::cout << ((fileStat.st_mode & S_IXUSR) ? "x" : "-");
                    std::cout << ((fileStat.st_mode & S_IRGRP) ? "r" : "-");
                    std::cout << ((fileStat.st_mode & S_IWGRP) ? "w" : "-");
                    std::cout << ((fileStat.st_mode & S_IXGRP) ? "x" : "-");
                    std::cout << ((fileStat.st_mode & S_IROTH) ? "r" : "-");
                    std::cout << ((fileStat.st_mode & S_IWOTH) ? "w" : "-");
                    std::cout << ((fileStat.st_mode & S_IXOTH) ? "x" : "-");
                    std::cout << std::endl;
                    std::cout << "Size: " << fileStat.st_size << " bytes" << std::endl;
                }
            }
        }
    } else {
        std::cerr << "Error: The specified directory does not exist or is not a directory." << std::endl;
    }
}

int main(int argc, char* argv[]) {
    if (argc != 5) {
        std::cerr << "Usage: " << argv[0] << " -d <directory> -f <filename>" << std::endl;
        return 1;
    }

    std::string option = argv[1];
    if (option != "-d") {
        std::cerr << "Error: Invalid option. Use -d to specify the directory." << std::endl;
        return 1;
    }

    fs::path directory(argv[2]);

    option = argv[3];
    if (option != "-f") {
        std::cerr << "Error: Invalid option. Use -f to specify the file name." << std::endl;
        return 1;
    }

    std::string filename = argv[4];

    findFile(directory, filename);

    return 0;
}
