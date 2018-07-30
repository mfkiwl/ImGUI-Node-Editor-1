PROJ_DIR = os.getcwd()

solution "Node-Editor"
location(path.join(PROJ_DIR,"build/"))

configurations {
	"debug",
	"release",
}
platforms {
	"x64",
}

language "C++"

	project "node-editor"
		configurations "debug"
			targetdir (path.join(PROJ_DIR,"build/debug"))
		configurations "release"
			targetdir (path.join(PROJ_DIR,"build/release"))

	location "build/"
	kind "ConsoleApp"

	configuration "debug"
		targetdir (path.join(PROJ_DIR,"build/debug"))
		debugdir(path.join(PROJ_DIR,"build/debug"))
	configuration "release"
		targetdir (path.join(PROJ_DIR,"build/release"))
		debugdir(path.join(PROJ_DIR,"build/release"))

	configuration {}
	libdirs{
		path.join(PROJ_DIR,"lib/"),
	}
	links {
		"opengl32",
		"glfw3",
	}
	includedirs{
		path.join(PROJ_DIR,"include/"),
	}


	files {
		path.join(PROJ_DIR,"source/*.cpp"),
		path.join(PROJ_DIR,"source/*.c"),
		path.join(PROJ_DIR,"source/*.h"),
	}