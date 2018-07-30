#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "Catch.hpp"
#include "image/image_drawer.hpp"
#include <iostream>
#include <algorithm>

std::ostream& operator<<(std::ostream& os, const image::color_container_t& colors) {
    for (auto&& it : colors) {
        os << static_cast<int>(it.red) << " " 
            << static_cast<int>(it.green) << " " 
            << static_cast<int>(it.blue) << " " 
            << static_cast<int>(it.alpha) << "\n";
    }
    return os;
}

TEST_CASE( "We can write color container inside an image stream", "[image_drawer]" ) {
    image::color_container_t colors{
        {255, 255, 255, 0}, {255, 255, 255, 0}, {255, 255, 255, 0}
    };
    
    SECTION ( "We can write our colors container inside a stream" ) {
        std::ostringstream oss;
        oss << colors;
        std::string oss_str = oss.str();
        REQUIRE( oss_str == "255 255 255 0\n255 255 255 0\n255 255 255 0\n" );
    }
    SECTION ( "We can write our colors container using the image drawer" ) {
        std::ostringstream oss;
        image::image_drawer<std::ostringstream> drawer_oss{ std::move(oss) };
        drawer_oss.insert_on_stream(colors);
        std::string oss_str = drawer_oss.get_output_image().str();
        REQUIRE( oss_str == "255 255 255 0\n255 255 255 0\n255 255 255 0\n" );
    }
}
