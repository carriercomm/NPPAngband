
/* File: was obj-ui.c */

/*
 * Copyright (c) 1997 Ben Harrison, James E. Wilson, Robert A. Koeneke
 * 						Jeff Greene, Diego Gonzalez
 *
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


#include "src/object_select.h"

bool floor_tab::count_floor_items(int mode, int sq_y, int sq_x)
{
    int this_o_idx, next_o_idx;

    // assume we aren't using the floor
    bool allow_floor = FALSE;

    if (!(mode & (USE_FLOOR))) return (FALSE);

    // Wipe the vector
    floor_items.clear();

    /* Scan all objects in the grid */
    for (this_o_idx = dungeon_info[sq_y][sq_x].object_idx; this_o_idx; this_o_idx = next_o_idx)
    {

        /* Get the object */
        object_type *o_ptr = &o_list[this_o_idx];

        /* Get the next object */
        next_o_idx = o_ptr->next_o_idx;

        /* Verify item tester */
        if (!get_item_okay(0 - this_o_idx)) continue;

        /* Accept this item */
        floor_items.append(this_o_idx);
        allow_floor = TRUE;
    }

    return (allow_floor);
}

// Make the tab for the widget
floor_tab::floor_tab()
{
    QVBoxLayout *floor_view = new QVBoxLayout;

    // Make a button for each tab.
    for (int i = 0; i < floor_items.size(); i++)
    {
        QChar which_char = letter_to_number(i);
        object_type *o_ptr = &o_list[floor_items[i]];
        QString o_name = object_desc(o_ptr, ODESC_PREFIX | ODESC_FULL);
        QString button_name = (QString("%1) %2") .arg(which_char) .arg(o_name));
        QPushButton *this_button = new QPushButton(button_name);

        // TODO add a signal.

        floor_view->addWidget(this_button);
    }
    setLayout(floor_view);

}

bool inven_tab::count_inven_items(int mode)
{
    // assume we aren't using the floor
    bool allow_inven = FALSE;

    if (!(mode & (USE_INVEN))) return (FALSE);

    // Wipe the vector
    inven_items.clear();

    /* Scan all objects in the grid */
    for (int i = 0; i < (INVEN_WIELD - 1); i++)
    {

        /* Verify item tester */
        if (!get_item_okay(i)) continue;

        /* Accept this item */
        inven_items.append(i);
        allow_inven = TRUE;
    }

    return (allow_inven);
}

inven_tab::inven_tab()
{
    QVBoxLayout *equip_view = new QVBoxLayout;

    // Make a button for each tab.
    for (int i = 0; i < inven_items.size(); i++)
    {
        QChar which_char = letter_to_number(i);
        object_type *o_ptr = &inventory[inven_items[i]];
        QString o_name = object_desc(o_ptr, ODESC_PREFIX | ODESC_FULL);
        QString button_name = (QString("%1) %2") .arg(which_char) .arg(o_name));
        QPushButton *this_button = new QPushButton(button_name);

        // TODO add a signal.

        equip_view->addWidget(this_button);
    }
    setLayout(equip_view);
}

bool equip_tab::count_equip_items(int mode)
{
    // assume we aren't using the floor
    bool allow_equip = FALSE;

    // Wipe the vector
    equip_items.clear();

    if (!(mode & (USE_EQUIP))) return (FALSE);

    /* Scan all objects in the grid */
    for (int i = INVEN_WIELD; i < QUIVER_START; i++)
    {

        /* Verify item tester */
        if (!get_item_okay(i)) continue;

        /* Accept this item */
        equip_items.append(i);
        allow_equip = TRUE;
    }

    return (allow_equip);
}

equip_tab::equip_tab()
{
    QVBoxLayout *equip_view = new QVBoxLayout;

    // Make a button for each tab.
    for (int i = 0; i < equip_items.size(); i++)
    {
        QChar which_char = letter_to_number(i);
        object_type *o_ptr = &inventory[equip_items[i]];
        QString o_name = object_desc(o_ptr, ODESC_PREFIX | ODESC_FULL);
        QString button_name = (QString("%1) %2") .arg(which_char) .arg(o_name));
        QPushButton *this_button = new QPushButton(button_name);

        // TODO add a signal.

        equip_view->addWidget(this_button);
    }
    setLayout(equip_view);
}

