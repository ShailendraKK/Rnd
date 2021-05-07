/* Copyright (C) 2015-2016,  Netronome Systems, Inc.  All rights reserved. */

#ifndef __PIF_HEADERS_H__
#define __PIF_HEADERS_H__

/* Generated C source defining PIF headers, metadata and registers */
/* Warning: your edits to this file may be lost */

/*
 * Packet headers
 */

/* ethernet (14B) */
struct pif_header_ethernet {
    /* dstAddr [32;16] */
    unsigned int dstAddr:32;
    /* dstAddr [16;0] */
    unsigned int __dstAddr_1:16;
    /* srcAddr [16;32] */
    unsigned int srcAddr:16;
    /* srcAddr [32;0] */
    unsigned int __srcAddr_1:32;
    unsigned int etherType:16;
};

/* ethernet field accessor macros */
#define PIF_HEADER_GET_ethernet___dstAddr___0(_hdr_p) ((((_hdr_p)->dstAddr & 0xffff) << 16) | ((_hdr_p)->__dstAddr_1)) /* ethernet.dstAddr [32;0] */

#define PIF_HEADER_SET_ethernet___dstAddr___0(_hdr_p, _val) \
    do { \
        (_hdr_p)->dstAddr &= (unsigned)(0xffff0000); \
        (_hdr_p)->dstAddr |= (unsigned)((((_val) >> 16) & 0xffff)); \
        (_hdr_p)->__dstAddr_1 = (unsigned)(((_val))); \
    } while (0) /* ethernet.dstAddr[32;0] */

#define PIF_HEADER_GET_ethernet___dstAddr___1(_hdr_p) ((((_hdr_p)->dstAddr >> 16) & 0xffff)) /* ethernet.dstAddr [16;32] */

#define PIF_HEADER_SET_ethernet___dstAddr___1(_hdr_p, _val) \
    do { \
        (_hdr_p)->dstAddr &= (unsigned)(0xffff); \
        (_hdr_p)->dstAddr |= (unsigned)((((_val) & 0xffff) << 16)); \
    } while (0) /* ethernet.dstAddr[16;32] */

#define PIF_HEADER_GET_ethernet___srcAddr___0(_hdr_p) (((_hdr_p)->__srcAddr_1)) /* ethernet.srcAddr [32;0] */

#define PIF_HEADER_SET_ethernet___srcAddr___0(_hdr_p, _val) \
    do { \
        (_hdr_p)->__srcAddr_1 = (unsigned)(((_val))); \
    } while (0) /* ethernet.srcAddr[32;0] */

#define PIF_HEADER_GET_ethernet___srcAddr___1(_hdr_p) (((_hdr_p)->srcAddr)) /* ethernet.srcAddr [16;32] */

#define PIF_HEADER_SET_ethernet___srcAddr___1(_hdr_p, _val) \
    do { \
        (_hdr_p)->srcAddr = (unsigned)(((_val))); \
    } while (0) /* ethernet.srcAddr[16;32] */

#define PIF_HEADER_GET_ethernet___etherType(_hdr_p) (((_hdr_p)->etherType)) /* ethernet.etherType [16;0] */

#define PIF_HEADER_SET_ethernet___etherType(_hdr_p, _val) \
    do { \
        (_hdr_p)->etherType = (unsigned)(((_val))); \
    } while (0) /* ethernet.etherType[16;0] */


/* ipv4 (20B) */
struct pif_header_ipv4 {
    unsigned int version:4;
    unsigned int ihl:4;
    unsigned int diffserv:8;
    unsigned int totalLen:16;
    unsigned int identification:16;
    unsigned int flags:3;
    unsigned int fragOffset:13;
    unsigned int ttl:8;
    unsigned int protocol:8;
    unsigned int hdrChecksum:16;
    unsigned int srcAddr:32;
    unsigned int dstAddr:32;
};

/* ipv4 field accessor macros */
#define PIF_HEADER_GET_ipv4___version(_hdr_p) (((_hdr_p)->version)) /* ipv4.version [4;0] */

#define PIF_HEADER_SET_ipv4___version(_hdr_p, _val) \
    do { \
        (_hdr_p)->version = (unsigned)(((_val))); \
    } while (0) /* ipv4.version[4;0] */

#define PIF_HEADER_GET_ipv4___ihl(_hdr_p) (((_hdr_p)->ihl)) /* ipv4.ihl [4;0] */

