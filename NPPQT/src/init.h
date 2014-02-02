#ifndef INIT_H
#define INIT_H

#include <src/defines.h>
#include <QChar>
#include <QFile>
#include <QMessageBox>
#include <QTextStream>
#include "src/store.h"
#include "src/structures.h"
#include "src/globals.h"
#include "src/function_declarations.h"


/*
 * Copyright (c) 2000 Robert Ruehlmann
 *
 * This software may be copied and distributed for educational, research,
 * and not for profit purposes provided that this copyright and statement
 * are included in all such copies.
 */


/*
 * Parse errors
 */
enum
{
    PARSE_ERROR_GENERIC = 1,
    PARSE_ERROR_INVALID_FLAG,
    PARSE_ERROR_INVALID_ITEM_NUMBER,
    PARSE_ERROR_INVALID_SPELL_FREQ,
    PARSE_ERROR_INVALID_VALUE,
    PARSE_ERROR_MISSING_COLON,
    PARSE_ERROR_MISSING_FIELD,
    PARSE_ERROR_MISSING_RECORD_HEADER,
    PARSE_ERROR_NON_SEQUENTIAL_RECORDS,
    PARSE_ERROR_NOT_NUMBER,
    PARSE_ERROR_OBSOLETE_FILE,
    PARSE_ERROR_OUT_OF_BOUNDS,
    PARSE_ERROR_OUT_OF_MEMORY,
    PARSE_ERROR_TOO_FEW_ENTRIES,
    PARSE_ERROR_TOO_MANY_ENTRIES,
    PARSE_ERROR_UNDEFINED_DIRECTIVE,
    PARSE_ERROR_UNRECOGNISED_BLOW,
    PARSE_ERROR_UNRECOGNISED_TVAL,
    PARSE_ERROR_UNRECOGNISED_SVAL,
    PARSE_ERROR_VAULT_TOO_BIG,
    PARSE_ERROR_TOO_MANY_ALLOCATIONS,
    PARSE_ERROR_TOO_MANY_ARGUMENTS,
    PARSE_ERROR_NON_SEQUENTIAL_QUESTS,
    PARSE_ERROR_NAME_TOO_LONG,

    PARSE_ERROR_MAX
};


// Specify which information to be parsed
extern int (*parse_which_info)(QString line_info);


// Create directories where all the files are located.
extern void create_directories();


extern int init_store_txt(QFile fp);
extern int init_names_txt(QFile fp);


extern int parse_z_info(QString line_info);
extern int parse_v_info(QString line);
extern int parse_f_info(QString line);
extern int parse_k_info(QString line);
extern int parse_t_info(QString buf);
extern int parse_a_info(QString buf);
extern int parse_e_info(QString buf);
extern int parse_r_info(QString buf);
extern int parse_p_info(QString buf);
extern int parse_c_info(QString buf);
extern int parse_h_info(QString buf);
extern int parse_b_info(QString buf);
extern int parse_q_info(QString buf);
extern int parse_n_info(QString buf);
extern int parse_flavor_info(QString buf);
extern int parse_s_info(QString buf);
extern void quit_npp_games(QString message);


// parsing functions used in other parts of the source code
extern int process_n_line(QString read_from_line, QString *save_to_string, int *array_index, int max_index);
extern int process_4_ints(QString line_info, int *v1, int *v2, int *v3, int *v4);

/*
 * Error tracking
 */
extern int last_idx;
extern int prev_lev;
extern int shop_idx;
extern int owner_idx;
extern int cur_title;
extern int cur_equip;

#endif // INIT_H