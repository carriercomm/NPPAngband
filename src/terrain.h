#ifndef INCLUDED_TERRAIN_H
#define INCLUDED_TERRAIN_H

/* File: terrain.h */

/*
 * Copyright (c) 2010 Jeff Greene, Diego Gonzalez
 *
 * This work is free software; you can redistribute it and/or modify it
 * under the terms of either:
 *
 * a) the GNU General Public License as published by the Free Software
 *    Foundation, version 2, or
 *
 * b) the "Angband licence":
 *    This software may be copied and distributed for educational, research,
 *    and not for profit purposes provided that this copyright and statement
 *    are included in all such copies.  Other copyrights may also apply.
 */


/*
 * Do not edit this file unless you know *exactly* what you are doing.
 *
 * Some of the values in this file were chosen to preserve game balance,
 * while others are hard-coded based on the format of old save-files, the
 * definition of arrays in various places, mathematical properties, fast
 * computation, storage limits, or the format of external text files.
 *
 * Changing some of these values will induce crashes or memory errors or
 * savefile mis-reads.  Most of the comments in this file are meant as
 * reminders, not complete descriptions, and even a complete knowledge
 * of the source may not be sufficient to fully understand the effects
 * of changing certain definitions.
 *
 * Lastly, note that the code does not always use the symbolic constants
 * below, and sometimes uses various hard-coded values that may not even
 * be defined in this file, but which may be related to definitions here.
 * This is of course bad programming practice, but nobody is perfect.
 *
 * For example, there are MANY things that depend on the screen being
 * 80x24, with the top line used for messages, the bottom line being
 * used for status, and exactly 22 lines used to show the dungeon.
 * Just because your screen can hold 46 lines does not mean that the
 * game will work if you try to use 44 lines to show the dungeon.
 *
 * You have been warned.
 */


#define NEED_FLOW		MAX_FLOWS

#define ELEM_FLOW_BASE FLOW_LAVA
#define ELEM_FLOW_TAIL FLOW_MUD

#define ELEM_FLOW_BASE_NO_DOORS FLOW_LAVA_NO_DOORS
#define ELEM_FLOW_TAIL_NO_DOORS FLOW_MUD_NO_DOORS

#define ELEMENT_LAVA 	(0x00000001L)
#define ELEMENT_ICE  	(0x00000002L)
#define ELEMENT_OIL   	(0x00000004L)
#define ELEMENT_FIRE   	(0x00000008L)
#define ELEMENT_SAND 	(0x00000010L)
#define ELEMENT_FOREST	(0x00000020L)
#define ELEMENT_WATER 	(0x00000040L)
#define ELEMENT_ACID   	(0x00000080L)
#define ELEMENT_MUD 	(0x00000100L)

#define ELEM_BASE ELEMENT_LAVA
#define ELEM_TAIL ELEMENT_MUD


#define TERRAIN_MASK (ELEMENT_LAVA | ELEMENT_ICE | ELEMENT_OIL | ELEMENT_FIRE | \
	  ELEMENT_SAND | ELEMENT_FOREST | ELEMENT_WATER | ELEMENT_ACID | ELEMENT_MUD)

/*
 * These are shortcuts to the multi-element terrain features.
 * Use with care, there aren't specific flows to support them.
 */
#define ELEMENT_BWATER (ELEMENT_LAVA | ELEMENT_WATER)
#define ELEMENT_BMUD (ELEMENT_LAVA | ELEMENT_MUD)

/*
 * Maximum distance from the character to store flow (noise) information
 */
#define FLOW_LENGTH_FULL   55

#define FLOW_LENGTH_PARTIAL   5

#define BASE_FLOW_CENTER 10000

#define BASE_FLOW_MAX	 35000

#define MAX_DISTANCE_BETWEEN_UPDATES 12



#ifdef MONSTER_SMELL
/*
 * Character turns it takes for smell to totally dissipate
 */
#define SMELL_STRENGTH   50


#endif /*MONSTER_SMELL*/


/*
 * Number of feats we change to (Excluding default). Used in f_info.txt.
 */
#define MAX_FEAT_STATES	 8


/*** Feature Indexes (see "lib/edit/feature.txt") ***/

/* Nothing */
#define FEAT_NONE		0

/* Various */
#define FEAT_FLOOR		1

#define FEAT_GLYPH		3

#define FEAT_TRAP_DOOR		14
#define FEAT_TRAP_SUMMON	18

/* Extra */
#define FEAT_RUBBLE		48

/* Seams */
#define FEAT_MAGMA		49
#define FEAT_QUARTZ		50
#define FEAT_MAGMA_H	51
#define FEAT_QUARTZ_H	52

/*stairs moved to make way for adventurers guild*/
#define FEAT_LESS		71
#define FEAT_MORE		72

