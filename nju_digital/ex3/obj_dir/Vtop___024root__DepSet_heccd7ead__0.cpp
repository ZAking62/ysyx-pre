// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "verilated.h"

#include "Vtop___024root.h"

VL_INLINE_OPT void Vtop___024root___ico_sequent__TOP__0(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___ico_sequent__TOP__0\n"); );
    // Body
    vlSelf->out_c = (1U & (IData)(((0U == (6U & (IData)(vlSelf->op))) 
                                   & ((1U & (IData)(vlSelf->op))
                                       ? (1U & (((IData)(1U) 
                                                 + 
                                                 ((IData)(vlSelf->in_x) 
                                                  + 
                                                  (0xfU 
                                                   & (~ (IData)(vlSelf->in_y))))) 
                                                >> 4U))
                                       : (1U & (((IData)(vlSelf->in_x) 
                                                 + (IData)(vlSelf->in_y)) 
                                                >> 4U))))));
    if ((4U & (IData)(vlSelf->op))) {
        if ((2U & (IData)(vlSelf->op))) {
            if ((1U & (IData)(vlSelf->op))) {
                vlSelf->out_s = (((IData)(vlSelf->in_x) 
                                  == (IData)(vlSelf->in_y))
                                  ? 1U : 0U);
                vlSelf->zero = ((0U == (IData)(vlSelf->out_s))
                                 ? 1U : 0U);
                vlSelf->overflow = 0U;
            } else {
                vlSelf->out_s = ((IData)((((IData)(vlSelf->in_x) 
                                           >> 3U) & 
                                          (~ ((IData)(vlSelf->in_y) 
                                              >> 3U))))
                                  ? 1U : ((IData)((
                                                   (~ 
                                                    ((IData)(vlSelf->in_x) 
                                                     >> 3U)) 
                                                   & ((IData)(vlSelf->in_y) 
                                                      >> 3U)))
                                           ? 0U : (
                                                   ((IData)(vlSelf->in_x) 
                                                    < (IData)(vlSelf->in_y))
                                                    ? 1U
                                                    : 0U)));
                vlSelf->zero = ((0U == (IData)(vlSelf->out_s))
                                 ? 1U : 0U);
                vlSelf->overflow = 0U;
            }
        } else if ((1U & (IData)(vlSelf->op))) {
            vlSelf->out_s = ((IData)(vlSelf->in_x) 
                             ^ (IData)(vlSelf->in_y));
            vlSelf->zero = (1U & (~ (IData)((0U != (IData)(vlSelf->out_s)))));
            vlSelf->overflow = 0U;
        } else {
            vlSelf->out_s = ((IData)(vlSelf->in_x) 
                             | (IData)(vlSelf->in_y));
            vlSelf->zero = (1U & (~ (IData)((0U != (IData)(vlSelf->out_s)))));
            vlSelf->overflow = 0U;
        }
    } else if ((2U & (IData)(vlSelf->op))) {
        if ((1U & (IData)(vlSelf->op))) {
            vlSelf->out_s = ((IData)(vlSelf->in_x) 
                             & (IData)(vlSelf->in_y));
            vlSelf->zero = (1U & (~ (IData)((0U != (IData)(vlSelf->out_s)))));
            vlSelf->overflow = 0U;
        } else {
            vlSelf->out_s = (0xfU & (~ (IData)(vlSelf->in_x)));
            vlSelf->zero = (1U & (~ (IData)((0U != (IData)(vlSelf->out_s)))));
            vlSelf->overflow = 0U;
        }
    } else if ((1U & (IData)(vlSelf->op))) {
        vlSelf->out_s = (0xfU & ((IData)(1U) + ((IData)(vlSelf->in_x) 
                                                + (~ (IData)(vlSelf->in_y)))));
        vlSelf->zero = (1U & (~ (IData)((0U != (IData)(vlSelf->out_s)))));
        vlSelf->overflow = (((1U & ((IData)(vlSelf->in_x) 
                                    >> 3U)) == (1U 
                                                & (~ 
                                                   ((IData)(vlSelf->in_y) 
                                                    >> 3U)))) 
                            & ((1U & ((IData)(vlSelf->out_s) 
                                      >> 3U)) != (1U 
                                                  & ((IData)(vlSelf->in_x) 
                                                     >> 3U))));
    } else {
        vlSelf->out_s = (0xfU & ((IData)(vlSelf->in_x) 
                                 + (IData)(vlSelf->in_y)));
        vlSelf->zero = (1U & (~ (IData)((0U != (IData)(vlSelf->out_s)))));
        vlSelf->overflow = (((1U & ((IData)(vlSelf->in_x) 
                                    >> 3U)) == (1U 
                                                & ((IData)(vlSelf->in_y) 
                                                   >> 3U))) 
                            & ((1U & ((IData)(vlSelf->out_s) 
                                      >> 3U)) != (1U 
                                                  & ((IData)(vlSelf->in_x) 
                                                     >> 3U))));
    }
}

void Vtop___024root___eval_ico(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_ico\n"); );
    // Body
    if (vlSelf->__VicoTriggered.at(0U)) {
        Vtop___024root___ico_sequent__TOP__0(vlSelf);
    }
}

void Vtop___024root___eval_act(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_act\n"); );
}

void Vtop___024root___eval_nba(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_nba\n"); );
}

void Vtop___024root___eval_triggers__ico(Vtop___024root* vlSelf);
#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__ico(Vtop___024root* vlSelf);
#endif  // VL_DEBUG
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
    CData/*0:0*/ __VicoContinue;
    VlTriggerVec<0> __VpreTriggered;
    IData/*31:0*/ __VnbaIterCount;
    CData/*0:0*/ __VnbaContinue;
    // Body
    vlSelf->__VicoIterCount = 0U;
    __VicoContinue = 1U;
    while (__VicoContinue) {
        __VicoContinue = 0U;
        Vtop___024root___eval_triggers__ico(vlSelf);
        if (vlSelf->__VicoTriggered.any()) {
            __VicoContinue = 1U;
            if (VL_UNLIKELY((0x64U < vlSelf->__VicoIterCount))) {
#ifdef VL_DEBUG
                Vtop___024root___dump_triggers__ico(vlSelf);
#endif
                VL_FATAL_MT("top.v", 1, "", "Input combinational region did not converge.");
            }
            vlSelf->__VicoIterCount = ((IData)(1U) 
                                       + vlSelf->__VicoIterCount);
            Vtop___024root___eval_ico(vlSelf);
        }
    }
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
    if (VL_UNLIKELY((vlSelf->op & 0xf8U))) {
        Verilated::overWidthError("op");}
    if (VL_UNLIKELY((vlSelf->in_x & 0xf0U))) {
        Verilated::overWidthError("in_x");}
    if (VL_UNLIKELY((vlSelf->in_y & 0xf0U))) {
        Verilated::overWidthError("in_y");}
}
#endif  // VL_DEBUG
