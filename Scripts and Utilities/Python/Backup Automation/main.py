import shutil
from datetime import date
import os
import sys

os.chdir(sys.path[0])

def take_backup(src_file_name, dst_file_name=None, src_dir='', dst_dir=''):
    if not src_file_name:
        return

    today = date.today()
    date_format = today.strftime("%d_%b_%Y_")
    src_path = os.path.join(src_dir, src_file_name)

    if not dst_file_name or dst_file_name.isspace():
        dst_file_name = src_file_name

    dst_path = os.path.join(dst_dir, date_format + dst_file_name)

    try:
        shutil.copy2(src_path, dst_path)
        print("Backup Successful")
    except FileNotFoundError:
        print("Source file or directory does not exist")
    except PermissionError:
        shutil.copytree(src_path, dst_path)
        print("Backup Successful (Folder)")
    except Exception as e:
        print(f"Error: {e}")

take_backup("main.py")
take_backup("main.py", dst_dir="C:/Users/rahlo/OneDrive/Fork/ForkQuest/Scripts and Utilities/Python/Backup Automation/Backups")
take_backup("main.py", "backup_main.py", dst_dir="C:/Users/rahlo/OneDrive/Fork/ForkQuest/Scripts and Utilities/Python/Backup Automation/Backups")
take_backup("Backup Automation", dst_dir="C:/Users/rahlo/OneDrive/Fork/ForkQuest/Scripts and Utilities/Python/Backup Automation/Backups")