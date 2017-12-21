import os
import time

#需要备份的文件或文件夹
source = ["F:\learn\简明Python教程\Python_temp\新建文件夹", "F:\learn\简明Python教程\Python_temp\新建文件夹2"]
#主备份文件夹
target_dir = 'F:\learn\简明Python教程\Python_temp'
#如不存在目标目录，则创建
if not os.path.exists(target_dir):
    os.mkdir(target_dir)

#将当前日期作为主备份目录下的子目录名称
today = target_dir + os.sep + time.strftime('%Y%m%d')
#将当前时间作为zip文件的文件名
now = time.strftime('%H%M%S')
#zip文件名的格式
target = today + os.sep + now + '.zip'
#如子目录不存在，则创建它
if not os.path.exists(today):
    os.mkdir(today)
    print('Successfully created directory', today)

#使用zip命令将文件打包成zip格式文件
zip_command = 'zip -r {0} {1}'.format(target, ' '.join(source))

#运行备份
print('Zip command is:')
print(zip_command)
print('Running:')
if os.system(zip_command) == 0:
    print('Successful backup to', target)
else:
    print('Backup FAILED')
