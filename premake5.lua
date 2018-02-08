workspace "ZTracer"
   configurations { "Debug", "Release" }
   location "build"
   flags { "FatalWarnings", "UndefinedIdentifiers", "ShadowedVariables" }
   warnings "Extra"
   cppdialect "C++17"
   links { "m" }
   
project "ZTracer"
   kind "ConsoleApp"
   language "C++"
   includedirs { "./", "./include" }
   files { "./src/**.cpp", "./include/**.hh", "./include/**.hpp", "./main.cpp" }
   filter { "configurations:Debug" }
       defines { "DEBUG" }
       symbols "On"

   filter { "configurations:Release" }
       defines { "NDEBUG" }
       optimize "On"

project "ZTracerUnitTest"
    kind "ConsoleApp"
    language "C++"
    includedirs { "./", "./include", "./test" }
    files { "./src/**.cpp", "./include/**.hh", "./include/**.hpp", "./test/**.cpp" }
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
