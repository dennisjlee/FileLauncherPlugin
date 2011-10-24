#/**********************************************************\ 
#
# Auto-Generated Plugin Configuration file
# for File Launcher Plugin
#
#\**********************************************************/

set(PLUGIN_NAME "FileLauncherPlugin")
set(PLUGIN_PREFIX "FLP")
set(COMPANY_NAME "DJLee")

# ActiveX constants:
set(FBTYPELIB_NAME FileLauncherPluginLib)
set(FBTYPELIB_DESC "FileLauncherPlugin 1.0 Type Library")
set(IFBControl_DESC "FileLauncherPlugin Control Interface")
set(FBControl_DESC "FileLauncherPlugin Control Class")
set(IFBComJavascriptObject_DESC "FileLauncherPlugin IComJavascriptObject Interface")
set(FBComJavascriptObject_DESC "FileLauncherPlugin ComJavascriptObject Class")
set(IFBComEventSource_DESC "FileLauncherPlugin IFBComEventSource Interface")
set(AXVERSION_NUM "1")

# NOTE: THESE GUIDS *MUST* BE UNIQUE TO YOUR PLUGIN/ACTIVEX CONTROL!  YES, ALL OF THEM!
set(FBTYPELIB_GUID a83c0a45-a112-57fa-b362-a7d57d2303ae)
set(IFBControl_GUID f6464977-b65e-5946-956a-2cd8c7673863)
set(FBControl_GUID adbb2f05-7796-5beb-b266-1d58e51a7e95)
set(IFBComJavascriptObject_GUID fcda66fb-e9be-5f70-a661-216f661752b7)
set(FBComJavascriptObject_GUID a6e15a71-881e-55e7-bb60-56a7fd7034e6)
set(IFBComEventSource_GUID fa446869-cac5-549e-8c6c-a68703a0d28a)

# these are the pieces that are relevant to using it from Javascript
set(ACTIVEX_PROGID "DJLee.FileLauncherPlugin")
set(MOZILLA_PLUGINID "djlee.com/FileLauncherPlugin")

# strings
set(FBSTRING_CompanyName "DJ Lee")
set(FBSTRING_FileDescription "Plugin that lets javascript launch a local file using the default application.")
set(FBSTRING_PLUGIN_VERSION "1.0.0.0")
set(FBSTRING_LegalCopyright "Copyright 2011 DJ Lee")
set(FBSTRING_PluginFileName "np${PLUGIN_NAME}.dll")
set(FBSTRING_ProductName "File Launcher Plugin")
set(FBSTRING_FileExtents "")
set(FBSTRING_PluginName "File Launcher Plugin")
set(FBSTRING_MIMEType "application/x-launchlocalfile")

# Uncomment this next line if you're not planning on your plugin doing
# any drawing:

set (FB_GUI_DISABLED 1)

# Mac plugin settings. If your plugin does not draw, set these all to 0
set(FBMAC_USE_QUICKDRAW 0)
set(FBMAC_USE_CARBON 0)
set(FBMAC_USE_COCOA 0)
set(FBMAC_USE_COREGRAPHICS 0)
set(FBMAC_USE_COREANIMATION 0)
set(FBMAC_USE_INVALIDATINGCOREANIMATION 0)

# If you want to register per-machine on Windows, uncomment this line
#set (FB_ATLREG_MACHINEWIDE 1)
