#include "plugin.h"

void Plugin::registerTypes(const char* uri)
{    
    qmlRegisterType<YoutubeAPI>(uri, 1, 0, "YoutubeAPI");
}