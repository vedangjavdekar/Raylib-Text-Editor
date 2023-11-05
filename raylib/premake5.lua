project "raylib"
    kind "StaticLib"
    staticruntime "off"

	defines{
        "PLATFORM_DESKTOP",
        "GRAPHICS_API_OPENGL_43"
    }
    
    language "C"
    location "%{_MAIN_SCRIPT_DIR}/build/%{prj.name}"

    targetdir "%{_MAIN_SCRIPT_DIR}/bin/%{prj.name}/%{cfg.buildcfg}"
    objdir "%{_MAIN_SCRIPT_DIR}/bin-int/%{prj.name}/%{cfg.buildcfg}"
    debugdir "%{_MAIN_SCRIPT_DIR}/"
    
    includedirs { 
        "src", 
        "src/external/glfw/include",
        "src/extras" 
    }

    vpaths 
    {
        ["Header Files"] = { "src/**.h"},
        ["Source Files/*"] = {"src/**.c"},
    }

    files {
        "src/*.h", 
        "src/*.c"
    }

    filter "action:vs*"
        defines{
            "_WINSOCK_DEPRECATED_NO_WARNINGS", 
            "_CRT_SECURE_NO_WARNINGS"
        }
        characterset ("MBCS")
    
    filter "system:windows"
        defines{"_WIN32"}
        links {"winmm"}

    filter "configurations:Debug"
      defines { "DEBUG" }
      symbols "On"

   filter "configurations:Release"
      defines { "NDEBUG" }
      optimize "On"