
#include "src/npp.h"


// It is important to make sure that all global variables are wiped in between games,
// and all arrays freed.

byte game_mode;

bool arg_wizard;

bool character_generated;	/* The character exists */
bool character_dungeon;		/* The character has a dungeon */
bool character_loaded;		/* The character was loaded from a savefile */
bool character_saved;		/* The character was just saved to a savefile */

s16b character_icky;		/* Depth of the game in special mode */
s16b character_xtra;		/* Depth of the game in startup mode */

u32b seed_randart;		/* Hack -- consistent random artifacts */

u32b seed_flavor;		/* Hack -- consistent object colors */
u32b seed_town;			/* Hack -- consistent town layout */
u32b seed_ghost;			/* Hack -- consistent player_ghosts */

s16b num_repro;			/* Current reproducer count */
s16b object_level;		/* Current object creation level */
s16b monster_level;		/* Current monster creation level */

QChar summon_kin_type;		/* Hack -- See summon_specific() */

monster_type *summoner; 	/*Track the current summoner*/

s32b turn;				/* Current game turn */


QString current_savefile;
QFile notes_file;


s16b total_wakeup_chance;

/*
 * Dungeon variables
 */

byte feeling;			/* Most recent feeling */
s16b rating;			/* Level's current rating */

u32b  level_flag;		/* Level type */

bool good_item_flag;	/* True if "Artifact" on this level */

bool closing_flag;		/* Dungeon is closing */

/*
 * Structure (not array) of size limits
 */
maxima *z_info;

/*
 * The vault generation array
 */
vault_type *v_info;



/*
 * The terrain feature array
 */
feature_type *f_info;

/*
 * The terrain lore array
 */
feature_lore *f_l_list;

/*
 * The object kind array
 */
object_kind *k_info;

/*
 * The ghost template array
 */
ghost_template *t_info;


/*
 * The artifact array
 */
artifact_type *a_info;
artifact_lore *a_l_list;

/*
 * The random name generator table
 */
names_type *n_info;

/*
 * The ego-item array
 */
ego_item_type *e_info;

/*
 * The monster race array
 */
monster_race *r_info;


/*
 * The player race array
 */
player_race *p_info;

/*
 * The player class array
 */
player_class *c_info;

/*
 * The player history array
 */
hist_type *h_info;

/*
 * The shop owner array
 */
owner_type *b_info;

/*
 * The racial price adjustment array
 */
byte *g_info;


/*
 * The quest array
 */
quest_type *q_info;

/*
 * The object flavor array
 */
flavor_type *flavor_info;

/*Monster_movement energy info*/
move_moment_type *mon_moment_info;
u16b move_moment_num;

/*
 * Array[z_info->o_max] of dungeon objects
 */
object_type *o_list;

/*
 * Array[z_info->m_max] of dungeon monsters
 */
monster_type *mon_list;

/*
 * Array[z_info->r_max] of monster lore
 */
monster_lore *l_list;

/*
 * Array[z_info->x_max] of dungeon effects
 */
effect_type *x_list;


/*
 * Array[MAX_STORES] of stores
 */
store_type *store;

/*
 * Array[INVEN_TOTAL] of objects in the player's inventory
 */
object_type *inventory;


/*
 * The size of "alloc_kind_table" (at most z_info->k_max * 4)
 */
s16b alloc_kind_size;

/*
 * The array[alloc_kind_size] of entries in the "kind allocator table"
 */
alloc_entry *alloc_kind_table;


/*
 * The size of the "alloc_ego_table"
 */
s16b alloc_ego_size;

/*
 * The array[alloc_ego_size] of entries in the "ego allocator table"
 */
alloc_entry *alloc_ego_table;

/*
 * The size of "alloc_feat_table" (at most MAX_F_IDX * 4)
 */
s16b alloc_feat_size;

/*
 * The array[alloc_feat_size] of entries in the "feat allocator table"
 */
alloc_entry *alloc_feat_table;



/*
 * The size of "alloc_race_table" (at most z_info->r_max)
 */
s16b alloc_race_size;

/*
 * The array[alloc_race_size] of entries in the "race allocator table"
 */
alloc_entry *alloc_race_table;


/*** Player information ***/

/*
 * Pointer to the player tables (sex, race, class, magic)
 */
const player_sex *sp_ptr;
const player_race *rp_ptr;
player_class *cp_ptr;
player_magic *mp_ptr;

/*
 * The player other record (static)
 */
static player_other player_other_body;

/*
 * Pointer to the player other record
 */
player_other *op_ptr = &player_other_body;

/*
 * The player info record (static)
 */
static player_type player_type_body;

/*
 * Pointer to the player info record
 */
player_type *p_ptr = &player_type_body;



s16b x_pop(void);

/* squelch.c */
byte squelch_level[SQUELCH_BYTES];


/*
 * Arrays[NUM_FLOWS][DUNGEON_HGT][DUNGEON_WID] of cave grid flow "cost" values
 */
u16b cave_cost[MAX_FLOWS][MAX_DUNGEON_HGT][MAX_DUNGEON_WID];


/*
 * Flow cost at the center grid of the current update.
 */
int cost_at_center[MAX_FLOWS];

//pre-defined colors - loaded at startup
QColor defined_colors[MAX_COLORS];


