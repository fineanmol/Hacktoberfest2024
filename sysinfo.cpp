#include <iostream>
#include <fstream>
#include <sys/utsname.h>
#include <sstream>

// Function to read and parse the /proc/meminfo file to get total RAM
long long get_total_ram() {
    std::ifstream meminfo_file("/proc/meminfo");
    std::string line;
    long long total_ram = 0;

    while (std::getline(meminfo_file, line)) {
        if (line.find("MemTotal:") != std::string::npos) {
            std::istringstream ss(line);
            std::string key;
            ss >> key >> total_ram;
            break;
        }
    }

    return total_ram;
}

int main() {
    struct utsname system_info;
    uname(&system_info);

    std::cout << "Operating System: " << system_info.sysname << std::endl;
    std::cout << "Kernel Version: " << system_info.release << std::endl;
    std::cout << "CPU Architecture: " << system_info.machine << std::endl;

    long long total_ram = get_total_ram();
    std::cout << "Total RAM: " << total_ram / 1024 << " MB" << std::endl;

    return 0;
}