#define PIF_HEADER_SET_ipv4___ihl(_hdr_p, _val) \
    do { \
        (_hdr_p)->ihl = (unsigned)(((_val))); \
    } while (0) /* ipv4.ihl[4;0] */

#define PIF_HEADER_GET_ipv4___diffserv(_hdr_p) (((_hdr_p)->diffserv)) /* ipv4.diffserv [8;0] */

#define PIF_HEADER_SET_ipv4___diffserv(_hdr_p, _val) \
    do { \
        (_hdr_p)->diffserv = (unsigned)(((_val))); \
    } while (0) /* ipv4.diffserv[8;0] */

#define PIF_HEADER_GET_ipv4___totalLen(_hdr_p) (((_hdr_p)->totalLen)) /* ipv4.totalLen [16;0] */

#define PIF_HEADER_SET_ipv4___totalLen(_hdr_p, _val) \
    do { \
        (_hdr_p)->totalLen = (unsigned)(((_val))); \
    } while (0) /* ipv4.totalLen[16;0] */

#define PIF_HEADER_GET_ipv4___identification(_hdr_p) (((_hdr_p)->identification)) /* ipv4.identification [16;0] */

#define PIF_HEADER_SET_ipv4___identification(_hdr_p, _val) \
    do { \
        (_hdr_p)->identification = (unsigned)(((_val))); \
    } while (0) /* ipv4.identification[16;0] */

#define PIF_HEADER_GET_ipv4___flags(_hdr_p) (((_hdr_p)->flags)) /* ipv4.flags [3;0] */

#define PIF_HEADER_SET_ipv4___flags(_hdr_p, _val) \
    do { \
        (_hdr_p)->flags = (unsigned)(((_val))); \
    } while (0) /* ipv4.flags[3;0] */

#define PIF_HEADER_GET_ipv4___fragOffset(_hdr_p) (((_hdr_p)->fragOffset)) /* ipv4.fragOffset [13;0] */

#define PIF_HEADER_SET_ipv4___fragOffset(_hdr_p, _val) \
    do { \
        (_hdr_p)->fragOffset = (unsigned)(((_val))); \
    } while (0) /* ipv4.fragOffset[13;0] */

#define PIF_HEADER_GET_ipv4___ttl(_hdr_p) (((_hdr_p)->ttl)) /* ipv4.ttl [8;0] */

#define PIF_HEADER_SET_ipv4___ttl(_hdr_p, _val) \
    do { \
        (_hdr_p)->ttl = (unsigned)(((_val))); \
    } while (0) /* ipv4.ttl[8;0] */

#define PIF_HEADER_GET_ipv4___protocol(_hdr_p) (((_hdr_p)->protocol)) /* ipv4.protocol [8;0] */

#define PIF_HEADER_SET_ipv4___protocol(_hdr_p, _val) \
    do { \
        (_hdr_p)->protocol = (unsigned)(((_val))); \
    } while (0) /* ipv4.protocol[8;0] */

#define PIF_HEADER_GET_ipv4___hdrChecksum(_hdr_p) (((_hdr_p)->hdrChecksum)) /* ipv4.hdrChecksum [16;0] */

#define PIF_HEADER_SET_ipv4___hdrChecksum(_hdr_p, _val) \
    do { \
        (_hdr_p)->hdrChecksum = (unsigned)(((_val))); \
    } while (0) /* ipv4.hdrChecksum[16;0] */

#define PIF_HEADER_GET_ipv4___srcAddr(_hdr_p) (((_hdr_p)->srcAddr)) /* ipv4.srcAddr [32;0] */

#define PIF_HEADER_SET_ipv4___srcAddr(_hdr_p, _val) \
    do { \
        (_hdr_p)->srcAddr = (unsigned)(((_val))); \
    } while (0) /* ipv4.srcAddr[32;0] */

#define PIF_HEADER_GET_ipv4___dstAddr(_hdr_p) (((_hdr_p)->dstAddr)) /* ipv4.dstAddr [32;0] */

#define PIF_HEADER_SET_ipv4___dstAddr(_hdr_p, _val) \
    do { \
        (_hdr_p)->dstAddr = (unsigned)(((_val))); \
    } while (0) /* ipv4.dstAddr[32;0] */


