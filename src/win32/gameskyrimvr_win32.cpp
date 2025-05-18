#include "../gameskyrimvr.h"

using namespace MOBase;

QString GameSkyrimVR::identifyGamePath() const
{
  QString path = "Software\\Bethesda Softworks\\" + gameName();
  return findInRegistry(HKEY_LOCAL_MACHINE, path.toStdWString().c_str(),
                        L"Installed Path");
}