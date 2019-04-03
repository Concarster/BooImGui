project "SOIL2"
    kind "StaticLib"
    language "C++"
    
	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bint/" .. outputdir .. "/%{prj.name}")

	files
	{
        "srcs/etc1_utils.c",
        "srcs/image_DXT.c",
        "srcs/image_helper.c",
        "srcs/SOIL2.c"
    }
    
	filter "system:windows"
        buildoptions { "-std=c17", "-lgdi32" }
        systemversion "latest"
        staticruntime "On"
        
        --files{}
        includedirs {
         "incs"
        }

		filter "system:windows"
        buildoptions { "-std=c17", "-lgdi32" }
        systemversion "latest"
        staticruntime "On"
        
        
    filter { "system:windows", "configurations:Release" }
        buildoptions "/MT"