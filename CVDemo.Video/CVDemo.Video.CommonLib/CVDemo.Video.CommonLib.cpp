// CVDemo.Video.CommonLib.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "CVDemo.Video.CommonLib.h"


// This is an example of an exported variable
CVDEMOVIDEOCOMMONLIB_API int nCVDemoVideoCommonLib=0;

// This is an example of an exported function.
CVDEMOVIDEOCOMMONLIB_API int fnCVDemoVideoCommonLib(void)
{
    return 42;
}

// This is the constructor of a class that has been exported.
// see CVDemo.Video.CommonLib.h for the class definition
CCVDemoVideoCommonLib::CCVDemoVideoCommonLib()
{
    return;
}
