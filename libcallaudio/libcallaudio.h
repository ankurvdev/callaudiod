/*
 * Copyright (C) 2020 Purism SPC
 * Copyright (C) 2020 Arnaud Ferraris <arnaud.ferraris@gmail.com>
 *
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#pragma once

#include "libcallaudio-enums.h"

#include <glib.h>

G_BEGIN_DECLS

/**
 * CallAudioMode:
 * @CALL_AUDIO_MODE_DEFAULT: Default mode (used for music, alarms, ringtones...)
 * @CALL_AUDIO_MODE_CALL: Voice call mode
 * @CALL_AUDIO_MODE_UNKNOWN: Mode unknown
 *
 * Enum values to indicate the mode to be selected.
 */

typedef enum {
  CALL_AUDIO_MODE_DEFAULT = 0,
  CALL_AUDIO_MODE_CALL,
  CALL_AUDIO_MODE_UNKNOWN = 255
} CallAudioMode;

/**
 * CallAudioSpeakerState:
 * @CALL_AUDIO_SPEAKER_OFF: Speaker disabled
 * @CALL_AUDIO_SPEAKER_ON: Speaker enabled
 * @CALL_AUDIO_SPEAKER_UNKNOWN: Unknown
 */

typedef enum {
  CALL_AUDIO_SPEAKER_OFF = 0,
  CALL_AUDIO_SPEAKER_ON = 1,
  CALL_AUDIO_SPEAKER_UNKNOWN = 255
} CallAudioSpeakerState;

/**
 * CallAudioMicState:
 * @CALL_AUDIO_MIC_OFF: Mic disabled
 * @CALL_AUDIO_MIC_ON: Mic enabled
 * @CALL_AUDIO_MIC_UNKNOWN: Unknown
 */

typedef enum {
  CALL_AUDIO_MIC_OFF = 0,
  CALL_AUDIO_MIC_ON,
  CALL_AUDIO_MIC_UNKNOWN = 255
} CallAudioMicState;

typedef void (*CallAudioCallback)(gboolean success,
                                  GError *error,
                                  gpointer data);

GLIB_DEPRECATED
gboolean call_audio_init     (GError **error);
GLIB_DEPRECATED
gboolean call_audio_is_inited(void);
GLIB_DEPRECATED
void     call_audio_deinit   (void);

GLIB_DEPRECATED
gboolean call_audio_select_mode      (CallAudioMode mode, GError **error);
GLIB_DEPRECATED
gboolean call_audio_select_mode_async(CallAudioMode     mode,
                                      CallAudioCallback cb,
                                      gpointer          data);
GLIB_DEPRECATED
CallAudioMode call_audio_get_audio_mode(void);

GLIB_DEPRECATED
gboolean call_audio_enable_speaker      (gboolean enable, GError **error);
GLIB_DEPRECATED
gboolean call_audio_enable_speaker_async(gboolean          enable,
                                         CallAudioCallback cb,
                                         gpointer          data);
GLIB_DEPRECATED
CallAudioSpeakerState call_audio_get_speaker_state(void);

GLIB_DEPRECATED
gboolean call_audio_mute_mic      (gboolean mute, GError **error);
GLIB_DEPRECATED
gboolean call_audio_mute_mic_async(gboolean          mute,
                                   CallAudioCallback cb,
                                   gpointer          data);
GLIB_DEPRECATED
CallAudioMicState call_audio_get_mic_state(void);

G_END_DECLS
