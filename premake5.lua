workspace "ZTracer"
   configurations { "Debug", "Release" }
   location "build"
   flags { "FatalWarnings", "UndefinedIdentifiers", "ShadowedVariables" }
   warnings "Extra"
   cppdialect "C++17"
   
project "ZTracer"
   kind "ConsoleApp"
   language "C++"
   includedirs { "./", "./include" }
   files { "./src/**.cpp", "./include/**.hh", "./include/**.hpp" }
   filter { "configurations:Debug" }
       defines { "DEBUG" }
       symbols "On"

   filter { "configurations:Release" }
       defines { "NDEBUG" }
       optimize "On"

newaction {
    trigger     = "clean",
    description = "Clean the build",
    execute     = function ()
       print("clean the premake generated source files...")
       os.rmdir("build")
       print("done.")
    end
 }