#define FEAT_LESS_SHAFT	73
#define FEAT_MORE_SHAFT	74


/* Walls */
#define FEAT_WALL_EXTRA	53
#define FEAT_WALL_INNER 54
#define FEAT_WALL_OUTER	55
#define FEAT_WALL_SOLID	56
#define FEAT_PERM_EXTRA	57
#define FEAT_PERM_INNER	58
#define FEAT_PERM_OUTER	59
#define FEAT_PERM_SOLID	60

/* Specials trap that only effects monsters.  Created only by rogues. */
#define FEAT_MTRAP_BASE			61 /* Level 1 */
#define FEAT_MTRAP_STURDY		62 /* Level 1 */
#define FEAT_MTRAP_SLOWING		63 /* Level 6 */
#define FEAT_MTRAP_CONFUSION	64 /* Level 12 */
#define FEAT_MTRAP_POISON		65 /* Level 18 */
#define FEAT_MTRAP_DRAIN_LIFE	66 /* Level 24 */
#define FEAT_MTRAP_ELEC			67 /* Level 30 */
#define FEAT_MTRAP_EXPLOSIVE	68 /* Level 36 */
#define FEAT_MTRAP_PORTAL		69 /* Level 42 */
#define FEAT_MTRAP_DISPEL_M		70 /* Level 48 */

/* More wall types */
/* Can't be bothered counting in hex */

#define FEAT_LIMESTONE  75
#define FEAT_SANDSTONE  76
#define FEAT_GRANITE_C	77
#define FEAT_EARTH_WALL 78
#define FEAT_ICE_WALL_C	79
#define FEAT_SHALE      80
#define FEAT_COAL       81
#define FEAT_BCOAL      82

#define FEAT_L_ROCK	83

#define FEAT_TRAP_MAGIC_MISSILE	160
#define FEAT_TRAP_HOLY_ORB		161

/* More floor types */

#define FEAT_FLOOR_EARTH 84

/* Bridges and terrain */

#define FEAT_ICE 		85
#define FEAT_ICE_WALL		86
#define FEAT_WATER      87
#define FEAT_WATER_H    88
#define FEAT_ACID       89
#define FEAT_ACID_H     90
#define FEAT_OIL_BURN	94

/* More terrain */
#define FEAT_SAND       95
#define FEAT_SAND_H     96
#define FEAT_MUD 		97
#define FEAT_MUD_H      98
#define FEAT_BMUD       99
#define FEAT_BWATER     100
#define FEAT_LAVA       101
#define FEAT_LAVA_H     102
#define FEAT_OIL 		103
#define FEAT_OIL_H 		104
#define FEAT_WALL_FIRE	105

#define FEAT_FLOOR_WET 107
#define FEAT_FLOOR_MUD	108
#define FEAT_EARTH	110

#define FEAT_ROCK	111
#define FEAT_PEBBLES	112

#define FEAT_FIRE	113
#define FEAT_THICKET	114
#define FEAT_TREE	115
#define FEAT_BURNING_TREE	116
#define FEAT_BUSH	118
#define FEAT_THORNS	119
#define FEAT_BRAMBLES	121

#define FEAT_CREST	124
#define FEAT_CREST_H	125
#define FEAT_WAVE	126
#define FEAT_WAVE_H	127

#define FEAT_DUNE	130
#define FEAT_FSOIL	134
#define FEAT_FSOIL_D	135

#define FEAT_GEYSER	137
#define FEAT_LAVA_W	138
#define FEAT_BURNT_S	139

#define FEAT_RUBBLE_H	148
#define FEAT_FROST_CLOUD   173
#define FEAT_INERTIA   174
#define FEAT_SMOKE	175
#define FEAT_FOG	176
#define FEAT_POISON_CLOUD		177
#define FEAT_STATIC				178
#define FEAT_STEAM				179
#define FEAT_GRAVITY			180
#define FEAT_SPARKS				181
#define FEAT_LIGHT				182
#define FEAT_DARK				183
#define FEAT_NETHER				184
#define FEAT_CHAOS				185
#define FEAT_DISENCHANTMENT		186
#define FEAT_NEXUS				187
#define FEAT_TIME				188
#define FEAT_CONFUSION			189
#define FEAT_FSOIL_DYNAMIC		190
#define FEAT_LIFE_DRAIN			191
#define FEAT_GLACIER			192

#define FEAT_WALL_INSCRIPTION          193
#define FEAT_PUTRID_FLOWER             194
#define FEAT_BWATER_WALL               196
#define FEAT_BMUD_WALL                 197
#define FEAT_SCORCHED_WALL             198
#define FEAT_ELVISH_WALL               199
#define FEAT_VINES                     200
#define FEAT_SILENT_WATCHER            201
#define FEAT_ETHEREAL_WALL             202
#define FEAT_SHARD                     203
#define FEAT_METEOR_BURST              204
#define FEAT_ACID_WALL                 205
#define FEAT_TOWN_FLOOR				206


