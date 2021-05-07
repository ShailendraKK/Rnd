/* Copyright (C) 2015-2016,  Netronome Systems, Inc.  All rights reserved. */

#include <nfp/me.h>
#include "pif_common.h"

/****************************************
 * ingress_flow                         *
 ****************************************/

/* State transition functions */

static int handle_ingress_flow_ingress__feature2_exact(__lmem uint32_t *_pif_parrep, __mem __addr40 uint32_t *actbuf, unsigned int actbuf_off, int *actlen, int *state)
{
    __gpr int action_id, ret;
    int next_state = PIF_CTLFLOW_STATE_ingress_flow_DONE;

#ifdef PIF_DEBUG
    __debug_label("pif_ctlflow_state_ingress_flow_ingress__feature2_exact");
#endif

    {
        struct pif_lookup_result result;
        result = pif_lookup(PIF_TABLE_ID_ingress__feature2_exact, _pif_parrep, actbuf, actbuf_off);
        action_id = result.action_id;
        *actlen = result.action_len;
    }

    next_state = PIF_CTLFLOW_STATE_ingress_flow_ingress__feature3_exact; /* always */

    if (*actlen > 0) {
        __critical_path();
        ret = pif_action_execute(_pif_parrep, actbuf, actbuf_off, *actlen);
        if (ret < 0)
            return ret;
        __critical_path();
        if (ret > 0)
            next_state = PIF_CTLFLOW_STATE_ingress_flow_DONE;
        __critical_path();
    }

    *state = next_state;
    return 0;
}

static int handle_ingress_flow_ingress__feature3_exact(__lmem uint32_t *_pif_parrep, __mem __addr40 uint32_t *actbuf, unsigned int actbuf_off, int *actlen, int *state)
{
    __gpr int action_id, ret;
    int next_state = PIF_CTLFLOW_STATE_ingress_flow_DONE;

#ifdef PIF_DEBUG
    __debug_label("pif_ctlflow_state_ingress_flow_ingress__feature3_exact");
#endif

    {
        struct pif_lookup_result result;
        result = pif_lookup(PIF_TABLE_ID_ingress__feature3_exact, _pif_parrep, actbuf, actbuf_off);
        action_id = result.action_id;
        *actlen = result.action_len;
    }

    next_state = PIF_CTLFLOW_STATE_ingress_flow_ingress__ipv4_exact; /* always */

    if (*actlen > 0) {
        __critical_path();
        ret = pif_action_execute(_pif_parrep, actbuf, actbuf_off, *actlen);
        if (ret < 0)
            return ret;
        __critical_path();
        if (ret > 0)
            next_state = PIF_CTLFLOW_STATE_ingress_flow_DONE;
        __critical_path();
    }

    *state = next_state;
    return 0;
}

static int handle_ingress_flow__condition_1(__lmem uint32_t *_pif_parrep)
{
    unsigned int pif_expression__condition_1_register_0;
    __lmem struct pif_header_ipv4 *ipv4;

#ifdef PIF_DEBUG
    __debug_label("pif_ctlflow_state_ingress_flow__condition_1");
#endif

    ipv4 = (__lmem struct pif_header_ipv4 *) (_pif_parrep + PIF_PARREP_ipv4_OFF_LW);

    //expression _condition_1: ((ipv4.protocol) == (6))
    {
    unsigned int pif_expression__condition_1_register_1;
    unsigned int pif_expression__condition_1_register_2;
    unsigned int pif_expression__condition_1_register_3;
    //subexpression 2: 6
    // constant : 0x6

    //subexpression 0: (ipv4.protocol)==(6)
    pif_expression__condition_1_register_1 = ipv4->protocol;
    pif_expression__condition_1_register_2 = 0x6;
    /* implicit cast 3 -> 8 */
    pif_expression__condition_1_register_3 = pif_expression__condition_1_register_2 & 0x7;
    pif_expression__condition_1_register_0 = (pif_expression__condition_1_register_1 == pif_expression__condition_1_register_3);
    }

    if (pif_expression__condition_1_register_0)
        return PIF_CTLFLOW_STATE_ingress_flow_ingress__feature2_exact;
    else
        return PIF_CTLFLOW_STATE_ingress_flow_ingress__tbl_act;
}

