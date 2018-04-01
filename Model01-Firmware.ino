// -*- mode: c++ -*-
// Copyright 2016 Keyboardio, inc. <jesse@keyboard.io>
// See "LICENSE" for license details

#ifndef BUILD_INFORMATION
#define BUILD_INFORMATION "locally built"
#endif


/**
 * These #include directives pull in the Kaleidoscope firmware core,
 * as well as the Kaleidoscope plugins we use in the Model 01's firmware
 */


// The Kaleidoscope core
#include "Kaleidoscope.h"

// Support for keys that move the mouse
#include "Kaleidoscope-MouseKeys.h"

// Support for macros
#include "Kaleidoscope-Macros.h"

// Support for controlling the keyboard's LEDs
#include "Kaleidoscope-LEDControl.h"

// Support for an "LED off mode"
#include "LED-Off.h"

// Support for the "Boot greeting" effect, which pulses the 'LED' button for 10s
// when the keyboard is connected to a computer (or that computer is powered on)
#include "Kaleidoscope-LEDEffect-BootGreeting.h"

// Support for LED modes that set all LEDs to a single color
#include "Kaleidoscope-LEDEffect-SolidColor.h"

// Support for Keyboardio's internal keyboard testing mode
#include "Kaleidoscope-Model01-TestMode.h"

// Support for host power management (suspend & wakeup)
#include "Kaleidoscope-HostPowerManagement.h"

// Support key do different things while held or tapped
#include <Kaleidoscope-Qukeys.h>

// held or tap to shift to layer
#include <Kaleidoscope-OneShot.h>

// copied from pending PR https://github.com/michabu/Kaleidoscope/blob/0a305fcd5a4d8eb87865786c9a6fcd4ee2866493/src/kaleidoscope/lang/de_qwertz.h
#include "lang_de_quertz.h"

/** This 'enum' is a list of all the macros used by the Model 01's firmware
  * The names aren't particularly important. What is important is that each
  * is unique.
  *
  * These are the names of your macros. They'll be used in two places.
  * The first is in your keymap definitions. There, you'll use the syntax
  * `M(MACRO_NAME)` to mark a specific keymap position as triggering `MACRO_NAME`
  *
  * The second usage is in the 'switch' statement in the `macroAction` function.
  * That switch statement actually runs the code associated with a macro when
  * a macro key is pressed.
  */

enum { MACRO_ANY
     };



/** The Model 01's key layouts are defined as 'keymaps'.
  *
  * Each keymap is defined as a list using the 'KEYMAP_STACKED' macro, built
  * of first the left hand's layout, followed by the right hand's layout.
  *
  * Keymaps typically consist mostly of `Key_` definitions:
  *    https://github.com/keyboardio/Kaleidoscope/blob/master/src/key_defs_keyboard.h
  *    https://github.com/keyboardio/Kaleidoscope/blob/master/src/key_defs_consumerctl.h
  *    https://github.com/keyboardio/Kaleidoscope/blob/master/src/key_defs_sysctl.h
  *    https://github.com/keyboardio/Kaleidoscope/blob/master/src/key_defs_keymaps.h
  *
  * Additional things that should be documented here include
  *   using ___ to let keypresses fall through to the previously active layer
  *   using XXX to mark a keyswitch as 'blocked' on this layer
  *   using ShiftToLayer() and LockLayer() keys to change the active keymap.
  *   the special nature of the PROG key
  *
  *
  * The "keymaps" data structure is a list of the keymaps compiled into the firmware.
  * The order of keymaps in the list is important, as the ShiftToLayer(#) and LockLayer(#)
  * macros switch to key layers based on this list.
  *
  * A key defined as 'ShiftToLayer(FUNCTION)' will switch to FUNCTION while held.
  * Similarly, a key defined as 'LockLayer(NUMPAD)' will switch to NUMPAD when tapped.
  */

/**
  * Layers are "0-indexed" -- That is the first one is layer 0. The second one is layer 1.
  * The third one is layer 2.
  * This 'enum' lets us use names like QWERTY, FUNCTION, and NUMPAD in place of
  * the numbers 0, 1 and 2.
  */

enum { QW, PA, FU }; // layers

/* This comment temporarily turns off astyle's indent enforcement
 *   so we can make the keymaps actually resemble the physical key layout better
 */
// *INDENT-OFF*