/* Level flags - extracted from feature flags */
#define LF1_LAVA 	ELEMENT_LAVA
#define LF1_ICE  	ELEMENT_ICE
#define LF1_OIL   	ELEMENT_OIL
#define LF1_FIRE   	ELEMENT_FIRE
#define LF1_SAND 	ELEMENT_SAND
#define LF1_FOREST	ELEMENT_FOREST
#define LF1_WATER 	ELEMENT_WATER
#define LF1_ACID   	ELEMENT_ACID
#define LF1_MUD 	ELEMENT_MUD


/* These ones don't match ELEMENT_* flags */
/* IMPORTANT: THERE AREN'T FLOWS FOR THESE FLAGS */
/* They exists only to finetune dungeon generation */
#define LF1_BWATER     0x40000000UL
#define LF1_BMUD       0x80000000UL


/*** Cave flags ***/

/*
 * Special cave grid flags
 */
#define CAVE_MARK		0x0001 	/* memorized feature */
#define CAVE_GLOW		0x0002 	/* self-illuminating */
#define CAVE_ICKY		0x0004 	/* part of a vault */
#define CAVE_ROOM		0x0008 	/* part of a room */
#define CAVE_G_VAULT    0x0010  /* part of a greater vault */
#define CAVE_MARKED		0x0020 	/* used to occasionally allow unusual things to happen */
#define CAVE_DTRAP		0x0040 	/* trap detected grid */
#define CAVE_LOS		0x0080 	/* grid allows LOS */
#define CAVE_FIRE       0x0100  /* is in line of fire */
#define CAVE_SEEN     	0x0200  /* seen flag */
#define CAVE_VIEW       0x0400  /* view flag */
#define CAVE_HALO		0x0800	/* glowing grid (FF2_GLOW), or adjacent to glowing grid */

#define CAVE_PROJECT	0x1000  /* grid allows projections */
#define CAVE_FLOW       0x2000  /* temporary flag to mark a square flow to be updated during the next cycle. */
#define CAVE_MOVE       0x4000  /* grid allows movement */
#define CAVE_TEMP       0x8000  /* temporary flag (hard-coded position) */


#define FF1_LOS  		0x00000001  /*allow LOS to pass*/
#define FF1_PROJECT     0x00000002  /*allow projections/spells to pass*/
#define FF1_MOVE 		0x00000004  /*allow movement*/
#define FF1_PLACE       0x00000008  /*square suitable for monsters*/
#define FF1_DROP 		0x00000010  /*square suitable for object drops*/
#define FF1_SECRET      0x00000020  /*Terrain is a secret*/
#define FF1_NOTICE      0x00000040  /*Notice this feature*/
#define FF1_REMEMBER    0x00000080  /*Remember this feature*/
#define FF1_CAN_OPEN	0x00000100  /*Can open this feature*/
#define FF1_CAN_CLOSE  	0x00000200  /*Can close this feature*/
#define FF1_CAN_BASH	0x00000400  /*Can bash this feature*/
#define FF1_CAN_SPIKE  	0x00000800  /*Can spike this feature*/
#define FF1_CAN_DISARM 	0x00001000  /*Can disarm this feature*/
#define FF1_SHOP        0x00002000  /*Feature is a shop*/
#define FF1_CAN_TUNNEL 	0x00004000  /*Can tunnel this feature*/
#define FF1_F1XXX_1	0x00008000  /*Unused*/
#define FF1_HAS_GOLD    0x00010000  /*Feature has gold*/
#define FF1_HAS_ITEM    0x00020000  /*Feature has an item*/
#define FF1_DOOR 	0x00040000  /*Detected by detect doors/destroyed by destroy doors*/
#define FF1_TRAP 	0x00080000  /*Detected by detect traps/destroyed by destroy traps*/
#define FF1_STAIRS      0x00100000  /*Detected by detect doors/destroyed by destroy stairs*/
#define FF1_GLYPH       0x00200000  /*Destroyed by powerful creatures*/
#define FF1_LESS 	0x00400000  /*Not allowed in town*/
#define FF1_MORE 	0x00800000  /*Not allowed on quest levels*/
#define FF1_RUN  	0x01000000  /*Can run over*/
#define FF1_FLOOR       0x02000000  /*Can create doors, stairs, rubble here.*/
#define FF1_WALL 	0x04000000  /*Blocks flow and treated as WALL by magic mapping/enlightenment.*/
#define FF1_PERMANENT   0x08000000  /*Never destroy/modify this location.*/
#define FF1_INNER       0x10000000  /*Inner wall of room - don't overwrite with corridor.*/
#define FF1_OUTER       0x20000000  /*Outer wall of room - OK to overwrite with corridor/turn to door*/
#define FF1_SOLID       0x40000000  /*Outer wall of room - not OK to overwrite with corridor/turn to door.*/
#define FF1_HIT_TRAP	0x80000000  /*Replace with another feature when moved into*/

