import mysql.connector, sys
sys.path.append("/home/natsu/文档/git/learn/Scrapy_dingdian/Scrapy_dingdian")
import settings

MYSQL_USER = settings.MYSQL_USER
MYSQL_PASSWORD = settings.MYSQL_PASSWORD
MYSQL_DB = settings.MYSQL_DB

cnx = mysql.connector.connect(user = MYSQL_USER, password = MYSQL_PASSWORD, database = MYSQL_DB)
cur = cnx.cursor(buffered = True)

class Sql():
    @classmethod
    def insert_dingdian(cls, xs_name, xs_author, category, name_id, serialnumber, serialstatus, novelurl):
        sql = "INSERT INTO dingdian (\
                name_id,\
                xs_name,\
                xs_author,\
                category,\
                serialnumber,\
                serialstatus,\
                novelurl\
        ) VALUES (\
                %(name_id)s,\
                %(xs_name)s,\
                %(xs_author)s,\
                %(category)s,\
                %(serialnumber)s,\
                %(serialstatus)s,\
                %(novelurl)s\
        )"
        value = {
            "name_id": name_id,
            "xs_name": xs_name,
            "xs_author": xs_author,
            "category": category,
            "serialnumber": serialnumber,
            "serialstatus": serialstatus,
            "novelurl": novelurl
        }
        cur.execute(sql, value)
        cnx.commit()

    @classmethod
    def select_name(cls, name_id):
        sql = 'SELECT EXISTS(SELECT * FROM dingdian WHERE name_id=%(name_id)s)'
        value = {
            'name_id': name_id
        }
        cur.execute(sql, value)
        return cur.fetchall()[0]
