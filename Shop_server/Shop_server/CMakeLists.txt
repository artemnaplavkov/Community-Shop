# CMakeList.txt: проект CMake для Shop_server; включите исходный код и определения,
# укажите здесь логику для конкретного проекта.
#
include_directories("../..")

# Добавьте источник в исполняемый файл этого проекта.
add_executable (Shop_server "Shop_server.cpp" "../../menu.h" "../../menu.cpp" "../../socket.h" "../../socket.cpp"  "../../courier.cpp" "../../courier.h" "../../point.cpp" "../../point.h" "../../order.cpp" "../../order.h" "../../storage.cpp" "../../storage.h" "../../time_manager.cpp" "../../time_manager.h" "../../point_manager.cpp" "../../point_manager.h" "../../database_manager.cpp" "../../database_manager.h")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET Shop_server PROPERTY CXX_STANDARD 20)
endif()

# TODO: Добавьте тесты и целевые объекты, если это необходимо.
