import sys
sys.path.append("/home/natsu/文档/git/learn/Scrapy_dingdian/Scrapy_dingdian")
from mysqlpipelines.sql import Sql
from items import ScrapyDingdianItem

class DingdianPipeline():
    def process_item(self, item, spider):
        if isinstance(item, ScrapyDingdianItem):
            name_id = item['name_id']
            ret = Sql.select_name(name_id)
            if ret[0] == 1:
                print('已存在')
                pass
            else:
                xs_name = item['name']
                xs_author = item['author']
                category = item['category']
                serialnumber = item['serialnumber']
                serialstatus = item['serialstatus']
                novelurl = item['novelurl']
                Sql.insert_dingdian(xs_name,
                                    xs_author,
                                    category,
                                    name_id,
                                    serialnumber,
                                    serialstatus,
                                    novelurl
                                   )
                print('开始存储小说数据')
