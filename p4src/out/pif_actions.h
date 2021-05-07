/* Copyright (C) 2015-2016,  Netronome Systems, Inc.  All rights reserved. */

#ifndef __PIF_ACTIONS_H__
#define __PIF_ACTIONS_H__

/* Warning: generated file - your edits to this file may be lost */

/* Action operation IDs */

#define PIF_ACTION_ID_ingress__act 0
#define PIF_ACTION_ID_ingress__set_actionselect2 1
#define PIF_ACTION_ID_ingress__set_actionselect3 2
#define PIF_ACTION_ID_ingress__set_actionselect1 3
#define PIF_ACTION_ID_ingress__ipv4_forward 4
#define PIF_ACTION_ID_ingress__drop 5
#define PIF_ACTION_ID_MAX 5

/* Match action data structure */

__packed struct pif_action_actiondata_ingress__act {
    uint32_t __pif_rule_no;
    uint32_t __pif_table_no;
};

__packed struct pif_action_actiondata_ingress__set_actionselect2 {
    uint32_t __pif_rule_no;
    uint32_t __pif_table_no;
    uint8_t __pif_padding[2]; /* padding */
    uint16_t featurevalue2;
};

__packed struct pif_action_actiondata_ingress__set_actionselect3 {
    uint32_t __pif_rule_no;
    uint32_t __pif_table_no;
    uint8_t __pif_padding[2]; /* padding */
    uint16_t featurevalue3;
};

__packed struct pif_action_actiondata_ingress__set_actionselect1 {
    uint32_t __pif_rule_no;
    uint32_t __pif_table_no;
    uint8_t __pif_padding[2]; /* padding */
    uint16_t featurevalue1;
};

__packed struct pif_action_actiondata_ingress__ipv4_forward {
    uint32_t dstAddr_1; /* dstAddr[48:16] */
    uint32_t __pif_rule_no;
    uint32_t __pif_table_no;
    uint16_t port;
    uint16_t dstAddr_0; /* dstAddr[16:0] */
};

__packed struct pif_action_actiondata_ingress__drop {
    uint32_t __pif_rule_no;
    uint32_t __pif_table_no;
};

#endif /* __PIF_ACTIONS_H__ */
