#ifndef _DMUSICC_H
#define _DMUSICC_H

/* DirectMusic core API definitions */

#include <windows.h>

#define COM_NO_WINDOWS_H
#include <objbase.h>
#include <mmsystem.h>

#include "dls1.h"
#include "dmerror.h"
#include "dmdls.h"
#include "dsound.h"
#include "dmusbuff.h"

#include <pshpack8.h>

#ifdef __cplusplus
extern "C" {
#endif

#define DMUS_MAX_DESCRIPTION 128
#define DMUS_MAX_DRIVER 128

#define DMUS_EFFECT_NONE  0x00000000
#define DMUS_EFFECT_REVERB  0x00000001
#define DMUS_EFFECT_CHORUS  0x00000002
#define DMUS_EFFECT_DELAY  0x00000004

#define DMUS_PC_INPUTCLASS  (0)
#define DMUS_PC_OUTPUTCLASS  (1)

#define DMUS_PC_DLS  (0x00000001)
#define DMUS_PC_EXTERNAL  (0x00000002)
#define DMUS_PC_SOFTWARESYNTH  (0x00000004)
#define DMUS_PC_MEMORYSIZEFIXED  (0x00000008)
#define DMUS_PC_GMINHARDWARE  (0x00000010)
#define DMUS_PC_GSINHARDWARE  (0x00000020)
#define DMUS_PC_XGINHARDWARE  (0x00000040)
#define DMUS_PC_DIRECTSOUND  (0x00000080)
#define DMUS_PC_SHAREABLE  (0x00000100)
#define DMUS_PC_DLS2  (0x00000200)
#define DMUS_PC_AUDIOPATH  (0x00000400)
#define DMUS_PC_WAVE  (0x00000800)

#define DMUS_PC_SYSTEMMEMORY  (0x7FFFFFFF)

#define DMUS_PORT_WINMM_DRIVER  (0)
#define DMUS_PORT_USER_MODE_SYNTH  (1)
#define DMUS_PORT_KERNEL_MODE  (2)

#define DMUS_PORTPARAMS_VOICES  0x00000001
#define DMUS_PORTPARAMS_CHANNELGROUPS  0x00000002
#define DMUS_PORTPARAMS_AUDIOCHANNELS  0x00000004
#define DMUS_PORTPARAMS_SAMPLERATE  0x00000008
#define DMUS_PORTPARAMS_EFFECTS  0x00000020
#define DMUS_PORTPARAMS_SHARE  0x00000040
#define DMUS_PORTPARAMS_FEATURES  0x00000080

#define DMUS_PORT_FEATURE_AUDIOPATH  0x00000001
#define DMUS_PORT_FEATURE_STREAMING  0x00000002

#define DMUS_SYNTHSTATS_VOICES  (1<<0)
#define DMUS_SYNTHSTATS_TOTAL_CPU  (1<<1)
#define DMUS_SYNTHSTATS_CPU_PER_VOICE  (1<<2)
#define DMUS_SYNTHSTATS_LOST_NOTES  (1<<3)
#define DMUS_SYNTHSTATS_PEAK_VOLUME  (1<<4)
#define DMUS_SYNTHSTATS_FREE_MEMORY  (1<<5)

#define DMUS_SYNTHSTATS_SYSTEMMEMORY  DMUS_PC_SYSTEMMEMORY

#define DMUS_CLOCKF_GLOBAL  0x00000001

#define DSBUSID_FIRST_SPKR_LOC  0
#define DSBUSID_FRONT_LEFT  0
#define DSBUSID_LEFT  0
#define DSBUSID_FRONT_RIGHT  1
#define DSBUSID_RIGHT  1
#define DSBUSID_FRONT_CENTER  2
#define DSBUSID_LOW_FREQUENCY  3
#define DSBUSID_BACK_LEFT  4
#define DSBUSID_BACK_RIGHT  5
#define DSBUSID_FRONT_LEFT_OF_CENTER  6
#define DSBUSID_FRONT_RIGHT_OF_CENTER  7
#define DSBUSID_BACK_CENTER  8
#define DSBUSID_SIDE_LEFT  9
#define DSBUSID_SIDE_RIGHT  10
#define DSBUSID_TOP_CENTER  11
#define DSBUSID_TOP_FRONT_LEFT  12
#define DSBUSID_TOP_FRONT_CENTER  13
#define DSBUSID_TOP_FRONT_RIGHT  14
#define DSBUSID_TOP_BACK_LEFT  15
#define DSBUSID_TOP_BACK_CENTER  16
#define DSBUSID_TOP_BACK_RIGHT  17
#define DSBUSID_LAST_SPKR_LOC  17

#define DSBUSID_IS_SPKR_LOC(id) (((id) >= DSBUSID_FIRST_SPKR_LOC) && ((id) <= DSBUSID_LAST_SPKR_LOC))

#define DSBUSID_REVERB_SEND  64
#define DSBUSID_CHORUS_SEND  65

#define DSBUSID_DYNAMIC_0  512

#define DSBUSID_NULL  0xFFFFFFFF

#ifndef _DIRECTAUDIO_PRIORITIES_DEFINED_
#define _DIRECTAUDIO_PRIORITIES_DEFINED_

#define DAUD_CRITICAL_VOICE_PRIORITY  (0xF0000000)
#define DAUD_HIGH_VOICE_PRIORITY  (0xC0000000)
#define DAUD_STANDARD_VOICE_PRIORITY  (0x80000000)
#define DAUD_LOW_VOICE_PRIORITY  (0x40000000)
#define DAUD_PERSIST_VOICE_PRIORITY  (0x10000000)

#define DAUD_CHAN1_VOICE_PRIORITY_OFFSET  (0x0000000E)
#define DAUD_CHAN2_VOICE_PRIORITY_OFFSET  (0x0000000D)
#define DAUD_CHAN3_VOICE_PRIORITY_OFFSET  (0x0000000C)
#define DAUD_CHAN4_VOICE_PRIORITY_OFFSET  (0x0000000B)
#define DAUD_CHAN5_VOICE_PRIORITY_OFFSET  (0x0000000A)
#define DAUD_CHAN6_VOICE_PRIORITY_OFFSET  (0x00000009)
#define DAUD_CHAN7_VOICE_PRIORITY_OFFSET  (0x00000008)
#define DAUD_CHAN8_VOICE_PRIORITY_OFFSET  (0x00000007)
#define DAUD_CHAN9_VOICE_PRIORITY_OFFSET  (0x00000006)
#define DAUD_CHAN10_VOICE_PRIORITY_OFFSET  (0x0000000F)
#define DAUD_CHAN11_VOICE_PRIORITY_OFFSET  (0x00000005)
#define DAUD_CHAN12_VOICE_PRIORITY_OFFSET  (0x00000004)
#define DAUD_CHAN13_VOICE_PRIORITY_OFFSET  (0x00000003)
#define DAUD_CHAN14_VOICE_PRIORITY_OFFSET  (0x00000002)
#define DAUD_CHAN15_VOICE_PRIORITY_OFFSET  (0x00000001)
#define DAUD_CHAN16_VOICE_PRIORITY_OFFSET  (0x00000000)

#define DAUD_CHAN1_DEF_VOICE_PRIORITY  (DAUD_STANDARD_VOICE_PRIORITY|DAUD_CHAN1_VOICE_PRIORITY_OFFSET)
#define DAUD_CHAN2_DEF_VOICE_PRIORITY  (DAUD_STANDARD_VOICE_PRIORITY|DAUD_CHAN2_VOICE_PRIORITY_OFFSET)
#define DAUD_CHAN3_DEF_VOICE_PRIORITY  (DAUD_STANDARD_VOICE_PRIORITY|DAUD_CHAN3_VOICE_PRIORITY_OFFSET)
#define DAUD_CHAN4_DEF_VOICE_PRIORITY  (DAUD_STANDARD_VOICE_PRIORITY|DAUD_CHAN4_VOICE_PRIORITY_OFFSET)
#define DAUD_CHAN5_DEF_VOICE_PRIORITY  (DAUD_STANDARD_VOICE_PRIORITY|DAUD_CHAN5_VOICE_PRIORITY_OFFSET)
#define DAUD_CHAN6_DEF_VOICE_PRIORITY  (DAUD_STANDARD_VOICE_PRIORITY|DAUD_CHAN6_VOICE_PRIORITY_OFFSET)
#define DAUD_CHAN7_DEF_VOICE_PRIORITY  (DAUD_STANDARD_VOICE_PRIORITY|DAUD_CHAN7_VOICE_PRIORITY_OFFSET)
#define DAUD_CHAN8_DEF_VOICE_PRIORITY  (DAUD_STANDARD_VOICE_PRIORITY|DAUD_CHAN8_VOICE_PRIORITY_OFFSET)
#define DAUD_CHAN9_DEF_VOICE_PRIORITY  (DAUD_STANDARD_VOICE_PRIORITY|DAUD_CHAN9_VOICE_PRIORITY_OFFSET)
#define DAUD_CHAN10_DEF_VOICE_PRIORITY  (DAUD_STANDARD_VOICE_PRIORITY|DAUD_CHAN10_VOICE_PRIORITY_OFFSET)
#define DAUD_CHAN11_DEF_VOICE_PRIORITY  (DAUD_STANDARD_VOICE_PRIORITY|DAUD_CHAN11_VOICE_PRIORITY_OFFSET)
#define DAUD_CHAN12_DEF_VOICE_PRIORITY  (DAUD_STANDARD_VOICE_PRIORITY|DAUD_CHAN12_VOICE_PRIORITY_OFFSET)
#define DAUD_CHAN13_DEF_VOICE_PRIORITY  (DAUD_STANDARD_VOICE_PRIORITY|DAUD_CHAN13_VOICE_PRIORITY_OFFSET)
#define DAUD_CHAN14_DEF_VOICE_PRIORITY  (DAUD_STANDARD_VOICE_PRIORITY|DAUD_CHAN14_VOICE_PRIORITY_OFFSET)
#define DAUD_CHAN15_DEF_VOICE_PRIORITY  (DAUD_STANDARD_VOICE_PRIORITY|DAUD_CHAN15_VOICE_PRIORITY_OFFSET)
#define DAUD_CHAN16_DEF_VOICE_PRIORITY  (DAUD_STANDARD_VOICE_PRIORITY|DAUD_CHAN16_VOICE_PRIORITY_OFFSET)

#endif /* _DIRECTAUDIO_PRIORITIES_DEFINED_ */

#define DMUS_VOLUME_MAX  2000
#define DMUS_VOLUME_MIN  -20000

typedef ULONGLONG SAMPLE_TIME;
typedef ULONGLONG SAMPLE_POSITION;
typedef SAMPLE_TIME *LPSAMPLE_TIME;

typedef struct _DMUS_BUFFERDESC *LPDMUS_BUFFERDESC;
typedef struct _DMUS_BUFFERDESC {
    DWORD dwSize;
    DWORD dwFlags;
    GUID guidBufferFormat;
    DWORD cbBuffer;
} DMUS_BUFFERDESC;

typedef struct _DMUS_PORTCAPS {
    DWORD dwSize;
    DWORD dwFlags;
    GUID guidPort;
    DWORD dwClass;
    DWORD dwType;
    DWORD dwMemorySize;
    DWORD dwMaxChannelGroups;
    DWORD dwMaxVoices;
    DWORD dwMaxAudioChannels;
    DWORD dwEffectFlags;
    WCHAR wszDescription[DMUS_MAX_DESCRIPTION];
} DMUS_PORTCAPS;

typedef DMUS_PORTCAPS *LPDMUS_PORTCAPS;

typedef struct _DMUS_PORTPARAMS {
    DWORD dwSize;
    DWORD dwValidParams;
    DWORD dwVoices;
    DWORD dwChannelGroups;
    DWORD dwAudioChannels;
    DWORD dwSampleRate;
    DWORD dwEffectFlags;
    BOOL fShare;
} DMUS_PORTPARAMS7;

typedef struct _DMUS_PORTPARAMS8 {
    DWORD dwSize;
    DWORD dwValidParams;
    DWORD dwVoices;
    DWORD dwChannelGroups;
    DWORD dwAudioChannels;
    DWORD dwSampleRate;
    DWORD dwEffectFlags;
    BOOL fShare;
    DWORD dwFeatures;
} DMUS_PORTPARAMS8;

typedef DMUS_PORTPARAMS8 DMUS_PORTPARAMS;
typedef DMUS_PORTPARAMS *LPDMUS_PORTPARAMS;

typedef struct _DMUS_SYNTHSTATS *LPDMUS_SYNTHSTATS;
typedef struct _DMUS_SYNTHSTATS8 *LPDMUS_SYNTHSTATS8;
typedef struct _DMUS_SYNTHSTATS {
    DWORD dwSize;
    DWORD dwValidStats;
    DWORD dwVoices;
    DWORD dwTotalCPU;
    DWORD dwCPUPerVoice;
    DWORD dwLostNotes;
    DWORD dwFreeMemory;
    long lPeakVolume;
} DMUS_SYNTHSTATS;

typedef struct _DMUS_SYNTHSTATS8 {
    DWORD dwSize;
    DWORD dwValidStats;
    DWORD dwVoices;
    DWORD dwTotalCPU;
    DWORD dwCPUPerVoice;
    DWORD dwLostNotes;
    DWORD dwFreeMemory;
    long lPeakVolume;
    DWORD dwSynthMemUse;
} DMUS_SYNTHSTATS8;

typedef struct _DMUS_WAVES_REVERB_PARAMS {
    float fInGain;
    float fReverbMix;
    float fReverbTime;
    float fHighFreqRTRatio;
} DMUS_WAVES_REVERB_PARAMS;

typedef enum {
    DMUS_CLOCK_SYSTEM = 0,
    DMUS_CLOCK_WAVE = 1
} DMUS_CLOCKTYPE;

typedef struct _DMUS_CLOCKINFO7 *LPDMUS_CLOCKINFO7;
typedef struct _DMUS_CLOCKINFO7 {
    DWORD dwSize;
    DMUS_CLOCKTYPE ctType;
    GUID guidClock;
    WCHAR wszDescription[DMUS_MAX_DESCRIPTION];
} DMUS_CLOCKINFO7;

typedef struct _DMUS_CLOCKINFO8 *LPDMUS_CLOCKINFO8;
typedef struct _DMUS_CLOCKINFO8 {
    DWORD dwSize;
    DMUS_CLOCKTYPE ctType;
    GUID guidClock;
    WCHAR wszDescription[DMUS_MAX_DESCRIPTION];
    DWORD dwFlags;
} DMUS_CLOCKINFO8;

typedef DMUS_CLOCKINFO8 DMUS_CLOCKINFO;
typedef DMUS_CLOCKINFO *LPDMUS_CLOCKINFO;

interface IDirectMusic;
interface IDirectMusic8;
interface IDirectMusicBuffer;
interface IDirectMusicPort;
interface IDirectMusicThru;
interface IReferenceClock;

#ifndef __cplusplus
typedef interface IDirectMusic IDirectMusic;
typedef interface IDirectMusic8 IDirectMusic8;
typedef interface IDirectMusicPort IDirectMusicPort;
typedef interface IDirectMusicBuffer IDirectMusicBuffer;
typedef interface IDirectMusicThru IDirectMusicThru;
typedef interface IReferenceClock IReferenceClock;
#endif /* __cplusplus */

typedef IDirectMusic *LPDIRECTMUSIC;
typedef IDirectMusic8 *LPDIRECTMUSIC8;
typedef IDirectMusicPort *LPDIRECTMUSICPORT;
typedef IDirectMusicBuffer *LPDIRECTMUSICBUFFER;

#undef INTERFACE
#define INTERFACE IDirectMusic
DECLARE_INTERFACE_(IDirectMusic,IUnknown)
{
    STDMETHOD(QueryInterface)(THIS_ REFIID,LPVOID*) PURE;
    STDMETHOD_(ULONG,AddRef)(THIS) PURE;
    STDMETHOD_(ULONG,Release)(THIS) PURE;
    STDMETHOD(EnumPort)(THIS_ DWORD,LPDMUS_PORTCAPS) PURE;
    STDMETHOD(CreateMusicBuffer)(THIS_ LPDMUS_BUFFERDESC,LPDIRECTMUSICBUFFER*,LPUNKNOWN) PURE;
    STDMETHOD(CreatePort)(THIS_ REFCLSID,LPDMUS_PORTPARAMS,LPDIRECTMUSICPORT*,LPUNKNOWN) PURE;
    STDMETHOD(EnumMasterClock)(THIS_ DWORD,LPDMUS_CLOCKINFO) PURE;
    STDMETHOD(GetMasterClock)(THIS_ LPGUID,IReferenceClock**) PURE;
    STDMETHOD(SetMasterClock)(THIS_ REFGUID) PURE;
    STDMETHOD(Activate)(THIS_ BOOL) PURE;
    STDMETHOD(GetDefaultPort)(THIS_ LPGUID) PURE;
    STDMETHOD(SetDirectSound)(THIS_ LPDIRECTSOUND,HWND) PURE;
};

#undef INTERFACE
#define INTERFACE IDirectMusic8
DECLARE_INTERFACE_(IDirectMusic8,IDirectMusic)
{
    STDMETHOD(QueryInterface)(THIS_ REFIID,LPVOID*) PURE;
    STDMETHOD_(ULONG,AddRef)(THIS) PURE;
    STDMETHOD_(ULONG,Release)(THIS) PURE;
    STDMETHOD(EnumPort)(THIS_ DWORD,LPDMUS_PORTCAPS) PURE;
    STDMETHOD(CreateMusicBuffer)(THIS_ LPDMUS_BUFFERDESC,LPDIRECTMUSICBUFFER*,LPUNKNOWN) PURE;
    STDMETHOD(CreatePort)(THIS_ REFCLSID,LPDMUS_PORTPARAMS,LPDIRECTMUSICPORT*,LPUNKNOWN) PURE;
    STDMETHOD(EnumMasterClock)(THIS_ DWORD,LPDMUS_CLOCKINFO) PURE;
    STDMETHOD(GetMasterClock)(THIS_ LPGUID,IReferenceClock**) PURE;
    STDMETHOD(SetMasterClock)(THIS_ REFGUID) PURE;
    STDMETHOD(Activate)(THIS_ BOOL) PURE;
    STDMETHOD(GetDefaultPort)(THIS_ LPGUID) PURE;
    STDMETHOD(SetDirectSound)(THIS_ LPDIRECTSOUND,HWND) PURE;
    STDMETHOD(SetExternalMasterClock)(THIS_ IReferenceClock*) PURE;
};

#undef INTERFACE
#define INTERFACE IDirectMusicBuffer
DECLARE_INTERFACE_(IDirectMusicBuffer,IUnknown)
{
    STDMETHOD(QueryInterface)(THIS_ REFIID,LPVOID*) PURE;
    STDMETHOD_(ULONG,AddRef)(THIS) PURE;
    STDMETHOD_(ULONG,Release)(THIS) PURE;
    STDMETHOD(Flush)(THIS) PURE;
    STDMETHOD(TotalTime)(THIS_ LPREFERENCE_TIME) PURE;
    STDMETHOD(PackStructured)(THIS_ REFERENCE_TIME,DWORD,DWORD) PURE;
    STDMETHOD(PackUnstructured)(THIS_ REFERENCE_TIME,DWORD,DWORD,LPBYTE) PURE;
    STDMETHOD(ResetReadPtr)(THIS) PURE;
    STDMETHOD(GetNextEvent)(THIS_ LPREFERENCE_TIME,LPDWORD,LPDWORD,LPBYTE*) PURE;
    STDMETHOD(GetRawBufferPtr)(THIS_ LPBYTE*) PURE;
    STDMETHOD(GetStartTime)(THIS_ LPREFERENCE_TIME) PURE;
    STDMETHOD(GetUsedBytes)(THIS_ LPDWORD) PURE;
    STDMETHOD(GetMaxBytes)(THIS_ LPDWORD) PURE;
    STDMETHOD(GetBufferFormat)(THIS_ LPGUID) PURE;
    STDMETHOD(SetStartTime)(THIS_ REFERENCE_TIME) PURE;
    STDMETHOD(SetUsedBytes)(THIS_ DWORD) PURE;
};

typedef IDirectMusicBuffer IDirectMusicBuffer8;
typedef IDirectMusicBuffer8 *LPDIRECTMUSICBUFFER8;

#undef INTERFACE
#define INTERFACE IDirectMusicInstrument
DECLARE_INTERFACE_(IDirectMusicInstrument,IUnknown)
{
    STDMETHOD(QueryInterface)(THIS_ REFIID,LPVOID*) PURE;
    STDMETHOD_(ULONG,AddRef)(THIS) PURE;
    STDMETHOD_(ULONG,Release)(THIS) PURE;
    STDMETHOD(GetPatch)(THIS_ DWORD*) PURE;
    STDMETHOD(SetPatch)(THIS_ DWORD) PURE;
};

typedef IDirectMusicInstrument IDirectMusicInstrument8;
typedef IDirectMusicInstrument8 *LPDIRECTMUSICINSTRUMENT8;

#undef INTERFACE
#define INTERFACE IDirectMusicDownloadedInstrument
DECLARE_INTERFACE_(IDirectMusicDownloadedInstrument,IUnknown)
{
    STDMETHOD(QueryInterface)(THIS_ REFIID,LPVOID*) PURE;
    STDMETHOD_(ULONG,AddRef)(THIS) PURE;
    STDMETHOD_(ULONG,Release)(THIS) PURE;
};

typedef IDirectMusicDownloadedInstrument IDirectMusicDownloadedInstrument8;
typedef IDirectMusicDownloadedInstrument8 *LPDIRECTMUSICDOWNLOADEDINSTRUMENT8;

#undef INTERFACE
#define INTERFACE IDirectMusicCollection
DECLARE_INTERFACE_(IDirectMusicCollection,IUnknown)
{
    STDMETHOD(QueryInterface)(THIS_ REFIID,LPVOID*) PURE;
    STDMETHOD_(ULONG,AddRef)(THIS) PURE;
    STDMETHOD_(ULONG,Release)(THIS) PURE;
    STDMETHOD(GetInstrument)(THIS_ DWORD,IDirectMusicInstrument**) PURE;
    STDMETHOD(EnumInstrument)(THIS_ DWORD,DWORD*,LPWSTR,DWORD) PURE;
};

typedef IDirectMusicCollection IDirectMusicCollection8;
typedef IDirectMusicCollection8 *LPDIRECTMUSICCOLLECTION8;

#undef INTERFACE
#define INTERFACE IDirectMusicDownload
DECLARE_INTERFACE_(IDirectMusicDownload,IUnknown)
{
    STDMETHOD(QueryInterface)(THIS_ REFIID,LPVOID*) PURE;
    STDMETHOD_(ULONG,AddRef)(THIS) PURE;
    STDMETHOD_(ULONG,Release)(THIS) PURE;
    STDMETHOD(GetBuffer)(THIS_ void**,DWORD*) PURE;
};

typedef IDirectMusicDownload IDirectMusicDownload8;
typedef IDirectMusicDownload8 *LPDIRECTMUSICDOWNLOAD8;

#undef INTERFACE
#define INTERFACE IDirectMusicPortDownload
DECLARE_INTERFACE_(IDirectMusicPortDownload,IUnknown)
{
    STDMETHOD(QueryInterface)(THIS_ REFIID,LPVOID*) PURE;
    STDMETHOD_(ULONG,AddRef)(THIS) PURE;
    STDMETHOD_(ULONG,Release)(THIS) PURE;
    STDMETHOD(GetBuffer)(THIS_ DWORD,IDirectMusicDownload**) PURE;
    STDMETHOD(AllocateBuffer)(THIS_ DWORD,IDirectMusicDownload**) PURE;
    STDMETHOD(GetDLId)(THIS_ DWORD*,DWORD) PURE;
    STDMETHOD(GetAppend)(THIS_ DWORD*) PURE;
    STDMETHOD(Download)(THIS_ IDirectMusicDownload*) PURE;
    STDMETHOD(Unload)(THIS_ IDirectMusicDownload*) PURE;
};

typedef IDirectMusicPortDownload IDirectMusicPortDownload8;
typedef IDirectMusicPortDownload8 *LPDIRECTMUSICPORTDOWNLOAD8;

#undef INTERFACE
#define INTERFACE IDirectMusicPort
DECLARE_INTERFACE_(IDirectMusicPort,IUnknown)
{
    STDMETHOD(QueryInterface)(THIS_ REFIID,LPVOID*) PURE;
    STDMETHOD_(ULONG,AddRef)(THIS) PURE;
    STDMETHOD_(ULONG,Release)(THIS) PURE;
    STDMETHOD(PlayBuffer)(THIS_ LPDIRECTMUSICBUFFER) PURE;
    STDMETHOD(SetReadNotificationHandle)(THIS_ HANDLE) PURE;
    STDMETHOD(Read)(THIS_ LPDIRECTMUSICBUFFER) PURE;
    STDMETHOD(DownloadInstrument)(THIS_ IDirectMusicInstrument*,IDirectMusicDownloadedInstrument**,DMUS_NOTERANGE*,DWORD) PURE;
    STDMETHOD(UnloadInstrument)(THIS_ IDirectMusicDownloadedInstrument*) PURE;
    STDMETHOD(GetLatencyClock)(THIS_ IReferenceClock**) PURE;
    STDMETHOD(GetRunningStats)(THIS_ LPDMUS_SYNTHSTATS) PURE;
    STDMETHOD(Compact)(THIS) PURE;
    STDMETHOD(GetCaps)(THIS_ LPDMUS_PORTCAPS) PURE;
    STDMETHOD(DeviceIoControl)(THIS_ DWORD,LPVOID,DWORD,LPVOID,DWORD,LPDWORD,LPOVERLAPPED) PURE;
    STDMETHOD(SetNumChannelGroups)(THIS_ DWORD) PURE;
    STDMETHOD(GetNumChannelGroups)(THIS_ LPDWORD) PURE;
    STDMETHOD(Activate)(THIS_ BOOL) PURE;
    STDMETHOD(SetChannelPriority)(THIS_ DWORD,DWORD,DWORD) PURE;
    STDMETHOD(GetChannelPriority)(THIS_ DWORD,DWORD,LPDWORD) PURE;
    STDMETHOD(SetDirectSound)(THIS_ LPDIRECTSOUND,LPDIRECTSOUNDBUFFER) PURE;
    STDMETHOD(GetFormat)(THIS_ LPWAVEFORMATEX,LPDWORD,LPDWORD) PURE;
};

typedef IDirectMusicPort IDirectMusicPort8;
typedef IDirectMusicPort8 *LPDIRECTMUSICPORT8;

#undef INTERFACE
#define INTERFACE IDirectMusicThru
DECLARE_INTERFACE_(IDirectMusicThru,IUnknown)
{
    STDMETHOD(QueryInterface)(THIS_ REFIID,LPVOID*) PURE;
    STDMETHOD_(ULONG,AddRef)(THIS) PURE;
    STDMETHOD_(ULONG,Release)(THIS) PURE;
    STDMETHOD(ThruChannel)(THIS_ DWORD,DWORD,DWORD,DWORD,LPDIRECTMUSICPORT) PURE;
};

typedef IDirectMusicThru IDirectMusicThru8;
typedef IDirectMusicThru8 *LPDIRECTMUSICTHRU8;

#ifndef __IReferenceClock_INTERFACE_DEFINED__
#define __IReferenceClock_INTERFACE_DEFINED__

DEFINE_GUID(IID_IReferenceClock,0x56a86897,0x0ad4,0x11ce,0xb0,0x3a,0x00,0x20,0xaf,0x0b,0xa7,0x70);

#undef INTERFACE
#define INTERFACE IReferenceClock
DECLARE_INTERFACE_(IReferenceClock,IUnknown)
{
    STDMETHOD(QueryInterface)(THIS_ REFIID,LPVOID*) PURE;
    STDMETHOD_(ULONG,AddRef)(THIS) PURE;
    STDMETHOD_(ULONG,Release)(THIS) PURE;
    STDMETHOD(GetTime)(THIS_ REFERENCE_TIME*) PURE;
    STDMETHOD(AdviseTime)(THIS_ REFERENCE_TIME,REFERENCE_TIME,HANDLE,DWORD*) PURE;
    STDMETHOD(AdvisePeriodic)(THIS_ REFERENCE_TIME,REFERENCE_TIME,HANDLE,DWORD*) PURE;
    STDMETHOD(Unadvise)(THIS_ DWORD) PURE;
};

#endif /* __IReferenceClock_INTERFACE_DEFINED__ */

DEFINE_GUID(CLSID_DirectMusic,0x636b9f10,0x0c7d,0x11d1,0x95,0xb2,0x00,0x20,0xaf,0xdc,0x74,0x21);
DEFINE_GUID(CLSID_DirectMusicCollection,0x480ff4b0,0x28b2,0x11d1,0xbe,0xf7,0x0,0xc0,0x4f,0xbf,0x8f,0xef);
DEFINE_GUID(CLSID_DirectMusicSynth,0x58C2B4D0,0x46E7,0x11D1,0x89,0xAC,0x00,0xA0,0xC9,0x05,0x41,0x29);
DEFINE_GUID(IID_IDirectMusic,0x6536115a,0x7b2d,0x11d2,0xba,0x18,0x00,0x00,0xf8,0x75,0xac,0x12);
DEFINE_GUID(IID_IDirectMusicBuffer,0xd2ac2878,0xb39b,0x11d1,0x87,0x4,0x0,0x60,0x8,0x93,0xb1,0xbd);
DEFINE_GUID(IID_IDirectMusicPort,0x08f2d8c9,0x37c2,0x11d2,0xb9,0xf9,0x00,0x00,0xf8,0x75,0xac,0x12);
DEFINE_GUID(IID_IDirectMusicThru,0xced153e7,0x3606,0x11d2,0xb9,0xf9,0x00,0x00,0xf8,0x75,0xac,0x12);
DEFINE_GUID(IID_IDirectMusicPortDownload,0xd2ac287a,0xb39b,0x11d1,0x87,0x4,0x0,0x60,0x8,0x93,0xb1,0xbd);
DEFINE_GUID(IID_IDirectMusicDownload,0xd2ac287b,0xb39b,0x11d1,0x87,0x4,0x0,0x60,0x8,0x93,0xb1,0xbd);
DEFINE_GUID(IID_IDirectMusicCollection,0xd2ac287c,0xb39b,0x11d1,0x87,0x4,0x0,0x60,0x8,0x93,0xb1,0xbd);
DEFINE_GUID(IID_IDirectMusicInstrument,0xd2ac287d,0xb39b,0x11d1,0x87,0x4,0x0,0x60,0x8,0x93,0xb1,0xbd);
DEFINE_GUID(IID_IDirectMusicDownloadedInstrument,0xd2ac287e,0xb39b,0x11d1,0x87,0x4,0x0,0x60,0x8,0x93,0xb1,0xbd);
DEFINE_GUID(IID_IDirectMusic2,0x6fc2cae1,0xbc78,0x11d2,0xaf,0xa6,0x0,0xaa,0x0,0x24,0xd8,0xb6);
DEFINE_GUID(IID_IDirectMusic8,0x2d3629f7,0x813d,0x4939,0x85,0x08,0xf0,0x5c,0x6b,0x75,0xfd,0x97);

#define IID_IDirectMusicThru8 IID_IDirectMusicThru
#define IID_IDirectMusicPortDownload8 IID_IDirectMusicPortDownload
#define IID_IDirectMusicDownload8 IID_IDirectMusicDownload
#define IID_IDirectMusicCollection8 IID_IDirectMusicCollection
#define IID_IDirectMusicInstrument8 IID_IDirectMusicInstrument
#define IID_IDirectMusicDownloadedInstrument8 IID_IDirectMusicDownloadedInstrument
#define IID_IDirectMusicPort8 IID_IDirectMusicPort

DEFINE_GUID(GUID_DMUS_PROP_GM_Hardware,0x178f2f24,0xc364,0x11d1,0xa7,0x60,0x00,0x00,0xf8,0x75,0xac,0x12);
DEFINE_GUID(GUID_DMUS_PROP_GS_Hardware,0x178f2f25,0xc364,0x11d1,0xa7,0x60,0x00,0x00,0xf8,0x75,0xac,0x12);
DEFINE_GUID(GUID_DMUS_PROP_XG_Hardware,0x178f2f26,0xc364,0x11d1,0xa7,0x60,0x00,0x00,0xf8,0x75,0xac,0x12);
DEFINE_GUID(GUID_DMUS_PROP_XG_Capable,0x6496aba1,0x61b0,0x11d2,0xaf,0xa6,0x0,0xaa,0x0,0x24,0xd8,0xb6);
DEFINE_GUID(GUID_DMUS_PROP_GS_Capable,0x6496aba2,0x61b0,0x11d2,0xaf,0xa6,0x0,0xaa,0x0,0x24,0xd8,0xb6);
DEFINE_GUID(GUID_DMUS_PROP_DLS1,0x178f2f27,0xc364,0x11d1,0xa7,0x60,0x00,0x00,0xf8,0x75,0xac,0x12);
DEFINE_GUID(GUID_DMUS_PROP_DLS2,0xf14599e5,0x4689,0x11d2,0xaf,0xa6,0x0,0xaa,0x0,0x24,0xd8,0xb6);
DEFINE_GUID(GUID_DMUS_PROP_INSTRUMENT2,0x865fd372,0x9f67,0x11d2,0x87,0x2a,0x0,0x60,0x8,0x93,0xb1,0xbd);
DEFINE_GUID(GUID_DMUS_PROP_SynthSink_DSOUND,0xaa97844,0xc877,0x11d1,0x87,0xc,0x0,0x60,0x8,0x93,0xb1,0xbd);
DEFINE_GUID(GUID_DMUS_PROP_SynthSink_WAVE,0xaa97845,0xc877,0x11d1,0x87,0xc,0x0,0x60,0x8,0x93,0xb1,0xbd);
DEFINE_GUID(GUID_DMUS_PROP_SampleMemorySize,0x178f2f28,0xc364,0x11d1,0xa7,0x60,0x00,0x00,0xf8,0x75,0xac,0x12);
DEFINE_GUID(GUID_DMUS_PROP_SamplePlaybackRate,0x2a91f713,0xa4bf,0x11d2,0xbb,0xdf,0x0,0x60,0x8,0x33,0xdb,0xd8);
DEFINE_GUID(GUID_DMUS_PROP_WriteLatency,0x268a0fa0,0x60f2,0x11d2,0xaf,0xa6,0x0,0xaa,0x0,0x24,0xd8,0xb6);
DEFINE_GUID(GUID_DMUS_PROP_WritePeriod,0x268a0fa1,0x60f2,0x11d2,0xaf,0xa6,0x0,0xaa,0x0,0x24,0xd8,0xb6);
DEFINE_GUID(GUID_DMUS_PROP_MemorySize,0x178f2f28,0xc364,0x11d1,0xa7,0x60,0x00,0x00,0xf8,0x75,0xac,0x12);
DEFINE_GUID(GUID_DMUS_PROP_WavesReverb,0x4cb5622,0x32e5,0x11d2,0xaf,0xa6,0x0,0xaa,0x0,0x24,0xd8,0xb6);
DEFINE_GUID(GUID_DMUS_PROP_Effects,0xcda8d611,0x684a,0x11d2,0x87,0x1e,0x0,0x60,0x8,0x93,0xb1,0xbd);
DEFINE_GUID(GUID_DMUS_PROP_LegacyCaps,0xcfa7cdc2,0x00a1,0x11d2,0xaa,0xd5,0x00,0x00,0xf8,0x75,0xac,0x12);
DEFINE_GUID(GUID_DMUS_PROP_Volume,0xfedfae25L,0xe46e,0x11d1,0xaa,0xce,0x00,0x00,0xf8,0x75,0xac,0x12);

#ifdef __cplusplus
};      /* extern "C" */
#endif

#include <poppack.h>

#endif /* _DMUSICC_H */