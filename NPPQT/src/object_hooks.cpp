/* File: object_hooks.cpp */

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

#include "src/npp.h"

/*
 * Hook to specify "weapon"
 */
bool item_tester_hook_wieldable_ided_weapon(object_type *o_ptr)
{
    switch (o_ptr->tval)
    {
        case TV_SWORD:
        case TV_HAFTED:
        case TV_POLEARM:
        {
            if (object_known_p(o_ptr)) return (TRUE);
            else return (FALSE);
        }
    }

    return (FALSE);
}


/*
 * Hook to specify "weapon"
 */
bool item_tester_hook_wieldable_weapon(object_type *o_ptr)
{
    switch (o_ptr->tval)
    {
        case TV_SWORD:
        case TV_HAFTED:
        case TV_POLEARM:
        {
            return (TRUE);
        }
    }

    return (FALSE);
}

/*
 * Hook to specify "weapon"
 */
bool item_tester_hook_weapon(object_type *o_ptr)
{
    switch (o_ptr->tval)
    {
        case TV_SWORD:
        case TV_HAFTED:
        case TV_POLEARM:
        case TV_DIGGING:
        case TV_BOW:
        case TV_BOLT:
        case TV_ARROW:
        case TV_SHOT:
        {
            return (TRUE);
        }
    }

    return (FALSE);
}

/*
 * Hook to specify "weapon"
 */
bool item_tester_hook_ided_weapon(object_type *o_ptr)
{
    switch (o_ptr->tval)
    {
        case TV_SWORD:
        case TV_HAFTED:
        case TV_POLEARM:
        case TV_DIGGING:
        case TV_BOW:
        case TV_BOLT:
        case TV_ARROW:
        case TV_SHOT:
        {
            if (object_known_p(o_ptr)) return (TRUE);
            else return (FALSE);
        }
    }

    return (FALSE);
}



/*
 * Hook to specify "armour"
 */
bool item_tester_hook_ided_armour(object_type *o_ptr)
{
    switch (o_ptr->tval)
    {
        case TV_DRAG_ARMOR:
        case TV_DRAG_SHIELD:
        case TV_HARD_ARMOR:
        case TV_SOFT_ARMOR:
        case TV_SHIELD:
        case TV_CLOAK:
        case TV_CROWN:
        case TV_HELM:
        case TV_BOOTS:
        case TV_GLOVES:
        {
            if (object_known_p(o_ptr)) return (TRUE);
            else return (FALSE);
        }
    }

    return (FALSE);
}



/*
 * Hook to specify "armour"
 */
bool item_tester_hook_armour(object_type *o_ptr)
{
    switch (o_ptr->tval)
    {
        case TV_DRAG_ARMOR:
        case TV_DRAG_SHIELD:
        case TV_HARD_ARMOR:
        case TV_SOFT_ARMOR:
        case TV_SHIELD:
        case TV_CLOAK:
        case TV_CROWN:
        case TV_HELM:
        case TV_BOOTS:
        case TV_GLOVES:
        {
            return (TRUE);
        }
    }

    return (FALSE);
}

/*
 * Hook to specify "ammo"
 */
bool item_tester_hook_ided_ammo(object_type *o_ptr)
{
    switch (o_ptr->tval)
    {
        case TV_BOLT:
        case TV_ARROW:
        case TV_SHOT:
        {
            if (object_known_p(o_ptr)) return (TRUE);
            else return FALSE;
        }
    }

    return (FALSE);
}

/*
 * Hook to specify "ammo"
 */
bool item_tester_hook_ammo(object_type *o_ptr)
{
    switch (o_ptr->tval)
    {
        case TV_BOLT:
        case TV_ARROW:
        case TV_SHOT:
        {
            return (TRUE);
        }
    }

    return (FALSE);
}

/*
 * Hook for "get_item()".  Determine if something is rechargable.
 */
bool item_tester_hook_recharge(object_type *o_ptr)
{
    /* Recharge staffs */
    if (o_ptr->tval == TV_STAFF) return (TRUE);

    /* Recharge wands */
    if (o_ptr->tval == TV_WAND) return (TRUE);

    /* Recharge rods */
    if (o_ptr->tval == TV_ROD) return (TRUE);

    /* Nope */
    return (FALSE);
}

/*
 * The "randart" tester
 */
bool item_tester_hook_randart(object_type *o_ptr)
{
    /*Hack - don't allow cursed items*/
    if(o_ptr->ident & (IDENT_CURSED)) return (FALSE);

    /*Hack - don't allow broken items*/
    if(o_ptr->ident & (IDENT_BROKEN)) return (FALSE);

    /*Hack - don't allow unidentified items*/
    if(!(o_ptr->ident & (IDENT_KNOWN))) return (FALSE);

    /* Don't use current artifacts */
    if (o_ptr->art_num) return (FALSE);

    if (can_be_randart(o_ptr))
    {
        /*We don't use ego-items, unless dragon armor*/
        if ((o_ptr->tval != TV_DRAG_ARMOR) && (o_ptr->tval != TV_DRAG_SHIELD))
        {
            if (o_ptr->ego_num) return(FALSE);
        }

        /*don't make artifacts out of stacks of items*/
        if (o_ptr->number > 1) return (FALSE);

        /*eligible to be a randart*/
        return (TRUE);
    }

    /* Assume cannot be a randart */
    return (FALSE);
}

/*
 * The flammable book tester
 */
bool item_tester_hook_flammable_book(object_type *o_ptr)
{
    u32b f1, f2, f3, fn;

    if 	((o_ptr->tval != TV_PRAYER_BOOK) && (o_ptr->tval != TV_DRUID_BOOK) &&
         (o_ptr->tval != TV_MAGIC_BOOK)) return (FALSE);

    /* Get the "known" flags */
    object_flags(o_ptr, &f1, &f2, &f3, &fn);

    /*already flammable*/
    if (f3 & TR3_IGNORE_FIRE) return (FALSE);

    /* Immune to lava, so they should resist fire. */
    if (fn & ELEMENT_LAVA) return (FALSE);

    /* Flammable spellbook */
    return (TRUE);
}


/*
 * Hook to determine if an object is activatable
 */
bool item_tester_hook_activate(object_type *o_ptr)
{
    u32b f1, f2, f3, fn;

    /* Not known */
    if (!o_ptr->is_known()) return (FALSE);

    /* Extract the flags */
    object_flags(o_ptr, &f1, &f2, &f3, &fn);

    /* Check activation flag */
    if (f3 & (TR3_ACTIVATE)) return (TRUE);

    /* Assume not */
    return (FALSE);
}

/*
 * Determine if an object can be browsed (spellbook)
 */
bool obj_can_browse(object_type *o_ptr)
{
    return (o_ptr->can_browse());
}
