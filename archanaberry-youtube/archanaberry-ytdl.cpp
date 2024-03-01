#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <filesystem>
#include <curl/curl.h>
#include <cstdlib>

#include "constants.hpp"
#include "index.hpp"

namespace fs = std::filesystem;

void mkdirp(const std::string& filepath) {
    fs::create_directories(filepath);
}

std::string get(const std::string& url) {
    std::string response_data;
    CURL* curl = curl_easy_init();
    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl, CURLOPT_USERAGENT, "microlinkhq/youtube-dl-exec");
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, [](char* ptr, size_t size, size_t nmemb, std::string* data) -> size_t {
            data->append(ptr, size * nmemb);
            return size * nmemb;
        });
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response_data);
        CURLcode res = curl_easy_perform(curl);
        if (res != CURLE_OK) {
            curl_easy_cleanup(curl);
            throw std::runtime_error("Failed to perform HTTP request");
        }
        curl_easy_cleanup(curl);
    }
    return response_data;
}

std::string getLatest(const std::string& data) {
    std::string url;
    size_t pos = data.find("\"browser_download_url\"");
    if (pos != std::string::npos) {
        size_t start = data.find("\"", pos + 1);
        size_t end = data.find("\"", start + 1);
        url = data.substr(start + 1, end - start - 1);
    }
    return get(url);
}

void downloadBinary(const std::string& url, const std::string& filepath) {
    std::ofstream file(filepath, std::ios::binary);
    if (!file.is_open()) {
        throw std::runtime_error("Failed to open file for writing");
    }
    std::string data = get(url);
    file.write(data.data(), data.size());
    file.close();
}

bool binaryVersionCheck(const std::string& command, const std::string& version) {
    std::string check_cmd = command + " --version";
    FILE* pipe = popen(check_cmd.c_str(), "r");
    if (!pipe) {
        return false;
    }
    char buffer[128];
    std::string result = "";
    while (!feof(pipe)) {
        if (fgets(buffer, 128, pipe) != NULL)
            result += buffer;
    }
    pclose(pipe);
    return result.find(version) != std::string::npos;
}

int main() {
    try {
        // Python version check
        if (std::getenv("YOUTUBE_DL_SKIP_PYTHON_CHECK") == nullptr) {
            if (!binaryVersionCheck("python3", ">=3.7") && !binaryVersionCheck("python", ">=3.7")) {
                throw std::runtime_error("youtube-dl-exec needs Python");
            }
        }

        // Download binary
        if (!constants::YOUTUBE_DL_SKIP_DOWNLOAD) {
            std::string binary_data;
            try {
                binary_data = get(constants::YOUTUBE_DL_HOST);
            } catch (const std::exception& e) {
                binary_data = getLatest(e.what());
            }
            mkdirp(constants::YOUTUBE_DL_DIR);
            downloadBinary(constants::YOUTUBE_DL_PATH, binary_data);
            // Set permissions for the downloaded binary if needed
            // chmod(constants::YOUTUBE_DL_PATH.c_str(), 0755);
        }
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}
