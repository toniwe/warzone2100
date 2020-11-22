#include "faction.h"
#include "lib/netplay/netplay.h"

static const struct FACTION factions[NUM_FACTIONS] = {
	{ "Normal",
		{
		}
	},
	{
		"NEXUS",
		{
			{"blwallc1.pie", "blwallc_nex.pie"},
			{"blwallh.pie", "blwallh_nex.pie"},
			{"blhq.pie", "blhq_nex.pie"},
			{"blguard1.pie", "blguard_nex.pie"},
			{"blguardr.pie", "blguardr_nex.pie"},
			{"blresch0.pie", "blresch0_nex.pie"},
			{"blresch4.pie", "blresch4_nex.pie"},
			{"research_module4.pie", "research_module4_nex.pie"},
			{"blbresch.pie", "blbresch_nex.pie"},
			{"blbpower.pie", "blbpower_nex.pie"},
			{"blbhq.pie",  "blbhq_nex.pie"},
			{"blbdrdcm.pie", "blbdrdcm_nex.pie"},
			{"blpower0.pie", "blpower0_nex.pie"},
			{"blpower4.pie", "blpower4_nex.pie"},
			{"blpilbox.pie", "blpilbox_nex.pie"},
			{"blfact0.pie", "blfact0_nex.pie"},
			{"factory_module1.pie", "factory_module1_nex.pie"},
			{"blfact1.pie", "blfact1_nex.pie"},
			{"factory_module2.pie", "factory_module2_nex.pie"},
			{"blfact2.pie", "blfact2_nex.pie"},
			{"blbfact.pie", "blbfact_nex.pie"},
			{"bldrdcm0.pie", "bldrdcm0_nex.pie"},
			{"blcfact1.pie", "blcfact1_nex.pie"},
			{"blbcfact.pie", "blbcfact_nex.pie"},
			{"blcanpil.pie", "blcanpil_nex.pie"},
			{"blhowmnt.pie", "blhowmnt_nex.pie"},
			{"blguardm.pie", "blguardm_nex.pie"},
			{"blvfact0.pie", "blvfact0_nex.pie"},
			{"blvfact1.pie", "blvfact1_nex.pie"},
			{"blvfact2.pie", "blvfact2_nex.pie"},
			{"vtolfactory_module1.pie", "vtolfactory_module1_nex.pie"},
			{"vtolfactory_module2.pie", "vtolfactory_module2_nex.pie"},
			{"blderik_anim.pie", "blderik_anim_nex.pie"},
			{"blderik.pie", "blderik_nex.pie"},
			{"blmrtpit.pie", "blmrtpit_nex.pie"}
		}
	},
	{
		"Collective",
		{
			{"blwallc1.pie", "blwallc_col.pie"},
			{"blwallh.pie", "blwall_col.pie"},
			{"blhq.pie", "blhq_col.pie"},
			{"blguard1.pie", "blguard_col.pie"},
			{"blguardr.pie", "blguardr_col.pie"},
			{"blresch0.pie", "blresch0_col.pie"},
			{"blresch4.pie", "blresch4_col.pie"},
			{"research_module4.pie", "research_module4_col.pie"},
			{"blbresch.pie", "blbresch_col.pie"},
		}
	}
};

optional<WzString> getFactionModelName(const FACTION *faction, const WzString& normalFactionName)
{
	auto pos = faction->replaceIMD.find(normalFactionName);
	if (pos == faction->replaceIMD.end())
	{
		return nullopt;
	} else {
		return pos->second;
	}
}

optional<WzString> getFactionModelName(const FactionID faction, const WzString& normalFactionName)
{
	return getFactionModelName(getFactionByID(faction), normalFactionName);
}

iIMDShape* getFactionIMD(const FACTION *faction, iIMDShape* imd)
{
	WzString name = WzString::fromUtf8(modelName(imd));
	auto factionModelName = getFactionModelName(faction, name);
	if (!factionModelName.has_value())
	{
		return imd;
	}
	else
	{
		return modelGet(factionModelName.value());
	}
}

const FACTION* getPlayerFaction(uint8_t player)
{
	return &(factions[NetPlay.players[player].faction]);
}

const FACTION* getFactionByID(FactionID faction)
{
	return &(factions[(uint8_t)faction]);
}