/* tcp (20B) */
struct pif_header_tcp {
    unsigned int srcPort:16;
    unsigned int dstPort:16;
    unsigned int seqNo:32;
    unsigned int ackNo:32;
    unsigned int dataOffset:4;
    unsigned int res:3;
    unsigned int ecn:3;
    unsigned int ctrl:6;
    unsigned int window:16;
    unsigned int checksum:16;
    unsigned int urgentPtr:16;
};

/* tcp field accessor macros */
#define PIF_HEADER_GET_tcp___srcPort(_hdr_p) (((_hdr_p)->srcPort)) /* tcp.srcPort [16;0] */

#define PIF_HEADER_SET_tcp___srcPort(_hdr_p, _val) \
    do { \
        (_hdr_p)->srcPort = (unsigned)(((_val))); \
    } while (0) /* tcp.srcPort[16;0] */

#define PIF_HEADER_GET_tcp___dstPort(_hdr_p) (((_hdr_p)->dstPort)) /* tcp.dstPort [16;0] */

#define PIF_HEADER_SET_tcp___dstPort(_hdr_p, _val) \
    do { \
        (_hdr_p)->dstPort = (unsigned)(((_val))); \
    } while (0) /* tcp.dstPort[16;0] */

#define PIF_HEADER_GET_tcp___seqNo(_hdr_p) (((_hdr_p)->seqNo)) /* tcp.seqNo [32;0] */

#define PIF_HEADER_SET_tcp___seqNo(_hdr_p, _val) \
    do { \
        (_hdr_p)->seqNo = (unsigned)(((_val))); \
    } while (0) /* tcp.seqNo[32;0] */

#define PIF_HEADER_GET_tcp___ackNo(_hdr_p) (((_hdr_p)->ackNo)) /* tcp.ackNo [32;0] */

#define PIF_HEADER_SET_tcp___ackNo(_hdr_p, _val) \
    do { \
        (_hdr_p)->ackNo = (unsigned)(((_val))); \
    } while (0) /* tcp.ackNo[32;0] */

#define PIF_HEADER_GET_tcp___dataOffset(_hdr_p) (((_hdr_p)->dataOffset)) /* tcp.dataOffset [4;0] */

#define PIF_HEADER_SET_tcp___dataOffset(_hdr_p, _val) \
    do { \
        (_hdr_p)->dataOffset = (unsigned)(((_val))); \
    } while (0) /* tcp.dataOffset[4;0] */

#define PIF_HEADER_GET_tcp___res(_hdr_p) (((_hdr_p)->res)) /* tcp.res [3;0] */

#define PIF_HEADER_SET_tcp___res(_hdr_p, _val) \
    do { \
        (_hdr_p)->res = (unsigned)(((_val))); \
    } while (0) /* tcp.res[3;0] */

#define PIF_HEADER_GET_tcp___ecn(_hdr_p) (((_hdr_p)->ecn)) /* tcp.ecn [3;0] */

#define PIF_HEADER_SET_tcp___ecn(_hdr_p, _val) \
    do { \
        (_hdr_p)->ecn = (unsigned)(((_val))); \
    } while (0) /* tcp.ecn[3;0] */

#define PIF_HEADER_GET_tcp___ctrl(_hdr_p) (((_hdr_p)->ctrl)) /* tcp.ctrl [6;0] */

#define PIF_HEADER_SET_tcp___ctrl(_hdr_p, _val) \
    do { \
        (_hdr_p)->ctrl = (unsigned)(((_val))); \
    } while (0) /* tcp.ctrl[6;0] */

#define PIF_HEADER_GET_tcp___window(_hdr_p) (((_hdr_p)->window)) /* tcp.window [16;0] */

#define PIF_HEADER_SET_tcp___window(_hdr_p, _val) \
    do { \
        (_hdr_p)->window = (unsigned)(((_val))); \
    } while (0) /* tcp.window[16;0] */

#define PIF_HEADER_GET_tcp___checksum(_hdr_p) (((_hdr_p)->checksum)) /* tcp.checksum [16;0] */

#define PIF_HEADER_SET_tcp___checksum(_hdr_p, _val) \
    do { \
        (_hdr_p)->checksum = (unsigned)(((_val))); \
    } while (0) /* tcp.checksum[16;0] */

#define PIF_HEADER_GET_tcp___urgentPtr(_hdr_p) (((_hdr_p)->urgentPtr)) /* tcp.urgentPtr [16;0] */