#define FF1_OBVIOUS_MASK \
		(FF1_LOS | FF1_PROJECT | FF1_MOVE | FF1_SHOP | \
			FF1_DOOR | FF1_TRAP | FF1_STAIRS | FF1_GLYPH | FF1_LESS | FF1_RUN | \
			FF1_FLOOR | FF1_WALL | FF1_PERMANENT | FF1_MORE | FF1_LESS)

#define FF2_BRIDGE      0x00000001  /*Bridge this feature when generating a corridor here.*/
#define FF2_RIVER       0x00000002  /*Place as river through dungeon.*/
#define FF2_LAKE 	0x00000004  /*Place as lake in dungeon.*/
#define FF2_BRIDGED	0x00000008  /* Feature has been bridged */
#define FF2_COVERED     0x00000010  /* Terrain provides coverage for monster */
#define FF2_GLOW 	0x00000020  /*Spot is self illuminating*/
#define FF2_ATTR_LIGHT   0x00000040  /*Attribute is modified by torchlight/blindness/not seen.*/
#define FF2_EFFECT     0x00000080  /* Feature is an effect, rather than a true floor feature */
#define FF2_F2XXX_3  	0x00000100  /* Unused */
#define FF2_SHALLOW     0x00000200  /*Double weight of load. Chance of sinking in feature and losing move*/
#define FF2_DEEP 	0x00000400  /*Triple weight of load. Chance of sinking in feature and losing move*/
#define FF2_F2XXX_13     0x00000800  /*Unused*/
#define FF2_HURT_ROCK   0x00001000  /*Destroyed by transmute rock to mud/rock remover.*/
#define FF2_HURT_FIRE   0x00002000  /*Destroyed by fire balls/bolts/breath*/
#define FF2_HURT_COLD   0x00004000  /*Destroyed by frost balls/bolts/breath*/
#define FF2_HURT_ACID   0x00008000  /*Destroyed by acid balls/bolts/breath*/
#define FF2_HURT_ELEC   0x00010000  /*Destroyed by electricity balls/bolts/breath*/
#define FF2_HURT_WATER 	0x00020000  /*Hurt by water*/
#define FF2_F2XXX_4	0x00040000  /*Unused*/
#define FF2_F2XXX_5	0x00080000  /*Unused*/
#define FF2_F2XXX_6	0x00100000  /*Unused*/
#define FF2_F2XXX_7	0x00200000  /*Unused*/
#define FF2_CAN_FLY	0x00400000  /*Creatures with CAN_FLY/MUST_FLY may enter and treated as flying*/
#define FF2_F2XXX_8    0x00800000  /*Unused*/
#define FF2_F2XXX_9   0x01000000  /*Unused*/
#define FF2_F2XXX_10     0x02000000  /*Unused*/
#define FF2_TRAP_PASSIVE 0x04000000 /* Feature is a passive trap set off by player*/
#define FF2_TRAP_SMART	0x08000000  /* Feature is an active trap that casts spells at the player*/
#define FF2_TRAP_MON   	0x10000000  /* Trap for the monsters to set off*/
#define FF2_F2XXX_11   	0x20000000  /* Unused */
#define FF2_F2XXX_12 	0x40000000  /* Unused */
#define FF2_SHAFT   	0x80000000  /* Shaft (goes up or down 2 levels)*/

#define FF2_OBVIOUS_MASK \
		(FF2_GLOW | FF2_EFFECT | FF2_TRAP_MON | FF2_TRAP_PASSIVE | FF2_TRAP_SMART | FF2_SHAFT)