//Various directories used by NPP
QString NPP_DIR_BASE;
QString NPP_DIR_BONE;
QString NPP_DIR_EDIT;
QString NPP_DIR_HELP;
QString NPP_DIR_ICON;
QString NPP_DIR_PREF;
QString NPP_DIR_SAVE;
QString NPP_DIR_USER;


// Monser race messages
monster_race_message *mon_msg;
monster_message_history *mon_message_hist;
u16b size_mon_msg;
u16b size_mon_hist;


/*
 * Array[VIEW_MAX] used by "update_view()"
 */
int view_n = 0;
u16b *view_g;


/*
 * Array[VIEW_MAX] used by "update_view()"
 */
int fire_n = 0;
u16b *fire_g;

/*
 * Arrays[TEMP_MAX] used for various things
 *
 * Note that temp_g shares memory with temp_x and temp_y.
 */
int temp_n = 0;
u16b *temp_g;
byte *temp_y;
byte *temp_x;

/*
 * Array[DUNGEON_HGT][256] of cave grid info flags (padded)
 *
 * This array is padded to a width of 256 to allow fast access to elements
 * in the array via "grid" values (see the GRID() macros).
 */
u16b (*cave_info)[256];

/*
 * Array[DUNGEON_HGT][DUNGEON_WID] of cave grid feature codes
 */
byte (*cave_feat)[MAX_DUNGEON_WID];


/*
 * Array[DUNGEON_HGT][DUNGEON_WID] of cave grid object indexes
 *
 * Note that this array yields the index of the top object in the stack of
 * objects in a given grid, using the "next_o_idx" field in that object to
 * indicate the next object in the stack, and so on, using zero to indicate
 * "nothing".  This array replicates the information contained in the object
 * list, for efficiency, providing extremely fast determination of whether
 * any object is in a grid, and relatively fast determination of which objects
 * are in a grid.
 */
s16b (*cave_o_idx)[MAX_DUNGEON_WID];

/*
 * Array[DUNGEON_HGT][DUNGEON_WID] of cave grid monster indexes
 *
 * Note that this array yields the index of the monster or player in a grid,
 * where negative numbers are used to represent the player, positive numbers
 * are used to represent a monster, and zero is used to indicate "nobody".
 * This array replicates the information contained in the monster list and
 * the player structure, but provides extremely fast determination of which,
 * if any, monster or player is in any given grid.
 */
s16b (*cave_m_idx)[MAX_DUNGEON_WID];

/*
 * Array[DUNGEON_HGT][DUNGEON_WID] of cave grid effect indexes
 *
 * Note that this array yields the index of the top object in the stack of
 * effects in a given grid, using the "next_x_idx" field in that effect to
 * indicate the next effect in the stack, and so on, using zero to indicate
 * "nothing".  This array replicates the information contained in the effect
 * list, for efficiency, providing extremely fast determination of whether
 * any effect is in a grid, and relatively fast determination of which effects
 * are in a grid.
 */

/*
 * Array[DUNGEON_HGT][DUNGEON_WID] of cave grid effect indexes
 *
 * Note that this array yields the index of the top object in the stack of
 * effects in a given grid, using the "next_x_idx" field in that effect to
 * indicate the next effect in the stack, and so on, using zero to indicate
 * "nothing".  This array replicates the information contained in the effect
 * list, for efficiency, providing extremely fast determination of whether
 * any effect is in a grid, and relatively fast determination of which effects
 * are in a grid.
 */

s16b (*cave_x_idx)[MAX_DUNGEON_WID];

/*
 * Table of avergae monster power.
 * Used to hep determine a suitable quest monster.
 */

u32b mon_power_ave[MAX_DEPTH_ALL][CREATURE_TYPE_MAX];



/*
 * The array of dynamic grids. -DG-
 */
dynamic_grid_type *dyna_g = NULL;

/*
 * Current number of grids in dyna_g
 */
u16b dyna_cnt = 0;

/*
 * The index of the entry that is after the last entry of dyna_g
 */
u16b dyna_next = 0;

/*
 * If dyna_full is FALSE, all the dynamic grids on the level are stored in
 * dyna_g. If it's TRUE, the contents of dyna_g are updated every certain
 * number of steps (see process_dynamic_terrain for this)
 */
bool dyna_full = FALSE;

/*
 * When dyna_full is TRUE, we need to track the center of the last update
 */
byte dyna_center_y = 255;
byte dyna_center_x = 255;

byte num_trap_on_level;
s16b player_ghost_num;
s16b ghost_r_idx;
QString player_ghost_name;
QString g_vault_name;
u16b altered_inventory_counter;
bool allow_altered_inventory;
u32b dungeon_summon_mask_f7;

s16b o_max;
s16b o_cnt;
s16b mon_max;
s16b mon_cnt;
s16b x_max;
s16b x_cnt;
bool do_feeling;

/*
 * Number of player turns the quest indicator is displayed
 * when the player fails or wins a quest.
 */
u16b quest_indicator_timer = 0;

/*
 * Remember what is being displayed on each row on the side of the screen.
 */
int sidebar_details[SIDEBAR_MAX_TYPES];


/*
 * Remember what is being displayed on each row on the side of the screen.
 */
int sidebar_monsters[SIDEBAR_MONSTER_MAX];

/*
 * It's TRUE if the player won a quest.
 */
byte quest_indicator_complete = FALSE;

u16b panel_change_offset_y;
u16b panel_change_offset_x;

/*
 * The current capabilities of the dungeon
 */
dungeon_capabilities_type *dun_cap = NULL;
