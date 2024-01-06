// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Valu.h"
#include "Valu__Syms.h"

//============================================================
// Constructors

Valu::Valu(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Valu__Syms(contextp(), _vcname__, this)}
    , big_up_mode{vlSymsp->TOP.big_up_mode}
    , big_down_mode{vlSymsp->TOP.big_down_mode}
    , small_up_mode{vlSymsp->TOP.small_up_mode}
    , small_down_mode{vlSymsp->TOP.small_down_mode}
    , A{vlSymsp->TOP.A}
    , B{vlSymsp->TOP.B}
    , mode{vlSymsp->TOP.mode}
    , result{vlSymsp->TOP.result}
    , zf{vlSymsp->TOP.zf}
    , of{vlSymsp->TOP.of}
    , cf{vlSymsp->TOP.cf}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
}

Valu::Valu(const char* _vcname__)
    : Valu(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Valu::~Valu() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void Valu___024root___eval_debug_assertions(Valu___024root* vlSelf);
#endif  // VL_DEBUG
void Valu___024root___eval_static(Valu___024root* vlSelf);
void Valu___024root___eval_initial(Valu___024root* vlSelf);
void Valu___024root___eval_settle(Valu___024root* vlSelf);
void Valu___024root___eval(Valu___024root* vlSelf);

void Valu::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Valu::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Valu___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_deleter.deleteAll();
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        vlSymsp->__Vm_didInit = true;
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        Valu___024root___eval_static(&(vlSymsp->TOP));
        Valu___024root___eval_initial(&(vlSymsp->TOP));
        Valu___024root___eval_settle(&(vlSymsp->TOP));
    }
    // MTask 0 start
    VL_DEBUG_IF(VL_DBG_MSGF("MTask0 starting\n"););
    Verilated::mtaskId(0);
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    Valu___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfThreadMTask(vlSymsp->__Vm_evalMsgQp);
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

//============================================================
// Events and timing
bool Valu::eventsPending() { return false; }

uint64_t Valu::nextTimeSlot() {
    VL_FATAL_MT(__FILE__, __LINE__, "", "%Error: No delays in the design");
    return 0;
}

//============================================================
// Utilities

const char* Valu::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void Valu___024root___eval_final(Valu___024root* vlSelf);

VL_ATTR_COLD void Valu::final() {
    Valu___024root___eval_final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Valu::hierName() const { return vlSymsp->name(); }
const char* Valu::modelName() const { return "Valu"; }
unsigned Valu::threads() const { return 1; }
