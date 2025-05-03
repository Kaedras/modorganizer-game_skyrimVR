#ifndef _SKYRIMVRSAVEGAME_H
#define _SKYRIMVRSAVEGAME_H

#include "gamebryosavegame.h"

#ifdef __unix__
#include <linux/compatibility.h>
#else
#include <Windows.h>
#endif

class GameSkyrimVR;

class SkyrimVRSaveGame : public GamebryoSaveGame
{
public:
  SkyrimVRSaveGame(QString const& fileName, GameSkyrimVR const* game);

protected:
  // Fetch easy-to-access information.
  void fetchInformationFields(FileWrapper& wrapper, uint32_t& version,
                              QString& playerName, uint16_t& playerLevel,
                              QString& playerLocation, uint32_t& saveNumber,
                              FILETIME& creationTime) const;

  std::unique_ptr<DataFields> fetchDataFields() const override;
};

#endif  // _SKYRIMVRSAVEGAME_H