#define FF3_LAVA		ELEMENT_LAVA  /*Never generate on water, acid, oil or ice level. Mark level as lava level*/
#define FF3_ICE			ELEMENT_ICE  /*Never generate on water, acid, oil or lava level. Mark level as water level.*/
#define FF3_OIL			ELEMENT_OIL  /*Never generate on ice, acid, water or lava level. Mark level as oil level*/
#define FF3_FIRE		ELEMENT_FIRE  /*Mark level as a fire level*/
#define FF3_SAND  		ELEMENT_SAND  /*Mark level as a sand level*/
#define FF3_FOREST 		ELEMENT_FOREST  /*Mark level as a forest level*/
#define FF3_WATER  		ELEMENT_WATER  /*Never generate on ice, lava, oil or acid level. Mark level as a water level*/
#define FF3_ACID 		ELEMENT_ACID  /*Never generate on ice, water, oil or lava level. Mark level as acid level*/
#define FF3_MUD	  		ELEMENT_MUD  /*Mark level as a mud level*/
#define FF3_F3XXX_0 	0x00000200  /*Unused*/
#define FF3_F3XXX_1		0x00000400  /* Reserved for level type */
#define FF3_F3XXX_2 	0x00000800  /* Reserved for level type */
#define FF3_F3XXX_3		0x00001000  /* Reserved for level type */
#define FF3_F3XXX_4  	0x00002000  /* Reserved for level type */
#define FF3_F3XXX_5     0x00004000  /* Reserved for level type */
#define FF3_F3XXX_6     0x00008000  /* Reserved for level type */
#define FF3_HURT_BOIL_WATER     0x00010000  /* Hurt by Boiling Water */
#define FF3_HURT_POIS		0x00020000  /* Hurt by Poison */
#define FF3_DOOR_JAMMED		0x00040000  /* Jammed Door*/
#define FF3_DOOR_CLOSED		0x00080000  /* Closed Door*/
#define FF3_DOOR_OPEN   	0x00100000  /* Open Door */
#define FF3_DOOR_BROKEN		0x00200000  /* Broken Door */
#define FF3_DOOR_LOCKED		0x00400000  /*Locked Door*/
#define FF3_PICK_TRAP	0x00800000  /* A trap needs to be picked*/
#define FF3_PICK_DOOR	0x01000000  /* A door needs to be picked*/
#define FF3_F3XXX_17    0x02000000  /* Unused*/
#define FF3_F3XXX_18    0x04000000  /* Unused*/
#define FF3_F3XXX_19    0x08000000  /* Unused*/
#define FF3_TREE	0x10000000  /* Feature is a tree*/
#define FF3_NEED_TREE	0x20000000  /* Feature needs a adjacent tree */
#define FF3_F3XXX_21    0x40000000  /* Unused*/
#define FF3_DYNAMIC		0x80000000  /* Dynamic feature */

#define FF3_OBVIOUS_MASK \
		(TERRAIN_MASK | FF3_DOOR_JAMMED | FF3_DOOR_CLOSED | FF3_DOOR_OPEN | \
	     FF3_DOOR_BROKEN | FF3_DOOR_LOCKED | FF3_TREE)



 /*
  * Feature actions -- used to define actions performed on features.
  *
  * Note that there is a one-to-one relationship between FS_* flags and FFx_*
  * flags. These values are formed with the position of a FFx flag inside
  * its group added to a base value.
  * See grab_one_feature_action (init1.c) and do_cmd_test (cmd2.c) for details.
  */
#define FS_FLAGS1       0
#define FS_SECRET       (FS_FLAGS1 + 5)
#define FS_OPEN		(FS_FLAGS1 + 8)
#define FS_CLOSE	(FS_FLAGS1 + 9)
#define FS_BASH		(FS_FLAGS1 + 10)
#define FS_SPIKE	(FS_FLAGS1 + 11)
#define FS_TUNNEL       (FS_FLAGS1 + 14)
#define FS_TRAP		(FS_FLAGS1 + 19)
#define FS_GLYPH	(FS_FLAGS1 + 21)
#define FS_FLOOR	(FS_FLAGS1 + 25)
#define FS_HIT_TRAP     (FS_FLAGS1 + 31)

#define FS_FLAGS2       32
#define FS_BRIDGE       (FS_FLAGS2 + 0)
#define FS_HURT_ROCK    (FS_FLAGS2 + 12)
#define FS_HURT_FIRE    (FS_FLAGS2 + 13)
#define FS_HURT_COLD    (FS_FLAGS2 + 14)
#define FS_HURT_ACID    (FS_FLAGS2 + 15)
#define FS_HURT_ELEC	(FS_FLAGS2 + 16)
#define FS_HURT_WATER	(FS_FLAGS2 + 17)

#define FS_FLAGS3       64
#define FS_HURT_BWATER	(FS_FLAGS3 + 16)
#define FS_HURT_POIS	(FS_FLAGS3 + 17)
#define FS_TREE			(FS_FLAGS3 + 28)
#define FS_NEED_TREE	(FS_FLAGS3 + 29)

#define FS_FLAGS_END    96


#define _feat_ff1_match(f_ptr, flags) ((f_ptr)->f_flags1 & (flags))

#define feat_ff1_match(f_idx, flags) _feat_ff1_match(f_info + (f_idx), flags)

#define cave_ff1_match(y, x, flags) \
_feat_ff1_match(f_info + cave_feat[y][x], flags)


#define _feat_ff2_match(f_ptr, flags) ((f_ptr)->f_flags2 & (flags))

