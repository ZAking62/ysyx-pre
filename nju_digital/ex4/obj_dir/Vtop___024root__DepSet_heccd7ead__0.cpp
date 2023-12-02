// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "verilated.h"

#include "Vtop___024root.h"

void Vtop___024root___eval_act(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_act\n"); );
}

VL_INLINE_OPT void Vtop___024root___nba_sequent__TOP__0(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__0\n"); );
    // Init
    IData/*31:0*/ __Vdly__top__DOT__count_clk;
    __Vdly__top__DOT__count_clk = 0;
    // Body
    __Vdly__top__DOT__count_clk = vlSelf->top__DOT__count_clk;
    if ((0x17d783fU == vlSelf->top__DOT__count_clk)) {
        vlSelf->top__DOT__clk_1s = (1U & (~ (IData)(vlSelf->top__DOT__clk_1s)));
        __Vdly__top__DOT__count_clk = 0U;
    } else {
        __Vdly__top__DOT__count_clk = ((IData)(1U) 
                                       + vlSelf->top__DOT__count_clk);
    }
    vlSelf->top__DOT__count_clk = __Vdly__top__DOT__count_clk;
}

extern const VlUnpacked<CData/*6:0*/, 16> Vtop__ConstPool__TABLE_hb2a417e2_0;

VL_INLINE_OPT void Vtop___024root___nba_sequent__TOP__1(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__1\n"); );
    // Init
    CData/*3:0*/ __Vtableidx1;
    __Vtableidx1 = 0;
    CData/*3:0*/ __Vtableidx2;
    __Vtableidx2 = 0;
    CData/*3:0*/ __Vdly__top__DOT__q1;
    __Vdly__top__DOT__q1 = 0;
    CData/*3:0*/ __Vdly__top__DOT__q2;
    __Vdly__top__DOT__q2 = 0;
    // Body
    __Vdly__top__DOT__q2 = vlSelf->top__DOT__q2;
    __Vdly__top__DOT__q1 = vlSelf->top__DOT__q1;
    if (vlSelf->areset) {
        __Vdly__top__DOT__q1 = 0U;
        __Vdly__top__DOT__q2 = 0U;
    } else if (vlSelf->en) {
        if (((9U == (IData)(vlSelf->top__DOT__q2)) 
             & (9U == (IData)(vlSelf->top__DOT__q1)))) {
            __Vdly__top__DOT__q2 = 0U;
            __Vdly__top__DOT__q1 = 0U;
        } else if (((9U != (IData)(vlSelf->top__DOT__q2)) 
                    & (9U == (IData)(vlSelf->top__DOT__q1)))) {
            __Vdly__top__DOT__q2 = (0xfU & ((IData)(1U) 
                                            + (IData)(vlSelf->top__DOT__q2)));
            __Vdly__top__DOT__q1 = 0U;
        } else {
            __Vdly__top__DOT__q1 = (0xfU & ((IData)(1U) 
                                            + (IData)(vlSelf->top__DOT__q1)));
        }
    } else {
        __Vdly__top__DOT__q2 = vlSelf->top__DOT__q2;
        __Vdly__top__DOT__q1 = vlSelf->top__DOT__q1;
    }
    vlSelf->top__DOT__q1 = __Vdly__top__DOT__q1;
    vlSelf->top__DOT__q2 = __Vdly__top__DOT__q2;
    __Vtableidx1 = vlSelf->top__DOT__q1;
    vlSelf->h1 = Vtop__ConstPool__TABLE_hb2a417e2_0
        [__Vtableidx1];
    __Vtableidx2 = vlSelf->top__DOT__q2;
    vlSelf->h2 = Vtop__ConstPool__TABLE_hb2a417e2_0
        [__Vtableidx2];
}

void Vtop___024root___eval_nba(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_nba\n"); );
    // Body
    if (vlSelf->__VnbaTriggered.at(0U)) {
        Vtop___024root___nba_sequent__TOP__0(vlSelf);
    }
    if (vlSelf->__VnbaTriggered.at(1U)) {
        Vtop___024root___nba_sequent__TOP__1(vlSelf);
    }
}

void Vtop___024root___eval_triggers__act(Vtop___024root* vlSelf);
#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__act(Vtop___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__nba(Vtop___024root* vlSelf);
#endif  // VL_DEBUG

void Vtop___024root___eval(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval\n"); );
    // Init
    VlTriggerVec<2> __VpreTriggered;
    IData/*31:0*/ __VnbaIterCount;
    CData/*0:0*/ __VnbaContinue;
    // Body
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        __VnbaContinue = 0U;
        vlSelf->__VnbaTriggered.clear();
        vlSelf->__VactIterCount = 0U;
        vlSelf->__VactContinue = 1U;
        while (vlSelf->__VactContinue) {
            vlSelf->__VactContinue = 0U;
            Vtop___024root___eval_triggers__act(vlSelf);
            if (vlSelf->__VactTriggered.any()) {
                vlSelf->__VactContinue = 1U;
                if (VL_UNLIKELY((0x64U < vlSelf->__VactIterCount))) {
#ifdef VL_DEBUG
                    Vtop___024root___dump_triggers__act(vlSelf);
#endif
                    VL_FATAL_MT("top.v", 1, "", "Active region did not converge.");
                }
                vlSelf->__VactIterCount = ((IData)(1U) 
                                           + vlSelf->__VactIterCount);
                __VpreTriggered.andNot(vlSelf->__VactTriggered, vlSelf->__VnbaTriggered);
                vlSelf->__VnbaTriggered.set(vlSelf->__VactTriggered);
                Vtop___024root___eval_act(vlSelf);
            }
        }
        if (vlSelf->__VnbaTriggered.any()) {
            __VnbaContinue = 1U;
            if (VL_UNLIKELY((0x64U < __VnbaIterCount))) {
#ifdef VL_DEBUG
                Vtop___024root___dump_triggers__nba(vlSelf);
#endif
                VL_FATAL_MT("top.v", 1, "", "NBA region did not converge.");
            }
            __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
            Vtop___024root___eval_nba(vlSelf);
        }
    }
}

#ifdef VL_DEBUG
void Vtop___024root___eval_debug_assertions(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->clk & 0xfeU))) {
        Verilated::overWidthError("clk");}
    if (VL_UNLIKELY((vlSelf->en & 0xfeU))) {
        Verilated::overWidthError("en");}
    if (VL_UNLIKELY((vlSelf->areset & 0xfeU))) {
        Verilated::overWidthError("areset");}
}
#endif  // VL_DEBUG
