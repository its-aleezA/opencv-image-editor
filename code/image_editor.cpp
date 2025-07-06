/*#include <stdio.h>
#include <opencv2/opencv.hpp>

using namespace cv;
int main(int argc, char** argv )
{

    Mat image;
    image = imread("C:/Users/ABC/Downloads/lenna.png");
    if ( !image.data )
    {
        printf("No image data \n");
        return -1;
    }
    namedWindow("Display Image", WINDOW_AUTOSIZE );
    imshow("Display Image", image);
    waitKey(0);
    return 0;
}*/

#include <opencv2/opencv.hpp>
#include <iostream>
#include <string>

using namespace cv;
using namespace std;

// ImageEditor Class
class ImageEditor
{
    private:
    Mat image;   // Original image
    Mat preview; // Edited image

    public:
    // Load Image
    bool loadImage(const string& path)
    {
        image = imread(path);
        if (image.empty())
        {
            cout << "Error: Could not load the image!" << endl;
            return false;
        }
        preview = image.clone();
        return true;
    }

    // Save Image
    bool saveImage(const string& path)
    {
        if (imwrite(path, preview))
        {
            cout << "Image saved successfully at: " << path << endl;
            return true;
        }
        else
        {
            cout << "Error: Could not save the image!" << endl;
            return false;
        }
    }

    // Display Image
    void displayImage(const string& windowName, const Mat& img) const
    {
        if (img.empty())
        {
            cout << "Error: Image is empty and cannot be displayed!" << endl;
            return;
        }
        namedWindow(windowName, WINDOW_AUTOSIZE);
        imshow(windowName, img);
    }

    // Getter for Original Image
    Mat getOriginalImage() const
    {
        return image;
    }

    // Resize Image
    void resizeImage(int width, int height)
    {
        resize(image, preview, Size(width, height));
    }

    // Crop Image
    void cropImage(int x, int y, int width, int height)
    {
        Rect roi(x, y, width, height);
        if (roi.x + roi.width <= image.cols && roi.y + roi.height <= image.rows)
        {
            preview = image(roi).clone();
        }
        else
        {
            cout << "Error: Cropping region is out of bounds!" << endl;
        }
    }

    // Rotate Image
    void rotateImage(double angle)
    {
        Point2f center(preview.cols / 2.0, preview.rows / 2.0);
        Mat rotationMatrix = getRotationMatrix2D(center, angle, 1.0);
        warpAffine(preview, preview, rotationMatrix, preview.size());
    }

    // Apply Grayscale Filter
    void applyGrayscale()
    {
        cvtColor(preview, preview, COLOR_BGR2GRAY);
    }

    // Apply Blur Filter
    void applyBlur(int kernelSize)
    {
        GaussianBlur(preview, preview, Size(kernelSize, kernelSize), 0);
    }

    // Adjust Brightness and Contrast
    void adjustBrightnessContrast(double alpha, int beta)
    {
        preview.convertTo(preview, -1, alpha, beta);
    }

    // Preview Changes
    void previewChanges()
    {
        displayImage("Preview", preview);
    }
};

int main()
{
    ImageEditor editor;
    string inputPath, outputPath;
    int choice;

    cout << "Enter the path of the image to load: ";
    cin >> inputPath;

    if (!editor.loadImage(inputPath))
    {
        return -1;
    }

    // Display the original image
    editor.displayImage("Original Image", editor.getOriginalImage());
    waitKey(0); // Wait for user input to close the window

    do {
        cout << "\nImage Editor Menu:\n";
        cout << "1. Resize Image\n";
        cout << "2. Crop Image\n";
        cout << "3. Rotate Image\n";
        cout << "4. Apply Grayscale\n";
        cout << "5. Apply Blur\n";
        cout << "6. Adjust Brightness/Contrast\n";
        cout << "7. Preview Changes\n";
        cout << "8. Save Image\n";
        cout << "9. Exit\n";
        cout << "Choose an option: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
            {
                int width, height;
                cout << "Enter new width: ";
                cin >> width;
                cout << "Enter new height: ";
                cin >> height;
                editor.resizeImage(width, height);
                break;
            }
            case 2:
            {
                int x, y, width, height;
                cout << "Enter x, y, width, and height for cropping: ";
                cin >> x >> y >> width >> height;
                editor.cropImage(x, y, width, height);
                break;
            }
            case 3:
            {
                double angle;
                cout << "Enter angle to rotate (in degrees): ";
                cin >> angle;
                editor.rotateImage(angle);
                break;
            }
            case 4:
                editor.applyGrayscale();
                break;
            case 5:
            {
                int kernelSize;
                cout << "Enter kernel size for blur (odd number): ";
                cin >> kernelSize;
                editor.applyBlur(kernelSize);
                break;
            }
            case 6:
            {
                double alpha;
                int beta;
                cout << "Enter alpha (contrast [1.0-3.0]): ";
                cin >> alpha;
                cout << "Enter beta (brightness [-100 to 100]): ";
                cin >> beta;
                editor.adjustBrightnessContrast(alpha, beta);
                break;
            }
            case 7:
                editor.previewChanges();
                waitKey(0); // Wait for user input before closing the preview
                break;
            case 8:
                cout << "Enter the path to save the image: ";
                cin >> outputPath;
                editor.saveImage(outputPath);
                break;
            case 9:
                cout << "Exiting editor." << endl;
                break;
            default:
                cout << "Invalid choice, please try again." << endl;
        }
    } while (choice != 9);

    destroyAllWindows();
    return 0;
}