#define feat_ff2_match(f_idx, flags) _feat_ff2_match(f_info + (f_idx), flags)

#define cave_ff2_match(y, x, flags) \
_feat_ff2_match(f_info + cave_feat[y][x], flags)

#define _feat_ff3_match(f_ptr, flags) ((f_ptr)->f_flags3 & (flags))

#define feat_ff3_match(f_idx, flags) _feat_ff3_match(f_info + (f_idx), flags)

#define cave_ff3_match(y, x, flags) \
_feat_ff3_match(f_info + cave_feat[y][x], flags)



/*
 * Effect index defines
 */
#define EFFECT_LINGERING_CLOUD	 1	    /* A radiating explosion */
#define EFFECT_SHIMMERING_CLOUD  2      /* A standard lingering cloud */
#define EFFECT_PERMANENT_CLOUD   3		/* Permanent Cloud */
#define EFFECT_TRAP_SMART	     4      /* A trap that casts spells at the player. */
#define EFFECT_TRAP_DUMB	     5      /* A passive trap. */
#define EFFECT_TRAP_PLAYER	     6		/* A trap set by the player for the monsters */
#define EFFECT_GLYPH		     7		/* A glyph of warding */
#define EFFECT_GLACIER			 8		/* A glacier */
#define EFFECT_INSCRIPTION		 9		/* An inscription  */



/*
 * Effect flags (reorder them later)
 */
#define EF1_HURT_PLAY       0x0001  /* Effect can hurt the character */
#define EF1_HURT_EVIL       0x0002  /* Effect hurts only evil monsters */
#define EF1_CHARACTER       0x0004  /* Effect is cast by the character */
#define EF1_SKIP			0x0008  /* This effect doesn't need processing. */
#define EF1_SM_TRAP_ORB		0x0010  /* This effect should not go away*/
#define EF1_SM_TRAP_BALL	0x0020  /* Smart Trap Ball spell */
#define EF1_SM_TRAP_BEAM	0x0040  /* Smart Trap Beam spell */
#define EF1_SM_TRAP_BOLT	0x0080  /* Smart Trap Bolt spell */
#define EF1_SM_TRAP_LOS     0x0100  /* Smart Trap Line of sight spell */
#define EF1_TRAP_SMART     	0x0200  /* Smart Trap*/
#define EF1_TRAP_DUMB     	0x0400  /* Passive Trap */
#define EF1_TRAP_PLAYER    	0x0800  /* Player Trap */
#define EF1_GLYPH	    	0x1000  /* Glpyh set by the player */
#define EF1_HIDDEN	    	0x2000  /* The effect can't be seen */
#define EF1_PERMANENT    	0x4000  /* This effect should not go away*/
/*Unused*/

/*Put a cap on effect damage*/
#define EFFECT_POWER_MAX    200

/*
 * Determines if an entity (monster/player) is native to the given feature.
 * NATIVE_FLAGS must contain the ELEMENT_* flag of the entity.
 */
#define is_monster_native_aux(FEAT, NATIVE_FLAGS) \
		(feat_ff3_match(FEAT, NATIVE_FLAGS) == feat_ff3_match(FEAT, TERRAIN_MASK))


/*
 * Determines if a monster is FULLY native to a certain location.
 */
#define is_monster_native(Y, X, RACE) is_monster_native_aux(cave_feat[Y][X], (RACE)->r_native)


/*
 * Determines if the player is FULLY native to a certain location.
 */
#define is_player_native(Y, X) is_monster_native_aux(cave_feat[Y][X], p_ptr->p_native)


/*
 * Determine if a "legal" grid contains the given CAVE_* flag
 */
#define cave_flag_bold(Y,X,FLG) \
	((cave_info[Y][X] & (FLG)) != 0)

/*
 * Determine if a "legal" grid is suitable for LOS
 *
 * Note the use of the new "CAVE_LOS" flag.
 */
#define cave_los_bold(Y,X) \
	cave_flag_bold(Y,X,CAVE_LOS)


/*
 * Determine if a "legal" grid is suitable for projections
 *
 * Note the use of the new "CAVE_PROJECT" flag.
 */
#define cave_project_bold(Y,X) \
	cave_flag_bold(Y,X,CAVE_PROJECT)


/*
 * Determine if a "legal" grid allows movement
 */
#define cave_passable_bold(Y,X) \
	cave_flag_bold(Y,X,CAVE_MOVE)

/*Convert old los function to generic_los*/
#define los(y1, x1, y2, x2) generic_los(y1, x1, y2, x2, CAVE_LOS)

/*
 * Determine if a "legal" grid is a "trap" grid
 */
#define cave_any_trap_bold(Y,X) \
	 (x_list[cave_x_idx[Y][X]].x_flags & (EF1_TRAP_DUMB | EF1_TRAP_SMART | EF1_TRAP_PLAYER | EF1_GLYPH))
