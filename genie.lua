PROJ_DIR = os.getcwd()

solution "Node-Editor"
	location (path.join(PROJ_DIR,"build/"))

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

		debugdir(path.join(PROJ_DIR,"build/debug"))

		files {
			path.join(PROJ_DIR,"source/*.cpp")
			path.join(PROJ_DIR,"source/*.h")
		}