static int handle_ingress_flow_ingress__ipv4_exact(__lmem uint32_t *_pif_parrep, __mem __addr40 uint32_t *actbuf, unsigned int actbuf_off, int *actlen, int *state)
{
    __gpr int action_id, ret;
    int next_state = PIF_CTLFLOW_STATE_ingress_flow_DONE;

#ifdef PIF_DEBUG
    __debug_label("pif_ctlflow_state_ingress_flow_ingress__ipv4_exact");
#endif

    {
        struct pif_lookup_result result;
        result = pif_lookup(PIF_TABLE_ID_ingress__ipv4_exact, _pif_parrep, actbuf, actbuf_off);
        action_id = result.action_id;
        *actlen = result.action_len;
    }

    next_state = PIF_CTLFLOW_STATE_ingress_flow_exit_control_flow; /* always */

    if (*actlen > 0) {
        __critical_path();
        ret = pif_action_execute(_pif_parrep, actbuf, actbuf_off, *actlen);
        if (ret < 0)
            return ret;
        __critical_path();
        if (ret > 0)
            next_state = PIF_CTLFLOW_STATE_ingress_flow_DONE;
        __critical_path();
    }

    *state = next_state;
    return 0;
}

static int handle_ingress_flow_ingress__tbl_act(__lmem uint32_t *_pif_parrep, __mem __addr40 uint32_t *actbuf, unsigned int actbuf_off, int *actlen, int *state)
{
    __gpr int action_id, ret;
    int next_state = PIF_CTLFLOW_STATE_ingress_flow_DONE;

#ifdef PIF_DEBUG
    __debug_label("pif_ctlflow_state_ingress_flow_ingress__tbl_act");
#endif

    {
        struct pif_action_actiondata_ingress__act actdata;
        __xwrite struct {
            union pif_action_opdata opdata;
            struct pif_action_actiondata_ingress__act actdata;
            } wr_buf;

        wr_buf.opdata.val32 = (PIF_ACTION_ID_ingress__act << PIF_ACTION_OPDATA_ACTION_ID_off) | ((sizeof(actdata) / 4) << PIF_ACTION_OPDATA_ACTDATA_CNT_off);
        actdata.__pif_table_no = 0xffffffff;
        actdata.__pif_rule_no = 0x0;
        wr_buf.actdata = actdata;

        mem_write32(&wr_buf,
                    actbuf + actbuf_off,
                    sizeof(wr_buf));
        *actlen = sizeof(wr_buf)/4;
    }

    next_state = PIF_CTLFLOW_STATE_ingress_flow_ingress__ipv4_exact; /* always */

    if (*actlen > 0) {
        __critical_path();
        ret = pif_action_execute(_pif_parrep, actbuf, actbuf_off, *actlen);
        if (ret < 0)
            return ret;
        __critical_path();
        if (ret > 0)
            next_state = PIF_CTLFLOW_STATE_ingress_flow_DONE;
        __critical_path();
    }

    *state = next_state;
    return 0;
}

static int handle_ingress_flow__condition_0(__lmem uint32_t *_pif_parrep)
{
    unsigned int pif_expression__condition_0_register_0;
    __lmem struct pif_parrep_ctldata *prdata = (__lmem struct pif_parrep_ctldata *)(_pif_parrep + PIF_PARREP_CTLDATA_OFF_LW);

#ifdef PIF_DEBUG
    __debug_label("pif_ctlflow_state_ingress_flow__condition_0");
#endif

    //expression _condition_0: (valid(ipv4))
    {
    //subexpression 0: valid(ipv4)
    pif_expression__condition_0_register_0 = PIF_PARREP_ipv4_VALID(prdata);
    }

    if (pif_expression__condition_0_register_0)
        return PIF_CTLFLOW_STATE_ingress_flow_ingress__feature1_exact;
    else
        return PIF_CTLFLOW_STATE_ingress_flow_ingress__ipv4_exact;
}

