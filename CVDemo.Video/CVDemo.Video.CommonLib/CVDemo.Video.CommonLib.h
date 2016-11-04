// The following ifdef block is the standard way of creating macros which make exporting 
// from a DLL simpler. All files within this DLL are compiled with the CVDEMOVIDEOCOMMONLIB_EXPORTS
// symbol defined on the command line. This symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see 
// CVDEMOVIDEOCOMMONLIB_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
#ifdef CVDEMOVIDEOCOMMONLIB_EXPORTS
#define CVDEMOVIDEOCOMMONLIB_API __declspec(dllexport)
#else
#define CVDEMOVIDEOCOMMONLIB_API __declspec(dllimport)
#endif

// This class is exported from the CVDemo.Video.CommonLib.dll
class CVDEMOVIDEOCOMMONLIB_API CCVDemoVideoCommonLib {
public:
	CCVDemoVideoCommonLib(void);
	// TODO: add your methods here.
};

extern CVDEMOVIDEOCOMMONLIB_API int nCVDemoVideoCommonLib;

CVDEMOVIDEOCOMMONLIB_API int fnCVDemoVideoCommonLib(void);
