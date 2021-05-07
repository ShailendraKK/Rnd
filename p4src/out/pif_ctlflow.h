/* Copyright (C) 2015-2016,  Netronome Systems, Inc.  All rights reserved. */

#ifndef __PIF_CTLFLOW_H__
#define __PIF_CTLFLOW_H__

/* Defines for checking flow presence */
#define PIF_CTLFLOW_HAS_ingress_flow

#define PIF_CTLFLOW_STATE_ingress 0
#define PIF_CTLFLOW_STATE_accept 0
/* Control state nodes for ingress_flow */
#define PIF_CTLFLOW_STATE_ingress_flow_DONE -1
#define PIF_CTLFLOW_STATE_ingress_flow_exit_control_flow -1
#define PIF_CTLFLOW_STATE_ingress_flow 0

#define PIF_CTLFLOW_STATE_ingress_flow_ingress__feature2_exact 0
#define PIF_CTLFLOW_STATE_ingress_flow_ingress__feature3_exact 1
#define PIF_CTLFLOW_STATE_ingress_flow__condition_1 2
#define PIF_CTLFLOW_STATE_ingress_flow_ingress__ipv4_exact 3
#define PIF_CTLFLOW_STATE_ingress_flow_ingress__tbl_act 4
#define PIF_CTLFLOW_STATE_ingress_flow__condition_0 5
#define PIF_CTLFLOW_STATE_ingress_flow_ingress__feature1_exact 6

/* Unified control state numbers */
#define PIF_CTLFLOW_STATE_ingress__feature2_exact 0
#define PIF_CTLFLOW_STATE_ingress__feature3_exact 1
#define PIF_CTLFLOW_STATE__condition_1 2
#define PIF_CTLFLOW_STATE_ingress__ipv4_exact 3
#define PIF_CTLFLOW_STATE_ingress__tbl_act 4
#define PIF_CTLFLOW_STATE__condition_0 5
#define PIF_CTLFLOW_STATE_ingress__feature1_exact 6

/* Control flow entry points  */
int pif_ctlflow_ingress_flow(int *start_state, __lmem uint32_t *_pif_parrep, __mem __addr40 uint32_t *actbuf, unsigned int actbuf_off);
int pif_ctlflow_egress_flow(int *start_state, __lmem uint32_t *_pif_parrep, __mem __addr40 uint32_t *actbuf, unsigned int actbuf_off);

#endif /* __PIF_CTLFLOW_H__ */
