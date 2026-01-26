project "Spark"
kind "StaticLib"
staticruntime "off"

targetdir("%{wks.location}/bin/" .. outputdir .. "/%{prj.name}")
objdir("%{wks.location}/bin-int/" .. outputdir .. "/%{prj.name}")

files
{
    "Src/**.cpp",
    "Src/**.h",
}


includedirs
{
    "Src",
}

defines
{
}

links
{
}


filter "system:linux"
systemversion "latest"

defines
{
}

links
{
}

filter "configurations:Debug"
defines "SPARK_DEBUG"
runtime "Debug"
symbols "on"

links
{
}

filter "configurations:Release"
defines "SPARK_RELEASE"
runtime "Release"
optimize "on"

links
{
}
