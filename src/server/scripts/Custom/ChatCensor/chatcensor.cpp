/*
<--------------------------------------------------------------------------->
- original author: unknown ?!
- Developer(s): Amir_Cinderella
- Complete: %100
- ScriptName: 'Chat censure'
- Comment: untested.
<--------------------------------------------------------------------------->
*/
#include "ScriptPCH.h"
#include "Channel.h"
#include "Language.h"

class System_Censure : public PlayerScript
{
public:
	System_Censure() : PlayerScript("System_Censure") {}

	void OnChat(Player* player, uint32 /*type*/, uint32 lang, std::string& msg)
	{
		CheckMessage(player, msg, lang, NULL, NULL, NULL, NULL);
	}

	void OnChat(Player* player, uint32 /*type*/, uint32 lang, std::string& msg, Player* receiver)
	{

		CheckMessage(player, msg, lang, receiver, NULL, NULL, NULL);
	}

	void OnChat(Player* player, uint32 /*type*/, uint32 lang, std::string& msg, Group* group)
	{
		CheckMessage(player, msg, lang, NULL, group, NULL, NULL);
	}

	void OnChat(Player* player, uint32 /*type*/, uint32 lang, std::string& msg, Guild* guild)
	{
		CheckMessage(player, msg, lang, NULL, NULL, guild, NULL);
	}



	void CheckMessage(Player* player, std::string& msg, uint32 lang, Player* /*receiver*/, Group* /*group*/, Guild* /*guild*/, Channel* channel)
	{
		std::string lower = msg;
		std::transform(lower.begin(), lower.end(), lower.begin(), ::tolower);

		QueryResult Result = WorldDatabase.Query("SELECT matn FROM chat_filter");

		if (!Result)
			return;

		do
		{
			Field* Fields = Result->Fetch();
			std::string moton = Fields[0].GetString();

			if (lower.find(moton) != std::string::npos)
			{
				msg = "C E N S U R A D O";
				ChatHandler(player->GetSession()).PSendSysMessage("Bonito ein! Isso é contra as regras do servidor!");
				return;
			}
		} while (Result->NextRow());
	}
};

void AddSC_System_Censure()
{
	new System_Censure();
}