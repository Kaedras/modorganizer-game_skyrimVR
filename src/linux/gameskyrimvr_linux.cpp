#include "../gameskyrimvr.h"

static const QString appID = QStringLiteral("611670");

using namespace MOBase;

QString GameSkyrimVR::identifyGamePath() const
{
  return parseSteamLocation(steamAPPId(), gameShortName());
}

QString GameSkyrimVR::localAppFolder()
{
  return GameGamebryo::localAppFolder(appID);
}