bool quiver_tab::count_quiver_items(int mode)
{
    // assume we aren't using the quiver
    bool allow_quiver = FALSE;

    // Wipe the vector
    quiver_items.clear();

    if (!(mode & (USE_QUIVER))) return (FALSE);

    /* Scan all objects in the grid */
    for (int i = INVEN_WIELD; i < QUIVER_START; i++)
    {

        /* Verify item tester */
        if (!get_item_okay(i)) continue;

        /* Accept this item */
        quiver_items.append(i);
        allow_quiver = TRUE;
    }

    return (allow_quiver);
}

quiver_tab::quiver_tab()
{
    QVBoxLayout *quiver_view = new QVBoxLayout;

    // Make a button for each tab.
    for (int i = 0; i < quiver_items.size(); i++)
    {
        QChar which_char = letter_to_number(i);
        object_type *o_ptr = &inventory[quiver_items[i]];
        QString o_name = object_desc(o_ptr, ODESC_PREFIX | ODESC_FULL);
        QString button_name = (QString("%1) %2") .arg(which_char) .arg(o_name));
        QPushButton *this_button = new QPushButton(button_name);

        // TODO add a signal.

        quiver_view->addWidget(this_button);
    }
    setLayout(quiver_view);
}



ObjectSelectDialog::ObjectSelectDialog(QString prompt, bool allow_floor, bool allow_inven, bool allow_equip, bool allow_quiver, QWidget *parent) : QDialog(parent)
{
    equip_tabs = new QTabWidget;

    // Add the tabs as necessary
    if (allow_floor) equip_tabs->addTab(new floor_tab(), "Floor Items");
    //if (allow_inven) equip_tabs->addTab(new inven_tab(), "Inventory");
    //if (allow_equip) equip_tabs->addTab(new equip_tab(), "Equipment");
    //if (allow_quiver) equip_tabs->addTab(new quiver_tab(), "Quiver");

    buttons = new QDialogButtonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel);

    connect(buttons, SIGNAL(accepted()), this, SLOT(accept()));
    connect(buttons, SIGNAL(rejected()), this, SLOT(reject()));

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addWidget(equip_tabs);
    mainLayout->addWidget(buttons);
    setLayout(mainLayout);

    setWindowTitle(prompt);

}


/*
 * Hack -- allow user to "prevent" certain choices.
 *
 * The item can be negative to mean "item on floor".
 */
static bool get_item_allow(int item, bool is_harmless)
{
    object_type *o_ptr;

    /* Inventory or floor */
    if (item >= 0)
        o_ptr = &inventory[item];
    else
        o_ptr = &o_list[0 - item];

    // TODO - work out a system to verify objects

    /* Allow it */
    return (TRUE);
}

/**
 * Display list items to choose from
 */
bool item_menu(int *cp, QString pmt, int mode, bool *oops, int sq_y, int sq_x)
{
    // SAVE For my infomenu_iter menu_f = {get_item_tag, NULL, get_item_display, get_item_action };
    bool done;

    int j;

    bool allow_floor = count_floor_items(mode, sq_y, sq_x);
    bool allow_equip = count_equip_items(mode);
    bool allow_inven = count_inven_items(mode);
    bool allow_quiver = count_quiver_items(mode);

    /* Require at least one legal choice */
    if (!allow_inven && !allow_equip && !allow_floor && !allow_quiver)
    {
        /* Cancel p_ptr->command_see */
        p_ptr->command_see = FALSE;

        /* Report failure */
        *oops = TRUE;

        /* Done here */
        return FALSE;
    }

    /* Hack -- Start on quiver if shooting or throwing */
    if ((mode & (QUIVER_FIRST)) && allow_quiver)
    {
        p_ptr->command_wrk = (USE_EQUIP);
    }
    /* Hack -- Start on equipment if requested */
    else if ((mode == (USE_EQUIP)) && allow_equip)
    {
        p_ptr->command_wrk = (USE_EQUIP);
    }

    /* Use inventory if allowed. */
    else if (allow_inven)
    {
        p_ptr->command_wrk = (USE_INVEN);
    }

    /* Use equipment if allowed */
    else if (allow_equip)
    {
        p_ptr->command_wrk = (USE_EQUIP);
    }

    /* Use floor if allowed */
    else if (allow_floor)
    {
        p_ptr->command_wrk = (USE_FLOOR);
    }
    /* Hack -- Use (empty) inventory if no other choices available. */
    else
    {
        p_ptr->command_wrk = (USE_INVEN);
    }
}


