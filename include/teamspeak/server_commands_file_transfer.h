#pragma once
/*WARNING: This file is auto generated. Do not edit this file, but edit the server messages and regenerate! */

#include "teamspeak/public_definitions.h"

#ifdef __cplusplus
extern "C" {
#endif

/** Structure that contains the command data for an ftcreatedir message */
struct ts3sc_data_ftcreatedir {
     uint64       channelID; ///< The channel ID where the directory is to be created
     const char*  dirname;   ///< utf8 encoded c string containing the directory name
};

/** Structure that contains the meta data for an ftcreatedir message */
struct ts3sc_meta_ftcreatedir {
     int RESERVED; ///< This is here because C forbids empty structs. DO NOT USE
};

/** C Structure that contains the meta data and data for an ftcreatedir message */
struct ts3sc_ftcreatedir {
    struct ts3sc_meta_ftcreatedir   m;      ///< meta data
    struct ts3sc_data_ftcreatedir   d;      ///< data
};

/** Structure that contains the command data for an ftdeletefile message */
struct ts3sc_data_ftdeletefile {
     uint64 channelID; ///< The channel ID where the file is to be deleted
};

/** Structure that contains the repeat command data for an ftdeletefile message */
struct ts3sc_array_ftdeletefile {
     const char* fileName;  ///< The file name to be deleted
};

/** Structure that contains the meta data for an ftdeletefile message */
struct ts3sc_meta_ftdeletefile {
     int RESERVED; ///< This is here because C forbids empty structs. DO NOT USE
};

/** C Structure that contains the meta data and data for an ftdeletefile message */
struct ts3sc_ftdeletefile {
    struct ts3sc_meta_ftdeletefile   m;      ///< meta data
    struct ts3sc_data_ftdeletefile   d;      ///< data
    int                              r_size; ///< number of items in r
    struct ts3sc_array_ftdeletefile* r;      ///< repeated data
};

/** Structure that contains the command data for an ftgetfileinfo message */
struct ts3sc_data_ftgetfileinfo {
     int RESERVED; ///< This is here because C forbids empty structs. DO NOT USE
};

/** Structure that contains the repeat command data for an ftgetfileinfo message */
struct ts3sc_array_ftgetfileinfo {
     uint64 channelID;     ///< The channel ID where the file is located
     const char* fileName; ///< utf8 encoded c string containing the file name
};

/** Structure that contains the meta data for an ftgetfileinfo message */
struct ts3sc_meta_ftgetfileinfo {
     int RESERVED; /**<This is here because C forbids empty structs. DO NOT USE*/
};

/** C Structure that contains the meta data and data for an ftgetfileinfo message */
struct ts3sc_ftgetfileinfo {
    struct ts3sc_meta_ftgetfileinfo   m;      ///< meta data
    struct ts3sc_data_ftgetfileinfo   d;      ///< data
    int                               r_size; ///< number of items in r
    struct ts3sc_array_ftgetfileinfo* r;      ///< repeated data
};

/** Structure that contains the command data for an ftgetfilelist message */
struct ts3sc_data_ftgetfilelist {
     uint64       channelID; ///< The channel ID
     const char*  path;      ///< utf8 encoded c string containing the path to get the files and directories in
};

/** Structure that contains the meta data for an ftgetfilelist message */
struct ts3sc_meta_ftgetfilelist {
     int RESERVED; ///< This is here because C forbids empty structs. DO NOT USE
};

/** C Structure that contains the meta data and data for an ftgetfilelist message */
struct ts3sc_ftgetfilelist {
    struct ts3sc_meta_ftgetfilelist   m;      ///< meta data
    struct ts3sc_data_ftgetfilelist   d;      ///< data
};

/** Structure that contains the command data for an ftinitdownload message */
struct ts3sc_data_ftinitdownload {
     const char*  fileName;  ///< The file name
     uint64       channelID; ///< The channel ID where the file is to be downloaded from
};

/** Structure that contains the meta data for an ftinitdownload message */
struct ts3sc_meta_ftinitdownload {
     int RESERVED; ///< This is here because C forbids empty structs. DO NOT USE
};

/** C Structure that contains the meta data and data for an ftinitdownload message */
struct ts3sc_ftinitdownload {
    struct ts3sc_meta_ftinitdownload   m;      ///< meta data
    struct ts3sc_data_ftinitdownload   d;      ///< data
};

/** Structure that contains the command data for an ftinitupload message */
struct ts3sc_data_ftinitupload {
     const char*  fileName;  ///< The file name
     uint64       fileSize;  ///< The file size
     uint64       channelID; ///< The channel ID where the file is to be uploaded
     int          overwrite; ///< Set to 1 to overwrite files, 0 to prevent overwrites. Mutually exclusive with resume.
     int          resume;    ///< Set to 1 to resume an existing upload, 0 to start from scratch. Mutually exclusive with overwrite
};

/** Structure that contains the meta data for an ftinitupload message */
struct ts3sc_meta_ftinitupload {
     int RESERVED; ///< This is here because C forbids empty structs. DO NOT USE
};

/** C Structure that contains the meta data and data for an ftinitupload message */
struct ts3sc_ftinitupload {
    struct ts3sc_meta_ftinitupload   m;      ///< message meta data
    struct ts3sc_data_ftinitupload   d;      ///< message data
};

/** Structure that contains the command data for an ftrenamefile message */
struct ts3sc_data_ftrenamefile {
     uint64       fromChannelID; ///< The channel ID where the file is located now
     uint64       toChannelID;   ///< The channel ID where the file is to be moved to
     const char*  oldFileName;   ///< utf8 encoded c string containing the current file name
     const char*  newFileName;   ///< utf8 encoded c string containing the new file name
};

/** Structure that contains the meta data for an ftrenamefile message */
struct ts3sc_meta_ftrenamefile {
     unsigned int has_toChannelID : 1; ///< boolean. 1 if the file is to be moved to a different channel.
};

/** C Structure that contains the meta data and data for an ftrenamefile message */
struct ts3sc_ftrenamefile {
    struct ts3sc_meta_ftrenamefile   m; ///< message meta data
    struct ts3sc_data_ftrenamefile   d; ///< message data
};

#ifdef __cplusplus
}
#endif