/*
 * Determine if a "legal" grid is a "trap" for monsters (set by player)
 */
#define cave_monster_trap_bold(Y,X) \
	 (x_list[cave_x_idx[Y][X]].x_flags & (EF1_TRAP_PLAYER))
/*
 * Determine if a "legal" grid is a "trap" grid for players (set by monsters)
 */
#define cave_player_trap_bold(Y,X) \
	 (x_list[cave_x_idx[Y][X]].x_flags & (EF1_TRAP_DUMB | EF1_TRAP_SMART))

/*
 * Determine if a "legal" grid is a smart "trap" for players (set by monsters)
 */
#define cave_smart_trap_bold(Y,X) \
	 (x_list[cave_x_idx[Y][X]].x_flags & (EF1_TRAP_SMART))

/*
 * Determine if a "legal" grid is a passive "trap" for players (set by monsters)
 */
#define cave_passive_trap_bold(Y,X) \
	 (x_list[cave_x_idx[Y][X]].x_flags & (EF1_TRAP_DUMB))

/*
 * Determine if a "legal" grid is a glyph.
 */
#define cave_player_glyph_bold(Y,X) \
	 (x_list[cave_x_idx[Y][X]].x_flags & (EF1_GLYPH))


/*
 * Determine if a "legal" grid is a "clean" floor grid
 *
 * Line 1 -- forbid non-dropable grids
 * Line 2 -- forbid unpassable grids
 * Line 3 -- forbid traps/glyphs
 * Line 4 -- forbid normal objects
 */
#define cave_clean_bold(Y,X) \
	(cave_ff1_match(Y, X, FF1_DROP) && \
	 cave_passable_bold(Y, X) && \
 	!cave_any_trap_bold(Y, X) && \
	 (cave_o_idx[Y][X] == 0))

/*
 * Determine if a "legal" grid is an "empty" floor grid
 *
 * Line 1 -- forbid doors, rubble, seams, walls
 * Line 2 -- forbid player/monsters
 * Line 3 -- forbid monster traps
 */
#define cave_empty_bold(Y,X) \
	(cave_ff1_match(Y, X, FF1_PLACE) && \
	 cave_passable_bold(Y, X) && \
 		!cave_player_glyph_bold(Y, X) && \
 		!cave_monster_trap_bold(Y, X) && \
	 	(cave_m_idx[Y][X] == 0))

/*
 * Determine if a "legal" grid is a valid starting grid for player
 */
#define cave_start_bold(Y,X) \
	(cave_passable_bold(Y, X) && \
	!cave_ff1_match(Y, X, FF1_PERMANENT) && \
	!cave_player_trap_bold(Y, X) && \
	(is_player_native(Y, X) || \
	 	(f_info[cave_feat[Y][X]].dam_non_native == 0)) && \
 	(cave_m_idx[Y][X] == 0))


/*
 * Determine if a "legal" grid is an "naked" floor grid
 *
 * Line 1 -- forbid non-floors and permanent features
 * Line 2 -- forbid normal objects
 * Line 3 -- forbid player/monsters
 */
#define cave_naked_bold(Y,X) \
		(cave_ff1_match(Y, X, FF1_FLOOR) && \
		cave_passable_bold(Y, X) && \
		!cave_any_trap_bold(Y, X) && \
	 	(cave_o_idx[Y][X] == 0) && \
	 	(cave_m_idx[Y][X] == 0))

/*
 * Determine if a "legal" grid is an "plain" floor grid
 * A harmless passable grid free of objects, monsters and effects
 *
 * Line 1 -- forbid permanent features
 * Line 2 -- forbid unpassable features
 * Line 3 -- forbid traps and glyphs
 * Line 4 -- forbid dangerous features
 * Line 5 -- forbid objects
 * Line 6 -- forbid monsters
 */
#define cave_plain_bold(Y,X) \
	(!cave_ff1_match(Y, X, FF1_PERMANENT) && \
	cave_passable_bold(Y, X) && \
	!cave_any_trap_bold(Y, X) && \
	(f_info[cave_feat[Y][X]].dam_non_native == 0) && \
	(cave_o_idx[Y][X] == 0) && \
	(cave_m_idx[Y][X] == 0))


/*
 * Determine if a "legal" grid is suitable for trapping
 *
 * Line 1 -- forbid non-floors features
 * Line 2 -- forbid unpassable objects
 * Line 3 -- forbid traps/glyphs
 * Line 4 -- forbid certain elements
 * Line 5 -- forbid objects
 *
 * This macro ignores the presence of monsters
 */
