#include <iostream>
#include <string>
#include <vector>
#include <map>

#include "constant.hpp"
#include "index.hpp"
#include "tinyspawn.hpp"

std::vector<std::string> args(const std::map<std::string, std::string>& flags) {
    std::vector<std::string> result;
    for (const auto& [key, value] : flags) {
        result.push_back("--" + key);
        result.push_back(value);
    }
    return result;
}

bool isJSON(const std::string& str) {
    return !str.empty() && str[0] == '{';
}

std::string parse(const std::string& stdout, const std::string& stderr) {
    if (!stdout.empty() && stdout != "null") {
        return isJSON(stdout) ? stdout : "";
    }
    throw std::runtime_error(stderr);
}

using ExecReturn = std::pair<std::string, int>;
using ExecFn = std::function<ExecReturn(const std::string&, const std::vector<std::string>&)>;
using CreateFn = std::function<ExecFn(const std::string&)>;

ExecReturn exec(const std::string& binaryPath, const std::string& url, const std::map<std::string, std::string>& flags) {
    TinySpawn spawn(binaryPath, args(flags));
    return {spawn.execute(url), spawn.getExitCode()};
}

CreateFn create(const std::string& binaryPath) {
    return [=](const std::string& url) {
        return [=](const std::map<std::string, std::string>& flags) {
            return exec(binaryPath, url, flags);
        };
    };
}

int main() {
    auto youtubeDl = create(constants::YOUTUBE_DL_PATH);
    // Gunakan youtubeDl untuk menjalankan perintah
    return 0;
}
