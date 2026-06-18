# Quake III Ultimate Arena Server Configuration

## 1. Gametype Definitions

The gametype indexing has been updated and expanded from vanilla Quake 3 and Team Arena. Use these integer values for `g_gametype`:

| Value | Gametype Description |
| :--- | :--- |
| `0` | Free For All (FFA) |
| `1` | Tournament (Duel) |
| `2` | `GT_SINGLE_PLAYER` *(Inactive / Unused)* |
| `3` | Arena |
| `4` | Team Deathmatch (TDM) |
| `5` | Team Arena |
| `6` | Freeze Tag *(Inactive / Unused)* |
| `7` | Capture the Flag (CTF) |
| `8` | One Flag CTF |
| `9` | Overload |
| `10` | Harvester |
| `11` | `GT_TEAMTOURNAMENT` *(Inactive / Unused)* |

*Note: These will change shortly to closer reflect that of Quake Live; this will happen when (hopefully) QL-compatible factories are implemented, whilst expanding upon them. I.e. g_freeze for all gametypes*

---

## 2. Server Gameplay & Physics Modifiers

These variables adjust general server settings.

| Variable | Default | Description |
| :--- | :--- | :--- |
| `g_noSelfDamage` | `0` | Disables splash and environmental damage dealt to oneself (`1` = Disabled, `0` = Standard self-damage behavior). |
| `g_startHealth` | `100` | Defines the starting health pool upon a standard player respawn (Range: `0` to `200`). |
| `g_startArmor` | `0` | Defines the starting armor pool upon a standard player respawn (Range: `0` to `200`). |
| `g_teamVisibility` | `1` | Whether or not server allows teammates to see eachothers' positions globally. `0` = Vanilla behavior; don't send any new messages; players with cg_drawFriend < 2 will raycast to hide known within PVS. `1` = Send 'tpos' message in team games, allowing allies to see eachother. |
| `g_itemVisibility` | `1` | Whether or not server allows players in match to receive item positions, respawn timers, etc. `0` = Vanilla behavior; don't send any new messages; nobody is allowed to see item positions and timers. `1` = Send 'ipos' message with item locations and stats, such as respawn times. |
| `g_allSpec` | `0` | Whether or not dead players in round-based gamemodes can spectate everybody. `0` = Default team-only dead spectators. `1` = Dead players can spectate everybody, including enemies. |

---

## 3. Game Balancing & Customization

Weapon systems can be fine-tuned via ammunition limits, velocity settings, structural behavior, and exact damage configurations. 

For variables containing a wildcard symbol (*X*), swap the token out for one of the following shortcodes:
*   `MG` (Machinegun), `SG` (Shotgun), `GL` (Grenade Launcher), `RL` (Rocket Launcher), `LG` (Lightning Gun), `RG` (Railgun), `PG` (Plasma Gun), `BFG` (BFG10K), `NG` (Nailgun), `PL` (Prox Launcher), `CG` (Chaingun), `HMG` (Heavy Machine Gun).

