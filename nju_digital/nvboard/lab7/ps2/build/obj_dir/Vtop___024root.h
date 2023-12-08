// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vtop.h for the primary calling header

#ifndef VERILATED_VTOP___024ROOT_H_
#define VERILATED_VTOP___024ROOT_H_  // guard

#include "verilated.h"

class Vtop__Syms;

class Vtop___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(clk,0,0);
    VL_IN8(ps2_clk,0,0);
    VL_IN8(reset,0,0);
    VL_IN8(ps2_data,0,0);
    VL_OUT8(seg0,6,0);
    VL_OUT8(seg1,6,0);
    VL_OUT8(seg2,6,0);
    VL_OUT8(seg3,6,0);
    VL_OUT8(seg4,6,0);
    VL_OUT8(seg5,6,0);
    CData/*0:0*/ top__DOT__overflow;
    CData/*0:0*/ top__DOT__ready;
    CData/*0:0*/ top__DOT__nextdata_n;
    CData/*7:0*/ top__DOT__data;
    CData/*7:0*/ top__DOT__kbd_data;
    CData/*7:0*/ top__DOT__count_data;
    CData/*2:0*/ top__DOT__p0__DOT__w_ptr;
    CData/*2:0*/ top__DOT__p0__DOT__r_ptr;
    CData/*3:0*/ top__DOT__p0__DOT__count;
    CData/*2:0*/ top__DOT__p0__DOT__ps2_clk_sync;
    CData/*0:0*/ top__DOT__p0__DOT____Vlvbound_h1a91ade8__0;
    CData/*0:0*/ __Vdly__top__DOT__ready;
    CData/*0:0*/ __Vtrigrprev__TOP__ps2_clk;
    CData/*0:0*/ __Vtrigrprev__TOP__clk;
    CData/*0:0*/ __VactContinue;
    SData/*9:0*/ top__DOT__p0__DOT__buffer;
    IData/*31:0*/ __VstlIterCount;
    IData/*31:0*/ __VactIterCount;
    VlUnpacked<CData/*7:0*/, 8> top__DOT__p0__DOT__fifo;
    VlUnpacked<CData/*7:0*/, 256> top__DOT__to__DOT__ram;
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<2> __VactTriggered;
    VlTriggerVec<2> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vtop__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vtop___024root(Vtop__Syms* symsp, const char* v__name);
    ~Vtop___024root();
    VL_UNCOPYABLE(Vtop___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);


#endif  // guard