#define PIF_HEADER_SET_tcp___urgentPtr(_hdr_p, _val) \
    do { \
        (_hdr_p)->urgentPtr = (unsigned)(((_val))); \
    } while (0) /* tcp.urgentPtr[16;0] */


/*
 * Metadata
 */

/* standard_metadata (16B) */
struct pif_header_standard_metadata {
    unsigned int clone_spec:32;
    unsigned int egress_spec:16;
    unsigned int egress_port:16;
    unsigned int ingress_port:16;
    unsigned int packet_length:14;
    unsigned int checksum_error:1;
    unsigned int _padding_0:1;
    unsigned int egress_instance:10;
    unsigned int parser_error_location:8;
    unsigned int instance_type:4;
    unsigned int parser_status:3;
    unsigned int _padding_1:7;
};

/* standard_metadata field accessor macros */
#define PIF_HEADER_GET_standard_metadata___clone_spec(_hdr_p) (((_hdr_p)->clone_spec)) /* standard_metadata.clone_spec [32;0] */

#define PIF_HEADER_SET_standard_metadata___clone_spec(_hdr_p, _val) \
    do { \
        (_hdr_p)->clone_spec = (unsigned)(((_val))); \
    } while (0) /* standard_metadata.clone_spec[32;0] */

#define PIF_HEADER_GET_standard_metadata___egress_spec(_hdr_p) (((_hdr_p)->egress_spec)) /* standard_metadata.egress_spec [16;0] */

#define PIF_HEADER_SET_standard_metadata___egress_spec(_hdr_p, _val) \
    do { \
        (_hdr_p)->egress_spec = (unsigned)(((_val))); \
    } while (0) /* standard_metadata.egress_spec[16;0] */

#define PIF_HEADER_GET_standard_metadata___egress_port(_hdr_p) (((_hdr_p)->egress_port)) /* standard_metadata.egress_port [16;0] */

#define PIF_HEADER_SET_standard_metadata___egress_port(_hdr_p, _val) \
    do { \
        (_hdr_p)->egress_port = (unsigned)(((_val))); \
    } while (0) /* standard_metadata.egress_port[16;0] */

#define PIF_HEADER_GET_standard_metadata___ingress_port(_hdr_p) (((_hdr_p)->ingress_port)) /* standard_metadata.ingress_port [16;0] */

#define PIF_HEADER_SET_standard_metadata___ingress_port(_hdr_p, _val) \
    do { \
        (_hdr_p)->ingress_port = (unsigned)(((_val))); \
    } while (0) /* standard_metadata.ingress_port[16;0] */

#define PIF_HEADER_GET_standard_metadata___packet_length(_hdr_p) (((_hdr_p)->packet_length)) /* standard_metadata.packet_length [14;0] */

#define PIF_HEADER_SET_standard_metadata___packet_length(_hdr_p, _val) \
    do { \
        (_hdr_p)->packet_length = (unsigned)(((_val))); \
    } while (0) /* standard_metadata.packet_length[14;0] */

#define PIF_HEADER_GET_standard_metadata___checksum_error(_hdr_p) (((_hdr_p)->checksum_error)) /* standard_metadata.checksum_error [1;0] */

#define PIF_HEADER_SET_standard_metadata___checksum_error(_hdr_p, _val) \
    do { \
        (_hdr_p)->checksum_error = (unsigned)(((_val))); \
    } while (0) /* standard_metadata.checksum_error[1;0] */

#define PIF_HEADER_GET_standard_metadata____padding_0(_hdr_p) (((_hdr_p)->_padding_0)) /* standard_metadata._padding_0 [1;0] */

#define PIF_HEADER_SET_standard_metadata____padding_0(_hdr_p, _val) \
    do { \
        (_hdr_p)->_padding_0 = (unsigned)(((_val))); \
    } while (0) /* standard_metadata._padding_0[1;0] */

#define PIF_HEADER_GET_standard_metadata___egress_instance(_hdr_p) (((_hdr_p)->egress_instance)) /* standard_metadata.egress_instance [10;0] */

#define PIF_HEADER_SET_standard_metadata___egress_instance(_hdr_p, _val) \
    do { \
        (_hdr_p)->egress_instance = (unsigned)(((_val))); \
    } while (0) /* standard_metadata.egress_instance[10;0] */

#define PIF_HEADER_GET_standard_metadata___parser_error_location(_hdr_p) (((_hdr_p)->parser_error_location)) /* standard_metadata.parser_error_location [8;0] */

