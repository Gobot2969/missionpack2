# Quake III Ultimate Arena Client Configuration

## 1. From Missionpackplus

General config improvements upon vanilla Q3/TA:

| Variable | Default | Description |
| --- | --- | --- |
| `cg_trueLightning` | `0.0` | Controls lightning shaft flexibility. At `1.0`, the beam sticks perfectly straight to your crosshair vector with zero lag-bending. |
| `cg_kickScale` | `0` | Sets screen vibration scaling factors when sustaining damage. Set to `0` to completely disable screen shake during combat. |
| `cg_hitSounds` | `0` | Hit sound mode |
| `cg_enemyModel` | `pm` | Forces all opposing players to render as one explicit model choice (e.g., `keel/pm`) for instantly predictable hitboxes. |
| `cg_enemyColors` | `222` | Assigns an override color profile directly to opposing character models to artificially boost visual contrast. |
| `cg_teamModel` | `""` | Overrides and forces an explicit uniform skin model across friendly teammates. |
| `cg_teamColors` | `""` | Assigns an explicit override color profile directly to friendly player meshes. |
| `cg_deadBodyDarken` | `1` | Automatically darkens dropped player corpses lying on the map floor to increase visibility contrast for live combatants. |
| `cg_fovAdjust` | `0` | Automatically scales focal viewing calculations to properly compensate for modern widescreen aspect ratio variations. |
| `cg_followKiller` | `0` | Directs the spectator follow-cam system to automatically focus over the player who eliminated you. |
| `cg_oldPlasma` | `1` | Enables vanilla plasma effect. Default `1`. |
| `cg_oldRail` | `1` | Enables vanilla rail effect. Default `1`. |
| `cg_oldRocket` | `1` | Enables vanilla rocket effect. Default `1`. |

---

## 2. Team/Item Markers and Timers

These variables control the global behavior and rendering constraints for all overhead Point of Interest indicators:

| Variable | Default | Description |
| --- | --- | --- |
| `cg_drawFriend` | `1` | `0`=Vanilla off behavior `1`=Vanilla indicators `2`=QL-styled always visibile 'POIs' |
| --- | --- | --- |
| `cg_poiTextBgAlpha` | `0.3` | Adjusts the background transparency of text elements attached to POI indicators. This includes the timer text above item POIs. |
| `cg_poiMaxDist` | `4000` | Sets the maximum distance in game units at which POIs remain visible on the screen. A linear alpha fade is applied between zero distance and max. |
| --- | --- | --- |
| `cg_teammatePOIs` | `1` | Quake Live compatibility R/O cvar. Automatically enables/disables itself depending on whether or not `cg_drawFriend` is `2`. |
| `cg_teammateNames` | `1` | Controls visibility behavior for player names above teammate POIs:<br>• `0`: Off<br>• `1`: Targeted (only when looking toward them)<br>• `2`: Always on.<br>*Requires `cg_drawFriend 2`.* |
| `cg_teammatePOIsIconSize` | `8` | Sets the initial size for teammate POI pics. *Requires `cg_drawFriend 2`.* |
| `cg_teammatePOIsIconMaxSize` | `12` | Sets the maximum size for teammate POI pics icons up close. *Requires `cg_drawFriend 2`.* |
| --- | --- | --- |
| `cg_itemPOIs` | `1` | Master toggle for rendering POIs over item spawners. |
| `cg_itemTimers` | `1` | Controls visibility of timer texts above item POIs:<br>• `0`: Off<br>• `1`: Targeted (only when looking toward them)<br>• `2`: Always on.<br>*Requires `cg_itemPOIs 1`.* |
| `cg_itemPOIsIconSize` | `24` | Sets the initial size of item POI pics. *Has no effect if `cg_itemPOIs` is set to `0`.* |
| `cg_itemPOIsIconMaxSize` | `32` | Limit the scaling limit for item POI pics. *Has no effect if `cg_itemPOIs` is set to `0`.* |

---
