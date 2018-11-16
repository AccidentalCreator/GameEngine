cmake_minimum_required(VERSION 2.6)
project(GAMEENGINE)

if(MSVC)
  include_directories(
    src
    contrib/msvc-windows-x86/glew/include
    contrib/msvc-windows-x86/SDL2/include
    contrib/msvc-windows-x86/SDL2_image/include
    contrib/msvc-windows-x86/GLM
    contrib/msvc-windows-x86/openal-soft/include
    contrib/msvc-windows-x86/ogg/include
    contrib/msvc-windows-x86/vorbis/include
  )

  link_directories(
    ${CMAKE_SOURCE_DIR}/contrib/msvc-windows-x86/SDL2/lib
    ${CMAKE_SOURCE_DIR}/contrib/msvc-windows-x86/SDL2_image/lib
    ${CMAKE_SOURCE_DIR}/contrib/msvc-windows-x86/glew/lib
    ${CMAKE_SOURCE_DIR}/contrib/msvc-windows-x86/GLM
    ${CMAKE_SOURCE_DIR}/contrib/msvc-windows-x86/openal-soft/lib
    ${CMAKE_SOURCE_DIR}/contrib/msvc-windows-x86/ogg/lib
    ${CMAKE_SOURCE_DIR}/contrib/msvc-windows-x86/vorbis/lib
  )

endif()

if(MSVC)
  add_definitions(-DSDL_MAIN_HANDLED)
endif()

add_executable(game
	src/game/PlayerHandler.h
	src/game/CameraHandler.h
	src/game/FloorBlock.h
	src/game/FloorManager.h

	src/game/main.cpp
	src/game/PlayerHandler.cpp
	src/game/CameraHandler.cpp
	src/game/FloorBlock.cpp
	src/game/FloorManager.cpp
)

if(MSVC)
  target_link_libraries(game
    SDL2 SDL2_image glew32 opengl32 OpenAL32 ogg vorbis vorbisfile
  )
else()
  target_link_libraries(game
    SDL2 SDL2_image GLU GLEW GL AL ogg vorbis vorbisfile
  )
endif()

if(MSVC)
  add_custom_command(TARGET game POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
      "${CMAKE_SOURCE_DIR}/contrib/msvc-windows-x86/SDL2/bin/SDL2.dll"
      "$<TARGET_FILE_DIR:GameEngine>"
  )

  add_custom_command(TARGET game POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
      "${CMAKE_SOURCE_DIR}/contrib/msvc-windows-x86/glew/bin/glew32.dll"
      "$<TARGET_FILE_DIR:GameEngine>"
  )

  add_custom_command(TARGET game POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
      "${CMAKE_SOURCE_DIR}/contrib/msvc-windows-x86/openal-soft/bin/OpenAL32.dll"
      "$<TARGET_FILE_DIR:GameEngine>"
  )
endif()


add_library(GameEngine
	src/GameEngine/Core.h
	src/GameEngine/Environment.h
	src/GameEngine/Entity.h
	src/GameEngine/KeyboardHandler.h
	src/GameEngine/MouseHandler.h
	src/GameEngine/Component.h
	src/GameEngine/GameEngine.h
	src/GameEngine/Screen.h
	src/GameEngine/stb_image.h
	src/GameEngine/Sound.h
	src/GameEngine/Exception.h
	src/GameEngine/Transform.h
	src/GameEngine/Camera.h
	src/GameEngine/Resources.h
	src/GameEngine/BoxCollision.h
	src/GameEngine/Button.h
	src/GameEngine/Orthagraphic.h
	src/GameEngine/Timer.h
	src/GameEngine/Texture.h
	src/GameEngine/StaticMeshCollider.h
	src/GameEngine/Mesh.h
	src/GameEngine/Face.h

	src/GameEngine/VertexBuffer.h
	src/GameEngine/VertexArray.h
	src/GameEngine/ShaderProgram.h
	src/GameEngine/MeshRenderer.h


	src/GameEngine/Core.cpp
	src/GameEngine/Environment.cpp
	src/GameEngine/Entity.cpp
	src/GameEngine/KeyboardHandler.cpp
	src/GameEngine/MouseHandler.cpp
	src/GameEngine/Component.cpp
	src/GameEngine/GameEngine.cpp
	src/GameEngine/Screen.cpp
	src/GameEngine/stb_image.cpp
	src/GameEngine/Sound.cpp
	src/GameEngine/Exception.cpp
	src/GameEngine/Transform.cpp
	src/GameEngine/Camera.cpp
	src/GameEngine/Resources.cpp
	src/GameEngine/BoxCollision.cpp
	src/GameEngine/Button.cpp
	src/GameEngine/Orthagraphic.cpp
	src/GameEngine/Timer.cpp
	src/GameEngine/Texture.cpp
	src/GameEngine/StaticMeshCollider.cpp
	src/GameEngine/Mesh.cpp
	src/GameEngine/Face.cpp
	src/GameEngine/tribox.cpp

	src/GameEngine/VertexBuffer.cpp
	src/GameEngine/VertexArray.cpp
	src/GameEngine/ShaderProgram.cpp
	src/GameEngine/MeshRenderer.cpp
)
	
target_link_libraries(game GameEngine)
target_link_libraries(GameEngine SDL2 SDL2_image glew32 opengl32)