| Variable | Default | Description |
| :--- | :--- | :--- |
| `g_startingWeapon` | `0` | Selects a specific standalone primary weapon id for players to spawn with by default (`0` = Gauntlet/Machinegun baseline). |
| `g_startAmmo*X*` | ` ` | Sets the baseline starting ammunition reserve given to players on spawn for the specified weapon identifier *X*. |
| `g_arenaAmmo*X*` | ` ` | Sets the baseline starting ammunition reserve given to players specifically in Arena/Team Arena game modes for weapon *X*. |
| `g_damage*X*` | `?` | Sets the explicit base direct-hit damage value for the specified weapon code *X* (Range: `0` to `999`). |
| `g_splashDamage*X*` | ` ` | Sets the impact blast damage coefficient for splash-damage tracking weapons (Applicable codes: `GL`, `RL`, `PG`, `BFG`). |
| `g_splashRadius*X*` | ` ` | Sets the radial blast distance falloff boundary for splash-damage tracking weapons (Applicable codes: `GL`, `RL`, `PG`, `BFG`). |
| `g_velocityRL` | `?` | Sets the physical travel velocity speed of fired Rocket Launcher projectiles. |
| `g_sgPellets` | `?` | Sets the exact number of independent hit-scan pellets generated per primary Shotgun blast. |
| `g_sgPelletSpread` | `700` | Configures the horizontal and vertical dispersion pattern width of Shotgun pellets. |
| `g_nailBounce` | `1` | Toggles Quake Live-style bouncing projectiles for the Nailgun (`1` = On, `0` = Off). |
| :--- | :--- | :--- |
| `g_ammoRespawn` | `5` | Ammo pickup respawn pacing configuration applied within FFA and Tournament modes in seconds. |
| `g_ammoTeamRespawn` | `5` | Ammo pickup respawn pacing configuration applied within team-based gametypes in seconds. |
| `g_armorRespawn` | `25` | Armor pickup respawn pacing configuration applied within FFA and Tournament modes in seconds. |
| `g_armorTeamRespawn` | `25` | Armor pickup respawn pacing configuration applied within team-based gametypes in seconds. |
| `g_healthRespawn` | `35` | Small and standard health item respawn pacing configuration applied within FFA and Tournament modes in seconds. |
| `g_healthTeamRespawn` | `35` | Small and standard health item respawn pacing configuration applied within team-based gametypes in seconds. |
| `g_megahealthRespawn` | `35` | Megahealth item respawn pacing configuration applied within FFA and Tournament modes in seconds. |
| `g_megahealthTeamRespawn` | `35` | Megahealth item respawn pacing configuration applied within team-based gametypes in seconds. |
| `g_powerupRespawn` | `120` | Major Powerup item respawn pacing configuration applied within FFA and Tournament modes in seconds. |
| `g_powerupTeamRespawn` | `120` | Major Powerup item respawn pacing configuration applied within team-based gametypes in seconds. |
| `g_holdableRespawn` | `60` | Inventory Holdable item respawn pacing configuration applied within FFA and Tournament modes in seconds. |
| `g_holdableTeamRespawn` | `60` | Inventory Holdable item respawn pacing configuration applied within team-based gametypes in seconds. |
| :--- | :--- | :--- |
| `g_grapple` | `0` | Master global toggle enabling grappling hook weapon (`1` = On, `0` = Off). |
| `g_grappleDelayTime` | `400` | Grapple delay time. |
| `g_grappleHoldTime` | `0` | Maximum duration a line can actively latch onto a surface in seconds (`0` allows infinite attachment). |
| `g_grappleSpeed` | `1600` | Grapple deploy speed in U/s |
| `g_grapplePull` | `800` | Grapple pull speed in U/s. |
| `g_grappleDamage` | `2` | Grapple damage amount (`0` to disable damage). |

---

## 6. Inventory Filtering & Spawn Loadouts

These bitmask commands strip items out of compiled game map objects, or explicitly bundle starting kits. To target multiple items simultaneously, compute the parameter argument by summing the decimal bitweight integers of your target choices.

### Weapon Generation & Spawn Kits (`wpflags`, `removeweapon`, `removeammo`)

*   **wpflags:** Set starting weapon inventories. *(Note: Players always retain the Gauntlet and Machinegun regardless of mask modification settings).*
*   **removeweapon:** Drops matching weapon pick-ups directly out of the active map context.
*   **removeammo:** Drops corresponding weapon-specific ammunition cases directly out of the active map context.

| Bitweight Integer | Targeted Asset Name |
| :--- | :--- |
| `1` | Machinegun |
| `2` | Shotgun |
| `4` | Grenade Launcher |
| `8` | Rocket Launcher |
| `16` | Lightning Gun |
| `32` | Railgun |
| `64` | Plasma Gun |
| `128` | BFG10K |
| `256` | Nailgun |
| `512` | Prox Launcher |
| `1024` | Chaingun |
| `2048` | Heavy Machine Gun |

### Standard Entity Filtering (`removeitem`)

Filters health resources, protection levels, and utility inventories out of the physical map layouts.

| Bitweight Integer | Targeted Asset Name |
| :--- | :--- |
| `1` | Armor Shard |
| `2` | Combat Armor (Yellow) |
| `4` | Body Armor (Red) |
| `8` | Small Health |
| `16` | Medium Health |
| `32` | Large Health |
| `64` | Megahealth |
| `128` | Holdable Teleporter |
| `256` | Holdable Medkit |
| `512` | Holdable Kamikaze |
| `1024` | Holdable Portal |
| `2048` | Holdable Invulnerability |
| `4096` | Armor Jacket (Green) |

### Powerup Filtering (`removepowerup`)

Filters timed multi-tier combat modifier field pick-ups out of the physical map layouts.

| Bitweight Integer | Targeted Asset Name |
| :--- | :--- |
| `1` | Quad Damage |
| `2` | Environmental Battle Suit |
| `4` | Haste |
| `8` | Invisibility |
| `16` | Regeneration |
| `32` | Flight |