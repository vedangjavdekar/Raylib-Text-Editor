project "raylib"
    filter "configurations:Debug.DLL OR Release.DLL"
        kind "SharedLib"
        defines {"BUILD_LIBTYPE_SHARED"}
        
    filter "configurations:Debug OR Release"
        kind "StaticLib"
        
    filter "action:vs*"
        defines{"_WINSOCK_DEPRECATED_NO_WARNINGS", "_CRT_SECURE_NO_WARNINGS"}
        characterset ("MBCS")
    
    filter "system:windows"
        defines{"_WIN32"}
        links {"winmm"}
        
    filter "system:linux"
        links {"pthread", "GL", "m", "dl", "rt", "X11"}
        
    filter{}
    
	defines{"PLATFORM_DESKTOP"}
    if (_OPTIONS["opengl43"]) then
		defines{"GRAPHICS_API_OPENGL_43"}
	else
		defines{"GRAPHICS_API_OPENGL_33"}
	end
    
    language "C"
    location "%{_MAIN_SCRIPT_DIR}/build/%{prj.name}"

    targetdir "%{_MAIN_SCRIPT_DIR}/bin/%{prj.name}/%{cfg.buildcfg}"
    objdir "%{_MAIN_SCRIPT_DIR}/bin-int/%{prj.name}/%{cfg.buildcfg}"
    debugdir "%{_MAIN_SCRIPT_DIR}/"
    
    includedirs { "src", "src/external/glfw/include","src/extras" }
    vpaths 
    {
        ["Header Files"] = { "src/**.h"},
        ["Source Files/*"] = {"src/**.c"},
    }
    files {"src/*.h", "src/*.c"}