#ifndef YOUTUBE_DL_CONFIG_HPP
#define YOUTUBE_DL_CONFIG_HPP

#include <string>

class YoutubeDLConfig {
public:
    static const std::string YOUTUBE_DL_DIR;
    static const std::string YOUTUBE_DL_FILE;
    static const std::string YOUTUBE_DL_FILENAME;
    static const std::string YOUTUBE_DL_HOST;
    static const std::string YOUTUBE_DL_PATH;
    static const std::string YOUTUBE_DL_PLATFORM;
    static const std::string YOUTUBE_DL_SKIP_DOWNLOAD;

    static std::string get(const std::string& key);
};

#endif // YOUTUBE_DL_CONFIG_HPP
