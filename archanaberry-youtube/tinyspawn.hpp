#ifndef TINYSPAWN_HPP
#define TINYSPAWN_HPP

#include <string>
#include <vector>

class TinySpawn {
public:
    TinySpawn(const std::string& binaryPath, const std::vector<std::string>& args);
    std::string execute(const std::string& url);
    int getExitCode();
private:
    std::string binaryPath;
    std::vector<std::string> args;
    int exitCode;
};

#endif // TINYSPAWN_HPP