static int handle_ingress_flow_ingress__feature1_exact(__lmem uint32_t *_pif_parrep, __mem __addr40 uint32_t *actbuf, unsigned int actbuf_off, int *actlen, int *state)
{
    __gpr int action_id, ret;
    int next_state = PIF_CTLFLOW_STATE_ingress_flow_DONE;

#ifdef PIF_DEBUG
    __debug_label("pif_ctlflow_state_ingress_flow_ingress__feature1_exact");
#endif

    {
        struct pif_lookup_result result;
        result = pif_lookup(PIF_TABLE_ID_ingress__feature1_exact, _pif_parrep, actbuf, actbuf_off);
        action_id = result.action_id;
        *actlen = result.action_len;
    }

    next_state = PIF_CTLFLOW_STATE_ingress_flow__condition_1; /* always */

    if (*actlen > 0) {
        __critical_path();
        ret = pif_action_execute(_pif_parrep, actbuf, actbuf_off, *actlen);
        if (ret < 0)
            return ret;
        __critical_path();
        if (ret > 0)
            next_state = PIF_CTLFLOW_STATE_ingress_flow_DONE;
        __critical_path();
    }

    *state = next_state;
    return 0;
}

/* Control flow entry point */

int pif_ctlflow_ingress_flow(int *start_state, __lmem uint32_t *_pif_parrep, __mem __addr40 uint32_t *actbuf, unsigned int actbuf_off)
{
    __gpr int actlen, totlen = 0;
    __gpr int ret;
    int pif_ctlflow_state_ingress_flow = PIF_CTLFLOW_STATE_ingress_flow__condition_0;

    while (pif_ctlflow_state_ingress_flow != PIF_CTLFLOW_STATE_ingress_flow_DONE) {
        PIF_DEBUG_SET_STATE(PIF_DEBUG_STATE_CONTROL, ((0 << 16) + pif_ctlflow_state_ingress_flow));
#ifdef PIF_DEBUG
        __debug_label("pif_ctlflow_state_ingress_flow");
#endif
        switch (pif_ctlflow_state_ingress_flow) {
        case PIF_CTLFLOW_STATE_ingress_flow_ingress__feature2_exact:
            ret = handle_ingress_flow_ingress__feature2_exact(_pif_parrep, actbuf, actbuf_off + totlen, (int *)&actlen, (int *)&pif_ctlflow_state_ingress_flow);
            break;
        case PIF_CTLFLOW_STATE_ingress_flow_ingress__feature3_exact:
            ret = handle_ingress_flow_ingress__feature3_exact(_pif_parrep, actbuf, actbuf_off + totlen, (int *)&actlen, (int *)&pif_ctlflow_state_ingress_flow);
            break;
        case PIF_CTLFLOW_STATE_ingress_flow__condition_1:
            pif_ctlflow_state_ingress_flow = handle_ingress_flow__condition_1(_pif_parrep);
            continue;
        case PIF_CTLFLOW_STATE_ingress_flow_ingress__ipv4_exact:
            ret = handle_ingress_flow_ingress__ipv4_exact(_pif_parrep, actbuf, actbuf_off + totlen, (int *)&actlen, (int *)&pif_ctlflow_state_ingress_flow);
            break;
        case PIF_CTLFLOW_STATE_ingress_flow_ingress__tbl_act:
            ret = handle_ingress_flow_ingress__tbl_act(_pif_parrep, actbuf, actbuf_off + totlen, (int *)&actlen, (int *)&pif_ctlflow_state_ingress_flow);
            break;
        case PIF_CTLFLOW_STATE_ingress_flow__condition_0:
            pif_ctlflow_state_ingress_flow = handle_ingress_flow__condition_0(_pif_parrep);
            continue;
        case PIF_CTLFLOW_STATE_ingress_flow_ingress__feature1_exact:
            ret = handle_ingress_flow_ingress__feature1_exact(_pif_parrep, actbuf, actbuf_off + totlen, (int *)&actlen, (int *)&pif_ctlflow_state_ingress_flow);
            break;
        }
        if (actlen < 0) /* error! */
            return actlen & ((~(1 << PIF_LOOKUP_ERROR_BIT)));
        __critical_path();
        totlen += actlen;
        if (ret < 0)
            return -totlen;
    }

    return totlen;
}

/* Empty control flow */
int pif_ctlflow_egress_flow(int *start_state, __lmem uint32_t *_pif_parrep, __mem __addr40 uint32_t *actbuf, unsigned int actbuf_off)
{
    return 0;
}
