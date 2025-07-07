# 🖼️ OpenCV Image Editor (C++)

A feature-rich, terminal-based image editor written in C++ using the OpenCV library. This editor allows users to perform common image manipulation tasks such as resizing, cropping, rotating, applying filters, and adjusting brightness and contrast.

Built for learning, testing, and offline image manipulation directly from the console.

---

## 🔧 Features

- ✅ Load and preview images
- ✂️ Crop to a specific region
- 🔄 Rotate to any angle
- 🖌 Grayscale & Gaussian Blur filters
- 💡 Brightness and contrast adjustments
- 💾 Save changes to disk
- 🖼️ Live preview with OpenCV GUI windows

---

## 📷 Sample Commands (Menu-Driven)

1. Resize Image
2. Crop Image
3. Rotate Image
4. Apply Grayscale
5. Apply Blur
6. Adjust Brightness/Contrast
7. Preview Changes
8. Save Image
9. Exit

---

## 💻 Dependencies

- C++17+

- OpenCV 4.x

---

## 🛠️ Build & Run

### 🧱 Compile:
          g++ code/image_editor.cpp -o image_editor `pkg-config --cflags --libs opencv4`
Adjust opencv4 to opencv if using OpenCV 3.

### ▶️ Run:
          ./image_editor

---

## 🗂 Folder Structure

| Path	| Description |
| ----------- | ----------- |
| code/ |	Contains the .cpp source file |
| assets/ |	Sample image |

---

## 👤 Author

[Aleeza Rizwan](https://github.com/its-aleezA)

---

## 🔖 License

This project is licensed under the MIT License.
See the [LICENSE](LICENSE) file for details.
