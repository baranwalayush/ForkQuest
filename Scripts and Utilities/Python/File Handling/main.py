# This script demonstrates basic file sorting and organization in Python.
# take input from terminal for a folder path,
import os
import sys
import shutil

supported_formats = ['jpg', 'pdf', 'xlsx', 'mp4', 'mp3', 'jp2', 'png', 'js', 'go', 'sh']

def organize_files_by_extension(folder_path):
    # Create a directory for each file type
    for filename in os.listdir(folder_path):
        if os.path.isfile(os.path.join(folder_path, filename)):
            file_extension = filename.split('.')[-1]
            extension_folder = os.path.join(file_extension, file_extension)
            others_path = os.path.join(folder_path, 'others')

            if file_extension in supported_formats:
                if not os.path.exists(extension_folder):
                    os.makedirs(extension_folder)

                shutil.move(os.path.join(folder_path, filename), os.path.join(extension_folder, filename))
            else:
                if not os.path.exists(others_path):
                    os.makedirs(others_path)

                shutil.move(os.path.join(folder_path, filename), os.path.join(others_path, filename))
            
    print("Files have been organized by extension.")

def list_files_in_directory(folder_path):
    print(f"Files in directory '{folder_path}':")

    for filename in os.listdir(folder_path):
        print(filename)
    
def main():
    if len(sys.argv) < 1:
        folder_path = sys.argv[1]
    else:
        folder_path = input("Please enter the folder path: ")
    
    list_files_in_directory(folder_path)
    organize_files_by_extension(folder_path)
    list_files_in_directory(folder_path)


if __name__ == "__main__":
    main()