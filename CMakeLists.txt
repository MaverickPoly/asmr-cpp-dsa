cmake_minimum_required(VERSION 3.31)
project(DSA)

set(CMAKE_CXX_STANDARD 20)


# =================== Data Structures
add_executable(Point2D
    DataStructures/Geometry/Point2D/main.cpp
    DataStructures/Geometry/Point2D/point2d.cpp
    DataStructures/Geometry/Point2D/point2d.h
)
add_executable(Vector2
    DataStructures/Geometry/Vector2/main.cpp
    DataStructures/Geometry/Vector2/vector2.cpp
    DataStructures/Geometry/Vector2/vector2.h
)
add_executable(Rect
    DataStructures/Geometry/Rect/main.cpp
    DataStructures/Geometry/Rect/rect.cpp
    DataStructures/Geometry/Rect/rect.h
    DataStructures/Geometry/Vector2/vector2.cpp
)
add_executable(Circle
    DataStructures/Geometry/Circle/main.cpp
    DataStructures/Geometry/Circle/circle.cpp
    DataStructures/Geometry/Circle/circle.h
    DataStructures/Geometry/Vector2/vector2.cpp
    DataStructures/Geometry/Point2D/point2d.cpp
)

add_executable(Stack
    DataStructures/Node/Stack/main.cpp
    DataStructures/Node/Stack/stack.tpp
    DataStructures/Node/Stack/stack.h
)
add_executable(Queue
    DataStructures/Node/Queue/main.cpp
    DataStructures/Node/Queue/queue.tpp
    DataStructures/Node/Queue/queue.h
)
add_executable(LinkedList
    DataStructures/Node/LinkedList/main.cpp
        DataStructures/Node/LinkedList/linked_list.tpp
        DataStructures/Node/LinkedList/linked_list.h
)





# =================== Algorithms




set_target_properties(Point2D PROPERTIES FOLDER "Geometry")
