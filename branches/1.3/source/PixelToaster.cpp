// Pixel Toaster Library Implementation
// Copyright � 2004-2006, Glenn Fiedler
// http://www.pixeltoaster.com

#ifndef PIXELTOASTER_NO_CRT
#include <cassert>
#else
#define assert(blah)
#endif

#include "PixelToaster.h"
#include "Common.h"
#include "Conversion.h"


#if PIXELTOASTER_PLATFORM == PIXELTOASTER_UNIX
	#include "UnixPlatform.h"
#endif

#if PIXELTOASTER_PLATFORM == PIXELTOASTER_APPLE
	#include "ApplePlatform.h"
#endif

#if PIXELTOASTER_PLATFORM == PIXELTOASTER_WINDOWS
	#include "WindowsPlatform.h"
#endif

#if PIXELTOASTER_PLATFORM == PIXELTOASTER_NULL
	#include "NullPlatform.h"
#endif

#ifndef DisplayClass
	#error display class undefined
#endif

#ifndef TimerClass
	#error timer class undefined
#endif


PixelToaster::DisplayInterface * PixelToaster::createDisplay()
{
    return new DisplayClass();
}

PixelToaster::TimerInterface * PixelToaster::createTimer()
{
    return new TimerClass();
}


PixelToaster::Converter_XBGRFFFF_to_XBGRFFFF converter_XBGRFFFF_to_XBGRFFFF;
PixelToaster::Converter_XBGRFFFF_to_XRGB8888 converter_XBGRFFFF_to_XRGB8888;
PixelToaster::Converter_XBGRFFFF_to_XBGR8888 converter_XBGRFFFF_to_XBGR8888;
PixelToaster::Converter_XBGRFFFF_to_RGB888 converter_XBGRFFFF_to_RGB888;
PixelToaster::Converter_XBGRFFFF_to_BGR888 converter_XBGRFFFF_to_BGR888;
PixelToaster::Converter_XBGRFFFF_to_RGB565 converter_XBGRFFFF_to_RGB565;
PixelToaster::Converter_XBGRFFFF_to_BGR565 converter_XBGRFFFF_to_BGR565;
PixelToaster::Converter_XBGRFFFF_to_XRGB1555 converter_XBGRFFFF_to_XRGB1555;
PixelToaster::Converter_XBGRFFFF_to_XBGR1555 converter_XBGRFFFF_to_XBGR1555;

PixelToaster::Converter_XRGB8888_to_XBGRFFFF converter_XRGB8888_to_XBGRFFFF;
PixelToaster::Converter_XRGB8888_to_XRGB8888 converter_XRGB8888_to_XRGB8888;
PixelToaster::Converter_XRGB8888_to_XBGR8888 converter_XRGB8888_to_XBGR8888;
PixelToaster::Converter_XRGB8888_to_RGB888 converter_XRGB8888_to_RGB888;
PixelToaster::Converter_XRGB8888_to_BGR888 converter_XRGB8888_to_BGR888;
PixelToaster::Converter_XRGB8888_to_RGB565 converter_XRGB8888_to_RGB565;
PixelToaster::Converter_XRGB8888_to_BGR565 converter_XRGB8888_to_BGR565;
PixelToaster::Converter_XRGB8888_to_XRGB1555 converter_XRGB8888_to_XRGB1555;
PixelToaster::Converter_XRGB8888_to_XBGR1555 converter_XRGB8888_to_XBGR1555;


PixelToaster::Converter * PixelToaster::requestConverter( PixelToaster::Format source, PixelToaster::Format destination )
{
    if ( source == Format::XBGRFFFF )
    {
        switch ( destination )
        {
            case Format::XBGRFFFF: return &converter_XBGRFFFF_to_XBGRFFFF;
            case Format::XRGB8888: return &converter_XBGRFFFF_to_XRGB8888;
            case Format::XBGR8888: return &converter_XBGRFFFF_to_XBGR8888;
            case Format::RGB888: return &converter_XBGRFFFF_to_RGB888;
            case Format::BGR888: return &converter_XBGRFFFF_to_BGR888;
            case Format::RGB565: return &converter_XBGRFFFF_to_RGB565;
            case Format::BGR565: return &converter_XBGRFFFF_to_BGR565;
            case Format::XRGB1555: return &converter_XBGRFFFF_to_XRGB1555;
            case Format::XBGR1555: return &converter_XBGRFFFF_to_XBGR1555;
			default: return 0;
        }
    }
    else if ( source==Format::XRGB8888 )
    {
        switch ( destination )
        {
            case Format::XBGRFFFF: return &converter_XRGB8888_to_XBGRFFFF;
            case Format::XRGB8888: return &converter_XRGB8888_to_XRGB8888;
            case Format::XBGR8888: return &converter_XRGB8888_to_XBGR8888;
            case Format::RGB888: return &converter_XRGB8888_to_RGB888;
            case Format::BGR888: return &converter_XRGB8888_to_BGR888;
            case Format::RGB565: return &converter_XRGB8888_to_RGB565;
            case Format::BGR565: return &converter_XRGB8888_to_BGR565;
            case Format::XRGB1555: return &converter_XRGB8888_to_XRGB1555;
            case Format::XBGR1555: return &converter_XRGB8888_to_XBGR1555;
			default: return 0;
        }
    }

	return 0;
}
