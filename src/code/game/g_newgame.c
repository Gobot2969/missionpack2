#include "..\common\jsmndr.h"
#include "g_local.h"

#define MAX_JSON_FILE_SIZE 65536
static char jsonFileBuffer[MAX_JSON_FILE_SIZE];
void ParseFactories( const char *json, int len );

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

void G_LoadFactories( void ) {
    fileHandle_t f;
    int len;

    // Open file using the early engine file system trap
    len = trap_FS_FOpenFile( "scripts/factories.txt", &f, FS_READ );
    if ( f == 0 || len <= 0 ) {
        Com_Printf( "G_LoadFactories: scripts/factories.txt not found or empty.\n" );
        if ( f ) {
            trap_FS_FCloseFile( f );
        }
        return;
    }

    if ( len >= MAX_JSON_FILE_SIZE ) {
        Com_Printf( "G_LoadFactories: File exceeds max safe QVM memory buffer size!\n" );
        trap_FS_FCloseFile( f );
        return;
    }

    // Read the complete text payload into memory
    trap_FS_Read( jsonFileBuffer, len, f );
    jsonFileBuffer[len] = '\0'; // Mandatory null termination
    trap_FS_FCloseFile( f );

    Com_Printf( "G_LoadFactories: Loaded %d bytes. Parsing tokens...\n", len );

    // Parse the factories
    ParseFactories( jsonFileBuffer, len );
}

void ParseFactories( const char *json, int len ) {
    jsmndr_parser parser;
    static jsmndrtok_t tokens[2048]; // Keep off the tiny QVM thread stack frame
    int num_toks;

    jsmndr_init( &parser );
    num_toks = jsmndr_parse( &parser, json, len, tokens, 2048 );

    if ( num_toks <= 0 ) {
        Com_Printf( "ParseFactories Error: Failed parsing tokens (Code: %d)\n", num_toks );
        return;
    }

    // Example loop extraction for setting early dynamic configuration cvars
    if ( tokens[0].type == JSON_OBJECT ) {
        int i;
        for ( i = 1; i < num_toks; i++ ) {
            // Find key-value pairs belonging straight to the main configuration object
            if ( tokens[i].parent == 0 && tokens[i].type == JSON_STRING ) {
                char cvar_name[64];
                char cvar_value[128];
                int val_idx = i + 1;
                int name_len;
                int val_len; /* FIXED: Moved variable declarations to the top of the block scope */

                // Extract Key Name
                name_len = tokens[i].end - tokens[i].start;
                if ( name_len >= sizeof(cvar_name) ) name_len = sizeof(cvar_name) - 1;
                Q_strncpyz( cvar_name, json + tokens[i].start, name_len + 1 );

                // Extract Value (Handles strings and primitives)
                val_len = tokens[val_idx].end - tokens[val_idx].start;
                if ( val_len >= sizeof(cvar_value) ) val_len = sizeof(cvar_value) - 1;
                Q_strncpyz( cvar_value, json + tokens[val_idx].start, val_len + 1 );

                // Force pass variables into the engine namespace right before cvars process
                Com_Printf( "JSON Config: Setting cvar '%s' to '%s'\n", cvar_name, cvar_value );
                trap_Cvar_Set( cvar_name, cvar_value );

                i++; // Skip the value token on the next iteration
            }
        }
    }
}