// use `setxkbmap de nodeadkeys` as workaround for dead backtick
const Key keymaps[][ROWS][COLS] PROGMEM = {

  [QW] = KEYMAP_STACKED
  (___                        , Key_1                  , Key_2             , Key_3              , Key_4               , Key_5             , Key_LEDEffectNext ,
   Consumer_PlaySlashPause    , Key_de_X               , Key_de_V          , Key_de_L           , Key_de_C            , Key_de_W          , LockLayer(FU)     ,
   Consumer_ScanNextTrack     , Key_de_U               , Key_de_I          , Key_de_A           , Key_de_E            , Key_de_O          ,
   Consumer_ScanPreviousTrack , Key_de_UE              , Key_de_OE         , Key_de_AE          , Key_de_P            , Key_de_Z          , Key_LeftShift     ,
   ALT_T(Escape)              , Key_Backspace          , SFT_T(Enter)      , OSM(LeftControl)   ,
   ShiftToLayer(PA)           ,

   System_Sleep               , Key_6                  , Key_7             , Key_8              , Key_9               , Key_0             , ___               ,
   ___                        , Key_de_K               , Key_de_H          , Key_de_G           , Key_de_F            , Key_de_Q          , Key_de_SZ         ,
   /*                         , */ Key_de_S            , Key_de_N          , Key_de_R           , Key_de_T            , Key_de_D          , Key_de_Y          ,
   Key_CapsLock               , Key_de_B               , Key_de_M          , Key_de_Comma       , Key_de_Period       , Key_de_J          , ___               ,
   OSM(RightControl)          , SFT_T(Tab)             , Key_Spacebar      , Key_LeftAlt        ,
   ShiftToLayer(PA))          ,

  [PA] = KEYMAP_STACKED
  (___                        , Key_F1                 , Key_F2            , Key_F3             , Key_F4              , Key_F5            , ___               ,
   ___                        , ___                    , Key_de_Underscore , Key_de_LeftBracket , Key_de_RightBracket , Key_de_Circumflex , ___               ,
   ___                        , Key_de_Backslash       , Key_de_Slash      , Key_de_LeftCurly   , Key_de_RightCurly   , Key_de_Asterisk   ,
   ___                        , Key_de_Hash            , Key_de_Dollar     , Key_de_Pipe        , Key_de_Tilde        , Key_de_Backtick   , ___               ,
   ___                        , ShiftToLayer(FU)       , ___               , ___                ,
   ___                        ,

   ___                        , Key_F6                 , Key_F7            , Key_F8             , Key_F9              , Key_F10           , Key_F11           ,
   ___                        , Key_de_ExlamationMark  , Key_de_LessThan   , Key_de_GreaterThan , Key_de_Equals       , Key_de_Ampersand  , Key_F12           ,
   /*                         , */ Key_de_QuestionMark , Key_de_LeftParen  , Key_de_RightParen  , Key_de_Minus        , Key_de_Colon      , Key_de_At         ,
   ___                        , Key_de_Plus            , Key_de_Percent    , Key_de_DoubleQuote , Key_de_Quote        , Key_de_Semicolon  , ___               ,
   ___                        , ___                    , OSL(FU)           , ___                ,
   ___)                       ,

  [FU] =  KEYMAP_STACKED
  (___                        , ___                    , ___               , ___                , ___                 , ___               , ___               ,
   ___                        , Key_PageUp             , Key_Backspace     , Key_UpArrow        , Key_Delete          , Key_PageDown      , ___               ,
   ___                        , Key_Home               , Key_LeftArrow     , Key_DownArrow      , Key_RightArrow      , Key_End           ,
   ___                        , Key_Escape             , Key_Tab           , ___                , Key_Enter           , Key_Undo          , ___               ,
   ___                        , ___                    , ___               , ___                ,
   ___                        ,

   ___                        , ___                    , ___               , ___                , ___                 , ___               , ___               ,
   ___                        , ___                    , Key_7             , Key_8              , Key_9               , Key_de_Plus       , Key_de_Minus      ,
  /*                          , */ Key_de_Euro         , Key_4             , Key_5              , Key_6               , Key_de_Comma      , Key_de_Period     ,
   ___                        , Key_0                  , Key_1             , Key_2              , Key_3               , Key_de_Semicolon  , Key_de_Colon      ,
   ___                        , ___                    , ___               , ___                ,
   ___)                       ,

};

/* Re-enable astyle's indent enforcement */
// *INDENT-ON*

