#include "../gameskyrimvr.h"

using namespace MOBase;

QString GameSkyrimVR::identifyGamePath() const
{
  return parseSteamLocation(steamAPPId(), gameShortName());
}