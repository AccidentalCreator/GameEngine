cmake_minimum_required(VERSION 2.6)
project(GAMEENGINE)

if(MSVC)
  include_directories(
    src
    contrib/msvc-windows-x86/glew/include
    contrib/msvc-windows-x86/SDL2/include
    contrib/msvc-windows-x86/SDL2_image/include
    contrib/msvc-windows-x86/GLM
  )

  link_directories(
    ${CMAKE_SOURCE_DIR}/contrib/msvc-windows-x86/SDL2/lib
   ${CMAKE_SOURCE_DIR}/contrib/msvc-windows-x86/SDL2_image/lib
    ${CMAKE_SOURCE_DIR}/contrib/msvc-windows-x86/glew/lib
    ${CMAKE_SOURCE_DIR}/contrib/msvc-windows-x86/GLM
  )
endif()

if(MSVC)
  add_definitions(-DSDL_MAIN_HANDLED)
endif()

add_executable(game
	src/game/main.cpp
)

if(MSVC)
  target_link_libraries(game
    SDL2 SDL2_image glew32 opengl32
  )
else()
  target_link_libraries(game
    SDL2 SDL2_image GLU GLEW GL
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
endif()


add_library(GameEngine
	src/GameEngine/Core.h
	src/GameEngine/Environment.h
	src/GameEngine/Entity.h
	src/GameEngine/Keyboard.h
	src/GameEngine/Component.h
	src/GameEngine/GameEngine.h
	src/GameEngine/Screen.h

	src/GameEngine/VertexBuffer.h
	src/GameEngine/VertexArray.h
	src/GameEngine/ShaderProgram.h
	src/GameEngine/MeshRenderer.h


	src/GameEngine/Core.cpp
	src/GameEngine/Environment.cpp
	src/GameEngine/Entity.cpp
	src/GameEngine/Keyboard.cpp
	src/GameEngine/Component.cpp
	src/GameEngine/GameEngine.cpp
	src/GameEngine/Screen.cpp

	src/GameEngine/VertexBuffer.cpp
	src/GameEngine/VertexArray.cpp
	src/GameEngine/ShaderProgram.cpp
	src/GameEngine/MeshRenderer.cpp
)
	
target_link_libraries(game GameEngine)
target_link_libraries(GameEngine SDL2 SDL2_image glew32 opengl32)