/** anyKeyMacro is used to provide the functionality of the 'Any' key.
 *
 * When the 'any key' macro is toggled on, a random alphanumeric key is
 * selected. While the key is held, the function generates a synthetic
 * keypress event repeating that randomly selected key.
 *
 */

static void anyKeyMacro(uint8_t keyState) {
  static Key lastKey;
  if (keyToggledOn(keyState))
    lastKey.keyCode = Key_A.keyCode + (uint8_t)(millis() % 36);

  if (keyIsPressed(keyState))
    kaleidoscope::hid::pressKey(lastKey);
}


/** macroAction dispatches keymap events that are tied to a macro
    to that macro. It takes two uint8_t parameters.

    The first is the macro being called (the entry in the 'enum' earlier in this file).
    The second is the state of the keyswitch. You can use the keyswitch state to figure out
    if the key has just been toggled on, is currently pressed or if it's just been released.

    The 'switch' statement should have a 'case' for each entry of the macro enum.
    Each 'case' statement should call out to a function to handle the macro in question.

 */

const macro_t *macroAction(uint8_t macroIndex, uint8_t keyState) {
  switch (macroIndex) {

  case MACRO_ANY:
    anyKeyMacro(keyState);
    break;
  }
  return MACRO_NONE;
}

// These 'solid' color effect definitions define a rainbow of
// LED color modes calibrated to draw 500mA or less on the
// Keyboardio Model 01.
static kaleidoscope::LEDSolidColor solidIndigo(0, 0, 170);

/** toggleLedsOnSuspendResume toggles the LEDs off when the host goes to sleep,
 * and turns them back on when it wakes up.
 */
void toggleLedsOnSuspendResume(kaleidoscope::HostPowerManagement::Event event) {
  switch (event) {
  case kaleidoscope::HostPowerManagement::Suspend:
    LEDControl.paused = true;
    LEDControl.set_all_leds_to({0, 0, 0});
    LEDControl.syncLeds();
    break;
  case kaleidoscope::HostPowerManagement::Resume:
    LEDControl.paused = false;
    LEDControl.refreshAll();
    break;
  case kaleidoscope::HostPowerManagement::Sleep:
    break;
  }
}

/** hostPowerManagementEventHandler dispatches power management events (suspend,
 * resume, and sleep) to other functions that perform action based on these
 * events.
 */
void hostPowerManagementEventHandler(kaleidoscope::HostPowerManagement::Event event) {
  toggleLedsOnSuspendResume(event);
}

/** The 'setup' function is one of the two standard Arduino sketch functions.
  * It's called when your keyboard first powers up. This is where you set up
  * Kaleidoscope and any plugins.
  */

void setup() {
  // First, call Kaleidoscope's internal setup function
  Kaleidoscope.setup();

  // Next, tell Kaleidoscope which plugins you want to use.
  // The order can be important. For example, LED effects are
  // added in the order they're listed here.
  Kaleidoscope.use(
    // The Qukeys plugin
    &Qukeys,

    // The boot greeting effect pulses the LED button for 10 seconds after the keyboard is first connected
    &BootGreetingEffect,

    // The hardware test mode, which can be invoked by tapping Prog, LED and the left Fn button at the same time.
    &TestMode,

    // LEDControl provides support for other LED modes
    &LEDControl,

    // We start with the LED effect that turns off all the LEDs.
    &LEDOff,

    // current main effect
    &solidIndigo,

    // The macros plugin adds support for macros
    &Macros,

    // The MouseKeys plugin lets you add keys to your keymap which move the mouse.
    &MouseKeys,

    // The HostPowerManagement plugin enables waking up the host from suspend,
    // and allows us to turn LEDs off when it goes to sleep.
    &HostPowerManagement,

    &OneShot
  );

  // We want the keyboard to be able to wake the host up from suspend.
  HostPowerManagement.enableWakeup();

  // We want to make sure that the firmware starts with LED effects off
  // This avoids over-taxing devices that don't have a lot of power to share
  // with USB devices
  LEDOff.activate();
}

/** loop is the second of the standard Arduino sketch functions.
  * As you might expect, it runs in a loop, never exiting.
  *
  * For Kaleidoscope-based keyboard firmware, you usually just want to
  * call Kaleidoscope.loop(); and not do anything custom here.
  */

void loop() {
  Kaleidoscope.loop();
}
