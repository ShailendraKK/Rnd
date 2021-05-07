/* Copyright (C) 2015-2016,  Netronome Systems, Inc.  All rights reserved. */

#ifndef __PIF_PARREP_H__
#define __PIF_PARREP_H__

/* Generated C source defining layout of parsed representation */
/* Warning: your edits to this file may be lost */

/*
 * Parsed representation control data
 */
struct pif_parrep_ctldata {
    unsigned int valid:1;
    unsigned int t0_valid:1;
    unsigned int t0_dirty:1;
    unsigned int t0_orig_len:1;
    unsigned int t1_valid:1;
    unsigned int t1_dirty:1;
    unsigned int t1_orig_len:1;
    unsigned int t2_valid:1;
    unsigned int t2_dirty:1;
    unsigned int t2_orig_len:1;
};

#define PIF_PARREP_CTLDATA_OFF_LW 0
#define PIF_PARREP_CTLDATA_LEN_LW 1

/*
 * Parsed representation layout
 */

/* Parsed represention tier types */

/* Parse state values */
#define PIF_PARREP_STATE_exit -1
#define PIF_PARREP_STATE_start 0
#define PIF_PARREP_STATE_parse_ipv4 1
#define PIF_PARREP_STATE_parse_tcp 2
#define PIF_PARREP_MAX_STATE 2

/* Tier 0 */
#define PIF_PARREP_T0_OFF_LW 1
#define PIF_PARREP_T0_LEN_LW 4
#define PIF_PARREP_ethernet_OFF_LW (PIF_PARREP_T0_OFF_LW)
#define PIF_PARREP_ethernet_LEN_LW 4
#define PIF_PARREP_ethernet_LEN_B 14

/* Tier 1 */
#define PIF_PARREP_T1_OFF_LW 5
#define PIF_PARREP_T1_LEN_LW 5
#define PIF_PARREP_ipv4_OFF_LW (PIF_PARREP_T1_OFF_LW)
#define PIF_PARREP_ipv4_LEN_LW 5
#define PIF_PARREP_ipv4_LEN_B 20

/* Tier 2 */
#define PIF_PARREP_T2_OFF_LW 10
#define PIF_PARREP_T2_LEN_LW 5
#define PIF_PARREP_tcp_OFF_LW (PIF_PARREP_T2_OFF_LW)
#define PIF_PARREP_tcp_LEN_LW 5
#define PIF_PARREP_tcp_LEN_B 20

/*
 * Metadata
 */

#define PIF_PARREP_standard_metadata_OFF_LW 15
#define PIF_PARREP_standard_metadata_LEN_LW 4

#define PIF_PARREP_ingress__scalars_OFF_LW 19
#define PIF_PARREP_ingress__scalars_LEN_LW 2

#define PIF_PARREP_LEN_LW 21

/* Parsing branches to a constant control entry point */
#define PIF_PARREP_NO_VARIABLE_EXIT

/* Control data macros */
#define PIF_PARREP_VALID(_ctl) (_ctl->valid)
#define PIF_PARREP_SET_VALID(_ctl) \
    do { _ctl->valid = 1; } while (0)

/* Tier 0 */
#define PIF_PARREP_T0_TYPE(ctl) ( ((ctl)->t0_type))
#define PIF_PARREP_T0_VALID(ctl) ( ((ctl)->t0_valid))
#define PIF_PARREP_ethernet_VALID(ctl) ( ((ctl)->t0_valid) )
#define PIF_PARREP_SET_ethernet_VALID(ctl) \
    do { \
        (ctl)->t0_valid = 1; \
    } while(0);
#define PIF_PARREP_CLEAR_ethernet_VALID(ctl) \
    do { \
        (ctl)->t0_valid = 0; \
    } while(0);

#define PIF_PARREP_ethernet_DIRTY(_ctl) ((_ctl)->t0_dirty)
#define PIF_PARREP_T0_DIRTY(_ctl) ((_ctl)->t0_dirty)
#define PIF_PARREP_CLEAR_T0_DIRTY(_ctl)     do { \
        (_ctl)->t0_dirty = 0; \
    } while(0);
#define PIF_PARREP_SET_T0_DIRTY(_ctl)     do { \
        (_ctl)->t0_dirty = 0; \
    } while(0);
#define PIF_PARREP_SET_ethernet_DIRTY(_ctl) \
    do { \
        (_ctl)->t0_dirty = 1; \
    } while(0);

#define PIF_PARREP_T0_ORIG_LEN(ctl) (((ctl)->t0_orig_len) ? PIF_PARREP_ethernet_LEN_B : 0)
#define PIF_PARREP_SET_T0_ORIG_LEN(ctl, len) \
    do { \
        (ctl)->t0_orig_len = (len == 0 ? 0 : 1); \
    } while(0);
