#include "SetSkyboxModifier.h"

using namespace std;

SetSkyboxModifier::SetSkyboxModifier(ZRoom* nZRoom, std::vector<uint8_t> rawData, int rawDataIndex) : ZRoomCommand(nZRoom, rawData, rawDataIndex)
{
	disableSky = rawData[rawDataIndex + 0x04];
	disableSunMoon = rawData[rawDataIndex + 0x05];
}

string SetSkyboxModifier::GenerateSourceCodePass1(string roomName)
{
	string sourceOutput = "";
	char line[2048];

	sprintf(line, "SetSkyboxModifier 0x%02X, 0x%02X\n", disableSky, disableSunMoon);
	sourceOutput = line;

	return sourceOutput;
}

string SetSkyboxModifier::GetCommandCName()
{
	return "SCmdSkyboxDisables";
}

RoomCommand SetSkyboxModifier::GetRoomCommand()
{
	return RoomCommand::SetSkyboxModifier;
}