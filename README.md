# Raster Graphics
This project was developed by me as part of the OOP Practicum @ Faculty of Mathematics and Informatics, Sofia University. It implements a console-based raster image editor that allows users to manipulate various image formats such as PPM, PGM, and PBM. The editor supports session-based management, where images can be loaded, transformed, and saved with various operations such as rotating, applying grayscale, converting to monochrome, creating collages, and more.

## Key Features
- **Session Management**: Manage multiple user sessions, each of which can hold multiple images.
- **Image Transformations**: Apply various transformations to images, such as rotating, converting to grayscale, applying a negative effect, and more.
- **Collage Creation**: Create horizontal or vertical collages from two images within the same session.
- **Multiple Image Formats Supported**: Works with PPM, PGM, and PBM image files.
- **Session Info**: Get detailed information about the current session, including the images involved and pending transformations.
  
## Commands
### General Commands
- `load <file1> <file2> ...`: Loads one or more images into the current session. If a session does not exist, it creates a new one.
Example: load image1.ppm
Output: Session with ID: 1 started

- `close`: Closes the current session and all images associated with it.
- `save`: Saves all images in the current session after applying all transformations.
- `saveas <filename>`: Saves the first loaded image in the session under a new filename.
- `help`: Lists all available commands.
- `exit`: Exits the application.
  
### Image Transformations
- `grayscale`: Converts all color images in the current session to grayscale (does not affect black and white images).
- `monochrome`: Converts all color images in the current session to monochrome (black and white only).
- `negative`: Applies a color inversion (negative effect) to all images in the current session.
- `rotate <direction>`: Rotates the current image 90 degrees in the specified direction (left or right).
- `undo`: Reverts the last transformation requested in the current session.
- `add <image>`: Adds an image to the current session without applying any previous transformations.
- `session info`: Displays detailed information about the current session, including image names and pending transformations.
- `switch <session_id>`: Switches to an existing session with the specified ID.
- `collage <direction> <image1> <image2> <output_image>`: Creates a collage from two images (image1 and image2) in the specified direction (horizontal or vertical), and saves it as a new image (output_image).
