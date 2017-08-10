/*
<--------------------------------------------------------------------------->
- Developer(s): Shadowguy
- Complete: %100
- ScriptName: 'Level NPC'
- Comment: untested.
<--------------------------------------------------------------------------->
*/

#include "ScriptPCH.h"


class level_npc : public CreatureScript
{
public:
	level_npc() : CreatureScript("level_npc") {}
	bool OnGossipHello(Player * player, Creature * creature)
	{
		AddGossipItemFor(player, 4, "Level 80", GOSSIP_SENDER_MAIN, 1);
		player->PlayerTalkClass->SendGossipMenu(9425, creature->GetGUID());
		return true;
	}

	bool OnGossipSelect(Player * player, Creature * creature, uint32 /*uiSender*/, uint32 uiAction)
	{
		player->PlayerTalkClass->ClearMenus();
		switch (player->getClass())
		{
		case 1:
		{
			player->GiveLevel(80);
			//player->SetMoney(99000000);
			player->SetFlag(PLAYER_FLAGS, PLAYER_FLAGS_NO_XP_GAIN);
			//player->TeleportTo(571, 5807.95f, 587.651f, 660.938f, 1.69498f);
			player->PlayerTalkClass->SendCloseGossip();
		}break;
		}
		return true;
	}
};

void AddSC_level_npc()
{
	new level_npc();
}
