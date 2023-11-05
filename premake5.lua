workspace "TextEditor"
   configurations { "Debug", "Release" }
   architecture "x86_64"
   location "build"

include "raylib/"

project "TextEditor"
   kind "ConsoleApp"
   language "C++"
   cppdialect "C++17"
   staticruntime "off"

   targetdir "bin/%{prj.name}/%{cfg.buildcfg}"
   debugdir "bin/%{prj.name}/%{cfg.buildcfg}"
   objdir "bin-int/%{prj.name}/%{cfg.buildcfg}"
   location "build/%{prj.name}"

   dependson {"raylib"}
   links{"raylib"}

   defines{
      "PLATFORM_DESKTOP",
      "GRAPHICS_API_OPENGL_43"
   }

   libdirs{
      "bin/raylib/%{cfg.buildcfg}"
   }
   files { 
      "%{prj.name}/include/**.h", 
      "%{prj.name}/include/**.hpp", 
      "%{prj.name}/src/**.cpp" 
   }

   includedirs {
      "%{prj.name}/include/",
      "raylib/src/"
   }

   filter "configurations:Debug"
      defines { "DEBUG" }
      symbols "On"

   filter "configurations:Release"
      defines { "NDEBUG" }
      optimize "On"
   
   filter "action:vs*"
      links{"raylib.lib"}