#define PIF_HEADER_SET_standard_metadata___parser_error_location(_hdr_p, _val) \
    do { \
        (_hdr_p)->parser_error_location = (unsigned)(((_val))); \
    } while (0) /* standard_metadata.parser_error_location[8;0] */

#define PIF_HEADER_GET_standard_metadata___instance_type(_hdr_p) (((_hdr_p)->instance_type)) /* standard_metadata.instance_type [4;0] */

#define PIF_HEADER_SET_standard_metadata___instance_type(_hdr_p, _val) \
    do { \
        (_hdr_p)->instance_type = (unsigned)(((_val))); \
    } while (0) /* standard_metadata.instance_type[4;0] */

#define PIF_HEADER_GET_standard_metadata___parser_status(_hdr_p) (((_hdr_p)->parser_status)) /* standard_metadata.parser_status [3;0] */

#define PIF_HEADER_SET_standard_metadata___parser_status(_hdr_p, _val) \
    do { \
        (_hdr_p)->parser_status = (unsigned)(((_val))); \
    } while (0) /* standard_metadata.parser_status[3;0] */

#define PIF_HEADER_GET_standard_metadata____padding_1(_hdr_p) (((_hdr_p)->_padding_1)) /* standard_metadata._padding_1 [7;0] */

#define PIF_HEADER_SET_standard_metadata____padding_1(_hdr_p, _val) \
    do { \
        (_hdr_p)->_padding_1 = (unsigned)(((_val))); \
    } while (0) /* standard_metadata._padding_1[7;0] */


/* ingress::scalars (8B) */
struct pif_header_ingress__scalars {
    unsigned int metadata__action_select2:14;
    unsigned int metadata__action_select3:14;
    unsigned int _padding_0:4;
    unsigned int metadata__action_select1:14;
    unsigned int _padding_1:18;
};

/* ingress::scalars field accessor macros */
#define PIF_HEADER_GET_ingress__scalars___metadata__action_select2(_hdr_p) (((_hdr_p)->metadata__action_select2)) /* ingress::scalars.metadata__action_select2 [14;0] */

#define PIF_HEADER_SET_ingress__scalars___metadata__action_select2(_hdr_p, _val) \
    do { \
        (_hdr_p)->metadata__action_select2 = (unsigned)(((_val))); \
    } while (0) /* ingress::scalars.metadata__action_select2[14;0] */

#define PIF_HEADER_GET_ingress__scalars___metadata__action_select3(_hdr_p) (((_hdr_p)->metadata__action_select3)) /* ingress::scalars.metadata__action_select3 [14;0] */

#define PIF_HEADER_SET_ingress__scalars___metadata__action_select3(_hdr_p, _val) \
    do { \
        (_hdr_p)->metadata__action_select3 = (unsigned)(((_val))); \
    } while (0) /* ingress::scalars.metadata__action_select3[14;0] */

#define PIF_HEADER_GET_ingress__scalars____padding_0(_hdr_p) (((_hdr_p)->_padding_0)) /* ingress::scalars._padding_0 [4;0] */

#define PIF_HEADER_SET_ingress__scalars____padding_0(_hdr_p, _val) \
    do { \
        (_hdr_p)->_padding_0 = (unsigned)(((_val))); \
    } while (0) /* ingress::scalars._padding_0[4;0] */

#define PIF_HEADER_GET_ingress__scalars___metadata__action_select1(_hdr_p) (((_hdr_p)->metadata__action_select1)) /* ingress::scalars.metadata__action_select1 [14;0] */

#define PIF_HEADER_SET_ingress__scalars___metadata__action_select1(_hdr_p, _val) \
    do { \
        (_hdr_p)->metadata__action_select1 = (unsigned)(((_val))); \
    } while (0) /* ingress::scalars.metadata__action_select1[14;0] */

#define PIF_HEADER_GET_ingress__scalars____padding_1(_hdr_p) (((_hdr_p)->_padding_1)) /* ingress::scalars._padding_1 [18;0] */

#define PIF_HEADER_SET_ingress__scalars____padding_1(_hdr_p, _val) \
    do { \
        (_hdr_p)->_padding_1 = (unsigned)(((_val))); \
    } while (0) /* ingress::scalars._padding_1[18;0] */



/*
 * Registers
 */

#endif /* __PIF_HEADERS_H__ */
