# CMakeList.txt : CMake project for test, include source and define
# project specific logic here.
#

enable_testing()

include_directories("../.." ".")

# Add source to this project's executable.
add_executable (test "test.cpp"  "../../socket.h" "../../socket.cpp"  "../../courier.cpp" "../../courier.h" "../../point.cpp" "../../point.h" "../../order.cpp" "../../order.h" "../../storage.cpp" "../../storage.h" "../../time_manager.cpp" "../../time_manager.h" "../../point_manager.cpp" "../../point_manager.h" "../../database_manager.cpp" "../../database_manager.h")


if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET test PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
# https://github.com/catchorg/Catch2/releases/download/v2.13.3/catch.hpp
add_test(test test_storage test_courier)
