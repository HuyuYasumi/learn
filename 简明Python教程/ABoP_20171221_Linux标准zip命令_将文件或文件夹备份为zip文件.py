import os
import time

#需要备份的文件或文件夹
source=["F:\learn\简明Python教程\Python_temp\新建文件夹"]
#主备份文件夹
target_dir='F:\learn\简明Python教程\Python_temp\新建文件夹 (2)'

#备份目录及文件名
target=target_dir+os.sep+time.strftime('%Y%m%d%H%M%S')+'.zip'
#如不存在目标目录，则创建
if not os.path.exists(target_dir):
    os.mkdir(target_dir)

#使用zip命令将文件打包成zip格式文件
zip_command='zip -r {0} {1}'.format(target, ' '.join(source))

#运行备份
print('Zip command is:')
print(zip_command)
print('Running:')
if os.system(zip_command) == 0:
    print('Successful backup to', target)
else:
    print('Backup FAILED')
