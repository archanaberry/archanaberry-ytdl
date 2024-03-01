#ifndef YOUTUBE_DL_TYPES_HPP
#define YOUTUBE_DL_TYPES_HPP

#include <string>
#include <vector>
#include <map>
#include <chrono>

enum class Acodec {
    Mp4A402,
    Mp4A405,
    None,
    Opus,
};

enum class AutomaticCaptionEXT {
    Json3,
    Srv1,
    Srv2,
    Srv3,
    Ttml,
    Vtt,
};

enum class DynamicRange {
    SDR,
};

enum class AudioEXTEnum {
    M4A,
    Mhtml,
    Mp4,
    None,
    The3Gp,
    Webm,
};

enum class Container {
    M4ADash,
    Mp4Dash,
    WebmDash,
};

enum class FormatNote {
    Default,
    Low,
    Medium,
    Premium,
    Storyboard,
    The1080P,
    The144P,
    The240P,
    The360P,
    The480P,
    The720P,
    Ultralow,
};

enum class Protocol {
    HTTPS,
    M3U8Native,
    Mhtml,
};

struct Heatmap {
    double start_time;
    double end_time;
    double value;
};

struct Fragment {
    std::string url;
    double duration;
};

struct HTTPHeaders {
    std::map<std::string, std::string> headers;
};

struct AutomaticCaption {
    AutomaticCaptionEXT ext;
    std::string url;
    std::string name;
};

struct Language {
    std::string language;
};

struct RequestedDownload {
    std::vector<Format> requested_formats;
    std::string format;
    std::string format_id;
    AudioEXTEnum ext;
    std::string protocol;
    std::string format_note;
    double filesize_approx;
    double tbr;
    int width;
    int height;
    std::string resolution;
    double fps;
    DynamicRange dynamic_range;
    std::string vcodec;
    double vbr;
    double aspect_ratio;
    Acodec acodec;
    double abr;
    double asr;
    int audio_channels;
    std::string _filename;
    std::string filename;
    bool __write_download_archive;
    Language language;
};

struct Thumbnail {
    std::string url;
    int preference;
    std::string id;
    int height;
    int width;
    std::string resolution;
};

struct Payload {
    std::string id;
    std::string title;
    std::vector<Format> formats;
    std::vector<Thumbnail> thumbnails;
    std::string thumbnail;
    std::string description;
    std::string channel_id;
    std::string channel_url;
    double duration;
    double view_count;
    double age_limit;
    std::string webpage_url;
    std::vector<std::string> categories;
    std::vector<std::string> tags;
    bool playable_in_embed;
    std::string live_status;
    std::chrono::system_clock::time_point release_timestamp;
    std::vector<std::string> _format_sort_fields;
    std::map<std::string, std::vector<AutomaticCaption>> automatic_captions;
    std::map<std::string, std::string> subtitles;
    int comment_count;
    Heatmap* chapters;
    std::string channel;
    double channel_follower_count;
    std::string uploader;
    std::string uploader_id;
    std::string uploader_url;
    std::string upload_date;
    std::string availability;
    std::string original_url;
    std::string webpage_url_basename;
    std::string webpage_url_domain;
    std::string extractor;
    std::string extractor_key;
    Payload* playlist;
    int playlist_index;
    std::string display_id;
    std::string fulltitle;
    std::string duration_string;
    bool is_live;
    bool was_live;
    RequestedDownload* requested_subtitles;
    bool _has_drm;
    std::chrono::system_clock::time_point epoch;
    std::vector<RequestedDownload> requested_downloads;
    Format requested_formats;
    std::string format;
    std::string format_id;
    AudioEXTEnum ext;
    std::string protocol;
    Language* language;
    std::string format_note;
    double filesize_approx;
    double tbr;
    int width;
    int height;
    std::string resolution;
    double fps;
    DynamicRange dynamic_range;
    std::string vcodec;
    double vbr;
    double stretched_ratio;
    double aspect_ratio;
    Acodec acodec;
    double abr;
    double asr;
    int audio_channels;
    std::string _type;
    Version version;
    bool channel_is_verified;
};

struct Version {
    std::string version;
    std::string current_git_head;
    std::string release_git_head;
    std::string repository;
};