#define cave_trappable_bold(Y, X) \
 (cave_ff1_match(Y, X, FF1_DROP) && \
 cave_passable_bold(Y, X) && \
 !cave_any_trap_bold(Y, X) && \
 !cave_ff3_match(Y, X, FF3_LAVA | FF3_WATER | FF3_ACID | FF3_OIL | FF3_FIRE) && \
 (cave_o_idx[Y][X] == 0))


/*
 * Determine if a "legal" grid is a "shop" grid
 */
#define cave_shop_bold(Y,X) \
	 (f_info[cave_feat[Y][X]].f_flags1 & (FF1_SHOP))


/*
 * Determine if a "legal" grid is a "wall" grid
 */
#define cave_wall_bold(Y,X) \
	 (f_info[cave_feat[Y][X]].f_flags1 & (FF1_WALL))

	 /*
 * Determine if a "legal" grid is a "wall" grid
 */
#define cave_door_bold(Y,X) \
	 (f_info[cave_feat[Y][X]].f_flags1 & (FF1_DOOR))

/*
 * Determine if a "legal" grid is an up stairs.
 */
#define cave_up_stairs(Y,X) \
   (cave_ff1_match(Y, X, FF1_STAIRS | FF1_LESS) == (FF1_STAIRS | FF1_LESS))

/*
 * Determine if a "legal" grid is a down stairs.
 */
#define cave_down_stairs(Y,X) \
   (cave_ff1_match(Y, X, FF1_STAIRS | FF1_MORE) == (FF1_STAIRS | FF1_MORE))

/*
 * Determine if a "legal" grid is a "stair" grid
 */
#define cave_stair_bold(Y,X) \
	cave_ff1_match(Y, X, FF1_STAIRS)

/*
 * Determine if a "legal" grid is a "stair" grid
 */
#define cave_shaft_bold(Y,X) \
	cave_ff2_match(Y, X, FF2_SHAFT)

/*
 * Determine if a "legal" grid is "permanent"
 *
 * Line 1 -- perma-walls
 * Line 2-3 -- stairs
 * Line 4-5 -- shop doors
 */
#define cave_perma_bold(Y,X) \
	(f_info[cave_feat[Y][X]].f_flags1  & (FF1_PERMANENT))

/*
 * Determine if a "legal" grid is a door but not secret.
 */
#define cave_known_door_bold(Y,X) \
	(cave_ff1_match(Y, X, FF1_DOOR | FF1_SECRET) == (FF1_DOOR))

/*
 * Determine if a "legal" grid is a secret door.

 */
#define cave_secret_door_bold(Y,X) \
	(cave_ff1_match(Y, X, FF1_DOOR | FF1_SECRET) == \
	(FF1_DOOR | FF1_SECRET))


/*
 * Determine if a "legal" grid is a closed door.
 * Open or broken doors don't count.
 */
#define cave_closed_door(Y,X) \
  	cave_ff3_match(Y, X, FF3_DOOR_CLOSED)

/*
 * Determine if a "legal" grid is a open door.
 * Closed or broken doors don't count.
 */
#define cave_open_door(Y,X) \
  	cave_ff3_match(Y, X, FF3_DOOR_OPEN)

/*
 * Determine if a "legal" grid is a closed door but not secret.
 * Open or broken doors don't count.
 */
#define cave_known_closed_door(Y,X) \
  	(cave_ff3_match(Y, X, FF3_DOOR_CLOSED) && \
   	!cave_ff1_match(Y, X, FF1_SECRET))

/*Compiler weirdness - if I use enums  I get compiler error messages */
# define 	FLOW_NO_DOORS			0
# define    FLOW_PASS_DOORS 		1
# define    FLOW_FLYING     		2
       /* This one is a copy of FLOW_FLYING without support for doors */
# define    FLOW_FLYING_NO_DOORS 	3
# define    FLOW_PASS_WALLS 		4
# define	FLOW_LAVA				5
# define	FLOW_ICE				6
# define	FLOW_OIL				7
# define 	FLOW_FIRE				8
# define	FLOW_SAND				9
# define	FLOW_FOREST				10
# define	FLOW_WATER				11
# define	FLOW_ACID				12
# define	FLOW_MUD				13
       /* These ones are copies of the elemental flows without support for doors */
# define	FLOW_LAVA_NO_DOORS		14
# define	FLOW_ICE_NO_DOORS		15
# define	FLOW_OIL_NO_DOORS		16
# define	FLOW_FIRE_NO_DOORS		17
# define	FLOW_SAND_NO_DOORS		18
# define	FLOW_FOREST_NO_DOORS	19
# define	FLOW_WATER_NO_DOORS		20
# define	FLOW_ACID_NO_DOORS		21
# define	FLOW_MUD_NO_DOORS		22
# define	MAX_FLOWS				23

#endif  /* INCLUDED_TERRAIN_H */
