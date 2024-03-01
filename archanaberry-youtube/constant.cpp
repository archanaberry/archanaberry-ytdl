#include "YoutubeDLConfig.hpp"
#include <cstdlib>
#include <iostream>
#include <filesystem>

namespace fs = std::filesystem;

const std::string YoutubeDLConfig::YOUTUBE_DL_DIR = YoutubeDLConfig::get("YOUTUBE_DL_DIR").empty() ? fs::current_path().parent_path().string() + "/bin" : YoutubeDLConfig::get("YOUTUBE_DL_DIR");
const std::string YoutubeDLConfig::YOUTUBE_DL_FILE = YoutubeDLConfig::get("YOUTUBE_DL_FILENAME").empty() || (YoutubeDLConfig::get("YOUTUBE_DL_PLATFORM") == "win32" && !YoutubeDLConfig::get("YOUTUBE_DL_FILENAME").ends_with(".exe")) ? YoutubeDLConfig::get("YOUTUBE_DL_FILENAME") + ".exe" : YoutubeDLConfig::get("YOUTUBE_DL_FILENAME");
const std::string YoutubeDLConfig::YOUTUBE_DL_FILENAME = YoutubeDLConfig::get("YOUTUBE_DL_FILENAME").empty() ? "yt-dlp" : YoutubeDLConfig::get("YOUTUBE_DL_FILENAME");
const std::string YoutubeDLConfig::YOUTUBE_DL_HOST = YoutubeDLConfig::get("YOUTUBE_DL_HOST").empty() ? "https://api.github.com/repos/yt-dlp/yt-dlp/releases/latest" : YoutubeDLConfig::get("YOUTUBE_DL_HOST");
const std::string YoutubeDLConfig::YOUTUBE_DL_PLATFORM = YoutubeDLConfig::get("YOUTUBE_DL_PLATFORM").empty() ? (std::getenv("YOUTUBE_DL_PLATFORM") || isUnix() ? "unix" : "win32") : YoutubeDLConfig::get("YOUTUBE_DL_PLATFORM");
const std::string YoutubeDLConfig::YOUTUBE_DL_PATH = YoutubeDLConfig::YOUTUBE_DL_DIR + "/" + YoutubeDLConfig::YOUTUBE_DL_FILE;
const std::string YoutubeDLConfig::YOUTUBE_DL_SKIP_DOWNLOAD = YoutubeDLConfig::get("YOUTUBE_DL_SKIP_DOWNLOAD");

std::string YoutubeDLConfig::get(const std::string& key) {
    const char* env = std::getenv(key.c_str());
    if (env != nullptr) {
        return env;
    }
    return "";
}
