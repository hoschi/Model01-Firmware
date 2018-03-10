#pragma once

// copied from pending PR https://github.com/michabu/Kaleidoscope/blob/0a305fcd5a4d8eb87865786c9a6fcd4ee2866493/src/kaleidoscope/lang/de_qwertz.h
// only the first half of the file!

// Alt gr
#define ALTGR RALT

/* German Umlaute */
#define Key_de_SZ Key_Minus
#define Key_de_AE Key_Quote
#define Key_de_UE Key_LeftBracket
#define Key_de_OE Key_Semicolon

/* These are deviating from the us layout */
#define Key_de_Circumflex Key_Backtick /* ^ and ° */
#define Key_de_Circle LSHIFT(Key_de_Circumflex) /* ° */

#define Key_de_ExlamationMark LSHIFT(Key_de_1)
#define Key_de_DoubleQuote LSHIFT(Key_de_2)
#define Key_de_Paragraph LSHIFT(Key_de_3)
#define Key_de_Dollar LSHIFT(Key_de_4)
#define Key_de_Percent LSHIFT(Key_de_5)
#define Key_de_Ampersand LSHIFT(Key_de_6)
#define Key_de_Slash LSHIFT(Key_de_7)
#define Key_de_LeftParen LSHIFT(Key_de_8)
#define Key_de_RightParen LSHIFT(Key_de_9)
#define Key_de_Equals LSHIFT(Key_de_0)
#define Key_de_QuestionMark LSHIFT(Key_de_SZ)
#define Key_de_LeftCurly ALTGR(Key_de_7)
#define Key_de_RightCurly ALTGR(Key_de_0)
#define Key_de_LeftBracket ALTGR(Key_de_8)
#define Key_de_RightBracket ALTGR(Key_de_9)
#define Key_de_Backslash ALTGR(Key_de_SZ)

#define Key_de_Tick Key_Equals /* Tick ´ and Backtick ` */
#define Key_de_Backtick LSHIFT(Key_de_Tick)

#define Key_de_At ALTGR(Key_de_Q)
#define Key_de_Euro ALTGR(Key_de_E)

#define Key_de_Plus Key_RightBracket /* Plus + Asterisk * and Tilde ~ */
#define Key_de_Asterisk LSHIFT(Key_de_Plus) /* * */
#define Key_de_Tilde ALTGR(Key_de_Plus) /* ~ */

#define Key_de_Hash Key_Backslash /* # and ' */
#define Key_de_Quote LSHIFT(Key_de_Hash)

#define Key_de_LessThan Key_NonUsBackslashAndPipe /* < and > and | */
#define Key_de_GreaterThan LSHIFT(Key_de_LessThan)
#define Key_de_Pipe ALTGR(Key_de_LessThan)

#define Key_de_Minus Key_Slash /* - and _ */
#define Key_de_Underscore LSHIFT(Key_de_Minus)

/* the default keys are just aliased to have them look the same */
#define Key_de_NoEvent Key_NoEvent
#define Key_de_ErrorRollover Key_ErrorRollover
#define Key_de_PostFail Key_PostFail
#define Key_de_ErrorUndefined Key_ErrorUndefined
#define Key_de_A Key_A
#define Key_de_B Key_B
#define Key_de_C Key_C
#define Key_de_D Key_D
#define Key_de_E Key_E
#define Key_de_F Key_F
#define Key_de_G Key_G
#define Key_de_H Key_H
#define Key_de_I Key_I
#define Key_de_J Key_J
#define Key_de_K Key_K
#define Key_de_L Key_L
#define Key_de_M Key_M
#define Key_de_N Key_N
#define Key_de_O Key_O
#define Key_de_P Key_P
#define Key_de_Q Key_Q
#define Key_de_R Key_R
#define Key_de_S Key_S
#define Key_de_T Key_T
#define Key_de_U Key_U
#define Key_de_V Key_V
#define Key_de_W Key_W
#define Key_de_X Key_X

/* These two are inverted in the german layout */
#define Key_de_Y Key_Z
#define Key_de_Z Key_Y

#define Key_de_1 Key_1
#define Key_de_2 Key_2
#define Key_de_3 Key_3
#define Key_de_4 Key_4
#define Key_de_5 Key_5
#define Key_de_6 Key_6
#define Key_de_7 Key_7
#define Key_de_8 Key_8
#define Key_de_9 Key_9
#define Key_de_0 Key_0
#define Key_de_Enter Key_Enter
#define Key_de_Escape Key_Escape
#define Key_de_Backspace Key_Backspace
#define Key_de_Tab Key_Tab
#define Key_de_Spacebar Key_Spacebar
#define Key_de_Comma Key_Comma
#define Key_de_Semicolon LSHIFT(Key_de_Comma)
#define Key_de_Period Key_Period
#define Key_de_Colon LSHIFT(Key_de_Period)
