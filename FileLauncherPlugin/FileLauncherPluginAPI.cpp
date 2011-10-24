/**********************************************************\

  Auto-generated FileLauncherPluginAPI.cpp

\**********************************************************/

#include "JSObject.h"
#include "variant_list.h"
#include "DOM/Document.h"
#include "DOM/Window.h"

// TODO(djlee): this is win only, use an #if
#include <windows.h>
#include <ShellAPI.h>
#include <tchar.h>

#include "FileLauncherPluginAPI.h"

///////////////////////////////////////////////////////////////////////////////
/// @fn FileLauncherPluginAPI::FileLauncherPluginAPI(const FileLauncherPluginPtr& plugin, const FB::BrowserHostPtr host)
///
/// @brief  Constructor for your JSAPI object.  You should register your methods, properties, and events
///         that should be accessible to Javascript from here.
///
/// @see FB::JSAPIAuto::registerMethod
/// @see FB::JSAPIAuto::registerProperty
/// @see FB::JSAPIAuto::registerEvent
///////////////////////////////////////////////////////////////////////////////
FileLauncherPluginAPI::FileLauncherPluginAPI(const FileLauncherPluginPtr& plugin, const FB::BrowserHostPtr& host) : m_plugin(plugin), m_host(host)
{
    registerMethod("echo",      make_method(this, &FileLauncherPluginAPI::echo));
    registerMethod("testEvent", make_method(this, &FileLauncherPluginAPI::testEvent));
    registerMethod("launchFile", make_method(this, &FileLauncherPluginAPI::launchFile));

    // Read-write property
    registerProperty("testString",
                     make_property(this,
                        &FileLauncherPluginAPI::get_testString,
                        &FileLauncherPluginAPI::set_testString));

    // Read-only property
    registerProperty("version",
                     make_property(this,
                        &FileLauncherPluginAPI::get_version));
}

///////////////////////////////////////////////////////////////////////////////
/// @fn FileLauncherPluginAPI::~FileLauncherPluginAPI()
///
/// @brief  Destructor.  Remember that this object will not be released until
///         the browser is done with it; this will almost definitely be after
///         the plugin is released.
///////////////////////////////////////////////////////////////////////////////
FileLauncherPluginAPI::~FileLauncherPluginAPI()
{
}

///////////////////////////////////////////////////////////////////////////////
/// @fn FileLauncherPluginPtr FileLauncherPluginAPI::getPlugin()
///
/// @brief  Gets a reference to the plugin that was passed in when the object
///         was created.  If the plugin has already been released then this
///         will throw a FB::script_error that will be translated into a
///         javascript exception in the page.
///////////////////////////////////////////////////////////////////////////////
FileLauncherPluginPtr FileLauncherPluginAPI::getPlugin()
{
    FileLauncherPluginPtr plugin(m_plugin.lock());
    if (!plugin) {
        throw FB::script_error("The plugin is invalid");
    }
    return plugin;
}



// Read/Write property testString
std::string FileLauncherPluginAPI::get_testString()
{
    return m_testString;
}
void FileLauncherPluginAPI::set_testString(const std::string& val)
{
    m_testString = val;
}

// Read-only property version
std::string FileLauncherPluginAPI::get_version()
{
    return "CURRENT_VERSION";
}

// Method echo
FB::variant FileLauncherPluginAPI::echo(const FB::variant& msg)
{
    static int n(0);
    fire_echo(msg, n++);
    return msg;
}

void FileLauncherPluginAPI::testEvent(const FB::variant& var)
{
    fire_fired(var, true, 1);
}

bool startsWith(std::string haystack, std::string needle)
{
  return haystack.compare(0, needle.size(), needle) == 0;
}

int FileLauncherPluginAPI::launchFile(const std::wstring& filename)
{
    // Forbid anything besides file:// and localhost.
    std::string location = m_host->getDOMWindow()->getLocation();
    std::string filePrefix("file://");
    std::string httpLocalhostPrefix("http://localhost");
    std::string httpsLocalhostPrefix("https://localhost/");
    if (startsWith(location, filePrefix) || startsWith(location, httpLocalhostPrefix) ||
        startsWith(location, httpsLocalhostPrefix)) {
      return (int)ShellExecute(NULL, _T("open"), filename.c_str(), NULL, NULL,
          SW_SHOW); /* consider SW_MAXIMIZE */
    } else {
      return -1;
    }
}