struct Flags {
    bool abortOnError;
    bool abortOnUnavailableFragment;
    std::vector<std::string> addHeader;
    bool addMetadata;
    int ageLimit;
    bool allFormats;
    bool allSubs;
    bool apListMso;
    std::string apMso;
    std::string apPassword;
    std::string apUsername;
    std::string audioFormat;
    int audioQuality;
    int autonumberStart;
    std::string batchFile;
    bool bidiWorkaround;
    std::string bufferSize;
    std::string cacheDir;
    bool callHome;
    std::string configLocation;
    bool consoleTitle;
    bool _continue;
    std::string convertSubs;
    std::string cookies;
    std::string date;
    std::string dateafter;
    std::string datebefore;
    std::string defaultSearch;
    std::string downloadArchive;
    bool dumpJson;
    bool dumpPages;
    bool dumpSingleJson;
    bool dumpUserAgent;
    bool embedSubs;
    bool embedThumbnail;
    std::string encoding;
    std::string exec;
    std::string externalDownloader;
    std::string externalDownloaderArgs;
    bool extractAudio;
    bool extractorDescriptions;
    std::string ffmpegLocation;
    std::string fixup;
    bool flatPlaylist;
    bool forceGenericExtractor;
    bool forceIpv4;
    bool forceIpv6;
    std::string format;
    bool geoBypass;
    std::string geoBypassCountry;
    std::string geoBypassIpBlock;
    std::string geoVerificationProxy;
    bool getDuration;
    bool getFilename;
    bool getFormat;
    bool getId;
    bool getThumbnail;
    bool getTitle;
    bool getUrl;
    bool help;
    bool hlsPreferFfmpeg;
    bool hlsPreferNative;
    bool hlsUseMpegts;
    std::string httpChunkSize;
    bool ignoreConfig;
    bool ignoreErrors;
    bool includeAds;
    bool keepFragments;
    bool keepVideo;
    std::string limitRate;
    bool listExtractors;
    bool listFormats;
    bool listSubs;
    bool listThumbnails;
    std::string loadInfoJson;
    bool markWatched;
    std::string matchFilter;
    std::string matchTitle;
    int maxDownloads;
    std::string maxFilesize;
    int maxSleepInterval;
    int maxViews;
    std::string mergeOutputFormat;
    std::string metadataFromTitle;
    std::string minFilesize;
    int minViews;
    bool netrc;
    bool newline;
    bool noCacheDir;
    bool noCheckCertificates;
    bool noColor;
    bool noMtime;
    bool noOverwrites;
    bool noPart;
    bool noPlaylist;
    bool noPostOverwrites;
    bool noProgress;
    bool noResizeBuffer;
    bool noWarnings;
    std::string output;
    std::string outputNaPlaceholder;
    std::string password;
    int playlistEnd;
    std::string playlistItems;
    bool playlistRandom;
    bool playlistReverse;
    int playlistStart;
    std::string postprocessorArgs;
    bool preferAvconv;
    bool preferFfmpeg;
    bool preferFreeFormats;
    bool preferInsecure;
    bool printJson;
    bool printTraffic;
    std::string proxy;
    bool quiet;
    std::string recodeVideo;
    std::string referer;
    std::string rejectTitle;
    std::string remuxVideo;
    bool restrictFilenames;
    int retries;
    bool rmCacheDir;
    bool simulate;
    bool skipDownload;
    bool skipUnavailableFragments;
    int sleepInterval;
    int socketTimeout;
    std::string sourceAddress;
    std::string subFormat;
    std::string subLang;
    std::string twofactor;
    bool update;
    std::string userAgent;
    std::string username;
    bool verbose;
    bool version;
    std::string videoPassword;
    bool writeAllThumbnails;
    bool writeAnnotations;
    bool writeAutoSub;
    bool writeDescription;
    bool writeInfoJson;
    bool writePages;
    bool writeSub;
    bool writeThumbnail;
    bool xattrs;
    bool xattrSetFilesize;
    bool yesPlaylist;
    bool youtubeSkipDashManifest;
};

struct ExecReturn {
    std::string stdout;
    int exitCode;
};

typedef ExecReturn (*ExecFn)(std::string, Flags, std::vector<std::string>);
typedef std::function<ExecReturn(std::string, Flags, std::vector<std::string>)> CreateFn;

extern CreateFn create;
extern ExecFn exec;
extern Payload youtubeDl(std::string, Flags, std::vector<std::string>);

#endif // YOUTUBE_DL_TYPES_HPP