#define PIF_PARREP_ethernet_ORIG_LEN(ctl) (((ctl)->t0_orig_len) ? PIF_PARREP_ethernet_LEN_B : 0)
#define PIF_PARREP_CLEAR_ethernet_ORIG_LEN(ctl) \
    do { \
        (ctl)->t0_orig_len = 0; \
    } while(0);
#define PIF_PARREP_SET_ethernet_ORIG_LEN(ctl, len) \
    do { \
        (ctl)->t0_orig_len = 1; \
    } while(0);

/* Tier 1 */
#define PIF_PARREP_T1_TYPE(ctl) ( ((ctl)->t1_type))
#define PIF_PARREP_T1_VALID(ctl) ( ((ctl)->t1_valid))
#define PIF_PARREP_ipv4_VALID(ctl) ( ((ctl)->t1_valid) )
#define PIF_PARREP_SET_ipv4_VALID(ctl) \
    do { \
        (ctl)->t1_valid = 1; \
    } while(0);
#define PIF_PARREP_CLEAR_ipv4_VALID(ctl) \
    do { \
        (ctl)->t1_valid = 0; \
    } while(0);

#define PIF_PARREP_ipv4_DIRTY(_ctl) ((_ctl)->t1_dirty)
#define PIF_PARREP_T1_DIRTY(_ctl) ((_ctl)->t1_dirty)
#define PIF_PARREP_CLEAR_T1_DIRTY(_ctl)     do { \
        (_ctl)->t1_dirty = 0; \
    } while(0);
#define PIF_PARREP_SET_T1_DIRTY(_ctl)     do { \
        (_ctl)->t1_dirty = 0; \
    } while(0);
#define PIF_PARREP_SET_ipv4_DIRTY(_ctl) \
    do { \
        (_ctl)->t1_dirty = 1; \
    } while(0);

#define PIF_PARREP_T1_ORIG_LEN(ctl) (((ctl)->t1_orig_len) ? PIF_PARREP_ipv4_LEN_B : 0)
#define PIF_PARREP_SET_T1_ORIG_LEN(ctl, len) \
    do { \
        (ctl)->t1_orig_len = (len == 0 ? 0 : 1); \
    } while(0);
#define PIF_PARREP_ipv4_ORIG_LEN(ctl) (((ctl)->t1_orig_len) ? PIF_PARREP_ipv4_LEN_B : 0)
#define PIF_PARREP_CLEAR_ipv4_ORIG_LEN(ctl) \
    do { \
        (ctl)->t1_orig_len = 0; \
    } while(0);
#define PIF_PARREP_SET_ipv4_ORIG_LEN(ctl, len) \
    do { \
        (ctl)->t1_orig_len = 1; \
    } while(0);

/* Tier 2 */
#define PIF_PARREP_T2_TYPE(ctl) ( ((ctl)->t2_type))
#define PIF_PARREP_T2_VALID(ctl) ( ((ctl)->t2_valid))
#define PIF_PARREP_tcp_VALID(ctl) ( ((ctl)->t2_valid) )
#define PIF_PARREP_SET_tcp_VALID(ctl) \
    do { \
        (ctl)->t2_valid = 1; \
    } while(0);
#define PIF_PARREP_CLEAR_tcp_VALID(ctl) \
    do { \
        (ctl)->t2_valid = 0; \
    } while(0);

#define PIF_PARREP_tcp_DIRTY(_ctl) ((_ctl)->t2_dirty)
#define PIF_PARREP_T2_DIRTY(_ctl) ((_ctl)->t2_dirty)
#define PIF_PARREP_CLEAR_T2_DIRTY(_ctl)     do { \
        (_ctl)->t2_dirty = 0; \
    } while(0);
#define PIF_PARREP_SET_T2_DIRTY(_ctl)     do { \
        (_ctl)->t2_dirty = 0; \
    } while(0);
#define PIF_PARREP_SET_tcp_DIRTY(_ctl) \
    do { \
        (_ctl)->t2_dirty = 1; \
    } while(0);

#define PIF_PARREP_T2_ORIG_LEN(ctl) (((ctl)->t2_orig_len) ? PIF_PARREP_tcp_LEN_B : 0)
#define PIF_PARREP_SET_T2_ORIG_LEN(ctl, len) \
    do { \
        (ctl)->t2_orig_len = (len == 0 ? 0 : 1); \
    } while(0);
#define PIF_PARREP_tcp_ORIG_LEN(ctl) (((ctl)->t2_orig_len) ? PIF_PARREP_tcp_LEN_B : 0)
#define PIF_PARREP_CLEAR_tcp_ORIG_LEN(ctl) \
    do { \
        (ctl)->t2_orig_len = 0; \
    } while(0);
#define PIF_PARREP_SET_tcp_ORIG_LEN(ctl, len) \
    do { \
        (ctl)->t2_orig_len = 1; \
    } while(0);



void pif_value_set_scan_configs();

#endif /* __PIF_PARREP_H__ */
