#include "HelpCommand.h"

void HelpCommand::execute(Application& application) const
{
    printInformation();
}

static void printInformation()
{
    std::cout << "Available commands:\n";
    std::cout << "1. load <filename> ...\n";
    std::cout << "   - Starts a new session and loads the specified image(s).\n";
    std::cout << "     Example: load image1.ppm image2.pgm\n";
    std::cout << "     Output: Session with ID: <id> started\n\n";

    std::cout << "2. add <image>\n";
    std::cout << "   - Adds the specified image to the current session.\n";
    std::cout << "     Example: add image3.ppm\n\n";

    std::cout << "3. save\n";
    std::cout << "   - Saves all images in the current session, applying all pending transformations.\n\n";

    std::cout << "4. saveas <filename>\n";
    std::cout << "   - Saves the first loaded image in the current session under a new name, applying all pending transformations.\n";
    std::cout << "     Example: saveas new_image.ppm\n\n";

    std::cout << "5. close\n";
    std::cout << "   - Closes the current session without saving.\n\n";

    std::cout << "6. exit\n";
    std::cout << "   - Exits the application.\n\n";

    std::cout << "7. help\n";
    std::cout << "   - Displays this help message.\n\n";

    std::cout << "8. grayscale\n";
    std::cout << "   - Applies a grayscale transformation to all color images in the current session.\n\n";

    std::cout << "9. monochrome\n";
    std::cout << "   - Converts all images in the current session to monochrome (black and white).\n\n";

    std::cout << "10. negative\n";
    std::cout << "    - Applies a negative transformation to all images in the current session.\n\n";

    std::cout << "11. rotate <direction>\n";
    std::cout << "    - Rotates all images in the current session 90 degrees in the specified direction (left or right).\n";
    std::cout << "      Example: rotate left\n\n";

    std::cout << "12. undo\n";
    std::cout << "    - Reverts the last transformation applied in the current session.\n\n";

    std::cout << "13. session info\n";
    std::cout << "    - Displays information about the current session, including session ID, loaded images, and pending transformations.\n\n";

    std::cout << "14. switch <session>\n";
    std::cout << "    - Switches to the specified session by its ID. If the session does not exist, an error message is displayed.\n";
    std::cout << "      Example: switch 2\n\n";

    std::cout << "15. collage <direction> <image1> <image2> <outimage>\n";
    std::cout << "    - Creates a collage of two images from the current session in the specified direction (horizontal or vertical) and saves it as a new image.\n";
    std::cout << "      Example: collage horizontal image1.ppm image2.ppm output_collage.ppm\n";
}


}