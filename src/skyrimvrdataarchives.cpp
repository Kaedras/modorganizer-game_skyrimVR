#include "skyrimvrdataarchives.h"

#include "iprofile.h"
#include <utility.h>

QStringList SkyrimVRDataArchives::vanillaArchives() const
{
  return {"Skyrim - Textures0.bsa", "Skyrim - Textures1.bsa", "Skyrim - Textures2.bsa",
          "Skyrim - Textures3.bsa", "Skyrim - Textures4.bsa", "Skyrim - Textures5.bsa",
          "Skyrim - Textures6.bsa", "Skyrim - Textures7.bsa", "Skyrim - Textures8.bsa",
          "Skyrim - Meshes0.bsa",   "Skyrim - Meshes1.bsa",   "Skyrim - Voices_en0.bsa",
          "Skyrim - Sounds.bsa",    "Skyrim - Interface.bsa", "Skyrim - Animations.bsa",
          "Skyrim - Shaders.bsa",   "Skyrim - Misc.bsa",      "Skyrim - Patch.bsa",
          "Skyrim_VR - Main.bsa"};
}

QStringList SkyrimVRDataArchives::archives(const MOBase::IProfile* profile) const
{
  QStringList result;

  QString iniFile = profile->localSettingsEnabled()
                        ? QDir(profile->absolutePath()).absoluteFilePath("SkyrimVR.ini")
                        : localGameDirectory().absoluteFilePath("SkyrimVR.ini");
  result.append(getArchivesFromKey(iniFile, "SResourceArchiveList"));
  result.append(getArchivesFromKey(iniFile, "SResourceArchiveList2"));

  return result;
}

void SkyrimVRDataArchives::writeArchiveList(MOBase::IProfile* profile,
                                            const QStringList& before)
{
  QString list = before.join(", ");

  QString iniFile = profile->localSettingsEnabled()
                        ? QDir(profile->absolutePath()).absoluteFilePath("SkyrimVR.ini")
                        : localGameDirectory().absoluteFilePath("SkyrimVR.ini");
  if (list.length() > 255) {
    int splitIdx = list.lastIndexOf(",", 256);
    setArchivesToKey(iniFile, "SResourceArchiveList", list.mid(0, splitIdx));
    setArchivesToKey(iniFile, "SResourceArchiveList2", list.mid(splitIdx + 2));
  } else {
    setArchivesToKey(iniFile, "SResourceArchiveList", list);
  }
}
