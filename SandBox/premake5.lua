project "SandBox"
kind "ConsoleApp"
staticruntime "off"

targetdir("%{wks.location}/bin/" .. outputdir .. "/%{prj.name}")
objdir("%{wks.location}/bin-int/" .. outputdir .. "/%{prj.name}")

files
{
    "Src/**.h",
    "Src/**.cpp"
}

includedirs
{
    "Src",
	"%{wks.location}/Spark/Src"
}

links
{
    "Spark"
}

filter "system:linux"
systemversion "latest"

filter "configurations:Debug"
defines "SPARK_DEBUG"
runtime "Debug"
symbols "on"

filter "configurations:Release"
defines "SPARK_RELEASE"
runtime "Release"
optimize "on"
