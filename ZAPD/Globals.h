#pragma once

#include <string>
#include <vector>
#include "ZFile.h"
#include "ZTexture.h"
#include "ZRoom/ZRoom.h"

class Globals
{
public:
	static Globals* Instance;

	bool genSourceFile; // Used for extraction
	bool useExternalResources;
	bool testMode; // Enables certain experimental features
	bool debugMessages; // Enables certain printfs
	bool profile; // Measure performance of certain operations
	bool includeFilePrefix; // Include the file prefix in symbols
	bool verbose = false; // ZAPD outputs additional information
	ZFileMode fileMode;
	std::string baseRomPath, inputPath, outputPath, cfgPath;
	TextureType texType;

	std::vector<ZFile*> files;
	std::vector<int> segments;
	std::map<int, std::string> segmentRefs;
	std::map<int, ZFile*> segmentRefFiles;
	ZRoom* lastScene;
	std::map<uint32_t, std::string> symbolMap;

	Globals();
	std::string FindSymbolSegRef(int segNumber, uint32_t symbolAddress);
	void ReadConfigFile(std::string configFilePath);
	void GenSymbolMap(std::string symbolMapPath);
	void AddSegment(int segment);
	bool HasSegment(int segment);
};

/*
 * Note: In being able to track references across files, there are a few major files that make use of segments...
 * Segment 1: nintendo_rogo_static/title_static
 * Segment 2: parameter_static
 * Segment 4: gameplay_keep
 * Segment 5: gameplay_field_keep, gameplay_dangeon_keep
 * Segment 7: link_animetion
 * Segment 8: icon_item_static
 * Segment 9: icon_item_24_static
 * Segment 12: icon_item_field_static, icon_item_dungeon_static
 * Segment 13: icon_item_nes_static
 *
 * I'm thinking a config file could be usable, but I'll have to experiment...
 */