/**
 *
 * This code was taken from FAAngband v1.6, Modified for NPP
 *
 * FAAngband notes are below:
 *
 * Let the user select an item, save its "index"
 *
 * Return TRUE only if an acceptable item was chosen by the user.
 *
 * The selected item must satisfy the "item_tester_hook()" function,
 * if that hook is set, and the "item_tester_tval", if that value is set.
 *
 * All "item_tester" restrictions are cleared before this function returns.
 *
 * The user is allowed to choose acceptable items from the equipment,
 * inventory, or floor, respectively, if the proper flag was given,
 * and there are any acceptable items in that location.
 *
 * Any of these are displayed (even if no acceptable items are in that
 * location) if the proper flag was given.
 *
 * If there are no acceptable items available anywhere, and "str" is
 * not NULL, then it will be used as the text of a warning message
 * before the function returns.
 *
 * If a legal item is selected from the inventory, we save it in "cp"
 * directly (0 to 35), and return TRUE.
 *
 * If a legal item is selected from the floor, we save it in "cp" as
 * a negative (-1 to -511), and return TRUE.
 *
 * If no item is available, we do nothing to "cp", and we display a
 * warning message, using "str" if available, and return FALSE.
 *
 * If no item is selected, we do nothing to "cp", and return FALSE.
 *
 * If 'all squelched items' are selected we set cp to ALL_SQUELCHED and return
 * TRUE.
 *
 * Global "p_ptr->command_new" is used when viewing the inventory or equipment
 * to allow the user to enter a command while viewing those screens, and
 * also to induce "auto-enter" of stores, and other such stuff.
 *
 * Global "p_ptr->command_see" may be set before calling this function to start
 * out in "browse" mode.  It is cleared before this function returns.
 *
 * Global "p_ptr->command_wrk" is used to choose between equip/inven/floor
 * listings.  It is equal to USE_INVEN or USE_EQUIP or USE_FLOOR, except
 * when this function is first called, when it is equal to zero, which will
 * cause it to be set to USE_INVEN.
 *
 * This function has been largely rewritten for FAangband 0.3.2 using
 * Pete Mack's menu code.
 *
 * Assumes the item is on the player square
 */
bool get_item(int *cp, QString pmt, QString str, int mode)
{
    bool item;

    bool oops = FALSE;

    /* No item selected */
    item = FALSE;
    *cp = 0;

    /* Go to menu */
    item = 1; // TODO item_menu(cp, pmt, mode, &oops, p_ptr->py, p_ptr->px);

    /* Check validity */
    if (item)
    {
        if (!get_item_allow(*cp, FALSE))
        {
            item = FALSE;
        }
    }

    /* Hack -- Cancel "display" */
    p_ptr->command_see = FALSE;

    /* Forget the item_tester_tval restriction */
    item_tester_tval = 0;

    /* Forget the item_tester_hook restriction */
    item_tester_hook = NULL;

    /* Forget the item tester_swap restriction */
    item_tester_swap = FALSE;

    /* Make sure the equipment/inventory windows are up to date */
    p_ptr->redraw |= (PR_INVEN | PR_EQUIP);

    /* Warning if needed */
    if (oops && !str.isEmpty()) message(str);

    /* Result */
    return (item);
}

/*
* Same notes as above for get_item, except this is used for squares other than the one the player is on.
* This can be used on any square on the map, but it is intended for
* disarming opening chests on adjacent squares.
*/
bool get_item_beside(int *cp, QString pmt, QString str, int sq_y, int sq_x)
{
    bool item;

    bool oops = FALSE;

    /* No item selected */
    item = FALSE;
    *cp = 0;

    /* Paranoia */
    if (!in_bounds_fully(sq_y, sq_x)) oops = TRUE;

    /* Go to menu */
    else item = 1; //TODO item_menu(cp, pmt, (USE_FLOOR), &oops, sq_y, sq_x);

    /* Check validity */
    if (item)
    {
        if (!get_item_allow(*cp, TRUE))
        {
            item = FALSE;
        }
    }

    /* Hack -- Cancel "display" */
    p_ptr->command_see = FALSE;

    /* Forget the item_tester_tval restriction */
    item_tester_tval = 0;

    /* Forger the item tester_swap restriction */
    item_tester_swap = FALSE;

    /* Forget the item_tester_hook restriction */
    item_tester_hook = NULL;

    /* Warning if needed */
    if (oops && !str.isEmpty()) message(str);

    /* Result */
    return (item);
}