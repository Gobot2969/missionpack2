#include "g_local.h"

/*
=================
G_SpawnGametypeAliases

Mapping of gametype enum values to the spawn string tokens used by
worldspawn "gametype" filters.
=================
*/

#define MAX_GAMETYPE_NAME_ALIASES 3

const char *const s_gametypeSpawnNames[GT_MAX_GAME_TYPE][MAX_GAMETYPE_NAME_ALIASES] = {
	{ "ffa", NULL, NULL },                          /* GT_FFA */
	{ "tournament", "duel", NULL },                 /* GT_TOURNAMENT */
	{ "single", "race", NULL },                     /* GT_SINGLE_PLAYER */
	{ "team", "tdm", NULL },                        /* GT_TEAM */
	{ "clanarena", "ca", NULL },                    /* GT_CLAN_ARENA */
	{ "ctf", NULL, NULL },                          /* GT_CTF */
	{ "oneflag", "1fctf", NULL },                   /* GT_1FCTF */
	{ "obelisk", "overload", NULL },                /* GT_OBELISK */
	{ "harvester", NULL, NULL },                    /* GT_HARVESTER */
	{ "freeze", "freezetag", NULL },                /* GT_FREEZE */
	{ "domination", "dom", NULL },                  /* GT_DOMINATION */
	{ "attackdefend", "ad", NULL },                 /* GT_ATTACK_DEFEND */
	{ "redrover", "rr", NULL },                     /* GT_RED_ROVER */
	{ "teamtournament", NULL, NULL },               /* GT_TEAMTOURNAMENT */
	{ "arena", "lms", NULL }                		/* GT_ARENA */
};
